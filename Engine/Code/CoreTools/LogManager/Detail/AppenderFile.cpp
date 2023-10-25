///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:52)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFile.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/Time/CustomTime.h"

using namespace std::literals;

CoreTools::AppenderFile::AppenderFile(const String& directory,
                                      const String& fileName,
                                      AppenderPrint appenderFlags,
                                      LogLevel logLevel,
                                      int maxFileSize,
                                      bool backup,
                                      String extensionName)
    : ParentType{ appenderFlags, logLevel },
      directory{ directory },
      prefixName{ GetPrefixName(directory, fileName) },
      extensionName{ std::move(extensionName) },
      maxFileSize{ maxFileSize },
      backup{ backup }
{
    Init(directory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::AppenderFile::Init(const String& newDirectory)
{
    NewDirectory(newDirectory);

    const auto fullName = GetFullName(prefixName, extensionName);
    auto streamManager = make_shared<OFStreamManager>(fullName, true);
    streamManager->SetSimplifiedChinese();

    if (IsExceedMaxSize(*streamManager, 0))
    {
        streamManager.reset();
        BackupFile(fullName);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::AppenderFile::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < maxFileSize)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::AppenderType CoreTools::AppenderFile::GetAppenderType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return AppenderType::File;
}

void CoreTools::AppenderFile::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const
{
    const auto fullName = GetFullName(prefixName, extensionName);

    auto streamManager = make_shared<OFStreamManager>(fullName, true);
    streamManager->SetSimplifiedChinese();

    const auto messageDescribe = message.GetMessageDescribe();

    if (const auto fullMessage = prefix.GetPrefix() + messageDescribe + postfix.GetPostfix();
        IsExceedMaxSize(*streamManager, boost::numeric_cast<PosType>(fullMessage.size())))
    {
        streamManager.reset();
        BackupFile(fullName);

        OFStreamManager newStreamManager{ fullName, false };
        newStreamManager.SetSimplifiedChinese();

        newStreamManager << fullMessage;
    }
    else
    {
        *streamManager << fullMessage;
    }
}

bool CoreTools::AppenderFile::IsExceedMaxSize(const OFStreamManager& stream, PosType increaseSize) const
{
    const auto fileSize = stream.GetStreamSize();

    return (maxFileSize < fileSize + increaseSize);
}

void CoreTools::AppenderFile::BackupFile(const String& fullName) const
{
    if (backup)
    {
        const IFStreamManager manager{ fullName };
        MAYBE_UNUSED const auto name = manager.BackupFile();
    }
}

const CoreTools::AppenderFile::AppenderImplSharedPtr CoreTools::AppenderFile::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

System::String CoreTools::AppenderFile::GetFullName(const String& prefixName, const String& extensionName)
{
    return prefixName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")."s) + extensionName;
}

System::String CoreTools::AppenderFile::GetPrefixName(const String& directory, const String& fileName)
{
    return directory + SYSTEM_TEXT("/"s) + fileName;
}

void CoreTools::AppenderFile::NewDirectory(const String& directory) noexcept
{
    MAYBE_UNUSED const auto result = System::CreateFileDirectory(directory, nullptr);
}

System::String CoreTools::AppenderFile::GetDirectory() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return directory;
}

System::String CoreTools::AppenderFile::GetExtensionName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return extensionName;
}

int CoreTools::AppenderFile::GetMaxFileSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return maxFileSize;
}

bool CoreTools::AppenderFile::IsBackup() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return backup;
}

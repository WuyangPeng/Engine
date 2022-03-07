///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFile.h"
#include "System/FileManager/FileTools.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/Time/CustomTime.h"

using std::make_shared;
using namespace std::literals;

CoreTools::AppenderFile::AppenderFile(const String& directory,
                                      const String& fileName,
                                      AppenderPrint appenderFlags,
                                      LogLevel logLevel,
                                      int maxFileSize,
                                      bool backup,
                                      const String& extensionName)
    : ParentType{ appenderFlags, logLevel },
      directory{ directory },
      prefixName{ GetPrefixName(directory, fileName) },
      extensionName{ extensionName },
      fullName{ GetFullName(prefixName, extensionName) },
      maxFileSize{ maxFileSize },
      backup{ backup },
      streamManager{}
{
    Init(directory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AppenderFile::Init(const String& newDirectory)
{
    NewDirectory(newDirectory);

    streamManager = make_shared<OFStreamManager>(fullName, true);
    streamManager->SetSimplifiedChinese();

    if (IsExceedMaxSize(0))
    {
        BackupFile();
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::AppenderFile::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < maxFileSize && streamManager != nullptr)
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

// private
void CoreTools::AppenderFile::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix)
{
    const auto messageDescribe = message.GetMessageDescribe();

    const auto fullMessage = prefix.GetPrefix() + messageDescribe + postfix.GetPostfix();

    if (IsExceedMaxSize(fullMessage.size()))
    {
        BackupFile();
    }

    *streamManager << fullMessage;
}

// private
bool CoreTools::AppenderFile::IsExceedMaxSize(PosType increaseSize)
{
    const auto fileSize = streamManager->GetOFStreamSize();

    return (maxFileSize < fileSize + increaseSize);
}

// private
void CoreTools::AppenderFile::BackupFile()
{
    if (backup)
    {
        const CoreTools::IFStreamManager manager{ fullName };
        MAYBE_UNUSED const auto name = manager.BackupFile();
    }

    streamManager = make_shared<OFStreamManager>(fullName, false);
    streamManager->SetSimplifiedChinese();
}

const CoreTools::AppenderFile::AppenderImplSharedPtr CoreTools::AppenderFile::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

void CoreTools::AppenderFile::Reload()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    fullName = GetFullName(prefixName, extensionName);

    streamManager = make_shared<OFStreamManager>(fullName, true);
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

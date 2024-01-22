/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:58)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "FileInStream.h"
#include "OutTopLevel.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CoreTools::FileInStream::FileInStream(const String& fileName)
    : inTopLevel{ InTopLevel::Create() }
{
    Load(fileName);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::FileInStream::Load(const System::String& fileName)
{
    ReadFileManager manager{ fileName };

    const auto readSize = manager.GetFileByteSize();

    // 获取该文件的版本。
    const auto version = Version::GetVersion();

    const auto length = version.length();
    if (readSize < boost::numeric_cast<int>(length + 1))
    {
        THROW_EXCEPTION(fileName + SYSTEM_TEXT("版本字符串不存在或者存储的版本字符串不够大"s))
    }

    const auto bufferInformation = std::make_shared<FileBuffer>(readSize);

    manager.Read(CoreTools::GetStreamSize<char>(), bufferInformation->GetSize(), bufferInformation->GetBufferBegin());

    // 比较所需的文件版本。
    if (const std::string fileVersion{ bufferInformation->GetBufferBegin(), length };
        fileVersion != version)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("版本字符串不匹配！"s))
    }

    // 从缓冲区重构场景图。
    const BufferInStream stream{ bufferInformation, boost::numeric_cast<int>(length) };

    inTopLevel = stream.GetTopLevel();
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileInStream)

CoreTools::InTopLevel CoreTools::FileInStream::GetInTopLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return inTopLevel;
}

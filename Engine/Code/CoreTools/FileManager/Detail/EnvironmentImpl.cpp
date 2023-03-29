///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:36)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerImpl.h"
#include "EnvironmentImpl.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::EnvironmentImpl::EnvironmentImpl() noexcept
    : directories{}, configurationPath{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentImpl)

int CoreTools::EnvironmentImpl::GetNumDirectories() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(directories.size());
}

bool CoreTools::EnvironmentImpl::InsertDirectory(const String& directory)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return directories.insert(directory).second;
}

bool CoreTools::EnvironmentImpl::EraseDirectory(const String& directory)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto eraseNumber = directories.erase(directory);

    return (eraseNumber != 0);
}

void CoreTools::EnvironmentImpl::EraseAllDirectories() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    directories.clear();
}

System::String CoreTools::EnvironmentImpl::GetPathReading(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetPath(fileName, SYSTEM_TEXT("r"s));
}

System::String CoreTools::EnvironmentImpl::GetPathWriting(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetPath(fileName, SYSTEM_TEXT("w"s));
}

System::String CoreTools::EnvironmentImpl::GetPathReadingAndWriting(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetPath(fileName, SYSTEM_TEXT("r+"s));
}

System::String CoreTools::EnvironmentImpl::GetPath(const String& fileName, const String& attributes) const
{
    for (const auto& path : directories)
    {
        if (auto decorated = path + fileName; IsFileInPathExist(decorated, attributes))
        {
            return decorated;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找符合条件的文件名！"s))
}

bool CoreTools::EnvironmentImpl::IsFileInPathExist(const String& decorated, const String& attributes)
{
    FILE* file{ nullptr };

    const auto decoratedConversion = StringConversion::StandardConversionCFileString(decorated);
    const auto attributesConversion = StringConversion::StandardConversionCFileString(attributes);

    if (System::OpenCFile(file, decoratedConversion, attributesConversion))
    {
        if (const auto result = System::CloseCFile(file); !result)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("文件"), decorated, SYSTEM_TEXT("关闭失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        return true;
    }
    else
    {
        return false;
    }
}

void CoreTools::EnvironmentImpl::SetConfigurationPath(const String& aConfigurationPath)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    configurationPath = aConfigurationPath;
}

const System::String CoreTools::EnvironmentImpl::GetConfigurationPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return configurationPath;
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 23:07)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerImpl.h"
#include "EnvironmentImpl.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::EnvironmentImpl::EnvironmentImpl() noexcept
    : directories{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentImpl)

int CoreTools::EnvironmentImpl::GetNumDirectories() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(directories.size());
}

CoreTools::EnvironmentImpl::String CoreTools::EnvironmentImpl::GetDirectory(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return directories.at(index);
}

bool CoreTools::EnvironmentImpl::InsertDirectory(const String& directory)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (directory.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Insert需要非空输入。"))
    }

    const auto forwardSlashDirectory = GetReplaceBackslash(directory);

    if (const auto iter = std::ranges::find(directories, forwardSlashDirectory);
        iter != directories.cend())
    {
        return false;
    }

    directories.emplace_back(forwardSlashDirectory);

    return true;
}

bool CoreTools::EnvironmentImpl::EraseDirectory(const String& directory)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!directory.empty())
    {
        const auto forwardSlashDirectory = GetReplaceBackslash(directory);

        if (const auto result = std::ranges::remove(directories, forwardSlashDirectory);
            result.begin() != result.end())
        {
            directories.erase(result.begin(), result.end());

            return true;
        }
    }

    return false;
}

System::String CoreTools::EnvironmentImpl::GetReplaceBackslash(String directory)
{
    CORE_TOOLS_ASSERTION_0(!directory.empty(), "目录必须非空。");

    boost::algorithm::replace_all(directory, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));

    if (directory.back() == TextParsing::gForwardSlash)
    {
        return directory;
    }
    else
    {
        // 确保所有目录都以斜杠结尾。
        return directory + TextParsing::gForwardSlash;
    }
}

void CoreTools::EnvironmentImpl::EraseAllDirectories() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    directories.clear();
}

System::String CoreTools::EnvironmentImpl::GetPathReading(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetPath(fileName, SYSTEM_TEXT("r"));
}

System::String CoreTools::EnvironmentImpl::GetPathWriting(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetPath(fileName, SYSTEM_TEXT("w"));
}

System::String CoreTools::EnvironmentImpl::GetPathReadingAndWriting(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetPath(fileName, SYSTEM_TEXT("r+"));
}

System::String CoreTools::EnvironmentImpl::GetPath(const String& fileName, const String& attributes) const
{
    for (const auto& path : directories)
    {
        if (auto decorated = path + fileName;
            IsFileInPathExist(decorated, attributes))
        {
            return decorated;
        }
    }

    if (IsFileInPathExist(fileName, attributes))
    {
        return fileName;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找符合条件的文件名！"s))
    }
}

bool CoreTools::EnvironmentImpl::IsFileInPathExist(const String& decorated, const String& attributes)
{
    if (FILE * file{ nullptr };
        System::OpenCFile(file,
                          StringConversion::StandardConversionCFileString(decorated),
                          StringConversion::StandardConversionCFileString(attributes)))
    {
        if (const auto result = System::CloseCFile(file);
            !result)
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

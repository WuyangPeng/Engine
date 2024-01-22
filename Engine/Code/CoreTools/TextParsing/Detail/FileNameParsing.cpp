/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:59)

#include "CoreTools/CoreToolsExport.h"

#include "FileNameParsing.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::FileNameParsing::FileNameParsing(const String& fullFileName)
    : fullFileName{ fullFileName }, slashPosition{ GetPosition(fullFileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

size_t CoreTools::FileNameParsing::GetPosition(const String& fullFileName)
{
    if (fullFileName.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空！\n"s))
    }

    const auto backSlashPosition = fullFileName.find_last_of(TextParsing::gBackSlash);
    const auto forwardSlashPosition = fullFileName.find_last_of(TextParsing::gForwardSlash);

    if (backSlashPosition == String::npos && forwardSlashPosition == String::npos)
    {
        return String::npos;
    }
    else if (backSlashPosition == String::npos && forwardSlashPosition != String::npos)
    {
        return forwardSlashPosition;
    }
    else if (backSlashPosition != String::npos && forwardSlashPosition == String::npos)
    {
        return backSlashPosition;
    }
    else if (backSlashPosition < forwardSlashPosition)
    {
        return forwardSlashPosition;
    }
    else
    {
        return backSlashPosition;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::FileNameParsing::IsValid() const noexcept
{
    if (!fullFileName.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::FileNameParsing::GetWithSlashFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (slashPosition == String::npos)
    {
        return TextParsing::gForwardSlash + fullFileName;
    }
    else
    {
        return fullFileName.substr(slashPosition);
    }
}

System::String CoreTools::FileNameParsing::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (slashPosition == String::npos)
    {
        return fullFileName;
    }
    else
    {
        return fullFileName.substr(slashPosition + 1);
    }
}

System::String CoreTools::FileNameParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto fileName = GetFileName();

    if (const auto dotPosition = fileName.find_first_of(TextParsing::gDot); dotPosition == String::npos)
    {
        return StringUtility::ToFirstLetterUpper(fileName);
    }
    else
    {
        return StringUtility::ToFirstLetterUpper(fileName.substr(0, dotPosition));
    }
}

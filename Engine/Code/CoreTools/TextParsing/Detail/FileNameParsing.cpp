/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:53)

#include "CoreTools/CoreToolsExport.h"

#include "FileNameParsing.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::FileNameParsing::FileNameParsing(const String& fullFileName)
    : fullFileName{ fullFileName }, slashPosition{ System::GetLastSlashPosition(fullFileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::FileNameParsing::IsValid() const noexcept
{
    return !fullFileName.empty();
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

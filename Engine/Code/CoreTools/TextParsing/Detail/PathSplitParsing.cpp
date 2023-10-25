///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:10)

#include "CoreTools/CoreToolsExport.h"

#include "PathSplitParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::PathSplitParsing::PathSplitParsing(String path)
    : path{ std::move(path) }, nameSpace{}, className{}
{
    Parsing();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::PathSplitParsing::SplitContainer CoreTools::PathSplitParsing::SplitPath() const
{
    SplitContainer pathSplit{};
    split(pathSplit, path, boost::is_any_of(TextParsing::gFileSplit), boost::token_compress_on);

    return pathSplit;
}

void CoreTools::PathSplitParsing::Parsing()
{
    if (path.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空。"s))
    }

    const auto pathSplit = SplitPath();

    ParsingNameSpace(pathSplit);
    ParsingClassName(pathSplit);
}

void CoreTools::PathSplitParsing::ParsingNameSpace(const SplitContainer& splitContainer)
{
    if (1 < splitContainer.size())
    {
        nameSpace = StringUtility::ToFirstLetterUpper(splitContainer.at(splitContainer.size() - 2));
    }
    else
    {
        nameSpace = TextParsing::gCSVNameSpace;
    }
}

void CoreTools::PathSplitParsing::ParsingClassName(const SplitContainer& splitContainer)
{
    if (!splitContainer.empty())
    {
        const auto& lastName = splitContainer.back();
        const auto position = lastName.find(TextParsing::gDot);

        className = StringUtility::ToFirstLetterUpper(lastName.substr(0, position));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空。"s))
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::PathSplitParsing::IsValid() const noexcept
{
    if (!path.empty() && !nameSpace.empty() && !className.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::PathSplitParsing::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return nameSpace;
}

System::String CoreTools::PathSplitParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return className;
}

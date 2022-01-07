///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:28)

#include "CoreTools/CoreToolsExport.h"

#include "PathSplitParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::PathSplitParsing::PathSplitParsing(const String& path)
    : path{ path }, nameSpace{}, className{}
{
    Parsing();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::PathSplitParsing::SplitContainer CoreTools::PathSplitParsing::SplitPath() const
{
    SplitContainer pathSplit{};
    boost::algorithm::split(pathSplit, path, boost::is_any_of(TextParsing::g_FileSplit), boost::token_compress_on);

    return pathSplit;
}

void CoreTools::PathSplitParsing::Parsing()
{
    if (path.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空。"s));
    }

    const auto pathSplit = SplitPath();

    ParsingNameSpace(pathSplit);
    ParsingClassName(pathSplit);
}

void CoreTools::PathSplitParsing::ParsingNameSpace(const SplitContainer& splitContainer)
{
    if (1 < splitContainer.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        nameSpace = StringConversion::ToFirstLetterUpper(splitContainer[splitContainer.size() - 2]);

#include STSTEM_WARNING_POP
    }
    else
    {
        nameSpace = TextParsing::g_CSVNameSpace;
    }
}

void CoreTools::PathSplitParsing::ParsingClassName(const SplitContainer& splitContainer)
{
    if (!splitContainer.empty())
    {
        const auto& lastName = splitContainer.back();
        const auto poistion = lastName.find(TextParsing::g_Dot);

        className = StringConversion::ToFirstLetterUpper(lastName.substr(0, poistion));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空。"s));
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

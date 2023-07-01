///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:06)

#include "CoreTools/CoreToolsExport.h"

#include "ChildMemberParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ChildMemberParsing::ChildMemberParsing(CSVHead csvHead) noexcept
    : ParentType{ 1 }, csvHead{ std::move(csvHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ChildMemberParsing)

System::String CoreTools::ChildMemberParsing::GenerateChildMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gPrivate;

    content += GenerateMember();

    content += GenerateIndentation();
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildMemberParsing::GenerateMember() const
{
    String content{};

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        const auto abbreviation = csvHead.GetAbbreviation(index);
        const auto variableName = csvHead.GetVariableName(index);
        const auto annotation = StringConversion::Utf8ConversionStandard(csvHead.GetAnnotation(index));

        content += GenerateIndentation(1);
        content += abbreviation;

        content += TextParsing::gSpace;
        content += variableName;
        content += TextParsing::gSemicolonAnnotation;
        content += annotation;
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

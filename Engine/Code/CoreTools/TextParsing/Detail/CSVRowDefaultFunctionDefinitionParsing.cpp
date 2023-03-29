///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:40)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "CSVRowDefaultFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVRowDefaultFunctionDefinitionParsing::CSVRowDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVRowDefaultFunctionDefinitionParsing)

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateCSVRowChildConstructorDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateConstructor(TextParsing::gCSVRow);

    content += GenerateParentMember();

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateMemberDefinition(index, (index == count - 1) ? CSVPositionType::End : CSVPositionType::Middle);
    }

    content += GenerateCSVRowConstructorDefinitionContent();

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateCSVRowConstructorDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateConstructor(TextParsing::gCSVRow);

    content += GenerateMemberColon();

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateMemberDefinition(index, GetPositionType(index, count));
    }

    content += GenerateCSVRowConstructorDefinitionContent();

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateCSVRowConstructorDefinitionContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();

    if (HasCSVHeadScope())
    {
        content += GenerateChecking();
        content += GenerateUserSelfClassIsValid1(1);
    }
    else
    {
        content += GenerateUserSelfClassIsValid9(1);
    }

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateParentMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gParentTypeMember;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateMemberDefinition(int index, CSVPositionType csvPositionType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto getFunctionName = csvHead.GetFunctionName(index);
    const auto variableName = csvHead.GetVariableName(index);
    const auto lowerVariableName = StringUtility::ToFirstLetterLower(variableName);

    String content{};
    if (csvPositionType != CSVPositionType::Begin)
    {
        content += TextParsing::gMemberIndentation;
    }

    content += lowerVariableName;
    content += TextParsing::gCsvRowVariable;
    content += getFunctionName;
    content += TextParsing::gSystemTextBegin;
    content += lowerVariableName;
    content += TextParsing::gSystemTextEnd;
    content += TextParsing::gRightBrace;

    if (csvPositionType != CSVPositionType::End)
    {
        content += TextParsing::gComma;
    }

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateChecking() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gChecking;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateMemberColon() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gColon;
    content += TextParsing::gSpace;

    return content;
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:56)

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

    auto content = GenerateConstructor(TextParsing::g_CSVRow);

    content += GenerateParentMember();

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateMemberDefinition(index, (index == count - 1) ? CSVPoistionType::End : CSVPoistionType::Middle);
    }

    content += GenerateCSVRowConstructorDefinitionContent();

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateCSVRowConstructorDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateConstructor(TextParsing::g_CSVRow);

    content += GenerateMemberColon();

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateMemberDefinition(index, GetPoistionType(index, count));
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
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateParentMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ParentTypeMember;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateMemberDefinition(int index, CSVPoistionType csvPoistionType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto getFunctionName = csvHead.GetFunctionName(index);
    auto variableName = csvHead.GetVariableName(index);
    auto lowerVariableName = StringUtility::ToFirstLetterLower(variableName);

    String content{};
    if (csvPoistionType != CSVPoistionType::Begin)
    {
        content += TextParsing::g_MemberIndentation;
    }

    content += lowerVariableName;
    content += TextParsing::g_CsvRowVariable;
    content += getFunctionName;
    content += TextParsing::g_SystemTextBegin;
    content += lowerVariableName;
    content += TextParsing::g_SystemTextEnd;
    content += TextParsing::g_RightBigParantheses;

    if (csvPoistionType != CSVPoistionType::End)
    {
        content += TextParsing::g_Comma;
    }

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateChecking() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Checking;
    content += TextParsing::g_SemicolonNewline;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVRowDefaultFunctionDefinitionParsing::GenerateMemberColon() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Colon;
    content += TextParsing::g_Space;

    return content;
}

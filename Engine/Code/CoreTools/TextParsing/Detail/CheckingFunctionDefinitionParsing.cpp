///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:53)

#include "CoreTools/CoreToolsExport.h"

#include "CheckingFunctionDefinitionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::CheckingFunctionDefinitionParsing::CheckingFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CheckingFunctionDefinitionParsing)

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateCheckingFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateChecking();

    content += GenerateFunctionBeginBrackets();

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateCheckingMember(index, index == 0);
    }

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateChecking() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_Void };

    content += GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Checking;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateCheckingMember(int index, bool isBegin) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    const auto csvHead = GetCSVHead();

    const auto scope = csvHead.GetScope(index);

    if (!scope.empty())
    {
        if (isBegin)
        {
            content += TextParsing::g_NewlineCharacter;
        }

        content += GenerateCheckingMemberScopeExpression(csvHead.GetScopeExpression(index));

        content += GenerateFunctionBeginBrackets(1);

        const auto variableName = csvHead.GetVariableName(index);
        content += GenerateThrowException(variableName);

        content += GenerateFunctionEndBrackets(1);
    }

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateIsValidFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateOpenClassInvariant();

    content += GenerateIsValid();

    content += GenerateFunctionBeginBrackets();
    content += GenerateIsValidAchieve();
    content += GenerateFunctionEndBrackets();

    content += GenerateOpenClassInvariantEndif();

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateIsValid() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_Bool };

    content += GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_IsValid;

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateThrowException(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ThrowException;
    content += variableName;
    content += SYSTEM_TEXT(" 数据校验失败。\"s));\n"s);

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateCheckingMemberScopeExpression(const String& scopeExpression) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += SYSTEM_TEXT("if (!(");
    content += scopeExpression;
    content += SYSTEM_TEXT("))\n"s);

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateIsValidAchieve() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateParentTypeIsValid(1);

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateIsValidMember(index, index == 0);
    }

    content += TextParsing::g_RightBracket;

    constexpr auto indentation = 1;

    content += GenerateFunctionBeginBrackets(indentation);
    content += GenerateReturnTrue(indentation + 1);
    content += GenerateFunctionEndBrackets(indentation);

    content += GenerateElse(indentation);

    content += GenerateFunctionBeginBrackets(indentation);
    content += GenerateReturnFalse(indentation + 1);
    content += GenerateFunctionEndBrackets(indentation);

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateIsValidMember(int index, bool isBegin) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    const auto csvHead = GetCSVHead();

    const auto scope = csvHead.GetScope(index);

    if (!scope.empty())
    {
        if (isBegin)
        {
            content += TextParsing::g_AndNewline;
        }

        content += GenerateIsValidMemberScopeExpression(csvHead.GetScopeExpression(index));
    }

    return content;
}

System::String CoreTools::CheckingFunctionDefinitionParsing::GenerateIsValidMemberScopeExpression(const String& scopeExpression) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_LeftBrackets;
    content += scopeExpression;
    content += TextParsing::g_RightBrackets;

    return content;
}
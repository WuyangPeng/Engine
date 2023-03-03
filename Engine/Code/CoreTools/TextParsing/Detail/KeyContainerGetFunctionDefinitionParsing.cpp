///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:26)

#include "CoreTools/CoreToolsExport.h"

#include "KeyContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::KeyContainerGetFunctionDefinitionParsing::KeyContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, KeyContainerGetFunctionDefinitionParsing)

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto lowerClassName = StringUtility::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetFirstDefinition(lowerClassName);

    content += GenerateGetKeyDefinition();
    content += GenerateGetDefinition(lowerClassName);
    content += GenerateGetContainerDefinition(lowerClassName, TextParsing::g_Container);

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = GenerateGetKeyFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GeneratReturnGenerateKey();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Get;
    content += csvHead.GetCSVClassName();

    content += GenerateGetKeyFunctionList();

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyFunctionList() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_LeftBrackets };

    const auto csvHead = GetCSVHead();
    const auto result = csvHead.GetKeyName();

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += TextParsing::g_Space;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::g_Comma;
            content += TextParsing::g_Space;
        }
    }

    content += TextParsing::g_ConstNewline;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GeneratReturnGenerateKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += TextParsing::g_Get;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_LeftBrackets;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_DoubleColonGenerateKey;

    content += GenerateGetKeyFunctionCall();

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyFunctionCall() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_LeftBrackets };

    auto index = 0u;
    const auto csvHead = GetCSVHead();
    const auto result = csvHead.GetKeyName();
    for (const auto& value : result)
    {
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::g_Comma;
            content += TextParsing::g_Space;
        }
    }

    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateLambdaFunctionInit();
    content += GenerateLambdaFunctionFind(lowerClassName);
    content += GenerateLambdaFunctionResult(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Get;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_LeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::g_KeyConstFunction;

    return content;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 10:08)

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
    content += GenerateGetContainerDefinition(lowerClassName, TextParsing::gContainer);

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
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnGenerateKey();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += csvHead.GetCSVClassName();

    content += GenerateGetKeyFunctionList();

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyFunctionList() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gLeftBrackets };

    const auto csvHead = GetCSVHead();
    const auto result = csvHead.GetKeyName();

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += TextParsing::gSpace;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::gComma;
            content += TextParsing::gSpace;
        }
    }

    content += TextParsing::gConstNewline;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateReturnGenerateKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gGet;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gDoubleColonGenerateKey;

    content += GenerateGetKeyFunctionCall();

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetKeyFunctionCall() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gLeftBrackets };

    auto index = 0u;
    const auto csvHead = GetCSVHead();

    for (const auto result = csvHead.GetKeyName(); const auto& value : result)
    {
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::gComma;
            content += TextParsing::gSpace;
        }
    }

    content += TextParsing::gRightBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateLambdaFunctionInit();
    content += GenerateLambdaFunctionFind(lowerClassName);
    content += GenerateLambdaFunctionResult(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::KeyContainerGetFunctionDefinitionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::gKeyConstFunction;

    return content;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:36)

#include "CoreTools/CoreToolsExport.h"

#include "VectorContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::VectorContainerGetFunctionDefinitionParsing::VectorContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, VectorContainerGetFunctionDefinitionParsing)

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto lowerClassName = StringUtility::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetDefinition(lowerClassName);

    content += GenerateGetAllContainerDefinition(lowerClassName);
    content += GenerateGetContainerDefinition(lowerClassName, TextParsing::gContainer);

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateLambdaFunctionInit();
    content += GenerateEqualRange(lowerClassName);
    content += GenerateFindResult(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetFunction() const
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
    content += TextParsing::gGetFirst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::gKeyConstFunction;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateEqualRange(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::gEqualRange;
    content += lowerClassName;
    content += TextParsing::gDot;
    content += TextParsing::gBegin;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += lowerClassName;
    content += TextParsing::gEndMakeShared;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBaseKeyFunction;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateReturnRangeFirst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gReturnRangeFirst;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateRangeFirst(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gRangeFirst;
    content += lowerClassName;
    content += TextParsing::gCEnd;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateFindResult(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateRangeFirst(lowerClassName);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateReturnRangeFirst();
    content += GenerateFunctionEndBrackets(1);

    content += GenerateElse(1);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateLambdaFunctionThrowException(lowerClassName);
    content += GenerateFunctionEndBrackets(1);

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetAllContainerDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetContainerFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateLambdaFunctionInit();
    content += GenerateEqualRange(lowerClassName);
    content += GenerateReturnContainer();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;

    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gContainer;
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

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateReturnContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturnContainerRange;

    return content;
}

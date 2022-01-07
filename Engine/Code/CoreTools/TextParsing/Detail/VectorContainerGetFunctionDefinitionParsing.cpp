///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:34)

#include "CoreTools/CoreToolsExport.h"

#include "VectorContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
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

    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetDefinition(lowerClassName);

    content += GenerateGetAllContainerDefinition(lowerClassName);
    content += GenerateGetContainerDefinition(lowerClassName, TextParsing::g_Container);

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateLambdaFunctionInit();
    content += GenerateEqualRange(lowerClassName);
    content += GenerateFindResult(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetFunction() const
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
    content += TextParsing::g_GetFirst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_LeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::g_KeyConstFunction;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateEqualRange(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_EqualRange;
    content += lowerClassName;
    content += TextParsing::g_Begin;
    content += lowerClassName;
    content += TextParsing::g_EndMakeShared;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_BaseKeyFunction;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateReturnRangeFirst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ReturnRangeFirst;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateRangeFirst(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_RangeFirst;
    content += lowerClassName;
    content += TextParsing::g_CEnd;

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
    content += TextParsing::g_NewlineCharacter;

    content += GenerateLambdaFunctionInit();
    content += GenerateEqualRange(lowerClassName);
    content += GenerateReturnContainer();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateGetContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;

    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Container;
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

System::String CoreTools::VectorContainerGetFunctionDefinitionParsing::GenerateReturnContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ReturnContainerRange;

    return content;
}

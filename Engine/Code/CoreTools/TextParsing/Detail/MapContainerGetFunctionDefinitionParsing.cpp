///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "MapContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::MapContainerGetFunctionDefinitionParsing::MapContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MapContainerGetFunctionDefinitionParsing)

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetMapFirstDefinition(lowerClassName);

    content += GenerateGetMapDefinition(lowerClassName);
    content += GenerateGetContainerDefinition(lowerClassName, TextParsing::g_MappingContainer);

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetFirstFunction() const
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
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_GetFirst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_FunctionConst;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetMapFirstDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFirstFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetMapReturnFirst(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetMapReturnFirst(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIfEmpty(lowerClassName);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateThrowException(lowerClassName);
    content += GenerateFunctionEndBrackets(1);

    content += GenerateElse(1);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateReturnBegin(lowerClassName);
    content += GenerateFunctionEndBrackets(1);

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateIfEmpty(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_If;
    content += lowerClassName;
    content += TextParsing::g_Empty;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateThrowException(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ThrowException;
    content += lowerClassName;
    content += TextParsing::g_ContainerZero;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateReturnBegin(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_Return;
    content += lowerClassName;
    content += TextParsing::g_BeginSecond;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetMapDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunction();

    content += GenerateMapFind(lowerClassName);

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateMapFind(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateMapFindDefinition(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateMapFindDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIterFind(lowerClassName);
    content += GenerateFindJudge(lowerClassName);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateReturnIterSecond();
    content += GenerateFunctionEndBrackets(1);

    content += GenerateElse(1);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateLambdaFunctionThrowException(lowerClassName);
    content += GenerateFunctionEndBrackets(1);

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetFunction() const
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

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateIterFind(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ConstAutoIter;
    content += lowerClassName;
    content += TextParsing::g_FindKey;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateFindJudge(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_IfIter;
    content += lowerClassName;
    content += TextParsing::g_CEnd;

    return content;
}

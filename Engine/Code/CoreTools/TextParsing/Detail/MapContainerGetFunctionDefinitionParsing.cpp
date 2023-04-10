///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:51)

#include "CoreTools/CoreToolsExport.h"

#include "MapContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
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

    const auto lowerClassName = StringUtility::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetMapFirstDefinition(lowerClassName);

    content += GenerateGetMapDefinition(lowerClassName);
    content += GenerateGetContainerDefinition(lowerClassName, TextParsing::gMappingContainer);

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetFirstFunction() const
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
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gGetFirst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gFunctionConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateGetMapFirstDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFirstFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetMapReturnFirst(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

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

    content += TextParsing::gIf;
    content += lowerClassName;
    content += TextParsing::gEmpty;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateThrowException(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gThrowException;
    content += lowerClassName;
    content += TextParsing::gContainerZero;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateReturnBegin(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += lowerClassName;
    content += TextParsing::gBeginSecond;

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
    content += TextParsing::gNewlineCharacter;

    content += GenerateMapFindDefinition(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

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
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColonConst;
    content += csvHead.GetCSVClassName();
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

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateIterFind(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gConstAutoIter;
    content += lowerClassName;
    content += TextParsing::gFindKey;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDefinitionParsing::GenerateFindJudge(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gIfIter;
    content += lowerClassName;
    content += TextParsing::gCEnd;

    return content;
}

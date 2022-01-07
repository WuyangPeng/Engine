///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "MapContainerGetFunctionDetailDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::MapContainerGetFunctionDetailDefinitionParsing::MapContainerGetFunctionDetailDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MapContainerGetFunctionDetailDefinitionParsing)

System::String CoreTools::MapContainerGetFunctionDetailDefinitionParsing::GenerateGetFirstContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto csvClassName = csvHead.GetCSVClassName();

    auto content = GenerateIndentation();

    content += TextParsing::g_FunctionTemplate;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += csvClassName;
    content += TextParsing::g_Container;
    content += TextParsing::g_DoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += csvClassName;
    content += TextParsing::g_Container;
    content += TextParsing::g_GetFirst;
    content += csvClassName;
    content += TextParsing::g_FunctionParameterConst;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDetailDefinitionParsing::GenerateEmplaceBack() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_IfFunctionValueSecond;

    content += GenerateFunctionBeginBrackets(2);

    content += GenerateIndentation(3);
    content += TextParsing::g_ResultEmplaceBackValueSecond;

    content += GenerateFunctionEndBrackets(2);

    return content;
}

System::String CoreTools::MapContainerGetFunctionDetailDefinitionParsing::GenerateFind(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateLoopInit(lowerClassName);

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateIndentation(2);
    content += TextParsing::g_IfFunctionValueSecond;

    content += GenerateFunctionBeginBrackets(2);

    content += GenerateIndentation(3);
    content += TextParsing::g_ReturnValueSecond;

    content += GenerateFunctionEndBrackets(2);

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateThrowException(lowerClassName);

    return content;
}

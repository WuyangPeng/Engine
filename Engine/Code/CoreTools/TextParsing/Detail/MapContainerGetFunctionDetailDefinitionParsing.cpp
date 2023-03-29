///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 10:10)

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

    content += TextParsing::gFunctionTemplate;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += csvClassName;
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColonConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += csvClassName;
    content += TextParsing::gContainer;
    content += TextParsing::gGetFirst;
    content += csvClassName;
    content += TextParsing::gFunctionParameterConst;

    return content;
}

System::String CoreTools::MapContainerGetFunctionDetailDefinitionParsing::GenerateEmplaceBack() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gIfFunctionValueSecond;

    content += GenerateFunctionBeginBrackets(2);

    content += GenerateIndentation(3);
    content += TextParsing::gResultEmplaceBackValueSecond;

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
    content += TextParsing::gIfFunctionValueSecond;

    content += GenerateFunctionBeginBrackets(2);

    content += GenerateIndentation(3);
    content += TextParsing::gReturnValueSecond;

    content += GenerateFunctionEndBrackets(2);

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateThrowException(lowerClassName);

    return content;
}

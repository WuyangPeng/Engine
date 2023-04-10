///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:54)

#include "CoreTools/CoreToolsExport.h"

#include "ContainerGetFunctionDetailDefinitionParsing.h"
#include "DefaultContainerGetFunctionDetailDefinitionParsing.h"
#include "MapContainerGetFunctionDetailDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ContainerGetFunctionDetailDefinitionParsing::ContainerGetFunctionDetailDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ csvHead, className, String{} }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerGetFunctionDetailDefinitionParsing)

CoreTools::ContainerGetFunctionDetailDefinitionParsing::ContainerGetFunctionDetailDefinitionParsingSharedPtr CoreTools::ContainerGetFunctionDetailDefinitionParsing::Create(const CSVHead& csvHead, const String& className)
{
    switch (const auto csvFormatType = csvHead.GetCSVFormatType(); csvFormatType)
    {
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_shared<MapContainerGetFunctionDetailDefinitionParsing>(csvHead, className);
        }
        default:
        {
            return std::make_shared<DefaultContainerGetFunctionDetailDefinitionParsing>(csvHead, className);
        }
    }
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto lowerClassName = StringUtility::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = GenerateGetFirstFunction(lowerClassName);

    content += GenerateGetFunction(lowerClassName);

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetFirstFunction(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFirstContainer();

    content += GenerateFunctionBeginBrackets();
    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateFind(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateFindIf(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gIterFindIf;
    content += lowerClassName;
    content += TextParsing::gFindFunction;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateIterIf(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gIfIter;
    content += lowerClassName;
    content += TextParsing::gCEnd;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateThrowException(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gThrowException;
    content += lowerClassName;
    content += TextParsing::gConditionNotFind;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetFunction(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetContainer();

    content += GenerateFunctionBeginBrackets();
    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetFindResult(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetContainer() const
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
    content += TextParsing::gDoubleColon;
    content += TextParsing::gContainer;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += csvClassName;
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += csvClassName;
    content += TextParsing::gFunctionParameterConst;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateContainerInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gContainerResult;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateLoopInit(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gForLoop;
    content += lowerClassName;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewline;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateReturnResult() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturnResult;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetFindResult(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateContainerInit();

    content += GenerateLoopInit(lowerClassName);

    content += GenerateFunctionBeginBrackets(1);

    content += GenerateEmplaceBack();

    content += GenerateFunctionEndBrackets(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnResult();

    return content;
}

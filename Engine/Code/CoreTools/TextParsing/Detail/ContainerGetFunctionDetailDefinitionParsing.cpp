///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:55)

#include "CoreTools/CoreToolsExport.h"

#include "ContainerGetFunctionDetailDefinitionParsing.h"
#include "DefaultContainerGetFunctionDetailDefinitionParsing.h"
#include "MapContainerGetFunctionDetailDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
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
    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_shared<MapContainerGetFunctionDetailDefinitionParsing>(csvHead, className);
        }
        break;
        default:
        {
            return std::make_shared<DefaultContainerGetFunctionDetailDefinitionParsing>(csvHead, className);
        }
        break;
    }
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

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
    content += TextParsing::g_NewlineCharacter;

    content += GenerateFind(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateFindIf(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_IterFindIf;
    content += lowerClassName;
    content += TextParsing::g_CBegin;
    content += lowerClassName;
    content += TextParsing::g_CEndFunction;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateIterIf(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_IfIter;
    content += lowerClassName;
    content += TextParsing::g_CEnd;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateThrowException(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ThrowException;
    content += lowerClassName;
    content += TextParsing::g_ConditionNotFind;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetFunction(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetContainer();

    content += GenerateFunctionBeginBrackets();
    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetFindResult(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateGetContainer() const
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
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Container;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += csvClassName;
    content += TextParsing::g_Container;
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Get;
    content += csvClassName;
    content += TextParsing::g_FunctionParameterConst;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateContainerInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ContainerResult;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateLoopInit(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ForLoop;
    content += lowerClassName;
    content += TextParsing::g_RightBracket;

    return content;
}

System::String CoreTools::ContainerGetFunctionDetailDefinitionParsing::GenerateReturnResult() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ReturnResult;

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
    content += TextParsing::g_NewlineCharacter;

    content += GenerateReturnResult();

    return content;
}

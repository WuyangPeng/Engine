///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:54)

#include "CoreTools/CoreToolsExport.h"

#include "ContainerGetFunctionDefinitionParsing.h"
#include "DefaultContainerGetFunctionDefinitionParsing.h"
#include "KeyContainerGetFunctionDefinitionParsing.h"
#include "MapContainerGetFunctionDefinitionParsing.h"
#include "UniqueContainerGetFunctionDefinitionParsing.h"
#include "VectorContainerGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ContainerGetFunctionDefinitionParsing::ContainerGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerGetFunctionDefinitionParsing)

CoreTools::ContainerGetFunctionDefinitionParsing::ContainerGetFunctionDefinitionParsingSharedPtr CoreTools::ContainerGetFunctionDefinitionParsing::Create(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
{
    switch (const auto csvFormatType = csvHead.GetCSVFormatType(); csvFormatType)
    {
        case CSVFormatType::Vector:
        {
            return std::make_shared<VectorContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_shared<MapContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        case CSVFormatType::Key:
        {
            return std::make_shared<KeyContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        case CSVFormatType::Unique:
        {
            return std::make_shared<UniqueContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        default:
        {
            return std::make_shared<DefaultContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
    }
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetFirstDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFirstFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetReturnFirst(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetFirstFunction() const
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
    content += TextParsing::gFunctionConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetReturnFirst(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += lowerClassName;
    content += TextParsing::gAtZero;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetContainerDefinition(const String& lowerClassName, const StringView& containerName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetContainerFunction(containerName);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnContainer(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateReturnContainer(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += lowerClassName;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetContainerFunction(const StringView& containerName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gDoubleColon;
    content += containerName;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += containerClassName;
    content += TextParsing::gGetContainerConstEnd;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gLambdaFunctionInit;

    content += GenerateIndentation(2);
    content += TextParsing::gReturnKeyLess;

    content += GenerateIndentation(1);
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionFind(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::gLowerBound;
    content += lowerClassName;
    content += TextParsing::gStdMakeShared;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBaseKeyFunction;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionResult(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateLambdaFunctionResultJudge(lowerClassName);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateLambdaFunctionReturnIter();
    content += GenerateFunctionEndBrackets(1);

    content += GenerateElse(1);

    content += GenerateFunctionBeginBrackets(1);
    content += GenerateLambdaFunctionThrowException(lowerClassName);
    content += GenerateFunctionEndBrackets(1);

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionResultJudge(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gIfIter;
    content += lowerClassName;
    content += TextParsing::gKeyJudge;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionThrowException(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gThrowException;
    content += lowerClassName;
    content += TextParsing::gKeyNotFind;

    return content;
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:55)

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
    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Vector:
        {
            return std::make_shared<VectorContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_shared<MapContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        break;
        case CSVFormatType::Key:
        {
            return std::make_shared<KeyContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        break;
        case CSVFormatType::Unique:
        {
            return std::make_shared<UniqueContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        break;
        default:
        {
            return std::make_shared<DefaultContainerGetFunctionDefinitionParsing>(csvHead, className, keyTypeDescribe);
        }
        break;
    }
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetFirstDefinition(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFirstFunction();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetReturnFirst(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetFirstFunction() const
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
    content += TextParsing::g_FunctionConst;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetReturnFirst(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += lowerClassName;
    content += TextParsing::g_AtZero;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetContainerDefinition(const String& lowerClassName, const StringView& containerName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetContainerFunction(containerName);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateReturnContainer(lowerClassName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateReturnContainer(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += lowerClassName;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateGetContainerFunction(const StringView& containerName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = GetCSVClassName();

    auto content = nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_DoubleColon;
    content += containerName;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += containerClassName;
    content += TextParsing::g_GetContainerConstEnd;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionInit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_LambdaFunctionInit;

    content += GenerateIndentation(2);
    content += TextParsing::g_ReturnKeyLess;

    content += GenerateIndentation(1);
    content += TextParsing::g_ClassEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionFind(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_LowerBound;
    content += lowerClassName;
    content += TextParsing::g_Begin;
    content += lowerClassName;
    content += TextParsing::g_EndMakeShared;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_BaseKeyFunction;
    content += TextParsing::g_NewlineCharacter;

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

    content += TextParsing::g_IfIter;
    content += lowerClassName;
    content += TextParsing::g_KeyJudge;

    return content;
}

System::String CoreTools::ContainerGetFunctionDefinitionParsing::GenerateLambdaFunctionThrowException(const String& lowerClassName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ThrowException;
    content += lowerClassName;
    content += TextParsing::g_KeyNotFind;

    return content;
}

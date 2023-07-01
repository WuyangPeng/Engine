///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:10)

#include "CoreTools/CoreToolsExport.h"

#include "BaseGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::BaseGetFunctionDefinitionParsing::BaseGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BaseGetFunctionDefinitionParsing)

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKeyDefinition();

    const auto size = GetCSVHeadCount();
    for (auto index = 0; index < size; ++index)
    {
        content += GenerateBaseGetFunctionDefinition(index);
    }

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateGetKeyDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKeyConst();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;
    content += GenerateReturnKey(1);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateGetKeyConst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GetKeyTypeDescribe();
    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGetKeyConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto actualType = csvHead.GetAbbreviationByNameSpace(index, GetCSVClassName());

    auto content = GenerateVariableFunction(index, actualType);
    content += TextParsing::gNewlineCharacter;

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    const auto dataType = csvHead.GetDataType(index);
    content += GenerateBaseGetFunctionReturnDefinition(dataType, actualType);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    content += GenerateBaseGetFunctionArrayDefinition(index);
    content += GenerateBaseGetFunctionMappingDefinition(index);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateVariableFunction(int index, const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto functionVariableName = csvHead.GetFunctionVariableName(index);

    auto content = actualType;

    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += functionVariableName;
    content += TextParsing::gFunctionConst;

    if (const auto dataType = csvHead.GetDataType(index); CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
    }

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetReturnDefinition(const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::gThrowException;
    content += StringUtility::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += endDescribe;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetEnumReturnDefinition(const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += actualType;
    content += TextParsing::gInit;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType, const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    if (dataType == CSVDataType::String)
    {
        return GenerateBaseGetReturnDefinition(TextParsing::gBaseNotGetString);
    }
    else if (dataType == CSVDataType::Enum)
    {
        return GenerateBaseGetEnumReturnDefinition(actualType);
    }
    else if (CSVDataType::BoolArray <= dataType)
    {
        return GenerateBaseGetReturnDefinition(TextParsing::gBaseNotGetArray);
    }
    else
    {
        return GenerateBaseGetFunctionReturnDefinition(dataType);
    }
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += CSVTypeConversion::GetBaseReturnDescribe(dataType);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayBody(bool unused) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    if (unused)
    {
        content += GenerateIndentation(1);
        content += SYSTEM_TEXT("System::UnusedFunction(index);\n");
        content += TextParsing::gNewlineCharacter;
    }

    content += GenerateBaseGetReturnDefinition(TextParsing::gBaseNotGetArray);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayCountDefinition(const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayCount(functionVariableName);

    content += GenerateBaseGetFunctionArrayBody(false);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayIndex(const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = valueType;
    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += functionVariableName;
    content += TextParsing::gIndexParameterConst;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayDefinition(const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateBaseGetFunctionArrayIndex(valueType, functionVariableName);

    content += GenerateBaseGetFunctionArrayBody(true);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayBeginDefinition(const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::gBeginFunctionConst);

    content += GenerateBaseGetFunctionArrayBody(false);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayEndDefinition(const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::gEndFunctionConst);

    content += GenerateBaseGetFunctionArrayBody(false);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    if (const auto dataType = csvHead.GetDataType(index); CSVDataType::BoolArray <= dataType)
    {
        const auto actualType = csvHead.GetActualTypeByNameSpace(index);
        const auto functionVariableName = csvHead.GetFunctionVariableName(index);
        const auto abbreviation = csvHead.GetAbbreviationByNameSpace(index, GetCSVClassName());

        auto content = GenerateBaseGetFunctionArrayCountDefinition(functionVariableName);
        content += GenerateBaseGetFunctionArrayDefinition(csvHead.GetValueType(index), functionVariableName);
        content += GenerateBaseGetFunctionArrayBeginDefinition(abbreviation, functionVariableName);
        content += GenerateBaseGetFunctionArrayEndDefinition(abbreviation, functionVariableName);

        return content;
    }

    return String{};
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionMappingBody() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::gNewlineCharacter;

    content += GenerateIndentation(1);
    content += SYSTEM_TEXT("System::UnusedFunction(csvContainer);\n");
    content += TextParsing::gNewlineCharacter;

    content += GenerateBaseGetReturnDefinition(TextParsing::gBaseNotGetMapping);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionMappingDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    if (const auto mapping = csvHead.GetMapping(index); !mapping.empty())
    {
        const auto upperVariableName = csvHead.GetUpperVariableName(index);

        auto content = GenerateBaseGetFunctionArrayMapping(upperVariableName, mapping, index);

        content += GenerateBaseGetFunctionMappingBody();

        return content;
    }

    return String{};
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayMapping(const String& upperVariableName, const String& mapping, int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateIndentation();

    const auto dataType = csvHead.GetDataType(index);

    if (CSVDataType::BoolArray <= dataType)
    {
        content += csvHead.GetNameSpace();
        content += TextParsing::gDoubleColon;
        content += GetCSVClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("Container");
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += GetCSVClassName();
        content += TextParsing::gDoubleColon;
        content += TextParsing::gGet;
        content += upperVariableName;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gContainerParameter;
        content += TextParsing::gNewlineCharacter;
    }
    else
    {
        content += csvHead.GetNameSpace();
        content += TextParsing::gDoubleColon;
        content += GetCSVClassName();
        content += TextParsing::gDoubleColon;
        content += SYSTEM_TEXT("Const");
        content += StringUtility::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("SharedPtr");
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += GetCSVClassName();
        content += TextParsing::gDoubleColon;
        content += TextParsing::gGet;
        content += upperVariableName;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gContainerParameter;
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

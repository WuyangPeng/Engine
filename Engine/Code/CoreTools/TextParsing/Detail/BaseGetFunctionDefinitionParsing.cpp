///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:52)

#include "CoreTools/CoreToolsExport.h"

#include "BaseGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
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
    content += TextParsing::g_NewlineCharacter;
    content += GenerateReturnKey(1);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateGetKeyConst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GetKeyTypeDescribe();
    content += TextParsing::g_Space;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_GetKeyConst;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto actualType = csvHead.GetActualTypeByNameSpace(index);

    auto content = GenerateVariableFunction(index, actualType);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    const auto dataType = csvHead.GetDataType(index);
    content += GenerateBaseGetFunctionReturnDefinition(dataType, actualType);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateBaseGetFunctionArrayDefinition(index);
    content += GenerateBaseGetFunctionMappingDefinition(index);

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateVariableFunction(int index, const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    auto content = actualType;

    content += TextParsing::g_Space;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += functionVariableName;
    content += TextParsing::g_FunctionConst;

    const auto dataType = csvHead.GetDataType(index);
    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += TextParsing::g_Noexcept;
    }

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetReturnDefinition(const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ThrowException;
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += endDescribe;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetEnumReturnDefinition(const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += actualType;
    content += TextParsing::g_Init;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType, const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    if (dataType == CSVDataType::String)
    {
        return GenerateBaseGetReturnDefinition(TextParsing::g_BaseNotGetString);
    }
    else if (dataType == CSVDataType::Enum)
    {
        return GenerateBaseGetEnumReturnDefinition(actualType);
    }
    else if (CSVDataType::BoolArray <= dataType)
    {
        return GenerateBaseGetReturnDefinition(TextParsing::g_BaseNotGetArray);
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

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayBody() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateBaseGetReturnDefinition(TextParsing::g_BaseNotGetArray);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayCountDefinition(const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayCount(functionVariableName);

    content += GenerateBaseGetFunctionArrayBody();

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayIndex(const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = valueType;
    content += TextParsing::g_Space;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += functionVariableName;
    content += TextParsing::g_MaybeUnusedIndexParameterConst;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayDefinition(const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateBaseGetFunctionArrayIndex(valueType, functionVariableName);

    content += GenerateBaseGetFunctionArrayBody();

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayBeginDefinition(const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::g_BeginFunctionConst);

    content += GenerateBaseGetFunctionArrayBody();

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayEndDefinition(const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::g_EndFunctionConst);

    content += GenerateBaseGetFunctionArrayBody();

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto dataType = csvHead.GetDataType(index);

    if (CSVDataType::BoolArray <= dataType)
    {
        const auto actualType = csvHead.GetActualTypeByNameSpace(index);
        const auto functionVariableName = csvHead.GetFunctionVariableName(index);

        auto content = GenerateBaseGetFunctionArrayCountDefinition(functionVariableName);
        content += GenerateBaseGetFunctionArrayDefinition(csvHead.GetValueType(index), functionVariableName);
        content += GenerateBaseGetFunctionArrayBeginDefinition(actualType, functionVariableName);
        content += GenerateBaseGetFunctionArrayEndDefinition(actualType, functionVariableName);

        return content;
    }

    return String{};
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionMappingBody() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst9(1);
    content += TextParsing::g_NewlineCharacter;

    content += GenerateBaseGetReturnDefinition(TextParsing::g_BaseNotGetMapping);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionMappingDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        auto upperVariableName = csvHead.GetUpperVariableName(index);

        auto content = GenerateBaseGetFunctionArrayMapping(upperVariableName, mapping);

        content += GenerateBaseGetFunctionMappingBody();

        return content;
    }

    return String{};
}

System::String CoreTools::BaseGetFunctionDefinitionParsing::GenerateBaseGetFunctionArrayMapping(const String& upperVariableName, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateIndentation();

    content += TextParsing::g_SharedPtrConst;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += StringConversion::ToFirstLetterUpper(mapping);
    content += TextParsing::g_RightAngleBracket;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Get;
    content += upperVariableName;
    content += TextParsing::g_MaybeUnusedConst;
    content += nameSpace;
    content += TextParsing::g_ContainerParameter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

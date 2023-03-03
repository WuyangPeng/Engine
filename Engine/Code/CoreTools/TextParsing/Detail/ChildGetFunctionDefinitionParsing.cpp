///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:53)

#include "CoreTools/CoreToolsExport.h"

#include "ChildGetFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ChildGetFunctionDefinitionParsing::ChildGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ csvHead, className, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ChildGetFunctionDefinitionParsing)

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKeyDefinition();

    const auto size = GetCSVHeadCount();
    for (auto index = 0; index < size; ++index)
    {
        content += GenerateGetFunctionDefinition(index);
    }

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetKeyConst() const
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

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetKeyDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKeyConst();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateReturnGetKey();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateReturnGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);
    content += TextParsing::g_Return;

    const auto csvHead = GetCSVHead();
    if (csvHead.GetCSVFormatType() == CSVFormatType::Key)
    {
        content += csvHead.GetKey();
    }
    else
    {
        content += csvHead.GetVariableName(0);
    }

    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateUserClassIsValidConst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    const auto scope = csvHead.HasScope();
    if (scope)
    {
        content += TextParsing::g_UserClassIsValidConst1;
    }
    else
    {
        content += TextParsing::g_UserClassIsValidConst9;
    }

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateVariableFunction(int index, const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    String content = actualType;
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

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetVariableName(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += variableName;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateVariableFunction(index, csvHead.GetActualTypeByNameSpace(index));
    content += TextParsing::g_NewlineCharacter;

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetVariableName(csvHead.GetVariableName(index));

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetFunctionArrayDefinition(index);
    content += GenerateGetFunctionMappingDefinition(index);

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto dataType = csvHead.GetDataType(index);
    if (CSVDataType::BoolArray <= dataType)
    {
        const auto nameSpace = csvHead.GetNameSpace();

        const auto actualType = csvHead.GetActualTypeByNameSpace(index);
        const auto functionVariableName = csvHead.GetFunctionVariableName(index);
        const auto variableName = csvHead.GetVariableName(index);

        auto content = GenerateGetFunctionArrayCountDefinition(functionVariableName, variableName);

        content += GenerateGetFunctionArrayDefinition(csvHead.GetValueType(index), functionVariableName, variableName);
        content += GenerateGetFunctionArrayBeginDefinition(actualType, functionVariableName, variableName);
        content += GenerateGetFunctionArrayEndDefinition(actualType, functionVariableName, variableName);

        return content;
    }

    return String{};
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayCountDefinition(const String& functionVariableName, const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetFunctionArrayCount(functionVariableName);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetFunctionArraySize(variableName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArraySize(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ReturnNumericCast;
    content += variableName;
    content += TextParsing::g_ArraySize;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayIndex(const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = valueType;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += functionVariableName;
    content += TextParsing::g_IndexParameterConst;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayDefinition(const String& valueType, const String& functionVariableName, const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateGetFunctionArrayIndex(valueType, functionVariableName);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateReturnVariableName(variableName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateReturnVariableName(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += variableName;
    content += TextParsing::g_AtIndex;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayBeginDefinition(const String& actualType, const String& functionVariableName, const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::g_BeginFunctionConstNoexcept);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateReturnIter(variableName, TextParsing::g_FindCBegin);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateReturnIter(const String& variableName, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += variableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayEndDefinition(const String& actualType, const String& functionVariableName, const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::g_EndFunctionConstNoexcept);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateReturnIter(variableName, TextParsing::g_FindCEnd);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionMappingDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        auto variableName = csvHead.GetVariableName(index);
        auto upperVariableName = StringUtility::ToFirstLetterUpper(variableName);

        auto content = GenerateGetFunctionArrayMapping(upperVariableName, mapping);

        content += GenerateGetFunctionMappingBody(variableName, mapping);

        return content;
    }

    return String{};
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayMapping(const String& upperVariableName, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateIndentation();

    content += TextParsing::g_SharedPtrConst;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += StringUtility::ToFirstLetterUpper(mapping);
    content += TextParsing::g_RightAngleBracket;
    content += TextParsing::g_Space;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_Get;
    content += upperVariableName;
    content += TextParsing::g_LeftBrackets;
    content += TextParsing::g_Const;
    content += nameSpace;
    content += TextParsing::g_ContainerParameter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionMappingBody(const String& variableName, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto upperMapping = StringUtility::ToFirstLetterUpper(mapping);

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::g_NewlineCharacter;

    content += GenerateGetContainerMapping(variableName, upperMapping);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetContainerMapping(const String& variableName, const String& upperMapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::g_ReturnCsvContainerGet;
    content += upperMapping;
    content += TextParsing::g_ContainerGet;
    content += upperMapping;
    content += TextParsing::g_LeftBrackets;
    content += variableName;
    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

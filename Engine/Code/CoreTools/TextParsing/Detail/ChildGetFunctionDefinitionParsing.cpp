///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:06)

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
    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGetKeyConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetKeyDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKeyConst();

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnGetKey();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateReturnGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;

    if (const auto csvHead = GetCSVHead(); csvHead.GetCSVFormatType() == CSVFormatType::Key)
    {
        content += csvHead.GetKey();
    }
    else
    {
        content += csvHead.GetVariableName(0);
    }

    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateUserClassIsValidConst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    if (const auto scope = csvHead.HasScope(); scope)
    {
        content += TextParsing::gUserClassIsValidConst1;
    }
    else
    {
        content += TextParsing::gUserClassIsValidConst9;
    }

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateVariableFunction(int index, const String& actualType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto functionVariableName = csvHead.GetFunctionVariableName(index);

    String content = actualType;
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

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetVariableName(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += variableName;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateVariableFunction(index, csvHead.GetActualTypeByNameSpace(index));
    content += TextParsing::gNewlineCharacter;

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetVariableName(csvHead.GetVariableName(index));

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetFunctionArrayDefinition(index);
    content += GenerateGetFunctionMappingDefinition(index);

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    if (const auto dataType = csvHead.GetDataType(index); CSVDataType::BoolArray <= dataType)
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
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetFunctionArraySize(variableName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArraySize(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturnNumericCast;
    content += variableName;
    content += TextParsing::gArraySize;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayIndex(const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = valueType;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += functionVariableName;
    content += TextParsing::gIndexParameterConst;

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
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnVariableName(variableName);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateReturnVariableName(const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += variableName;
    content += TextParsing::gAtIndex;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayBeginDefinition(const String& actualType, const String& functionVariableName, const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::gBeginFunctionConstNoexcept);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnIter(variableName, TextParsing::gFindCBegin);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateReturnIter(const String& variableName, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += variableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionArrayEndDefinition(const String& actualType, const String& functionVariableName, const String& variableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto nameSpace = csvHead.GetNameSpace();

    auto content = GenerateGetFunctionArrayConstIterator(actualType, functionVariableName, TextParsing::gEndFunctionConstNoexcept);

    content += GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::gNewlineCharacter;

    content += GenerateReturnIter(variableName, TextParsing::gFindCEnd);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionMappingDefinition(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    if (const auto mapping = csvHead.GetMapping(index); !mapping.empty())
    {
        const auto variableName = csvHead.GetVariableName(index);
        const auto upperVariableName = StringUtility::ToFirstLetterUpper(variableName);

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

    content += TextParsing::gSharedPtrConst;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(mapping);
    content += TextParsing::gMappingType;
    content += TextParsing::gRightAngleBracket;
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

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetFunctionMappingBody(const String& variableName, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto upperMapping = StringUtility::ToFirstLetterUpper(mapping);

    auto content = GenerateFunctionBeginBrackets();

    content += GenerateUserClassIsValidConst();
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetContainerMapping(variableName, upperMapping);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionDefinitionParsing::GenerateGetContainerMapping(const String& variableName, const String& upperMapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(1);

    content += TextParsing::gReturnCsvContainerGet;
    content += upperMapping;
    content += TextParsing::gContainerGet;
    content += upperMapping;
    content += TextParsing::gLeftBrackets;
    content += variableName;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    return content;
}

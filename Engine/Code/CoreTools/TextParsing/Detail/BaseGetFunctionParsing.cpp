///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:10)

#include "CoreTools/CoreToolsExport.h"

#include "BaseGetFunctionParsing.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::BaseGetFunctionParsing::BaseGetFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BaseGetFunctionParsing)

System::String CoreTools::BaseGetFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKey();

    const auto count = GetCSVHeadCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateBaseGetFunction(index);
    }

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateFunctionVariableNameBegin(const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscardVirtual;
    content += actualType;
    content += TextParsing::gSpace;
    content += functionVariableName;
    content += TextParsing::gFunctionConst;

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateFunctionVariableName(CSVDataType dataType, const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionVariableNameBegin(actualType, functionVariableName);

    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
    }

    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateArray(const String& actualType, const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCountFunction(functionVariableName, TextParsing::gNodiscardVirtual, TextParsing::gCountFunction);

    content += GenerateGetValueFunction(valueType, functionVariableName, TextParsing::gNodiscardVirtual, TextParsing::gIndexParameter);
    content += GenerateBeginIterFunction(actualType, functionVariableName, TextParsing::gNodiscardVirtual, TextParsing::gBeginFunction);
    content += GenerateEndIterFunction(actualType, functionVariableName, TextParsing::gNodiscardVirtual, TextParsing::gEndFunction);

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateMapping(int index, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto upperVariableName = csvHead.GetUpperVariableName(index);

    auto content = GenerateIndentation();

    const auto dataType = csvHead.GetDataType(index);

    if (CSVDataType::BoolArray <= dataType)
    {
        content += TextParsing::gNodiscardVirtual;
        content += StringUtility::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("Container");
        content += TextParsing::gSpace;
        content += TextParsing::gGet;
        content += upperVariableName;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += csvHead.GetNameSpace();
        content += TextParsing::gContainerParameter;
        content += TextParsing::gSemicolonNewline;
    }
    else
    {
        content += TextParsing::gNodiscardVirtual;
        content += SYSTEM_TEXT("Const");
        content += StringUtility::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("SharedPtr");
        content += TextParsing::gSpace;
        content += TextParsing::gGet;
        content += upperVariableName;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += csvHead.GetNameSpace();
        content += TextParsing::gContainerParameter;
        content += TextParsing::gSemicolonNewline;
    }

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateBaseGetFunction(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto functionVariableName = csvHead.GetFunctionVariableName(index);
    const auto dataType = csvHead.GetDataType(index);
    const auto actualType = csvHead.GetActualType(index);
    const auto valueType = csvHead.GetValueType(index);
    const auto abbreviation = csvHead.GetAbbreviation(index);

    auto content = GenerateFunctionVariableName(dataType, abbreviation, functionVariableName);

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GenerateArray(abbreviation, valueType, functionVariableName);
    }

    if (const auto mapping = csvHead.GetMapping(index); !mapping.empty())
    {
        content += GenerateMapping(index, mapping);
    }

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscardVirtual;
    content += GetKeyTypeDescribe();
    content += TextParsing::gSpace;
    content += TextParsing::gGetKeyConst;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gNewlineCharacter;

    return content;
}

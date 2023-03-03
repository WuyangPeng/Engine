///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:53)

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

    content += TextParsing::g_NodiscardVirtual;
    content += actualType;
    content += TextParsing::g_Space;
    content += functionVariableName;
    content += TextParsing::g_FunctionConst;

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateFunctionVariableName(CSVDataType dataType, const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateFunctionVariableNameBegin(actualType, functionVariableName);

    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += TextParsing::g_Noexcept;
    }

    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateArray(const String& actualType, const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCountFunction(functionVariableName, TextParsing::g_NodiscardVirtual, TextParsing::g_CountFunction);

    content += GenerateGetValueFunction(valueType, functionVariableName, TextParsing::g_NodiscardVirtual, TextParsing::g_MaybeUnusedIndexParameter);
    content += GenerateBeginIterFunction(actualType, functionVariableName, TextParsing::g_NodiscardVirtual, TextParsing::g_BeginFunction);
    content += GenerateEndIterFunction(actualType, functionVariableName, TextParsing::g_NodiscardVirtual, TextParsing::g_EndFunction);

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateMapping(int index, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    const auto upperVariableName = csvHead.GetUpperVariableName(index);

    auto content = GenerateIndentation();
    content += TextParsing::g_NodiscardVirtual;
    content += TextParsing::g_SharedPtrConst;
    content += StringUtility::ToFirstLetterUpper(mapping);
    content += TextParsing::g_RightAngleBracket;
    content += TextParsing::g_Space;
    content += TextParsing::g_Get;
    content += upperVariableName;
    content += TextParsing::g_MaybeUnusedConst;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_ContainerParameter;
    content += TextParsing::g_SemicolonNewline;

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

    auto content = GenerateFunctionVariableName(dataType, actualType, functionVariableName);

    if (CSVDataType::BoolArray <= dataType)
    {
        content += GenerateArray(actualType, valueType, functionVariableName);
    }

    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        content += GenerateMapping(index, mapping);
    }

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::BaseGetFunctionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_NodiscardVirtual;
    content += GetKeyTypeDescribe();
    content += TextParsing::g_Space;
    content += TextParsing::g_GetKeyConst;
    content += TextParsing::g_SemicolonNewline;

    content += TextParsing::g_NewlineCharacter;

    return content;
}

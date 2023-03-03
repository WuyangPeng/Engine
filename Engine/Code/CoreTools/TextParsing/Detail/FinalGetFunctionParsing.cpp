///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "FinalGetFunctionParsing.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::FinalGetFunctionParsing::FinalGetFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FinalGetFunctionParsing)

System::String CoreTools::FinalGetFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKey();

    const auto csvHead = GetCSVHead();
    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateGetFunction(index);
    }

    if (csvHead.GetCSVFormatType() == CSVFormatType::Key)
    {
        content += GenerateGetKeyFunction();
    }

    if (csvHead.HasScope())
    {
        content += GenerateChecking();
    }

    return content;
}

System::String CoreTools::FinalGetFunctionParsing::GenerateGetFunction(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto actualType = csvHead.GetActualType(index);
    const auto functionVariableName = csvHead.GetFunctionVariableName(index);
    const auto dataType = csvHead.GetDataType(index);
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

System::String CoreTools::FinalGetFunctionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Nodiscard;
    content += GetKeyTypeDescribe();
    content += TextParsing::g_Space;
    content += TextParsing::g_GetKeyConst;
    content += TextParsing::g_SemicolonNewline;

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::FinalGetFunctionParsing::GenerateChecking() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(-1);
    content += TextParsing::g_Private;

    content += GenerateIndentation();
    content += TextParsing::g_Void;
    content += TextParsing::g_Checking;
    content += TextParsing::g_SemicolonNewline;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::FinalGetFunctionParsing::GenerateFunctionVariableName(CSVDataType dataType, const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Nodiscard;
    content += actualType;
    content += TextParsing::g_Space;
    content += functionVariableName;
    content += TextParsing::g_FunctionConst;

    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += TextParsing::g_Noexcept;
    }

    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::FinalGetFunctionParsing::GenerateArray(const String& actualType, const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCountFunction(functionVariableName, TextParsing::g_Nodiscard, TextParsing::g_CountFunction);

    content += GenerateGetValueFunction(valueType, functionVariableName, TextParsing::g_Nodiscard, TextParsing::g_IndexParameter);
    content += GenerateBeginIterFunction(actualType, functionVariableName, TextParsing::g_Nodiscard, TextParsing::g_BeginNoexceptFunction);
    content += GenerateEndIterFunction(actualType, functionVariableName, TextParsing::g_Nodiscard, TextParsing::g_EndNoexceptFunction);

    return content;
}

System::String CoreTools::FinalGetFunctionParsing::GenerateMapping(int index, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    auto upperVariableName = csvHead.GetUpperVariableName(index);

    auto content = GenerateIndentation();

    content += TextParsing::g_Nodiscard;
    content += TextParsing::g_SharedPtrConst;
    content += StringUtility::ToFirstLetterUpper(mapping);
    content += TextParsing::g_RightAngleBracket;
    content += TextParsing::g_Space;
    content += TextParsing::g_Get;
    content += upperVariableName;

    content += TextParsing::g_LeftBrackets;
    content += TextParsing::g_Const;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_ContainerParameter;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

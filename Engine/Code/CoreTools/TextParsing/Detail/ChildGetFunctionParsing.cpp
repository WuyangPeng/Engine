///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:06)

#include "CoreTools/CoreToolsExport.h"

#include "ChildGetFunctionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ChildGetFunctionParsing::ChildGetFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ChildGetFunctionParsing)

System::String CoreTools::ChildGetFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateGetKey();

    const auto csvHead = GetCSVHead();
    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateChildGetFunction(index);
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

System::String CoreTools::ChildGetFunctionParsing::GenerateChildGetFunction(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto actualType = csvHead.GetActualType(index);
    const auto functionVariableName = csvHead.GetFunctionVariableName(index);
    const auto dataType = csvHead.GetDataType(index);
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

System::String CoreTools::ChildGetFunctionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscard;
    content += GetKeyTypeDescribe();
    content += TextParsing::gGetKeyConstOverride;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionParsing::GenerateChecking() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(-1);
    content += TextParsing::gPrivate;

    content += GenerateIndentation();
    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += TextParsing::gCheckingConst;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ChildGetFunctionParsing::GenerateFunctionVariableName(CSVDataType dataType, const String& actualType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscard;
    content += actualType;
    content += TextParsing::gSpace;
    content += functionVariableName;
    content += TextParsing::gFunctionConst;

    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
    }

    content += TextParsing::gOverride;

    return content;
}

System::String CoreTools::ChildGetFunctionParsing::GenerateArray(const String& actualType, const String& valueType, const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCountFunction(functionVariableName, TextParsing::gNodiscard, TextParsing::gCountOverrideFunction);

    content += GenerateGetValueFunction(valueType, functionVariableName, TextParsing::gNodiscard, TextParsing::gIndexParameterOverride);
    content += GenerateBeginIterFunction(actualType, functionVariableName, TextParsing::gNodiscard, TextParsing::gBeginOverrideFunction);
    content += GenerateEndIterFunction(actualType, functionVariableName, TextParsing::gNodiscard, TextParsing::gEndOverrideFunction);

    return content;
}

System::String CoreTools::ChildGetFunctionParsing::GenerateMapping(int index, const String& mapping) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto upperVariableName = csvHead.GetUpperVariableName(index);

    auto content = GenerateIndentation();

    const auto dataType = csvHead.GetDataType(index);

    if (CSVDataType::BoolArray <= dataType)
    {
        content += TextParsing::gNodiscard;
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
        content += TextParsing::gOverride;
    }
    else
    {
        content += TextParsing::gNodiscard;
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
        content += TextParsing::gOverride;
    }

    return content;
}

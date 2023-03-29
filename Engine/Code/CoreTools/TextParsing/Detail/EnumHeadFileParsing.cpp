///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:47)

#include "CoreTools/CoreToolsExport.h"

#include "EnumHeadFileParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::EnumHeadFileParsing::EnumHeadFileParsing(CSVHead csvHead, CSVContent csvContent, String className) noexcept
    : ParentType{ 0 }, csvHead{ std::move(csvHead) }, csvContent{ std::move(csvContent) }, className{ std::move(className) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnumHeadFileParsing)

System::String CoreTools::EnumHeadFileParsing::GenerateIoStreamHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (HasIoStreamOperator())
    {
        content += TextParsing::gIoStreamInclude;
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto idIndex = csvHead.GetDataIndex(TextParsing::gEnumIdDescribe);
    const auto nameIndex = csvHead.GetDataIndex(TextParsing::gEnumNameDescribe);
    const auto describeIndex = csvHead.GetDataIndex(TextParsing::gEnumDescribe);

    String content{};

    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        content += GetEnumVariableContent(column, idIndex, nameIndex, describeIndex);
    }

    content += GenerateClassEndBrackets(1);
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GetEnumVariableContent(const String& column, int idIndex, int nameIndex, int describeIndex) const
{
    const auto result = Parsing::GetSplitComma(column);

    const auto& id = result.at(idIndex);

    auto name = result.at(nameIndex);
    trim_if(name, boost::is_any_of(TextParsing::gQuotationMarks));

    auto describe = StringConversion::Utf8ConversionStandard(result.at(describeIndex));
    trim_if(describe, boost::is_any_of(TextParsing::gQuotationMarks));

    return GetEnumVariableContent(name, id, describe);
}

System::String CoreTools::EnumHeadFileParsing::GetEnumVariableContent(const String& name, const String& id, const String& describe) const
{
    auto content = GenerateIndentation(2);

    content += name;
    content += TextParsing::gSpace;
    content += TextParsing::gEqualSign;
    content += TextParsing::gSpace;
    content += id;
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += TextParsing::gSpace;
    content += TextParsing::gDoubleForwardSlash;
    content += TextParsing::gSpace;
    content += describe;
    content += TextParsing::gNewlineCharacter;

    return content;
}

bool CoreTools::EnumHeadFileParsing::HasIoStreamOperator() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (csvHead.HasDataField(TextParsing::gIoStream))
    {
        const auto column = csvContent.GetContent(0);
        const auto index = csvHead.GetDataIndex(TextParsing::gIoStream);

        return HasIoStreamOperator(index, column);
    }

    return false;
}

bool CoreTools::EnumHeadFileParsing::HasIoStreamOperator(int index, const String& column) const
{
    const auto result = Parsing::GetSplitComma(column);

    return IsOperatorTrue(result, index);
}

bool CoreTools::EnumHeadFileParsing::IsOperatorTrue(const SplitType& result, int index) const
{
    return index < 0 || boost::numeric_cast<int>(result.size()) <= index || result.at(index) != TextParsing::gFalse;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumOperator(const String& field, const SplitType& element, const String& operatorDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (csvHead.HasDataField(field))
    {
        if (const auto index = csvHead.GetDataIndex(field); IsOperatorTrue(element, index))
        {
            content += GenerateOperatorDescribe(operatorDescribe);
        }
    }

    return content;
}

CoreTools::Parsing::String CoreTools::EnumHeadFileParsing::GenerateOperatorDescribe(const String& operatorDescribe) const
{
    auto content = GenerateIndentation(1);

    content += operatorDescribe;
    content += TextParsing::gLeftBrackets;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumIoStreamOperator(const SplitType& element) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (csvHead.HasDataField(TextParsing::gIoStream))
    {
        if (const auto index = csvHead.GetDataIndex(TextParsing::gIoStream); IsOperatorTrue(element, index))
        {
            content += GenerateOperatorDescribe(SYSTEM_TEXT("ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE"s));
            content += GenerateOperatorDescribe(SYSTEM_TEXT("ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE"s));
            content += GenerateOperatorDescribe(SYSTEM_TEXT("ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE"s));
            content += GenerateOperatorDescribe(SYSTEM_TEXT("ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE"s));
        }
    }

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumOperator() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = csvContent.GetContent(0);

    const auto element = Parsing::GetSplitComma(column);

    auto content = GenerateFunctionEndBrackets();
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateStringCast();

    content += GenerateEnumCastString();
    content += GenerateGetEnumDescribe();

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateStringCast() const
{
    auto content = GenerateIndentation(1);

    content += TextParsing::gNodiscard;
    content += className;
    content += TextParsing::gSpace;
    content += TextParsing::gStringCast;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gDescribe;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumCastString() const
{
    auto content = GenerateIndentation(1);

    content += TextParsing::gNodiscard;
    content += TextParsing::gSystemString;
    content += TextParsing::gSpace;
    content += TextParsing::gEnumCastString;
    content += className;
    content += TextParsing::gTypeEnd;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateGetEnumDescribe() const
{
    auto content = GenerateIndentation(1);

    content += TextParsing::gNodiscard;
    content += TextParsing::gSystemString;
    content += TextParsing::gSpace;
    content += TextParsing::gGetEnumDescribe;
    content += className;
    content += TextParsing::gTypeEnd;
    content += TextParsing::gSemicolonNewline;

    return content;
}

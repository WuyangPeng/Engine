///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:23)

#include "CoreTools/CoreToolsExport.h"

#include "EnumHeadFileParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using std::vector;
using namespace std::literals;

CoreTools::EnumHeadFileParsing::EnumHeadFileParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className)
    : ParentType{ 0 }, csvHead{ csvHead }, csvContent{ csvContent }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnumHeadFileParsing)

System::String CoreTools::EnumHeadFileParsing::GenerateIOStreamHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (HasIOStreamOperator())
    {
        content += TextParsing::g_IOStreamInclude;
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto idIndex = csvHead.GetDataIndex(TextParsing::g_EnumIDDescribe);
    const auto nameIndex = csvHead.GetDataIndex(TextParsing::g_EnumNameDescribe);
    const auto describeIndex = csvHead.GetDataIndex(TextParsing::g_EnumDescribe);

    String content{};

    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        content += GetEnumVariableContent(column, idIndex, nameIndex, describeIndex);
    }

    content += GenerateClassEndBrackets(1);
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GetEnumVariableContent(const String& column, int idIndex, int nameIndex, int describeIndex) const
{
    const auto result = Parsing::GetSplitComma(column);

    auto id = result.at(idIndex);

    auto name = result.at(nameIndex);
    boost::algorithm::trim_if(name, boost::is_any_of(TextParsing::g_QuotationMarks));

    auto describe = StringConversion::UTF8ConversionStandard(result.at(describeIndex));
    boost::algorithm::trim_if(describe, boost::is_any_of(TextParsing::g_QuotationMarks));

    return GetEnumVariableContent(name, id, describe);
}

System::String CoreTools::EnumHeadFileParsing::GetEnumVariableContent(const String& name, const String& id, const String& describe) const
{
    auto content = GenerateIndentation(2);

    content += name;
    content += TextParsing::g_Space;
    content += TextParsing::g_equalSign;
    content += TextParsing::g_Space;
    content += id;
    content += TextParsing::g_Comma;
    content += TextParsing::g_Space;
    content += TextParsing::g_Space;
    content += TextParsing::g_DoubleForwardSlash;
    content += TextParsing::g_Space;
    content += describe;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

bool CoreTools::EnumHeadFileParsing::HasIOStreamOperator() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (csvHead.HasDataField(TextParsing::g_IOStream))
    {
        const auto column = csvContent.GetContent(0);
        const auto index = csvHead.GetDataIndex(TextParsing::g_IOStream);

        return HasIOStreamOperator(index, column);
    }

    return false;
}

bool CoreTools::EnumHeadFileParsing::HasIOStreamOperator(int index, const String& column) const
{
    const auto result = Parsing::GetSplitComma(column);

    return IsOperatorTrue(result, index);
}

bool CoreTools::EnumHeadFileParsing::IsOperatorTrue(const SplitType& result, int index) const
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return index < 0 || boost::numeric_cast<int>(result.size()) <= index || result[index] != TextParsing::g_False;

#include STSTEM_WARNING_POP
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumOperator(const String& field, const SplitType& element, const String& operatorDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (csvHead.HasDataField(field))
    {
        const auto index = csvHead.GetDataIndex(field);

        if (IsOperatorTrue(element, index))
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
    content += TextParsing::g_LeftBrackets;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumIOStreamOperator(const SplitType& element) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (csvHead.HasDataField(TextParsing::g_IOStream))
    {
        const auto index = csvHead.GetDataIndex(TextParsing::g_IOStream);

        if (IsOperatorTrue(element, index))
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

    auto content = GenerateEnumOperator(SYSTEM_TEXT("addable"s), element, SYSTEM_TEXT("ENUM_ADDABLE_OPERATOR_DEFINE"s));

    content += GenerateEnumOperator(SYSTEM_TEXT("subtractable"s), element, SYSTEM_TEXT("ENUM_SUBTRACTABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("multiplication"s), element, SYSTEM_TEXT("ENUM_MULTIPLICATION_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("negate"s), element, SYSTEM_TEXT("ENUM_NEGATE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("incrementable"s), element, SYSTEM_TEXT("ENUM_INCREMENTABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("decrementable"s), element, SYSTEM_TEXT("ENUM_DECREMENTABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("andable"s), element, SYSTEM_TEXT("ENUM_ANDABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("orable"s), element, SYSTEM_TEXT("ENUM_ORABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(SYSTEM_TEXT("xorable"s), element, SYSTEM_TEXT("ENUM_XORABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumIOStreamOperator(element);

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateStringCast();

    content += GenerateEnumCastString();
    content += GenerateGetEnumDescribe();

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateStringCast() const
{
    auto content = GenerateIndentation(1);

    content += TextParsing::g_Nodiscard;
    content += className;
    content += TextParsing::g_Space;
    content += TextParsing::g_StringCast;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Describe;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateEnumCastString() const
{
    auto content = GenerateIndentation(1);

    content += TextParsing::g_Nodiscard;
    content += TextParsing::g_SystemString;
    content += TextParsing::g_Space;
    content += TextParsing::g_EnumCastString;
    content += className;
    content += TextParsing::g_TypeEnd;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::EnumHeadFileParsing::GenerateGetEnumDescribe() const
{
    auto content = GenerateIndentation(1);

    content += TextParsing::g_Nodiscard;
    content += TextParsing::g_SystemString;
    content += TextParsing::g_Space;
    content += TextParsing::g_GetEnumDescribe;
    content += className;
    content += TextParsing::g_TypeEnd;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

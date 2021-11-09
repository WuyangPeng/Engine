///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/29 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateClassName.h"
#include "CSVGenerateEnumHeadFile.h"
#include "CSVGenerateGetFunctionDefinition.h"
#include "CSVGenerateHead.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"

using std::vector;
using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateEnumHeadFile::CSVGenerateEnumHeadFile(const CSVContent& csvContent)
    : ParentType{ csvContent.GetCSVHead() }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumHeadFile)

System::String CoreTools::CSVGenerateEnumHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetFilePrefix() const
{
    return String{ g_EnumFilePrefix };
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += g_HeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += g_NewlineCharacter;
    content += GenerateHeaderGuard();

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateEnumHead();
    content += g_NewlineCharacter;

    content += GenerateIOStreamHead();

    content += GenerateNameSpace();

    CSVGenerateClassName csvGenerateClassName{ GetCSVHead(), GetSuffix() };
    content += csvGenerateClassName.GenerateEnumClassName();

    content += GenerateEnumContent();
    content += GenerateEnumFunction();
    content += GenerateEnumOperator();

    CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateStringCastEnumDefinition();

    content += GenerateHeaderGuardEndif();

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GenerateIOStreamHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (HasIOStreamOperator())
    {
        content += SYSTEM_TEXT("#include <iostream>\n"s);
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GenerateEnumContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto head = GetCSVHead();

    const auto idIndex = head.GetDataIndex(g_EnumIDDescribe);
    const auto nameIndex = head.GetDataIndex(g_EnumNameDescribe);
    const auto describeIndex = head.GetDataIndex(g_EnumDescribe);

    String content{};

    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        const auto column = csvContent.GetContent(i);

        content += GetEnumVariableContent(column, idIndex, nameIndex, describeIndex);
    }

    content += g_ClassEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetEnumVariableContent(const String& column, int idIndex, int nameIndex, int describeIndex) const
{
    vector<String> result{};
    boost::algorithm::split(result, column, boost::is_any_of(g_Comma), boost::token_compress_off);

    auto id = result.at(idIndex);

    auto name = result.at(nameIndex);
    boost::algorithm::trim_if(name, boost::is_any_of(g_QuotationMarks));

    auto describe = StringConversion::UTF8ConversionStandard(result.at(describeIndex));
    boost::algorithm::trim_if(describe, boost::is_any_of(g_QuotationMarks));

    String content{};

    content += g_Indentation;
    content += g_Indentation;

    content += name + SYSTEM_TEXT(" = "s) + id + SYSTEM_TEXT(",  // "s) + describe + g_NewlineCharacter;

    return content;
}

bool CoreTools::CSVGenerateEnumHeadFile::HasIOStreamOperator() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto head = GetCSVHead();

    if (head.HasDataField(g_IOStream))
    {
        const auto column = csvContent.GetContent(0);
        const auto index = head.GetDataIndex(g_IOStream);

        return HasIOStreamOperator(index, column);
    }

    return false;
}

bool CoreTools::CSVGenerateEnumHeadFile::HasIOStreamOperator(int index, const String& column) const
{
    vector<String> result{};
    boost::algorithm::split(result, column, boost::is_any_of(g_Comma), boost::token_compress_off);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (index < 0 || boost::numeric_cast<int>(result.size()) <= index || result[index] != g_False)
    {
        return true;
    }

#include STSTEM_WARNING_POP

    return false;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GenerateEnumOperator(CSVHead head, const String& field, const vector<String>& element, const String& operatorDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (head.HasDataField(field))
    {
        const auto index = head.GetDataIndex(field);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (index < 0 || boost::numeric_cast<int>(element.size()) <= index || element[index] != g_False)
        {
            content += g_Indentation;
            content += operatorDescribe + SYSTEM_TEXT("("s) + head.GetCSVClassName() + SYSTEM_TEXT(");\n"s);
        }

#include STSTEM_WARNING_POP
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GenerateEnumIOStreamOperator(CSVHead head, const std::vector<String>& element) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (head.HasDataField(g_IOStream))
    {
        const auto index = head.GetDataIndex(g_IOStream);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (index < 0 || boost::numeric_cast<int>(element.size()) <= index || element[index] != g_False)
        {
            content += g_Indentation;
            content += SYSTEM_TEXT("ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE("s) + head.GetCSVClassName() + SYSTEM_TEXT(");\n"s);

            content += g_Indentation;
            content += SYSTEM_TEXT("ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE("s) + head.GetCSVClassName() + SYSTEM_TEXT(");\n"s);

            content += g_Indentation;
            content += SYSTEM_TEXT("ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE("s) + head.GetCSVClassName() + SYSTEM_TEXT(");\n"s);

            content += g_Indentation;
            content += SYSTEM_TEXT("ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE("s) + head.GetCSVClassName() + SYSTEM_TEXT(");\n"s);
        }

#include STSTEM_WARNING_POP
    }

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GenerateEnumOperator() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto head = GetCSVHead();

    const auto column = csvContent.GetContent(0);

    vector<String> element{};
    boost::algorithm::split(element, column, boost::is_any_of(g_Comma), boost::token_compress_off);

    String content{};

    content += GenerateEnumOperator(head, SYSTEM_TEXT("addable"s), element, SYSTEM_TEXT("ENUM_ADDABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("subtractable"s), element, SYSTEM_TEXT("ENUM_SUBTRACTABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("multiplication"s), element, SYSTEM_TEXT("ENUM_MULTIPLICATION_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("negate"s), element, SYSTEM_TEXT("ENUM_NEGATE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("incrementable"s), element, SYSTEM_TEXT("ENUM_INCREMENTABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("decrementable"s), element, SYSTEM_TEXT("ENUM_DECREMENTABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("andable"s), element, SYSTEM_TEXT("ENUM_ANDABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("orable"s), element, SYSTEM_TEXT("ENUM_ORABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumOperator(head, SYSTEM_TEXT("xorable"s), element, SYSTEM_TEXT("ENUM_XORABLE_OPERATOR_DEFINE"s));
    content += GenerateEnumIOStreamOperator(head, element);

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GenerateEnumFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto head = GetCSVHead();

    const auto className = head.GetCSVClassName() + GetSuffix();

    String content{ g_Indentation };

    content += SYSTEM_TEXT("NODISCARD "s);
    content += className + SYSTEM_TEXT(" StringCast");
    content += head.GetCSVClassName();
    content += SYSTEM_TEXT("(const System::String& describe);\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD System::String EnumCastString("s);
    content += className;
    content += SYSTEM_TEXT(" type);\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD System::String GetEnumDescribe("s);
    content += className;
    content += SYSTEM_TEXT(" type);\n"s);

    content += g_NewlineCharacter;

    return content;
}
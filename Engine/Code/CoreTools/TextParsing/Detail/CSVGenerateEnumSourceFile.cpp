///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/01 11:58)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumSourceFile.h"
#include "CSVGenerateHead.h"
#include "CSVGenerateHelper.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"

using std::vector;
using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateEnumSourceFile::CSVGenerateEnumSourceFile(const CSVContent& csvContent)
    : ParentType{ csvContent.GetCSVHead() }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumSourceFile)

System::String CoreTools::CSVGenerateEnumSourceFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFilePrefix() const
{
    return String{ g_EnumFilePrefix };
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += g_SourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += g_NewlineCharacter;

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateEnumSourceHead();

    content += GenerateEnumFunctionDefinition();

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GenerateEnumFunctionDefinition() const
{
    const auto head = GetCSVHead();

    const auto nameIndex = head.GetDataIndex(g_EnumNameDescribe);
    const auto describeIndex = head.GetDataIndex(g_EnumDescribe);

    auto content = GetStringCastEnum(nameIndex);
    content += GetEnumCastString(nameIndex);
    content += GetEnumDescribe(nameIndex, describeIndex);

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetStringCastEnum(int nameIndex) const
{
    const auto head = GetCSVHead();

    const auto className = head.GetCSVClassName();
    const auto nameSpace = head.GetNameSpace();

    auto content = head.GetCompleteClassName() + g_Space;
    content += nameSpace + SYSTEM_TEXT("::StringCast"s) + className + SYSTEM_TEXT("(const System::String& describe)\n"s);

    content += g_FunctionBeginBrackets;

    auto typeDescribe = g_Indentation.data() + SYSTEM_TEXT("static map<System::String, "s) + className + SYSTEM_TEXT("> typeDescribe{ "s);
    String space(typeDescribe.size(), g_Space);
    content += typeDescribe;

    const auto size = csvContent.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        const auto column = csvContent.GetContent(index);

        const auto csvPoistionType = GetPoistionType(index, size);

        content += GetStringCastEnumColumn(column, nameIndex, space, csvPoistionType);
    }

    content += g_NewlineCharacter;

    content += GetFindFunctionDefinition(SYSTEM_TEXT("describe"s));

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFindFunctionDefinition(const String& variable) const
{
    String content{};

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto iter = typeDescribe.find(") + variable + SYSTEM_TEXT(");\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (iter != typeDescribe.cend())\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return iter->second;\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\"未找到对应的类型。\"s));\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetStringCastEnumColumn(const String& column, int nameIndex, const String& space, CSVPoistionType csvPoistionType) const
{
    vector<String> result{};
    boost::algorithm::split(result, column, boost::is_any_of(g_Comma), boost::token_compress_off);

    auto name = result.at(nameIndex);
    boost::algorithm::trim_if(name, boost::is_any_of(g_QuotationMarks));

    return GetColumn(GetStringCastEnumColumn(name), space, csvPoistionType);
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetStringCastEnumColumn(const String& name) const
{
    const auto head = GetCSVHead();
    const auto className = head.GetCSVClassName();

    auto content = SYSTEM_TEXT("{ SYSTEM_TEXT(\""s);

    content += name;
    content += SYSTEM_TEXT("\"s), "s);
    content += className;
    content += g_DoubleColon;
    content += name;
    content += SYSTEM_TEXT(" }");

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetEnumCastString(int nameIndex) const
{
    const auto head = GetCSVHead();

    const auto className = head.GetCSVClassName();
    const auto nameSpace = head.GetNameSpace();

    auto content = SYSTEM_TEXT("System::String "s) + nameSpace + SYSTEM_TEXT("::EnumCastString(");
    content += className;
    content += SYSTEM_TEXT(" type)\n"s);

    content += g_FunctionBeginBrackets;

    auto typeDescribe = g_Indentation.data() + SYSTEM_TEXT("static map<"s) + className + SYSTEM_TEXT(", System::String> typeDescribe{ "s);
    String space(typeDescribe.size(), g_Space);
    content += typeDescribe;

    const auto size = csvContent.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        const auto column = csvContent.GetContent(index);

        const auto csvPoistionType = GetPoistionType(index, size);

        content += GetEnumCastStringColumn(column, nameIndex, space, csvPoistionType);
    }

    content += g_NewlineCharacter;

    content += GetFindFunctionDefinition(SYSTEM_TEXT("type"s));

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetEnumCastStringColumn(const String& column, int nameIndex, const String& space, CSVPoistionType csvPoistionType) const
{
    vector<String> result{};
    boost::algorithm::split(result, column, boost::is_any_of(g_Comma), boost::token_compress_off);

    auto name = result.at(nameIndex);
    boost::algorithm::trim_if(name, boost::is_any_of(g_QuotationMarks));

    return GetColumn(GetEnumCastStringColumn(name), space, csvPoistionType);
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetEnumCastStringColumn(const String& name) const
{
    const auto head = GetCSVHead();
    const auto className = head.GetCSVClassName();

    auto content = SYSTEM_TEXT("{ "s);

    content += className;
    content += g_DoubleColon;
    content += name;
    content += SYSTEM_TEXT(", SYSTEM_TEXT(\""s);
    content += name;
    content += SYSTEM_TEXT("\"s) }"s);

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetEnumDescribe(int nameIndex, int describeIndex) const
{
    const auto head = GetCSVHead();

    const auto className = head.GetCSVClassName();
    const auto nameSpace = head.GetNameSpace();

    auto content = SYSTEM_TEXT("System::String "s) + nameSpace + SYSTEM_TEXT("::GetEnumDescribe(") + className + SYSTEM_TEXT(" type)\n"s);

    content += g_FunctionBeginBrackets;

    auto typeDescribe = g_Indentation.data() + SYSTEM_TEXT("static map<"s) + className + SYSTEM_TEXT(", System::String> typeDescribe{ "s);
    String space(typeDescribe.size(), g_Space);
    content += typeDescribe;

    const auto size = csvContent.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        const auto column = csvContent.GetContent(index);

        const auto csvPoistionType = GetPoistionType(index, size);

        content += GetEnumDescribeColumn(column, nameIndex, describeIndex, space, csvPoistionType);
    }

    content += g_NewlineCharacter;

    content += GetFindFunctionDefinition(SYSTEM_TEXT("type"s));

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetEnumDescribeColumn(const String& column, int nameIndex, int describeIndex, const String& space, CSVPoistionType csvPoistionType) const
{
    vector<String> result{};
    boost::algorithm::split(result, column, boost::is_any_of(g_Comma), boost::token_compress_off);

    auto name = result.at(nameIndex);
    boost::algorithm::trim_if(name, boost::is_any_of(g_QuotationMarks));

    auto describe = StringConversion::UTF8ConversionStandard(result.at(describeIndex));
    boost::algorithm::trim_if(describe, boost::is_any_of(g_QuotationMarks));

    return GetColumn(GetEnumDescribeColumn(name, describe), space, csvPoistionType);
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetEnumDescribeColumn(const String& name, const String& describe) const
{
    const auto head = GetCSVHead();
    const auto className = head.GetCSVClassName();

    auto content = SYSTEM_TEXT("{ "s);

    content += className;
    content += g_DoubleColon;
    content += name;
    content += SYSTEM_TEXT(", SYSTEM_TEXT(\""s);
    content += describe;
    content += SYSTEM_TEXT("\"s) }"s);

    return content;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetColumn(const String& describe, const String& space, CSVPoistionType csvPoistionType) const
{
    String content{};

    if (csvPoistionType != CSVPoistionType::Begin)
    {
        content += space;
    }

    content += describe;

    if (csvPoistionType != CSVPoistionType::End)
    {
        content += SYSTEM_TEXT(",\n");
    }
    else
    {
        content += SYSTEM_TEXT(" };\n");
    }

    return content;
}

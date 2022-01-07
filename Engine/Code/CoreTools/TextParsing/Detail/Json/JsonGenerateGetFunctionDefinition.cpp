///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:43)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateGetFunctionDefinition.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using std::vector;
using namespace std::literals;

CoreTools::JsonGenerateGetFunctionDefinition::JsonGenerateGetFunctionDefinition(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateGetFunctionDefinition)

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDetailDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    String content{};

    for (const auto& value : jsonHead)
    {
        const auto jsonDataType = value->GetJsonDataType();

        if (jsonDataType == JsonDataType::Nested || jsonDataType == JsonDataType::NestedArray)
        {
            content += SYSTEM_TEXT("template <typename Function>\n"s);
            content += nameSpace;
            content += TextParsing::g_DoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::Const");
            content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("SharedPtr ");
            content += nameSpace;
            content += TextParsing::g_DoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::GetFirst");
            content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("(Function function) const\n");
            content += TextParsing::g_FunctionBeginBrackets;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_UserClassIsValidConst9;
            content += TextParsing::g_NewlineCharacter;

            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("const auto iter = std::find_if("s);
            content += StringConversion::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT(".cbegin(), "s);
            content += StringConversion::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT(".cend(), function);\n"s);
            content += TextParsing::g_NewlineCharacter;

            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("if (iter != "s);
            content += StringConversion::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT(".cend())\n"s);
            content += TextParsing::g_Indentation;
            content += TextParsing::g_FunctionBeginBrackets;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("return *iter;\n"s);
            content += TextParsing::g_Indentation;
            content += TextParsing::g_FunctionEndBrackets;

            content += TextParsing::g_NewlineCharacter;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
            content += StringConversion::ToFirstLetterLower(jsonHead.GetJsonClassName());
            content += SYSTEM_TEXT("表");
            content += StringConversion::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT("字段未找到满足条件的配置信息。\"s));\n"s);
            content += TextParsing::g_FunctionEndBrackets;

            content += TextParsing::g_NewlineCharacter;

            content += SYSTEM_TEXT("template <typename Function>\n"s);
            content += nameSpace;
            content += TextParsing::g_DoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::");
            content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("Container ");
            content += nameSpace;
            content += TextParsing::g_DoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::Get");
            content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("(Function function) const\n");
            content += TextParsing::g_FunctionBeginBrackets;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_UserClassIsValidConst9;
            content += TextParsing::g_NewlineCharacter;

            content += TextParsing::g_Indentation;
            content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("Container result{};\n"s);
            content += TextParsing::g_NewlineCharacter;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("for (const auto& value : "s);
            content += StringConversion::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT(")\n"s);

            content += TextParsing::g_Indentation;
            content += TextParsing::g_FunctionBeginBrackets;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("if (function(value))\n"s);
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_FunctionBeginBrackets;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("result.emplace_back(value);\n"s);
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_FunctionEndBrackets;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_FunctionEndBrackets;

            content += TextParsing::g_NewlineCharacter;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("return result;\n"s);
            content += TextParsing::g_FunctionEndBrackets;
            content += TextParsing::g_NewlineCharacter;
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDetailDefinition(const String& className, const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    String content{};

    const auto jsonDataType = jsonNode.GetJsonDataType();

    if (jsonDataType == JsonDataType::NestedArray)
    {
        content += SYSTEM_TEXT("template <typename Function>\n"s);
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(className);
        content += SYSTEM_TEXT("::Const");
        content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("SharedPtr ");
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(className);
        content += SYSTEM_TEXT("::GetFirst");
        content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("(Function function) const\n");
        content += TextParsing::g_FunctionBeginBrackets;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_UserClassIsValidConst9;
        content += TextParsing::g_NewlineCharacter;

        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("const auto iter = std::find_if("s);
        content += StringConversion::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(".cbegin(), "s);
        content += StringConversion::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(".cend(), function);\n"s);
        content += TextParsing::g_NewlineCharacter;

        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("if (iter != "s);
        content += StringConversion::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(".cend())\n"s);
        content += TextParsing::g_Indentation;
        content += TextParsing::g_FunctionBeginBrackets;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("return *iter;\n"s);
        content += TextParsing::g_Indentation;
        content += TextParsing::g_FunctionEndBrackets;

        content += TextParsing::g_NewlineCharacter;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(jsonHead.GetJsonClassName());
        content += SYSTEM_TEXT("表");
        content += StringConversion::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("字段未找到满足条件的配置信息。\"s));\n"s);
        content += TextParsing::g_FunctionEndBrackets;

        content += TextParsing::g_NewlineCharacter;

        content += SYSTEM_TEXT("template <typename Function>\n"s);
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(className);
        content += TextParsing::g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("Container ");
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(className);
        content += SYSTEM_TEXT("::Get");
        content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("(Function function) const\n");
        content += TextParsing::g_FunctionBeginBrackets;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_UserClassIsValidConst9;
        content += TextParsing::g_NewlineCharacter;

        content += TextParsing::g_Indentation;
        content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("Container result{};\n"s);
        content += TextParsing::g_NewlineCharacter;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("for (const auto& value : "s);
        content += StringConversion::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(")\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_FunctionBeginBrackets;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("if (function(value))\n"s);
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_FunctionBeginBrackets;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("result.emplace_back(value);\n"s);
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_FunctionEndBrackets;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_FunctionEndBrackets;

        content += TextParsing::g_NewlineCharacter;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("return result;\n"s);
        content += TextParsing::g_FunctionEndBrackets;
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonHead)
    {
        const auto jsonDataType = value->GetJsonDataType();

        auto typeName = StringConversion::ToFirstLetterUpper(value->GetTypeName());
        if (typeName == SYSTEM_TEXT("Id"s))
        {
            typeName = SYSTEM_TEXT("ID"s);
        }

        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                content += SYSTEM_TEXT("System::String "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += SYSTEM_TEXT("bool "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += SYSTEM_TEXT("int64_t "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += SYSTEM_TEXT("double "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Nested:
            {
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::StringArray:
                FALLTHROUGH;
            case JsonDataType::BoolArray:
                FALLTHROUGH;
            case JsonDataType::IntArray:
                FALLTHROUGH;
            case JsonDataType::Int64Array:
                FALLTHROUGH;
            case JsonDataType::DoubleArray:
            {
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += TextParsing::g_Space;
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return boost::numeric_cast<int>("s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".size());\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin();\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end();\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;

            case JsonDataType::NestedArray:
            {
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;

                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".at(0);\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(int id) const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return (*lhs).GetID() < (*rhs).GetID();\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_ClassEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("const auto iter = lower_bound("s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cbegin(), "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend(), make_shared<"s);
                content += StringConversion::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(id), function);\n"s);
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("if (iter != "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend() && (*iter)->GetID() == id)\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return *iter;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("else\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
                content += StringConversion::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("datas字段未找到id = \"s) + System::ToString(id) + SYSTEM_TEXT(\"的配置信息。\"s));\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += SYSTEM_TEXT("Container "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Container() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            default:
                break;
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDefinition(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    auto container = JsonNodeContainer::Create();
    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        const auto jsonDataType = value->GetJsonDataType();

        if (jsonDataType == JsonDataType::Nested || jsonDataType == JsonDataType::NestedArray)
        {
            container.AddJsonNode(value->GetJsonNodeContainer());
        }
        else if (!value->GetTypeName().empty())
        {
            container.AddJsonNode(value);
        }
    }

    for (const auto& value : container)
    {
        const auto jsonDataType = value->GetJsonDataType();

        auto typeName = StringConversion::ToFirstLetterUpper(value->GetTypeName());
        if (typeName == SYSTEM_TEXT("Id"s))
        {
            typeName = SYSTEM_TEXT("ID"s);
        }

        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                content += SYSTEM_TEXT("System::String "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += SYSTEM_TEXT("bool "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += SYSTEM_TEXT("int64_t "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += SYSTEM_TEXT("double "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Nested:
            {
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += TextParsing::g_DoubleColon;
                content += SYSTEM_TEXT("Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::StringArray:
                FALLTHROUGH;
            case JsonDataType::BoolArray:
                FALLTHROUGH;
            case JsonDataType::IntArray:
                FALLTHROUGH;
            case JsonDataType::Int64Array:
                FALLTHROUGH;
            case JsonDataType::DoubleArray:
            {
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += TextParsing::g_DoubleColon;
                content += typeName;
                content += TextParsing::g_Space;
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return boost::numeric_cast<int>("s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".size());\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin();\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end();\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;

            case JsonDataType::NestedArray:
            {
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;

                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".at(0);\n"s);

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(int id) const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return (*lhs).GetID() < (*rhs).GetID();\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_ClassEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("const auto iter = lower_bound("s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cbegin(), "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend(), make_shared<"s);
                content += StringConversion::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(id), function);\n"s);
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("if (iter != "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend() && (*iter)->GetID() == id)\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return *iter;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("else\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
                content += StringConversion::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("字段未找到id = \"s) + System::ToString(id) + SYSTEM_TEXT(\"的配置信息。\"s));\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += typeName;
                content += SYSTEM_TEXT("Container "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Container() const\n"s);

                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_UserClassIsValidConst9;
                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return "s);
                content += StringConversion::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::g_SemicolonNewline;

                content += TextParsing::g_FunctionEndBrackets;
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            default:
                break;
        }
    }

    return content;
}

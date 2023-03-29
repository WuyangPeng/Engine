///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 13:53)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDefaultFunctionDefinition.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateDefaultFunctionDefinition::JsonGenerateDefaultFunctionDefinition(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateDefaultFunctionDefinition)

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += SYSTEM_TEXT("Container::"s);
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += SYSTEM_TEXT("Container(const CoreTools::JsonRow& jsonRow)\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gColon;
    content += TextParsing::gSpace;

    auto index = 0;
    for (const auto& value : jsonHead)
    {
        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetString(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Bool:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetBool(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Int:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetInt(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Int64:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetInt64(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Double:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetDouble(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Nested:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ std::make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(jsonRow.GetJsonRow(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s))) }"s);
            }
            break;
            case JsonDataType::StringArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetStringArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetBoolArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetIntArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetInt64Array(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetDoubleArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{}"s);
            }
            break;
            default:
                break;
        }

        ++index;
        if (index == jsonHead.GetSize())
        {
            content += TextParsing::gNewlineCharacter;
        }
        else
        {
            content += TextParsing::gComma;
            content += TextParsing::gNewlineCharacter;
            content += TextParsing::gIndentation;
            content += TextParsing::gSpace;
            content += TextParsing::gSpace;
        }
    }

    content += TextParsing::gFunctionBeginBrackets;

    if (jsonHead.HasNested())
    {
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("Parsing(jsonRow);\n"s);
        content += TextParsing::gNewlineCharacter;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gUserSelfClassIsValid9;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    if (jsonHead.HasNested())
    {
        content += SYSTEM_TEXT("void "s);
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += SYSTEM_TEXT("Container::Parsing(const CoreTools::JsonRow& jsonRow)\n"s);

        content += TextParsing::gFunctionBeginBrackets;

        for (const auto& value : jsonHead)
        {
            if (const auto jsonDataType = value->GetJsonDataType(); jsonDataType == JsonDataType::NestedArray)
            {
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Row = jsonRow.GetJsonRowContainer(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s));\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("for (const auto& value : "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Row)\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".emplace_back(std::make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(value));\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += TextParsing::gSort;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(", [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return (*lhs).GetId() < (*rhs).GetId();\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gLambdaEnd;

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter = std::ranges::unique("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(", [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return (*lhs).GetId() == (*rhs).GetId();\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gLambdaEnd;

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("if ("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.begin() != "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.end())\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User, ");

                content += SYSTEM_TEXT("SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("字段存在重复主键。\")"s);

                content += SYSTEM_TEXT(", CoreTools::LogAppenderIOManageSign::TriggerAssert"s);

                content += SYSTEM_TEXT(");\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".erase("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.begin(), "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.end());\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;
            }
        }

        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    content += SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE("s);
    content += nameSpace;
    content += SYSTEM_TEXT(", "s);
    content += jsonHead.GetJsonClassName();
    content += SYSTEM_TEXT("Container)\n"s);

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateDefinition(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += SYSTEM_TEXT("(const CoreTools::JsonRow& jsonRow)\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gColon;
    content += TextParsing::gSpace;

    auto container = JsonNodeContainer::Create();
    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        if (const auto jsonDataType = value->GetJsonDataType(); jsonDataType == JsonDataType::Nested || jsonDataType == JsonDataType::NestedArray)
        {
            container.AddJsonNode(value->GetJsonNodeContainer());
        }
        else if (!value->GetTypeName().empty())
        {
            container.AddJsonNode(value);
        }
    }

    bool hasNestedArray = false;

    auto index = 0;
    for (const auto& value : container)
    {
        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetString(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Bool:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetBool(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Int:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetInt(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Int64:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetInt64(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Double:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetDouble(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::StringArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetStringArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetBoolArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetIntArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetInt64Array(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ jsonRow.GetDoubleArray(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s)) }"s);
            }
            break;
            case JsonDataType::Nested:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ std::make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(jsonRow.GetJsonRow(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s))) }"s);
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{}"s);

                hasNestedArray = true;
            }
            break;
            default:
                break;
        }

        ++index;
        if (index == container.GetSize())
        {
            content += TextParsing::gNewlineCharacter;
        }
        else
        {
            content += TextParsing::gComma;
            content += TextParsing::gNewlineCharacter;
            content += TextParsing::gIndentation;
            content += TextParsing::gSpace;
            content += TextParsing::gSpace;
        }
    }

    content += TextParsing::gFunctionBeginBrackets;

    if (hasNestedArray)
    {
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("Parsing(jsonRow);\n"s);
        content += TextParsing::gNewlineCharacter;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gUserSelfClassIsValid9;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    if (hasNestedArray)
    {
        content += SYSTEM_TEXT("void "s);
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("::Parsing(const CoreTools::JsonRow& jsonRow)\n"s);

        content += TextParsing::gFunctionBeginBrackets;

        for (const auto& value : container)
        {
            if (const auto jsonDataType = value->GetJsonDataType(); jsonDataType == JsonDataType::NestedArray)
            {
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Row = jsonRow.GetJsonRowContainer(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s));\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("for (const auto& value : "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Row)\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".emplace_back(std::make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(value));\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += TextParsing::gSort;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(", [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return (*lhs).GetId() < (*rhs).GetId();\n"s);

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("});\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter = std::ranges::unique("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(", [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return (*lhs).GetId() == (*rhs).GetId();\n"s);

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("});\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("if ("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.begin() != "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.end())\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User, ");

                content += SYSTEM_TEXT("SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("字段存在重复主键。\")"s);

                content += SYSTEM_TEXT(", CoreTools::LogAppenderIOManageSign::TriggerAssert"s);

                content += SYSTEM_TEXT(");\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".erase("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.begin(), "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter.end());\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;
            }
        }

        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    if (jsonNode.GetJsonDataType() == JsonDataType::NestedArray)
    {
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("(int id) noexcept\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gColon;
        content += TextParsing::gSpace;

        index = 0;
        for (const auto& value : container)
        {
            if (value->GetTypeName() == SYSTEM_TEXT("id"s))
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{ id }"s);
            }
            else
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("{}"s);
            }

            ++index;
            if (index == container.GetSize())
            {
                content += TextParsing::gNewlineCharacter;
            }
            else
            {
                content += TextParsing::gComma;
                content += TextParsing::gNewlineCharacter;
                content += TextParsing::gIndentation;
                content += TextParsing::gSpace;
                content += TextParsing::gSpace;
            }
        }

        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gUserSelfClassIsValid9;
        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    content += SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE("s);
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += jsonHead.GetJsonClassName();
    content += SYSTEM_TEXT(", "s);
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += SYSTEM_TEXT(")\n"s);

    content += TextParsing::gNewlineCharacter;

    return content;
}

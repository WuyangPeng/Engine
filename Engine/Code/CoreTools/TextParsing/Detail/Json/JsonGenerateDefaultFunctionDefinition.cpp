///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:42)

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

using std::vector;
using namespace std::literals;

CoreTools::JsonGenerateDefaultFunctionDefinition::JsonGenerateDefaultFunctionDefinition(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateDefaultFunctionDefinition)

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    auto content = nameSpace;
    content += TextParsing::g_DoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += SYSTEM_TEXT("Container::"s);
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += SYSTEM_TEXT("Container(const CoreTools::JsonRow& jsonRow)\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Colon;
    content += TextParsing::g_Space;

    auto index = 0;
    for (const auto& value : jsonHead)
    {
        const auto jsonDataType = value->GetJsonDataType();

        switch (jsonDataType)
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
                content += SYSTEM_TEXT("{ make_shared<"s);
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
            content += TextParsing::g_NewlineCharacter;
        }
        else
        {
            content += TextParsing::g_Comma;
            content += TextParsing::g_NewlineCharacter;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Space;
            content += TextParsing::g_Space;
        }
    }

    content += TextParsing::g_FunctionBeginBrackets;

    if (jsonHead.HasNested())
    {
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("Parsing(jsonRow);\n"s);
        content += TextParsing::g_NewlineCharacter;
    }

    content += TextParsing::g_Indentation;
    content += TextParsing::g_UserSelfClassIsValid9;
    content += TextParsing::g_FunctionEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    if (jsonHead.HasNested())
    {
        content += SYSTEM_TEXT("void "s);
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += SYSTEM_TEXT("Container::Parsing(const CoreTools::JsonRow& jsonRow)\n"s);

        content += TextParsing::g_FunctionBeginBrackets;

        for (const auto& value : jsonHead)
        {
            const auto jsonDataType = value->GetJsonDataType();

            if (jsonDataType == JsonDataType::NestedArray)
            {
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("const auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Size = jsonRow.GetCount(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s));\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("for (auto i = 0; i < "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Size; ++i)\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".emplace_back(make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::g_DoubleColon;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(jsonRow.GetJsonRow(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s), i)));\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("std::sort("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin(), "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end(), [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return (*lhs).GetID() < (*rhs).GetID();\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_LambdaEnd;

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter = unique("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin(), "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end(), [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return (*lhs).GetID() == (*rhs).GetID();\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_LambdaEnd;

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("if ("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter != "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend())\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT(" LOG_SINGLETON_ENGINE_APPENDER(Warn, User)\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("<< SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("字段存在重复主键。\")\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("<< LOG_SINGLETON_TRIGGER_ASSERT;\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".erase("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter, "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end());\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;
            }
        }

        content += TextParsing::g_FunctionEndBrackets;
        content += TextParsing::g_NewlineCharacter;
    }

    content += SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE("s);
    content += nameSpace;
    content += SYSTEM_TEXT(", "s);
    content += jsonHead.GetJsonClassName();
    content += SYSTEM_TEXT("Container)\n"s);

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateDefinition(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    auto content = nameSpace;
    content += TextParsing::g_DoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::g_DoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::g_DoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += SYSTEM_TEXT("(const CoreTools::JsonRow& jsonRow)\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Colon;
    content += TextParsing::g_Space;

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

    bool hasNestedArray = false;

    auto index = 0;
    for (const auto& value : container)
    {
        const auto jsonDataType = value->GetJsonDataType();

        switch (jsonDataType)
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
                content += SYSTEM_TEXT("{ make_shared<"s);
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
            content += TextParsing::g_NewlineCharacter;
        }
        else
        {
            content += TextParsing::g_Comma;
            content += TextParsing::g_NewlineCharacter;
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Space;
            content += TextParsing::g_Space;
        }
    }

    content += TextParsing::g_FunctionBeginBrackets;

    if (hasNestedArray)
    {
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("Parsing(jsonRow);\n"s);
        content += TextParsing::g_NewlineCharacter;
    }

    content += TextParsing::g_Indentation;
    content += TextParsing::g_UserSelfClassIsValid9;
    content += TextParsing::g_FunctionEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    if (hasNestedArray)
    {
        content += SYSTEM_TEXT("void "s);
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += SYSTEM_TEXT("Container::Parsing(const CoreTools::JsonRow& jsonRow)\n"s);

        content += TextParsing::g_FunctionBeginBrackets;

        for (const auto& value : jsonHead)
        {
            const auto jsonDataType = value->GetJsonDataType();

            if (jsonDataType == JsonDataType::NestedArray)
            {
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("const auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Size = jsonRow.GetCount(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s));\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("for (auto i = 0; i < "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Size; ++i)\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".emplace_back(make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::g_DoubleColon;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(jsonRow.GetJsonRow(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("\"s), i)));\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("std::sort("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin(), "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end(), [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return (*lhs).GetID() < (*rhs).GetID();\n"s);

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("});\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("auto "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter = unique("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin(), "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end(), [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("return (*lhs).GetID() == (*rhs).GetID();\n"s);

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("});\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("if ("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter != "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend())\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionBeginBrackets;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT(" LOG_SINGLETON_ENGINE_APPENDER(Warn, User)\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("<< SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("字段存在重复主键。\")\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("<< LOG_SINGLETON_TRIGGER_ASSERT;\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".erase("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("Iter, "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end());\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_FunctionEndBrackets;
            }
        }

        content += TextParsing::g_FunctionEndBrackets;
        content += TextParsing::g_NewlineCharacter;
    }

    if (jsonNode.GetJsonDataType() == JsonDataType::NestedArray)
    {
        content += nameSpace;
        content += TextParsing::g_DoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::g_DoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::g_DoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("(int id)\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Colon;
        content += TextParsing::g_Space;

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
                content += TextParsing::g_NewlineCharacter;
            }
            else
            {
                content += TextParsing::g_Comma;
                content += TextParsing::g_NewlineCharacter;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Space;
                content += TextParsing::g_Space;
            }
        }

        content += TextParsing::g_FunctionBeginBrackets;

        content += TextParsing::g_Indentation;
        content += TextParsing::g_UserSelfClassIsValid9;
        content += TextParsing::g_FunctionEndBrackets;
        content += TextParsing::g_NewlineCharacter;
    }

    content += SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE("s);
    content += nameSpace;
    content += SYSTEM_TEXT(", "s);
    content += jsonHead.GetJsonClassName();
    content += SYSTEM_TEXT("Container)\n"s);

    content += TextParsing::g_NewlineCharacter;

    return content;
}

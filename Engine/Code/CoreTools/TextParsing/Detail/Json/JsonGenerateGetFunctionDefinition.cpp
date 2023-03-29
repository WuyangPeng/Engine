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
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateGetFunctionDefinition::JsonGenerateGetFunctionDefinition(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
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
            content += TextParsing::gDoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::Const");
            content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("SharedPtr ");
            content += nameSpace;
            content += TextParsing::gDoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::GetFirst");
            content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("(Function function) const\n");
            content += TextParsing::gFunctionBeginBrackets;
            content += TextParsing::gIndentation;
            content += TextParsing::gUserClassIsValidConst9;
            content += TextParsing::gNewlineCharacter;

            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("const auto iter = std::ranges::find_if("s);
            content += StringUtility::ToFirstLetterLower(value->GetTypeName()); 
            content += SYSTEM_TEXT(", function);\n"s);
            content += TextParsing::gNewlineCharacter;

            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("if (iter != "s);
            content += StringUtility::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT(".cend())\n"s);
            content += TextParsing::gIndentation;
            content += TextParsing::gFunctionBeginBrackets;
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("return *iter;\n"s);
            content += TextParsing::gIndentation;
            content += TextParsing::gFunctionEndBrackets;

            content += TextParsing::gNewlineCharacter;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
            content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
            content += SYSTEM_TEXT("表");
            content += StringUtility::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT("字段未找到满足条件的配置信息。\"s))\n"s);
            content += TextParsing::gFunctionEndBrackets;

            content += TextParsing::gNewlineCharacter;

            content += SYSTEM_TEXT("template <typename Function>\n"s);
            content += nameSpace;
            content += TextParsing::gDoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::");
            content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("Container ");
            content += nameSpace;
            content += TextParsing::gDoubleColon;
            content += jsonHead.GetJsonClassName();
            content += SYSTEM_TEXT("Container::Get");
            content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("(Function function) const\n");
            content += TextParsing::gFunctionBeginBrackets;
            content += TextParsing::gIndentation;
            content += TextParsing::gUserClassIsValidConst9;
            content += TextParsing::gNewlineCharacter;

            content += TextParsing::gIndentation;
            content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
            content += SYSTEM_TEXT("Container result{};\n"s);
            content += TextParsing::gNewlineCharacter;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("for (const auto& value : "s);
            content += StringUtility::ToFirstLetterLower(value->GetTypeName());
            content += SYSTEM_TEXT(")\n"s);

            content += TextParsing::gIndentation;
            content += TextParsing::gFunctionBeginBrackets;
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("if (function(value))\n"s);
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += TextParsing::gFunctionBeginBrackets;
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("result.emplace_back(value);\n"s);
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += TextParsing::gFunctionEndBrackets;
            content += TextParsing::gIndentation;
            content += TextParsing::gFunctionEndBrackets;

            content += TextParsing::gNewlineCharacter;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("return result;\n"s);
            content += TextParsing::gFunctionEndBrackets;
            content += TextParsing::gNewlineCharacter;
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
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += SYSTEM_TEXT("::Const");
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("SharedPtr ");
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += SYSTEM_TEXT("::GetFirst");
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("(Function function) const\n");
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gUserClassIsValidConst9;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("const auto iter = std::ranges::find_if("s);
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(", function);\n"s);
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("if (iter != "s);
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(".cend())\n"s);
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("return *iter;\n"s);
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
        content += SYSTEM_TEXT("表");
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("字段未找到满足条件的配置信息。\"s))\n"s);
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;

        content += SYSTEM_TEXT("template <typename Function>\n"s);
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("Container ");
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += SYSTEM_TEXT("::Get");
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("(Function function) const\n");
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gUserClassIsValidConst9;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += SYSTEM_TEXT("Container result{};\n"s);
        content += TextParsing::gNewlineCharacter;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("for (const auto& value : "s);
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += SYSTEM_TEXT(")\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("if (function(value))\n"s);
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("result.emplace_back(value);\n"s);
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("return result;\n"s);
        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
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

        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                content += SYSTEM_TEXT("System::String "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += SYSTEM_TEXT("bool "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += SYSTEM_TEXT("int64_t "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += SYSTEM_TEXT("double "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
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
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
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
                content += TextParsing::gSpace;
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return boost::numeric_cast<int>("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".size());\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const noexcept\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin();\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const noexcept\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end();\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
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

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".at(0);\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(int key) const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return (*lhs).GetId() < (*rhs).GetId();\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gClassEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto iter = std::ranges::lower_bound("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName()); 
                content += SYSTEM_TEXT(", std::make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(key), function);\n"s);
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("if (iter != "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend() && (*iter)->GetId() == key)\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return *iter;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("else\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("datas字段未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s))\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::"s);
                content += typeName;
                content += SYSTEM_TEXT("Container "s);
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Container() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
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

        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                content += SYSTEM_TEXT("System::String "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += SYSTEM_TEXT("bool "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += SYSTEM_TEXT("int64_t "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += SYSTEM_TEXT("double "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Nested:
            {
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += TextParsing::gDoubleColon;
                content += SYSTEM_TEXT("Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept\n"s);
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
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
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += TextParsing::gDoubleColon;
                content += typeName;
                content += TextParsing::gSpace;
                content += jsonHead.GetCompleteClassName();
                content += SYSTEM_TEXT("Container::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += SYSTEM_TEXT("int "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return boost::numeric_cast<int>("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".size());\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const noexcept\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".begin();\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const noexcept\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".end();\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;

                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".at(0);\n"s);

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += SYSTEM_TEXT("Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(int key) const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return (*lhs).GetId() < (*rhs).GetId();\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gClassEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("const auto iter = std::ranges::lower_bound("s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName()); 
                content += SYSTEM_TEXT(", std::make_shared<"s);
                content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">(key), function);\n"s);
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("if (iter != "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT(".cend() && (*iter)->GetId() == key)\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return *iter;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("else\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
                content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
                content += SYSTEM_TEXT("表"s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += SYSTEM_TEXT("字段未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s))\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gFunctionEndBrackets;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;

                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::"s);
                content += typeName;
                content += SYSTEM_TEXT("Container "s);
                content += jsonHead.GetCompleteClassName();
                content += TextParsing::gDoubleColon;
                content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
                content += SYSTEM_TEXT("::Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Container() const\n"s);

                content += TextParsing::gFunctionBeginBrackets;

                content += TextParsing::gIndentation;
                content += TextParsing::gUserClassIsValidConst9;
                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("return "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;

                content += TextParsing::gFunctionEndBrackets;
                content += TextParsing::gNewlineCharacter;
            }
            break;
            default:
                break;
        }
    }

    return content;
}

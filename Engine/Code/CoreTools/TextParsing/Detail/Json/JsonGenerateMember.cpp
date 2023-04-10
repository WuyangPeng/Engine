///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/08 17:19)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateMember.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

CoreTools::JsonGenerateMember::JsonGenerateMember(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateMember)

CoreTools::JsonGenerateMember::String CoreTools::JsonGenerateMember::GenerateContainerMember(int indentationCount, const StringView& typeName, const JsonNode& jsonNode)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += typeName;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::JsonGenerateMember::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIndentation };
    content += TextParsing::gPrivate;

    for (const auto& value : jsonHead)
    {
        constexpr auto indentationCount = 2;

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gSystemString, *value);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gBool, *value);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gInt, *value);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gInt64, *value);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gDouble, *value);
            }
            break;
            case JsonDataType::Nested:
            {
                String typeName{};

                typeName += TextParsing::gCapitalConst;
                typeName += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                typeName += TextParsing::gSharedPtr;

                content += GenerateContainerMember(indentationCount, typeName, *value);
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
                content += GenerateContainerMember(indentationCount, StringUtility::ToFirstLetterUpper(value->GetTypeName()), *value);
            }
            break;
            case JsonDataType::NestedArray:
            {
                String typeName{};
                typeName += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                typeName += TextParsing::gContainer;

                content += GenerateContainerMember(indentationCount, typeName, *value);
            }
            break;
            default:
                break;
        }
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateMember::GenerateNestedContainerMember(int indentationCount, const JsonNode& jsonNode) const
{
    String content{};
    for (const auto& inner : jsonNode.GetJsonNodeContainer())
    {
        switch (const auto innerJsonDataType = inner->GetJsonDataType();
                innerJsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gSystemString, *inner);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gBool, *inner);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gInt, *inner);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gInt64, *inner);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gDouble, *inner);
            }
            break;
            case JsonDataType::Nested:
            {
                String typeName{};

                typeName += TextParsing::gCapitalConst;
                typeName += StringUtility::ToFirstLetterUpper(inner->GetTypeName());
                typeName += TextParsing::gSharedPtr;

                content += GenerateContainerMember(indentationCount, typeName, *inner);
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
                content += GenerateContainerMember(indentationCount, StringUtility::ToFirstLetterUpper(inner->GetTypeName()), *inner);
            }
            break;
            case JsonDataType::NestedArray:
            {
                String typeName{};
                typeName += StringUtility::ToFirstLetterUpper(inner->GetTypeName());
                typeName += TextParsing::gContainer;

                content += GenerateContainerMember(indentationCount, typeName, *inner);
            }
            break;
            default:
                break;
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateMember::GenerateContainerMember(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIndentation };
    content += TextParsing::gIndentation;
    content += TextParsing::gPrivate;

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        constexpr auto indentationCount = 3;

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gSystemString, *value);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gBool, *value);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gInt, *value);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gInt64, *value);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerMember(indentationCount, TextParsing::gDouble, *value);
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
                content += GenerateContainerMember(indentationCount, content += StringUtility::ToFirstLetterUpper(value->GetTypeName()), *value);
            }
            break;

            case JsonDataType::Nested:
                FALLTHROUGH;
            case JsonDataType::NestedArray:
            {
                content += GenerateNestedContainerMember(indentationCount, *value);
            }
            break;
            default:
                break;
        }
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

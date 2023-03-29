///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 14:05)

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

using namespace std::literals;

CoreTools::JsonGenerateMember::JsonGenerateMember(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateMember)

System::String CoreTools::JsonGenerateMember::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIndentation };
    content += TextParsing::gPrivate;

    for (const auto& value : jsonHead)
    {
        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("System::String "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Bool:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("bool "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Int:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("int "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Int64:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("int64_t "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Double:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("double "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Nested:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("Const"s);
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("SharedPtr "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
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
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += TextParsing::gSpace;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("Container "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
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

System::String CoreTools::JsonGenerateMember::GenerateContainerMember(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIndentation };
    content += TextParsing::gIndentation;
    content += TextParsing::gPrivate;

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("System::String "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Bool:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("bool "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Int:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("int "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Int64:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("int64_t "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;
            case JsonDataType::Double:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("double "s);
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
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
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += StringUtility::ToFirstLetterUpper(value->GetTypeName());
                content += TextParsing::gSpace;
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gSemicolonNewline;
            }
            break;

            case JsonDataType::Nested:
                FALLTHROUGH;
            case JsonDataType::NestedArray:
            {
                for (const auto& inner : value->GetJsonNodeContainer())
                {
                    switch (const auto innerJsonDataType = inner->GetJsonDataType(); innerJsonDataType)
                    {
                        case JsonDataType::String:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("System::String "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        case JsonDataType::Bool:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("bool "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        case JsonDataType::Int:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("int "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        case JsonDataType::Int64:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("int64_t "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        case JsonDataType::Double:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("double "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        case JsonDataType::Nested:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("Const"s);
                            content += StringUtility::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT("SharedPtr "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
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
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += StringUtility::ToFirstLetterUpper(inner->GetTypeName());
                            content += TextParsing::gSpace;
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        case JsonDataType::NestedArray:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += StringUtility::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT("Container "s);
                            content += StringUtility::ToFirstLetterLower(inner->GetTypeName());
                            content += TextParsing::gSemicolonNewline;
                        }
                        break;
                        default:
                            break;
                    }
                }
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

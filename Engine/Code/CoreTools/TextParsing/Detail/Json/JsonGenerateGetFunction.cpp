///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 13:57)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateGetFunction.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateGetFunction::JsonGenerateGetFunction(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateGetFunction)

System::String CoreTools::JsonGenerateGetFunction::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonHead)
    {
        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD System::String Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD bool Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD int64_t Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD double Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Nested:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
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
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT(" Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const noexcept;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const noexcept;\n"s);

                content += TextParsing::gNewlineCharacter;
            }
            break;

            case JsonDataType::NestedArray:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(int key) const;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("Container Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Container() const;\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("template <typename Function>\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("(Function function) const;\n"s);

                content += TextParsing::gNewlineCharacter;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("template <typename Function>\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("Container Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(Function function) const;\n"s);

                content += TextParsing::gNewlineCharacter;
            }
            break;
            default:
                break;
        }
    }

    if (jsonHead.HasNested())
    {
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("private:\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("void Parsing(const CoreTools::JsonRow& jsonRow);\n"s);
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunction::GenerateContainerFunction(const JsonNode& jsonNode)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    bool hasNested = false;

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD System::String Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD bool Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD int64_t Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD double Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
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
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT(" Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const noexcept;\n"s);

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const noexcept;\n"s);

                content += TextParsing::gNewlineCharacter;
            }
            break;
            case JsonDataType::Nested:
                FALLTHROUGH;
            case JsonDataType::NestedArray:
            {
                for (const auto& inner : value->GetJsonNodeContainer())
                {
                    const auto innerJsonDataType = inner->GetJsonDataType();

                    typeName = StringUtility::ToFirstLetterUpper(inner->GetTypeName());

                    switch (innerJsonDataType)
                    {
                        case JsonDataType::String:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD System::String Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const;\n"s);
                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                        case JsonDataType::Bool:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD bool Is"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                        case JsonDataType::Int:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD int Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                        case JsonDataType::Int64:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD int64_t Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                        case JsonDataType::Double:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD double Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
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
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT(" Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const;\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD int Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("Size() const;\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("ConstIter Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("Begin() const noexcept;\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("ConstIter Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("End() const noexcept;\n"s);

                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                        case JsonDataType::Nested:
                        {
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                        case JsonDataType::NestedArray:
                        {
                            hasNested = true;

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const;\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("(int key) const;\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("Container Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("Container() const;\n"s);

                            content += TextParsing::gNewlineCharacter;

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("template <typename Function>\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                            content += typeName;
                            content += SYSTEM_TEXT("(Function function) const;\n"s);

                            content += TextParsing::gNewlineCharacter;

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("template <typename Function>\n"s);

                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += TextParsing::gIndentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("Container Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("(Function function) const;\n"s);

                            content += TextParsing::gNewlineCharacter;
                        }
                        break;
                    }
                }
            }
            break;
            default:
                break;
        }
    }

    if (hasNested)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("private:\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("void Parsing(const CoreTools::JsonRow& jsonRow);\n"s);
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}
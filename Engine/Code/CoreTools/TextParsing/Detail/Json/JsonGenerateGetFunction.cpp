///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:43)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateGetFunction.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using std::vector;
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
        const auto jsonDataType = value->GetJsonDataType();

        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());
        if (typeName == SYSTEM_TEXT("Id"s))
        {
            typeName = SYSTEM_TEXT("ID"s);
        }

        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD System::String Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD bool Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD int64_t Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD double Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Nested:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
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
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT(" Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const;\n"s);

                content += TextParsing::g_NewlineCharacter;
            }
            break;

            case JsonDataType::NestedArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(int id) const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("Container Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Container() const;\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("template <typename Function>\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD Const"s);
                content += typeName;
                content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                content += typeName;
                content += SYSTEM_TEXT("(Function function) const;\n"s);

                content += TextParsing::g_NewlineCharacter;

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("template <typename Function>\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("Container Get"s);
                content += typeName;
                content += SYSTEM_TEXT("(Function function) const;\n"s);

                content += TextParsing::g_NewlineCharacter;
            }
            break;
            default:
                break;
        }
    }

    if (jsonHead.HasNested())
    {
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("private:\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("void Parsing(const CoreTools::JsonRow& jsonRow);\n"s);
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunction::GenerateContainerFunction(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    bool hasNested = false;

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        const auto jsonDataType = value->GetJsonDataType();

        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());
        if (typeName == SYSTEM_TEXT("Id"s))
        {
            typeName = SYSTEM_TEXT("ID"s);
        }

        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD System::String Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Bool:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD bool Is"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Int64:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD int64_t Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
                content += TextParsing::g_NewlineCharacter;
            }
            break;
            case JsonDataType::Double:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD double Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const noexcept;\n"s);
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
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT(" Get"s);
                content += typeName;
                content += SYSTEM_TEXT("() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD int Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Size() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("Begin() const;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("NODISCARD "s);
                content += typeName;
                content += SYSTEM_TEXT("ConstIter Get"s);
                content += typeName;
                content += SYSTEM_TEXT("End() const;\n"s);

                content += TextParsing::g_NewlineCharacter;
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
                    if (typeName == SYSTEM_TEXT("Id"s))
                    {
                        typeName = SYSTEM_TEXT("ID"s);
                    }

                    switch (innerJsonDataType)
                    {
                        case JsonDataType::String:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD System::String Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const;\n"s);
                            content += TextParsing::g_NewlineCharacter;
                        }
                        break;
                        case JsonDataType::Bool:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD bool Is"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::g_NewlineCharacter;
                        }
                        break;
                        case JsonDataType::Int:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD int Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::g_NewlineCharacter;
                        }
                        break;
                        case JsonDataType::Int64:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD int64_t Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::g_NewlineCharacter;
                        }
                        break;
                        case JsonDataType::Double:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD double Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
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
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT(" Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const;\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD int Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("Size() const;\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("ConstIter Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("Begin() const;\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("ConstIter Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("End() const;\n"s);

                            content += TextParsing::g_NewlineCharacter;
                        }
                        break;
                        case JsonDataType::Nested:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const noexcept;\n"s);
                            content += TextParsing::g_NewlineCharacter;
                        }
                        break;
                        case JsonDataType::NestedArray:
                        {
                            hasNested = true;

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                            content += typeName;
                            content += SYSTEM_TEXT("() const;\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("(int id) const;\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("Container Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("Container() const;\n"s);

                            content += TextParsing::g_NewlineCharacter;

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("template <typename Function>\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD Const"s);
                            content += typeName;
                            content += SYSTEM_TEXT("SharedPtr GetFirst"s);
                            content += typeName;
                            content += SYSTEM_TEXT("(Function function) const;\n"s);

                            content += TextParsing::g_NewlineCharacter;

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("template <typename Function>\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("NODISCARD "s);
                            content += typeName;
                            content += SYSTEM_TEXT("Container Get"s);
                            content += typeName;
                            content += SYSTEM_TEXT("(Function function) const;\n"s);

                            content += TextParsing::g_NewlineCharacter;
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
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("private:\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("void Parsing(const CoreTools::JsonRow& jsonRow);\n"s);
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}
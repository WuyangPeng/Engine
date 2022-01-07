///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:39)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateClassName.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

using namespace std::literals;

CoreTools::JsonGenerateClassName::JsonGenerateClassName(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateClassName)

System::String CoreTools::JsonGenerateClassName::GenerateContainerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = jsonHead.GetJsonClassName() + SYSTEM_TEXT("Container"s);

    String content{ TextParsing::g_Indentation };
    content += TextParsing::g_Class;
    content += className;
    content += SYSTEM_TEXT(" final\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_FunctionBeginBrackets;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Public;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_ClassType;
    content += className;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateContainerClassName(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());

    String content{ TextParsing::g_Indentation };
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Class;
    content += className;
    content += SYSTEM_TEXT(" final\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_FunctionBeginBrackets;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Public;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_ClassType;
    content += className;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateUsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonHead)
    {
        const auto jsonDataType = value->GetJsonDataType();

        switch (jsonDataType)
        {
            case JsonDataType::Nested:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using Const"s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const "s);
                content += jsonHead.GetJsonClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">;\n"s);
            }
            break;
            case JsonDataType::StringArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<System::String>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::deque<bool>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<int>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<int64_t>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<double>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using Const"s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const "s);
                content += jsonHead.GetJsonClassName();
                content += TextParsing::g_DoubleColon;
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(">;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("Container = std::vector<Const"s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("SharedPtr>;\n"s);
            }
            break;
            default:
                break;
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateUsing(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        const auto jsonDataType = value->GetJsonDataType();

        switch (jsonDataType)
        {
            case JsonDataType::StringArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<System::String>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::deque<bool>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<int>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<int64_t>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT(" = std::vector<double>;\n"s);

                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += TextParsing::g_Indentation;
                content += SYSTEM_TEXT("using "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("ConstIter = "s);
                content += StringConversion::ToFirstLetterUpper(value->GetTypeName());
                content += SYSTEM_TEXT("::const_iterator;\n"s);
            }
            break;
            case JsonDataType::Nested:
                FALLTHROUGH;
            case JsonDataType::NestedArray:
            {
                for (const auto& inner : value->GetJsonNodeContainer())
                {
                    const auto innerJsonDataType = inner->GetJsonDataType();

                    switch (innerJsonDataType)
                    {
                        case JsonDataType::Nested:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("using Const"s);
                            content += StringConversion::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const "s);
                            content += StringConversion::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT(">;\n"s);
                        }
                        break;
                        case JsonDataType::NestedArray:
                        {
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("using Const"s);
                            content += StringConversion::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const "s);
                            content += StringConversion::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT(">;\n"s);

                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += TextParsing::g_Indentation;
                            content += SYSTEM_TEXT("using "s);
                            content += StringConversion::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT("Container = std::vector<Const"s);
                            content += StringConversion::ToFirstLetterUpper(inner->GetTypeName());
                            content += SYSTEM_TEXT("SharedPtr>;\n"s);
                        }
                        break;
                        default:
                            break;
                    }
                }
            }
            break;
                break;
            default:
                break;
        }
    }

    return content;
}

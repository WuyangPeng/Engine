///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/07 11:22)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateClassName.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

CoreTools::JsonGenerateClassName::JsonGenerateClassName(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateClassName)

System::String CoreTools::JsonGenerateClassName::GenerateContainerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = jsonHead.GetJsonClassName() + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };
    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gSpace;
    content += TextParsing::gFinal;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassType;
    content += className;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateContainerClassName(const JsonNode& jsonNode)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());

    String content{ TextParsing::gIndentation };
    content += TextParsing::gIndentation;
    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gSpace;
    content += TextParsing::gFinal;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassType;
    content += className;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateUsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonHead)
    {
        constexpr auto indentationCount = 2;

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::StringArray:
            {
                content += GenerateStringArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += GenerateBoolArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += GenerateIntArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += GenerateInt64ArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += GenerateDoubleArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateNestedUsing(*value, indentationCount, jsonHead.GetJsonClassName() + TextParsing::gDoubleColon.data());
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += GenerateNestedArrayUsing(*value, indentationCount, jsonHead.GetJsonClassName() + TextParsing::gDoubleColon.data());
            }
            break;
            default:
                break;
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateUsing(const JsonNode& jsonNode)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        constexpr auto indentationCount = 3;

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::StringArray:
            {
                content += GenerateStringArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += GenerateBoolArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += GenerateIntArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += GenerateInt64ArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += GenerateDoubleArrayUsing(*value, indentationCount);
            }
            break;
            case JsonDataType::Nested:
                FALLTHROUGH;
            case JsonDataType::NestedArray:
            {
                for (const auto& inner : value->GetJsonNodeContainer())
                {
                    switch (const auto innerJsonDataType = inner->GetJsonDataType();
                            innerJsonDataType)
                    {
                        case JsonDataType::Nested:
                        {
                            content += GenerateNestedUsing(*inner, indentationCount);
                        }
                        break;
                        case JsonDataType::NestedArray:
                        {
                            content += GenerateNestedArrayUsing(*inner, indentationCount);
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

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateStringArrayUsing(const JsonNode& jsonNode, int indentationCount)
{
    return GenerateArrayUsing(jsonNode, indentationCount, TextParsing::gStringArrayInitial);
}

System::String CoreTools::JsonGenerateClassName::GenerateBoolArrayUsing(const JsonNode& jsonNode, int indentationCount)
{
    return GenerateArrayUsing(jsonNode, indentationCount, TextParsing::gBoolArrayInitial);
}

System::String CoreTools::JsonGenerateClassName::GenerateIntArrayUsing(const JsonNode& jsonNode, int indentationCount)
{
    return GenerateArrayUsing(jsonNode, indentationCount, TextParsing::gIntArrayInitial);
}

System::String CoreTools::JsonGenerateClassName::GenerateInt64ArrayUsing(const JsonNode& jsonNode, int indentationCount)
{
    return GenerateArrayUsing(jsonNode, indentationCount, TextParsing::gInt64ArrayInitial);
}

System::String CoreTools::JsonGenerateClassName::GenerateDoubleArrayUsing(const JsonNode& jsonNode, int indentationCount)
{
    return GenerateArrayUsing(jsonNode, indentationCount, TextParsing::gDoubleArrayInitial);
}

CoreTools::JsonGenerateClassName::String CoreTools::JsonGenerateClassName::GenerateNestedUsing(const JsonNode& jsonNode, int indentationCount, const String& jsonClassName)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gUsingConst;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gSharedPtrEqualTo;

    content += jsonClassName;

    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gRightAngleBracket;
    content += TextParsing::gSemicolonNewline;

    return content;
}

CoreTools::JsonGenerateClassName::String CoreTools::JsonGenerateClassName::GenerateNestedArrayUsing(const JsonNode& jsonNode, int indentationCount, const String& jsonClassName)
{
    auto content = GenerateNestedUsing(jsonNode, indentationCount, jsonClassName);

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gUsing;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gContainerEqualTo;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gSharedPtr;
    content += TextParsing::gRightAngleBracket;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::JsonGenerateClassName::GenerateArrayUsing(const JsonNode& jsonNode, int indentationCount, const StringView& usingDefinition)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gUsing;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += usingDefinition;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gUsing;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gCapitalConst;
    content += TextParsing::gCapitalIter;
    content += TextParsing::gSpace;
    content += TextParsing::gEqualSign;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gConstIterator;
    content += TextParsing::gSemicolonNewline;

    return content;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/08 13:50)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateGetFunction.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

CoreTools::JsonGenerateGetFunction::JsonGenerateGetFunction(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateGetFunction)

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateContainerGetFunction(int indentationCount, const String& typeName, const String& getDescribe, const StringView& endDescribe)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += getDescribe;
    content += typeName;
    content += endDescribe;
    content += TextParsing::gNewlineCharacter;

    return content;
}

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateEndDescribe()
{
    String content{ TextParsing::gLeftBrackets };

    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSemicolonNewline;

    return content;
}

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateGetDescribe(const StringView& typeName)
{
    String content{ TextParsing::gNodiscard };

    content += typeName;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;

    return content;
}

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateIsDescribe(const StringView& typeName)
{
    String content{ TextParsing::gNodiscard };

    content += typeName;
    content += TextParsing::gSpace;
    content += TextParsing::gIs;

    return content;
}

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateNestedGetDescribe(const StringView& typeName)
{
    String content{};

    content += TextParsing::gNodiscard;
    content += TextParsing::gCapitalConst;
    content += typeName;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;

    return content;
}

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateContainerArrayGetFunction(int indentationCount, const String& typeName)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscard;
    content += typeName;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstSemicolonNewline;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscard;
    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gSize;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstSemicolonNewline;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscard;
    content += typeName;
    content += TextParsing::gConstIter;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gBeginNoexceptFunction;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscard;
    content += typeName;
    content += TextParsing::gConstIter;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gEndNoexceptFunction;

    content += TextParsing::gNewlineCharacter;

    return content;
}

CoreTools::JsonGenerateGetFunction::String CoreTools::JsonGenerateGetFunction::GenerateContainerNestedArrayGetFunction(int indentationCount, const String& typeName)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscardConst;
    content += typeName;
    content += TextParsing::gGetFirstSharedPtr;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstSemicolonNewline;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscardConst;
    content += typeName;
    content += TextParsing::gGetSharedPtr;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gInt;
    content += TextParsing::gKeyConst;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscard;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstSemicolonNewline;

    content += TextParsing::gNewlineCharacter;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gFunctionTemplate;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscardConst;
    content += typeName;
    content += TextParsing::gGetFirstSharedPtr;
    content += typeName;
    content += TextParsing::gFunctionParameter;

    content += TextParsing::gNewlineCharacter;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gFunctionTemplate;

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gNodiscard;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gSpace;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gFunctionParameter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunction::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonHead)
    {
        auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        constexpr auto indentationCount = 2;

        switch (const auto jsonDataType = value->GetJsonDataType();
                jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gSystemString), GenerateEndDescribe());
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateIsDescribe(TextParsing::gBool), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gInt), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gInt64), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gDouble), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateNestedGetDescribe(typeName), TextParsing::gConstNoexcept);
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
                content += GenerateContainerArrayGetFunction(indentationCount, typeName);
            }
            break;

            case JsonDataType::NestedArray:
            {
                content += GenerateContainerNestedArrayGetFunction(indentationCount, typeName);
            }
            break;
            default:
                break;
        }
    }

    if (jsonHead.HasNested())
    {
        content += GenerateParsingFunction(1);
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunction::GenerateParsingFunction(int indentationCount)
{
    String content{};

    for (auto i = 0; i < indentationCount; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gPrivate;

    for (auto i = 0; i < indentationCount + 1; ++i)
    {
        content += TextParsing::gIndentation;
    }

    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += TextParsing::gParsing;
    content += TextParsing::gJsonRowParameter;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunction::GenerateNestedArrayFunction(int indentationCount, const JsonNode& jsonNode, bool& hasNested)
{
    String content{};
    for (const auto& inner : jsonNode.GetJsonNodeContainer())
    {
        const auto innerJsonDataType = inner->GetJsonDataType();

        const auto typeName = StringUtility::ToFirstLetterUpper(inner->GetTypeName());

        switch (innerJsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gSystemString), GenerateEndDescribe());
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateIsDescribe(TextParsing::gBool), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gInt), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gInt64), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gDouble), TextParsing::gConstNoexcept);
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
                content += GenerateContainerArrayGetFunction(indentationCount, typeName);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateNestedGetDescribe(typeName), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::NestedArray:
            {
                hasNested = true;

                content += GenerateContainerNestedArrayGetFunction(indentationCount, typeName);
            }
            break;
        }
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

        constexpr auto indentationCount = 3;

        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gSystemString), GenerateEndDescribe());
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateIsDescribe(TextParsing::gBool), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gInt), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gInt64), TextParsing::gConstNoexcept);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerGetFunction(indentationCount, typeName, GenerateGetDescribe(TextParsing::gDouble), TextParsing::gConstNoexcept);
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
                content += GenerateContainerArrayGetFunction(indentationCount, typeName);
            }
            break;
            case JsonDataType::Nested:
                FALLTHROUGH;
            case JsonDataType::NestedArray:
            {
                content += GenerateNestedArrayFunction(indentationCount, *value, hasNested);
            }
            break;
            default:
                break;
        }
    }

    if (hasNested)
    {
        content += GenerateParsingFunction(2);
    }

    return content;
}

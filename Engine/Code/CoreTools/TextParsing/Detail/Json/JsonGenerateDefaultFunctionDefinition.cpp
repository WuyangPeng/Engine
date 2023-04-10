///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/07 16:45)

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

CoreTools::JsonGenerateDefaultFunctionDefinition::JsonGenerateDefaultFunctionDefinition(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateDefaultFunctionDefinition)

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateJsonRowGetDefinition(const JsonNode& jsonNode, const StringView& jsonRowGet)
{
    String content{};

    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += jsonRowGet;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSystemTextEnd;
    content += TextParsing::gRightBrace;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateJsonRowGetNestedDefinition(const JsonNode& jsonNode)
{
    String content{};

    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gLeftBrace;
    content += TextParsing::gSpace;
    content += TextParsing::gMakeShared;
    content += TextParsing::gLeftAngleBracket;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gGetJsonRow;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gGetNestedEnd;
    content += TextParsing::gRightBrace;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateMemberListDefinition() const
{
    String content{};

    auto index = 0;
    for (const auto& value : jsonHead)
    {
        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetString);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetBool);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetInt);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetInt64);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetDouble);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateJsonRowGetNestedDefinition(*value);
            }
            break;
            case JsonDataType::StringArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetStringArray);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetBoolArray);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetIntArray);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetInt64Array);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetDoubleArray);
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gInit;
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

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateParsingNestedArrayDefinition(const JsonNode& jsonNode) const
{
    String content{};

    content += TextParsing::gIndentation;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gAuto;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gGetJsonRowContainer;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gGetJsonRowContainerEnd;

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gForLoop;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gRow;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gEmplaceBack;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gValue;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gSort;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gFunction;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gGetIdLessReturn;

    content += TextParsing::gIndentation;
    content += TextParsing::gLambdaEnd;

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gAuto;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCapitalIter;

    content += TextParsing::gSpace;
    content += TextParsing::gEqualSign;
    content += TextParsing::gSpace;
    content += TextParsing::gRangesUnique;
    content += TextParsing::gLeftBrackets;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gFunction;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gGetIdEqualReturn;

    content += TextParsing::gIndentation;
    content += TextParsing::gLambdaEnd;

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIf;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCapitalIter;
    content += TextParsing::gDot;
    content += TextParsing::gBegin;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gNotEqualSign;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCapitalIter;
    content += TextParsing::gDot;
    content += TextParsing::gEnd;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gWarnLog;

    content += TextParsing::gSystemText;
    content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
    content += TextParsing::gDataSheet;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gRepeatFieldHint;

    content += TextParsing::gLogAssert;

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gDot;
    content += TextParsing::gErase;
    content += TextParsing::gLeftBrackets;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCapitalIter;
    content += TextParsing::gDot;
    content += TextParsing::gBegin;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCapitalIter;
    content += TextParsing::gDot;
    content += TextParsing::gEnd;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateParsingDefinition(const String& nameSpace) const
{
    String content{};

    if (jsonHead.HasNested())
    {
        content += TextParsing::gVoid;
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::gContainer;
        content += TextParsing::gDoubleColon;
        content += TextParsing::gParsing;
        content += TextParsing::gJsonRowParameter;
        content += TextParsing::gNewline;

        content += TextParsing::gFunctionBeginBrackets;

        for (const auto& value : jsonHead)
        {
            if (const auto jsonDataType = value->GetJsonDataType(); jsonDataType == JsonDataType::NestedArray)
            {
                content += GenerateParsingNestedArrayDefinition(*value);
            }
        }

        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    auto content = nameSpace;

    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::gContainer;
    content += TextParsing::gJsonRowParameter;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gColon;
    content += TextParsing::gSpace;

    content += GenerateMemberListDefinition();

    content += TextParsing::gFunctionBeginBrackets;

    if (jsonHead.HasNested())
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gParsingJsonRow;
        content += TextParsing::gNewlineCharacter;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gUserSelfClassIsValid9;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += GenerateParsingDefinition(nameSpace);

    content += TextParsing::gClassInvariantStubDefine;
    content += nameSpace;
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += jsonHead.GetJsonClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateIdConstructorDefinition(const JsonNode& jsonNode, const String& nameSpace, const JsonNodeContainer& container) const
{
    String content{};

    if (jsonNode.GetJsonDataType() == JsonDataType::NestedArray)
    {
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gInt;
        content += TextParsing::gSpace;
        content += TextParsing::gIdSmall;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
        content += TextParsing::gNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gColon;
        content += TextParsing::gSpace;

        auto index = 0;
        for (const auto& value : container)
        {
            if (value->GetTypeName() == TextParsing::gIdSmall)
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gLeftBrace;
                content += TextParsing::gSpace;
                content += TextParsing::gIdSmall;
                content += TextParsing::gSpace;
                content += TextParsing::gRightBrace;
            }
            else
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gInit;
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

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateParsingDefinition(const JsonNode& jsonNode) const
{
    String content{};

    if (const auto jsonDataType = jsonNode.GetJsonDataType();
        jsonDataType == JsonDataType::NestedArray)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += TextParsing::gAuto;
        content += TextParsing::gSpace;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gGetJsonRowContainer;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gGetJsonRowContainerEnd;

        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gForLoop;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gRow;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gEmplaceBack;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gValue;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gSort;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gFunction;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gGetIdLessReturn;

        content += TextParsing::gIndentation;
        content += TextParsing::gLambdaEnd;

        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += TextParsing::gAuto;
        content += TextParsing::gSpace;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gCapitalIter;

        content += TextParsing::gSpace;
        content += TextParsing::gEqualSign;
        content += TextParsing::gSpace;
        content += TextParsing::gRangesUnique;
        content += TextParsing::gLeftBrackets;

        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gFunction;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gGetIdEqualReturn;

        content += TextParsing::gIndentation;
        content += TextParsing::gLambdaEnd;

        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gIf;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gCapitalIter;
        content += TextParsing::gDot;
        content += TextParsing::gBegin;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSpace;
        content += TextParsing::gNotEqualSign;
        content += TextParsing::gSpace;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gCapitalIter;
        content += TextParsing::gDot;
        content += TextParsing::gEnd;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gWarnLog;

        content += TextParsing::gSystemText;
        content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
        content += TextParsing::gDataSheet;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gRepeatFieldHint;

        content += TextParsing::gLogAssert;

        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gDot;
        content += TextParsing::gErase;
        content += TextParsing::gLeftBrackets;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gCapitalIter;
        content += TextParsing::gDot;
        content += TextParsing::gBegin;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gComma;
        content += TextParsing::gSpace;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gCapitalIter;
        content += TextParsing::gDot;
        content += TextParsing::gEnd;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSemicolonNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;
    }

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateNestedArrayDefinition(const JsonNode& jsonNode, const String& nameSpace, const JsonNodeContainer& container, bool hasNestedArray) const
{
    String content{};

    if (hasNestedArray)
    {
        content += TextParsing::gVoid;
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gDoubleColon;
        content += TextParsing::gParsing;
        content += TextParsing::gJsonRowParameter;
        content += TextParsing::gNewline;

        content += TextParsing::gFunctionBeginBrackets;

        for (const auto& value : container)
        {
            content += GenerateParsingDefinition(*value);
        }

        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    content += GenerateIdConstructorDefinition(jsonNode, nameSpace, container);

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunctionDefinition::GenerateJsonRowDefinition(const JsonNodeContainer& container, bool& hasNestedArray)
{
    String content{};

    auto index = 0;
    for (const auto& value : container)
    {
        switch (const auto jsonDataType = value->GetJsonDataType(); jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetString);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetBool);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetInt);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetInt64);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetDouble);
            }
            break;
            case JsonDataType::StringArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetStringArray);
            }
            break;
            case JsonDataType::BoolArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetBoolArray);
            }
            break;
            case JsonDataType::IntArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetIntArray);
            }
            break;
            case JsonDataType::Int64Array:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetInt64Array);
            }
            break;
            case JsonDataType::DoubleArray:
            {
                content += GenerateJsonRowGetDefinition(*value, TextParsing::gJsonRowGetDoubleArray);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateJsonRowGetNestedDefinition(*value);
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += StringUtility::ToFirstLetterLower(value->GetTypeName());
                content += TextParsing::gInit;

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
    content += TextParsing::gJsonRowParameter;
    content += TextParsing::gNewline;

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

    content += GenerateJsonRowDefinition(container, hasNestedArray);

    content += TextParsing::gFunctionBeginBrackets;

    if (hasNestedArray)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gParsingJsonRow;
        content += TextParsing::gNewlineCharacter;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gUserSelfClassIsValid9;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += GenerateNestedArrayDefinition(jsonNode, nameSpace, container, hasNestedArray);

    content += TextParsing::gClassInvariantStubDefine;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += jsonHead.GetJsonClassName();
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gNewlineCharacter;

    return content;
}

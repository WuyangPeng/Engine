///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/08 17:03)

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

CoreTools::JsonGenerateGetFunctionDefinition::JsonGenerateGetFunctionDefinition(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateGetFunctionDefinition)

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDetailNestedDefinition(const String& nameSpace, const JsonNode& jsonNode) const
{
    String content{};

    content += TextParsing::gFunctionTemplate;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += jsonHead.GetJsonClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gCapitalConst;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += jsonHead.GetJsonClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gGetFirst;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gFunctionParameterConst;
    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIterFindIf;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gFindFunction;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIfIter;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCEnd;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnIter;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += TextParsing::gThrowException;
    content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
    content += TextParsing::gDataSheet;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gFieldConditionNotFind;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gFunctionTemplate;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += jsonHead.GetJsonClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gContainer;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += jsonHead.GetJsonClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gFunctionParameterConst;
    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gContainerResult;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += TextParsing::gForLoop;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIfFunction;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gResultEmplaceBack;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnResult;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDetailDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = jsonHead.GetNameSpace();

    String content{};

    for (const auto& value : jsonHead)
    {
        if (const auto jsonDataType = value->GetJsonDataType();
            jsonDataType == JsonDataType::Nested || jsonDataType == JsonDataType::NestedArray)
        {
            content += GenerateDetailNestedDefinition(nameSpace, *value);
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDetailDefinition(const String& className, const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    if (const auto jsonDataType = jsonNode.GetJsonDataType();
        jsonDataType == JsonDataType::NestedArray)
    {
        const auto nameSpace = jsonHead.GetNameSpace();

        content += TextParsing::gFunctionTemplate;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += TextParsing::gDoubleColon;
        content += TextParsing::gCapitalConst;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gSharedPtr;
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += TextParsing::gGetFirst;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gFunctionParameterConst;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gUserClassIsValidConst9;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gIterFindIf;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gFindFunction;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gIfIter;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gCEnd;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gReturnIter;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;
        content += TextParsing::gIndentation;
        content += TextParsing::gThrowException;
        content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
        content += TextParsing::gDataSheet;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gFieldConditionNotFind;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gFunctionTemplate;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gContainer;
        content += TextParsing::gSpace;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += jsonHead.GetJsonClassName();
        content += TextParsing::gDoubleColon;
        content += StringUtility::ToFirstLetterUpper(className);
        content += TextParsing::gDoubleColon;
        content += TextParsing::gGet;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gFunctionParameterConst;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gUserClassIsValidConst9;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
        content += TextParsing::gContainerResult;
        content += TextParsing::gNewlineCharacter;
        content += TextParsing::gIndentation;
        content += TextParsing::gForLoop;
        content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
        content += TextParsing::gRightBrackets;
        content += TextParsing::gNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIfFunction;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gResultEmplaceBack;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;
        content += TextParsing::gIndentation;
        content += TextParsing::gReturnResult;
        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateGetDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode) const
{
    String content{};

    content += jsonType;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateIsDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode) const
{
    String content{};

    content += jsonType;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gIs;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateGetDefinitionNoexcept(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode) const
{
    String content{};

    content += jsonType;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateGetNestedDefinition(const String& typeName, const JsonNode& jsonNode) const
{
    String content{};

    content += TextParsing::gCapitalConst;
    content += typeName;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateGetArrayDefinition(const String& typeName, const JsonNode& jsonNode) const
{
    String content{};

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gSize;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturnNumericCast;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gArraySize;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gConstIter;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gBeginFunctionConstNoexcept;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gDot;
    content += TextParsing::gBegin;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gConstIter;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gEndFunctionConstNoexcept;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gDot;
    content += TextParsing::gEnd;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateGetNestedArrayDefinition(const String& typeName, const JsonNode& jsonNode) const
{
    String content{};

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gCapitalConst;
    content += typeName;

    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gGetFirst;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gAtZero;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gCapitalConst;
    content += typeName;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += TextParsing::gKey;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gLambdaFunctionInit;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gGetIdLessReturn;

    content += TextParsing::gIndentation;
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gLowerBound;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gStdMakeShared;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gKeyFunction;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIfIter;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gCEndEqualKey;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnIter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gElse;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gThrowException;
    content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
    content += TextParsing::gDataSheet;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gFieldNotFind;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(jsonNode.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    for (const auto& value : jsonHead)
    {
        const auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        switch (const auto jsonDataType = value->GetJsonDataType();
                jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateGetDefinition(typeName, TextParsing::gSystemString, *value);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateIsDefinition(typeName, TextParsing::gBool, *value);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateGetDefinitionNoexcept(typeName, TextParsing::gInt, *value);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateGetDefinitionNoexcept(typeName, TextParsing::gInt64, *value);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateGetDefinitionNoexcept(typeName, TextParsing::gDouble, *value);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateGetNestedDefinition(typeName, *value);
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
                content += GenerateGetArrayDefinition(typeName, *value);
            }
            break;

            case JsonDataType::NestedArray:
            {
                content += GenerateGetNestedArrayDefinition(typeName, *value);
            }
            break;
            default:
                break;
        }
    }

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateContainerGetDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode, const JsonNode& container) const
{
    String content{};

    content += jsonType;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateContainerIsDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode, const JsonNode& container) const
{
    String content{};

    content += jsonType;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gIs;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateContainerGetDefinitionNoexcept(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode, const JsonNode& container) const
{
    String content{};

    content += jsonType;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateContainerGetNestedDefinition(const String& typeName, const JsonNode& jsonNode, const JsonNode& container) const
{
    String content{};

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gCapitalConst;
    content += typeName;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gSpace;
    content += TextParsing::gNoexcept;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateContainerGetArrayDefinition(const String& typeName, const JsonNode& jsonNode, const JsonNode& container) const
{
    String content{};

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gContainer;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gSize;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturnNumericCast;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gArraySize;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gConstIter;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gBeginFunctionConstNoexcept;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gDot;
    content += TextParsing::gBegin;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gConstIter;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gEndFunctionConstNoexcept;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gDot;
    content += TextParsing::gEnd;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateContainerGetNestedArrayDefinition(const String& typeName, const JsonNode& jsonNode, const JsonNode& container) const
{
    String content{};
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gCapitalConst;
    content += typeName;

    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gGetFirst;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gAtZero;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gCapitalConst;
    content += typeName;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += TextParsing::gKey;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSpace;
    content += TextParsing::gSmallConst;
    content += TextParsing::gNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gLambdaFunctionInit;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gGetIdLessReturn;

    content += TextParsing::gIndentation;
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gLowerBound;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gStdMakeShared;
    content += StringUtility::ToFirstLetterUpper(jsonHead.GetJsonClassName());
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(container.GetTypeName());
    content += TextParsing::gKeyFunction;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIfIter;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gCEndEqualKey;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnIter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gElse;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gThrowException;
    content += StringUtility::ToFirstLetterLower(jsonHead.GetJsonClassName());
    content += TextParsing::gDataSheet;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gFieldNotFind;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gSpace;
    content += jsonHead.GetCompleteClassName();
    content += TextParsing::gDoubleColon;
    content += StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());
    content += TextParsing::gDoubleColon;
    content += TextParsing::gGet;
    content += typeName;
    content += TextParsing::gContainer;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gConstNewline;

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserClassIsValidConst9;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gReturn;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(container.GetTypeName());
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateGetFunctionDefinition::GenerateDefinition(const JsonNode& jsonNode, const JsonNodeContainer& container) const
{
    String content{};

    for (const auto& value : container)
    {
        const auto typeName = StringUtility::ToFirstLetterUpper(value->GetTypeName());

        switch (const auto jsonDataType = value->GetJsonDataType();
                jsonDataType)
        {
            case JsonDataType::String:
            {
                content += GenerateContainerGetDefinition(typeName, TextParsing::gSystemString, jsonNode, *value);
            }
            break;
            case JsonDataType::Bool:
            {
                content += GenerateContainerIsDefinition(typeName, TextParsing::gBool, jsonNode, *value);
            }
            break;
            case JsonDataType::Int:
            {
                content += GenerateContainerGetDefinitionNoexcept(typeName, TextParsing::gInt, jsonNode, *value);
            }
            break;
            case JsonDataType::Int64:
            {
                content += GenerateContainerGetDefinitionNoexcept(typeName, TextParsing::gInt64, jsonNode, *value);
            }
            break;
            case JsonDataType::Double:
            {
                content += GenerateContainerGetDefinitionNoexcept(typeName, TextParsing::gDouble, jsonNode, *value);
            }
            break;
            case JsonDataType::Nested:
            {
                content += GenerateContainerGetNestedDefinition(typeName, jsonNode, *value);
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
                content += GenerateContainerGetArrayDefinition(typeName, jsonNode, *value);
            }
            break;
            case JsonDataType::NestedArray:
            {
                content += GenerateContainerGetNestedArrayDefinition(typeName, jsonNode, *value);
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
        if (const auto jsonDataType = value->GetJsonDataType();
            jsonDataType == JsonDataType::Nested || jsonDataType == JsonDataType::NestedArray)
        {
            container.AddJsonNode(value->GetJsonNodeContainer());
        }
        else if (!value->GetTypeName().empty())
        {
            container.AddJsonNode(value);
        }
    }

    content += GenerateDefinition(jsonNode, container);

    return content;
}

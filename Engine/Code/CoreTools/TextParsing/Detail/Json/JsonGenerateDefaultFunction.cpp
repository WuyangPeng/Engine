///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:25)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDefaultFunction.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

CoreTools::JsonGenerateDefaultFunction::JsonGenerateDefaultFunction(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateDefaultFunction)

System::String CoreTools::JsonGenerateDefaultFunction::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = jsonHead.GetJsonClassName();

    String content{ TextParsing::gIndentation };

    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gExplicit;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gContainer;
    content += TextParsing::gJsonRowParameter;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassInvariantDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunction::GenerateContainerDefaultFunction(const JsonNode& jsonNode)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName());

    String content{ TextParsing::gIndentation };

    content += TextParsing::gIndentation;
    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gExplicit;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gJsonRowParameter;
    content += TextParsing::gSemicolonNewline;

    if (jsonNode.GetJsonDataType() == JsonDataType::NestedArray)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gExplicit;
        content += TextParsing::gSpace;
        content += className;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gInt;
        content += TextParsing::gSpace;
        content += TextParsing::gIdSmall;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
        content += TextParsing::gSemicolonNewline;
    }

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassInvariantDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}

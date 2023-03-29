///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/14 14:50)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDefaultFunction.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

using namespace std::literals;

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
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("Container(const CoreTools::JsonRow& jsonRow);\n"s);
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
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::JsonRow& jsonRow);\n"s);

    if (jsonNode.GetJsonDataType() == JsonDataType::NestedArray)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("explicit "s);
        content += className;
        content += SYSTEM_TEXT("(int id) noexcept;\n"s);
    }

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassInvariantDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}

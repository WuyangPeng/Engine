///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:41)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDefaultFunction.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

using namespace std::literals;

CoreTools::JsonGenerateDefaultFunction::JsonGenerateDefaultFunction(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateDefaultFunction)

System::String CoreTools::JsonGenerateDefaultFunction::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = jsonHead.GetJsonClassName();

    String content{ TextParsing::g_Indentation };

    content += TextParsing::g_Public;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("Container(const CoreTools::JsonRow& jsonRow);\n"s);
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_ClassInvariantDeclare;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateDefaultFunction::GenerateContainerDefaultFunction(const JsonNode& jsonNode) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = StringConversion::ToFirstLetterUpper(jsonNode.GetTypeName());

    String content{ TextParsing::g_Indentation };

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Public;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::JsonRow& jsonRow);\n"s);

    if (jsonNode.GetJsonDataType() == JsonDataType::NestedArray)
    {
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("explicit "s);
        content += className;
        content += SYSTEM_TEXT("(int id);\n"s);
    }

    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_ClassInvariantDeclare;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

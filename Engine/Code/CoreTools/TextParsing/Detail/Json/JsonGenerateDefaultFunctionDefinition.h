///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:05)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateDefaultFunctionDefinition final
    {
    public:
        using ClassType = JsonGenerateDefaultFunctionDefinition;
        using String = System::String;
        using StringView = System::StringView;

    public:
        explicit JsonGenerateDefaultFunctionDefinition(JsonHead jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateDefinition() const;
        NODISCARD String GenerateDefinition(const JsonNode& jsonNode) const;

    private:
        NODISCARD String GenerateMemberListDefinition() const;

        NODISCARD String GenerateParsingDefinition(const String& nameSpace) const;

        NODISCARD String GenerateNestedArrayDefinition(const JsonNode& jsonNode, const String& nameSpace, const JsonNodeContainer& container, bool hasNestedArray) const;
        NODISCARD static String GenerateJsonRowDefinition(const JsonNodeContainer& container, bool& hasNestedArray);

        NODISCARD static String GenerateJsonRowGetDefinition(const JsonNode& jsonNode, const StringView& jsonRowGet);
        NODISCARD static String GenerateJsonRowGetNestedDefinition(const JsonNode& jsonNode);

        NODISCARD String GenerateParsingNestedArrayDefinition(const JsonNode& jsonNode) const;
        NODISCARD String GenerateIdConstructorDefinition(const JsonNode& jsonNode, const String& nameSpace, const JsonNodeContainer& container) const;
        NODISCARD String GenerateParsingDefinition(const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H
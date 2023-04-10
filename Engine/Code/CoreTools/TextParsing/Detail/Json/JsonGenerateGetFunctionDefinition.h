///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:05)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_GET_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_GET_FUNCTION_DEFINITION_H

#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateGetFunctionDefinition final
    {
    public:
        using ClassType = JsonGenerateGetFunctionDefinition;

        using String = System::String;
        using StringView = System::StringView;

    public:
        explicit JsonGenerateGetFunctionDefinition(JsonHead jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateDetailDefinition() const;
        NODISCARD String GenerateDetailDefinition(const String& className, const JsonNode& jsonNode) const;
        NODISCARD String GenerateDefinition() const;
        NODISCARD String GenerateDefinition(const JsonNode& jsonNode) const;

    private:
        NODISCARD String GenerateDetailNestedDefinition(const String& nameSpace, const JsonNode& jsonNode) const;
        NODISCARD String GenerateGetDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode) const;
        NODISCARD String GenerateIsDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode) const;
        NODISCARD String GenerateGetDefinitionNoexcept(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode) const;
        NODISCARD String GenerateGetNestedDefinition(const String& typeName, const JsonNode& jsonNode) const;
        NODISCARD String GenerateGetArrayDefinition(const String& typeName, const JsonNode& jsonNode) const;
        NODISCARD String GenerateGetNestedArrayDefinition(const String& typeName, const JsonNode& jsonNode) const;
        NODISCARD String GenerateDefinition(const JsonNode& jsonNode, const JsonNodeContainer& container) const;

        NODISCARD String GenerateContainerGetDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode, const JsonNode& container) const;
        NODISCARD String GenerateContainerIsDefinition(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode, const JsonNode& container) const;
        NODISCARD String GenerateContainerGetDefinitionNoexcept(const String& typeName, const StringView& jsonType, const JsonNode& jsonNode, const JsonNode& container) const;
        NODISCARD String GenerateContainerGetNestedDefinition(const String& typeName, const JsonNode& jsonNode, const JsonNode& container) const;
        NODISCARD String GenerateContainerGetArrayDefinition(const String& typeName, const JsonNode& jsonNode, const JsonNode& container) const;
        NODISCARD String GenerateContainerGetNestedArrayDefinition(const String& typeName, const JsonNode& jsonNode, const JsonNode& container) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_GET_FUNCTION_DEFINITION_H
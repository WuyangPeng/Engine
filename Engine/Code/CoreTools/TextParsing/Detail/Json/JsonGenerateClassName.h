///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/10 13:36)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_CLASS_NAME_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_CLASS_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateClassName final
    {
    public:
        using ClassType = JsonGenerateClassName;
        using String = System::String;

    public:
        explicit JsonGenerateClassName(JsonHead jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateContainerClassName() const;
        NODISCARD String GenerateUsing() const;
        NODISCARD static String GenerateContainerClassName(const JsonNode& jsonNode);
        NODISCARD static String GenerateUsing(const JsonNode& jsonNode);

    private:
        NODISCARD static String GenerateStringArrayUsing(const JsonNode& jsonNode, int indentationCount);
        NODISCARD static String GenerateBoolArrayUsing(const JsonNode& jsonNode, int indentationCount);
        NODISCARD static String GenerateIntArrayUsing(const JsonNode& jsonNode, int indentationCount);
        NODISCARD static String GenerateInt64ArrayUsing(const JsonNode& jsonNode, int indentationCount);
        NODISCARD static String GenerateDoubleArrayUsing(const JsonNode& jsonNode, int indentationCount);

        NODISCARD static String GenerateNestedUsing(const JsonNode& jsonNode, int indentationCount, const String& jsonClassName = String{});
        NODISCARD static String GenerateNestedArrayUsing(const JsonNode& jsonNode, int indentationCount, const String& jsonClassName = String{});

        NODISCARD static String GenerateArrayUsing(const JsonNode& jsonNode, int indentationCount, const String& usingDefinition);

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_CLASS_NAME_H
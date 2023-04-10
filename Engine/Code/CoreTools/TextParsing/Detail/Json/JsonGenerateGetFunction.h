///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:05)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_GET_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_GET_FUNCTION_H

#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateGetFunction final
    {
    public:
        using ClassType = JsonGenerateGetFunction;
        using String = System::String;
        using StringView = System::StringView;

    public:
        explicit JsonGenerateGetFunction(JsonHead jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateContainerFunction() const;
        NODISCARD static String GenerateContainerFunction(const JsonNode& jsonNode);

    private:
        NODISCARD static String GenerateParsingFunction(int indentationCount);
        NODISCARD static String GenerateContainerGetFunction(int indentationCount, const String& typeName, const String& getDescribe, const StringView& endDescribe);
        NODISCARD static String GenerateEndDescribe();
        NODISCARD static String GenerateGetDescribe(const StringView& typeName);
        NODISCARD static String GenerateIsDescribe(const StringView& typeName);
        NODISCARD static String GenerateNestedGetDescribe(const StringView& typeName);
        NODISCARD static String GenerateContainerArrayGetFunction(int indentationCount, const String& typeName);
        NODISCARD static String GenerateContainerNestedArrayGetFunction(int indentationCount, const String& typeName);
        NODISCARD static String GenerateNestedArrayFunction(int indentationCount, const JsonNode& jsonNode, bool& hasNested);

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_GET_FUNCTION_H
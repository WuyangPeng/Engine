///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:06)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_MEMBER_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_MEMBER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateMember final
    {
    public:
        using ClassType = JsonGenerateMember;
        using String = System::String;
        using StringView = System::StringView;

    public:
        explicit JsonGenerateMember(JsonHead jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateContainerMember() const;
        NODISCARD String GenerateContainerMember(const JsonNode& jsonNode) const;

    private:
        NODISCARD static String GenerateContainerMember(int indentationCount, const StringView& typeName, const JsonNode& jsonNode);
        NODISCARD String GenerateNestedContainerMember(int indentationCount, const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_MEMBER_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:06)

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
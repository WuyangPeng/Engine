///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:54)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_MEMBER_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_MEMBER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateMember final
    {
    public:
        using ClassType = JsonGenerateMember;
        using String = System::String;

    public:
        explicit JsonGenerateMember(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateContainerMember() const;
        NODISCARD String GenerateContainerMember(const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_MEMBER_H
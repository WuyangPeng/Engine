///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:07)

#ifndef CORE_TOOLS_TEXT_PARSING_BASE_MEMBER_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_BASE_MEMBER_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BaseMemberParsing final : public Parsing
    {
    public:
        using ClassType = BaseMemberParsing;
        using ParentType = Parsing;

    public:
        BaseMemberParsing() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateBaseMember(const String& keyTypeDescribe) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BASE_MEMBER_PARSING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:15)

#ifndef CORE_TOOLS_TEXT_PARSING_CHILD_MEMBER_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CHILD_MEMBER_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ChildMemberParsing final : public Parsing
    {
    public:
        using ClassType = ChildMemberParsing;
        using ParentType = Parsing;

    public:
        explicit ChildMemberParsing(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateChildMember() const;

    private:
        NODISCARD String GenerateMember() const;

    private:
        CSVHead csvHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CHILD_MEMBER_PARSING_H
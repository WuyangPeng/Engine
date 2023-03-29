///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/08 18:10)

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
        explicit ChildMemberParsing(CSVHead csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateChildMember() const;

    private:
        NODISCARD String GenerateMember() const;

    private:
        CSVHead csvHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CHILD_MEMBER_PARSING_H
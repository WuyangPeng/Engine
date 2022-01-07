///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:11)

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

        NODISCARD String GenerateBaseMember() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BASE_MEMBER_PARSING_H
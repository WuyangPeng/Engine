///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_MEMBER_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_MEMBER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateMember final
    {
    public:
        using ClassType = CSVGenerateMember;
        using String = System::String;

    public:
        CSVGenerateMember(CSVHead csvHead, String suffix) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static String GenerateBaseMember();
        NODISCARD String GenerateChildMember() const;
        NODISCARD String GenerateContainerMember() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_MEMBER_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/11/04 23:08)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_MEMBER_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_MEMBER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateMember final
    {
    public:
        using ClassType = CSVGenerateMember;
        using String = System::String;

    public:
        explicit CSVGenerateMember(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseMember() const;
        NODISCARD String GenerateChildMember() const;
        NODISCARD String GenerateContainerMember() const;
        NODISCARD String GenerateUniqueContainerMember() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_MEMBER_H
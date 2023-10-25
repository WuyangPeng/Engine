///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 14:08)

#ifndef CORE_TOOLS_TEXT_PARSING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE Parsing
    {
    public:
        using ClassType = Parsing;

        using String = System::String;
        using StringView = System::StringView;
        using SplitType = std::vector<String>;

    public:
        Parsing() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD static SplitType GetSplitComma(const String& column);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_PARSING_H
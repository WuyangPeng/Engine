/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 18:05)

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
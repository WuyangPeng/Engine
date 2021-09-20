///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/29 22:22)

#ifndef BOOK_WINDOWS_API_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_WINDOWS_API_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookOperatingSystem/BookWindowsAPI/BookWindowsAPIDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookWindowsAPI
{
    class BOOK_WINDOWS_API_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_WINDOWS_API_PLACEHOLDER_PLACEHOLDER_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 21:35)

#ifndef BOOK_DEBUGGING_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_DEBUGGING_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookOperatingSystem/BookDebugging/BookDebuggingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookDebugging
{
    class BOOK_DEBUGGING_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_DEBUGGING_PLACEHOLDER_PLACEHOLDER_H

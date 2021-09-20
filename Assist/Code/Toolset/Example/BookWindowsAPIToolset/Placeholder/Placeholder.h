///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/23 22:41)

#ifndef BOOK_WINDOWS_API_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_WINDOWS_API_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookWindowsAPIToolset/BookWindowsAPIToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookWindowsAPIToolset
{
    class BOOK_WINDOWS_API_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_WINDOWS_API_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

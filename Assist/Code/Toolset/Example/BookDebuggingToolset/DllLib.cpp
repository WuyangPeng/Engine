///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 19:33)

#include "Toolset/Example/BookDebuggingToolset/BookDebuggingToolsetExport.h"

#include "BookDebuggingToolset.h"

#ifndef BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

namespace BookDebuggingToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

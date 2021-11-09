///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 21:34)

#include "Example/BookOperatingSystem/BookDebugging/BookDebuggingExport.h"

#include "BookDebugging.h"

#ifndef BUILDING_BOOK_DEBUGGING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_DEBUGGING_STATIC

namespace BookDebugging
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_DEBUGGING_STATIC

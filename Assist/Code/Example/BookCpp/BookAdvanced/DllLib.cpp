///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/09 22:11)

#include "Example/BookCpp/BookAdvanced/BookAdvancedExport.h"

#include "BookAdvanced.h"

#ifndef BUILDING_BOOK_ADVANCED_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ADVANCED_STATIC

namespace BookAdvanced
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ADVANCED_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/25 20:44)

#include "Example/BookCpp/BookStandardLibrary/BookStandardLibraryExport.h"

#include "BookStandardLibrary.h"

#ifndef BUILDING_BOOK_STANDARD_LIBRARY_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_STANDARD_LIBRARY_STATIC

namespace BookStandardLibrary
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_STANDARD_LIBRARY_STATIC

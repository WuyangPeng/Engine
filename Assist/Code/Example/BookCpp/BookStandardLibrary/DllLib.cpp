///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/25 20:44)

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

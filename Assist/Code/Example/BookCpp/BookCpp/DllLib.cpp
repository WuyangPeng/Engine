///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/19 21:23)

#include "Example/BookCpp/BookCpp/BookCppExport.h"

#include "BookCpp.h"

#ifndef BUILDING_BOOK_CPP_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_CPP_STATIC

namespace BookCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_CPP_STATIC

///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/21 20:49)

#include "Example/BookCpp/BookPrimary/BookPrimaryExport.h"

#include "BookPrimary.h"

#ifndef BUILDING_BOOK_PRIMARY_STATIC

    #include "DllLib.h"

#else  // BUILDING_BOOK_PRIMARY_STATIC

namespace BookPrimary
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_PRIMARY_STATIC

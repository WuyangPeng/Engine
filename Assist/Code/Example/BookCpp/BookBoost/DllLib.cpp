///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/21 19:14)

#include "Example/BookCpp/BookBoost/BookBoostExport.h"

#include "BookBoost.h" 

#ifndef BUILDING_BOOK_BOOST_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_BOOST_STATIC

namespace BookBoost
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_BOOST_STATIC

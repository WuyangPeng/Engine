///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 20:45)

#include "Toolset/Example/BookBoostToolset/BookBoostToolsetExport.h"

#include "BookBoostToolset.h"

#ifndef BUILDING_BOOK_BOOST_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_BOOST_TOOLSET_STATIC

namespace BookBoostToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_BOOST_TOOLSET_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/04 23:12)

#include "Toolset/Example/BookPrimaryToolset/BookPrimaryToolsetExport.h"

#include "BookPrimaryToolset.h"

#ifndef BUILDING_BOOK_PRIMARY_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_PRIMARY_TOOLSET_STATIC

namespace BookPrimaryToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_PRIMARY_TOOLSET_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/12 0:06)

#include "Toolset/Example/BookACEToolset/BookACEToolsetExport.h"

#include "BookACEToolset.h"

#ifndef BUILDING_BOOK_ACE_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ACE_TOOLSET_STATIC

namespace BookACEToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ACE_TOOLSET_STATIC

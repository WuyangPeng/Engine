///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/24 20:51)

#include "Toolset/Example/BookLinuxToolset/BookLinuxToolsetExport.h"

#include "BookLinuxToolset.h"

#ifndef BUILDING_BOOK_LINUX_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_LINUX_TOOLSET_STATIC

namespace BookLinuxToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_LINUX_TOOLSET_STATIC

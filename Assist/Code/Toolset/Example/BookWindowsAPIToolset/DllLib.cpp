///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/23 22:40)

#include "Toolset/Example/BookWindowsAPIToolset/BookWindowsAPIToolsetExport.h"

#include "BookWindowsAPIToolset.h"

#ifndef BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC

namespace BookWindowsAPIToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC

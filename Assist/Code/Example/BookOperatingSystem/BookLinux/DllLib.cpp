///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/21 14:31)

#include "Example/BookOperatingSystem/BookLinux/BookLinuxExport.h"

#include "BookLinux.h"

#ifndef BUILDING_BOOK_LINUX_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_LINUX_STATIC

namespace BookLinux
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_LINUX_STATIC
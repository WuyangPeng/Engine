///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/24 20:47)

#include "Example/BookOperatingSystem/BookOperatingSystem/BookOperatingSystemExport.h"

#include "BookOperatingSystem.h"

#ifndef BUILDING_BOOK_OPERATING_SYSTEM_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_OPERATING_SYSTEM_STATIC

namespace BookOperatingSystem
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_OPERATING_SYSTEM_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 21:34)

#include "Example/BookOperatingSystem/BookDebugging/BookDebuggingExport.h"

#include "BookDebugging.h"

#ifndef BUILDING_BOOK_DEBUGGING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_DEBUGGING_STATIC

namespace BookDebugging
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_DEBUGGING_STATIC

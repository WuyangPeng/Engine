///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/26 23:04)

#include "Example/BookOperatingSystem/BookConcurrentProgramming/BookConcurrentProgrammingExport.h"

#include "BookConcurrentProgramming.h"

#ifndef BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

namespace BookConcurrentProgramming
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

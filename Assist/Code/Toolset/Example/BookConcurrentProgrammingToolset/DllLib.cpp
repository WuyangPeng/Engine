///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/02 22:35)

#include "Toolset/Example/BookConcurrentProgrammingToolset/BookConcurrentProgrammingToolsetExport.h"

#include "BookConcurrentProgrammingToolset.h"

#ifndef BUILDING_BOOK_CONCURRENT_PROGRAMMING_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_CONCURRENT_PROGRAMMING_TOOLSET_STATIC

namespace BookConcurrentProgrammingToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_CONCURRENT_PROGRAMMING_TOOLSET_STATIC

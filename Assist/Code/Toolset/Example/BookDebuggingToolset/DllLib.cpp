///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 19:33)

#include "Toolset/Example/BookDebuggingToolset/BookDebuggingToolsetExport.h"

#include "BookDebuggingToolset.h"

#ifndef BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

namespace BookDebuggingToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/24 16:24)

#include "Toolset/Example/BookIntermediateToolset/BookIntermediateToolsetExport.h"

#include "BookIntermediateToolset.h"

#ifndef BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

namespace BookIntermediateToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

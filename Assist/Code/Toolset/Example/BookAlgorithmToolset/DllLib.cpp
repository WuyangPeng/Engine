///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/15 1:02)

#include "Toolset/Example/BookAlgorithmToolset/BookAlgorithmToolsetExport.h"

#include "BookAlgorithmToolset.h"

#ifndef BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

namespace BookAlgorithmToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

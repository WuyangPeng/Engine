///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/25 23:57)

#include "Example/BookCpp/BookAlgorithm/BookAlgorithmExport.h"

#include "BookAlgorithm.h"

#ifndef BUILDING_BOOK_ALGORITHM_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ALGORITHM_STATIC

namespace BookAlgorithm
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ALGORITHM_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:57)

#include "Example/BookCpp/Algorithms/AlgorithmsExport.h"

#include "Algorithms.h"

#ifndef BUILDING_ALGORITHMS_STATIC

    #include "DllLib.h"

#else  // BUILDING_ALGORITHMS_STATIC

namespace Algorithms
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ALGORITHMS_STATIC

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/HowToSolve/HowToSolveExport.h"

#include "HowToSolve.h"

#ifndef BUILDING_HOW_TO_SOLVE_STATIC

    #include "DllLib.h"

#else  // BUILDING_HOW_TO_SOLVE_STATIC

namespace HowToSolve
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_HOW_TO_SOLVE_STATIC

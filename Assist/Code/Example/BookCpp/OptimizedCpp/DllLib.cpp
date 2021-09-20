///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/13 23:17)

#include "Example/BookCpp/OptimizedCpp/OptimizedCppExport.h"

#include "OptimizedCpp.h"

#ifndef BUILDING_OPTIMIZED_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_OPTIMIZED_CPP_STATIC

namespace OptimizedCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_OPTIMIZED_CPP_STATIC

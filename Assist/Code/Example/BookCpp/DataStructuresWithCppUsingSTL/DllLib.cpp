///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/DataStructuresWithCppUsingSTL/DataStructuresWithCppUsingSTLExport.h"

#include "DataStructuresWithCppUsingSTL.h"

#ifndef BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

namespace DataStructuresWithCppUsingSTL
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

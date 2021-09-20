///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/CppSTL/CppSTLExport.h"

#include "CppSTL.h"

#ifndef BUILDING_CPP_STL_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_STL_STATIC

namespace CppSTL
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_STL_STATIC

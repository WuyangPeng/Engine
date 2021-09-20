///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/02/28 19:36)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "ExtendedSTL.h"

#ifndef BUILDING_EXTENDED_STL_STATIC

    #include "DllLib.h"

#else  // BUILDING_EXTENDED_STL_STATIC

namespace ExtendedSTL
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EXTENDED_STL_STATIC

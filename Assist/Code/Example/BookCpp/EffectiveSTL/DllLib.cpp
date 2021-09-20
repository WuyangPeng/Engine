///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:45)

#include "Example/BookCpp/EffectiveSTL/EffectiveSTLExport.h"

#include "EffectiveSTL.h"

#ifndef BUILDING_EFFECTIVE_STL_STATIC

    #include "DllLib.h"

#else  // BUILDING_EFFECTIVE_STL_STATIC

namespace EffectiveSTL
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EFFECTIVE_STL_STATIC

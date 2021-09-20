///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:45)

#include "Example/BookCpp/MoreEffectiveCpp/MoreEffectiveCppExport.h"

#include "MoreEffectiveCpp.h"

#ifndef BUILDING_MORE_EFFECTIVE_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_MORE_EFFECTIVE_CPP_STATIC

namespace MoreEffectiveCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MORE_EFFECTIVE_CPP_STATIC

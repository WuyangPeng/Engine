///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/14 10:21)

#include "Interface/InterfaceExport.h"

#include "Interface/Interface.h"

#ifndef BUILDING_ACTIVITY_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ACTIVITY_STATIC

namespace Interface
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ACTIVITY_STATIC

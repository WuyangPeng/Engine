///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:53)

#include "Instance/InstanceExport.h"

#include "Instance/Instance.h"

#ifndef BUILDING_INSTANCE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_INSTANCE_STATIC

namespace Instance
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INSTANCE_STATIC

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.9.0.12 (2023/06/17 15:08)

#include "WorldServerMiddleLayerExport.h"

#include "DllLib.h"
#include "WorldServerMiddleLayer.h"

#ifdef BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

namespace WorldServerMiddleLayer
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

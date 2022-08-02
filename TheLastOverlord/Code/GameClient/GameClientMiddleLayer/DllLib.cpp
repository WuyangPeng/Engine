///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/20 10:55)

#include "GameClientMiddleLayerExport.h"

#include "DllLib.h"
#include "GameClientMiddleLayer.h"

#ifdef BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

namespace GameClientMiddleLayer
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC
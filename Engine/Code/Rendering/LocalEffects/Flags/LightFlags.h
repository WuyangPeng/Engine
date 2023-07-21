///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 14:59)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_FLAGS_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class LightType
    {
        Ambient,
        Directional,
        Point,
        Spot,
        Quantity
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_FLAGS_H

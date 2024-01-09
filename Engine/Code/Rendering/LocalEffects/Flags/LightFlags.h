/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 19:07)

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

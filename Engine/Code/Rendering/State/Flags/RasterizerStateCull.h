///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/04 20:37)

#ifndef RENDERING_STATE_RASTERIZER_STATE_CULL_H
#define RENDERING_STATE_RASTERIZER_STATE_CULL_H

#include "System/Helper/EnumMacro.h"

namespace Rendering
{
    enum class RasterizerStateCull
    {
        None,
        Front,
        Back,

        Count,
    };
}

#endif  // RENDERING_STATE_RASTERIZER_STATE_CULL_H

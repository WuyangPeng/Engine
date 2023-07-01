///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:06)

#ifndef RENDERING_STATE_RASTERIZER_STATE_CULL_H
#define RENDERING_STATE_RASTERIZER_STATE_CULL_H

#include "System/Helper/EnumOperator.h"

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

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:25)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_OPERATION_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_OPERATION_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class DepthStencilStateOperation
    {
        Keep,
        Zero,
        Replace,
        IncreaseSat,
        DecreaseSat,
        Invert,
        Increase,
        Decrease,

        Count
    };
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_OPERATION_H

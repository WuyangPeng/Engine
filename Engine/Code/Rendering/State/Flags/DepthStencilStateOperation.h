///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/18 18:56)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_OPERATION_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_OPERATION_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace Rendering
{
    enum class DepthStencilStateOperation
    {
        Keep,
        Zero,
        Replace,
        IncrSat,
        DecrSat,
        Invert,
        Incr,
        Decr
    };
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_OPERATION_H

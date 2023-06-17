///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:24)

#ifndef RENDERING_STATE_BLEND_STATE_COLOR_WRITE_H
#define RENDERING_STATE_BLEND_STATE_COLOR_WRITE_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class BlendStateColorWrite
    {
        Disenable = 0,
        EnableRed = (1 << 0),
        EnableGreen = (1 << 1),
        EnableBlue = (1 << 2),
        EnableAlpha = (1 << 3),
        EnableAll = EnableRed | EnableGreen | EnableBlue | EnableAlpha
    };

}

#endif  // RENDERING_STATE_BLEND_STATE_COLOR_WRITE_H

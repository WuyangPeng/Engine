///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/18 17:10)

#ifndef RENDERING_STATE_BLEND_STATE_COLOR_WRITE_H
#define RENDERING_STATE_BLEND_STATE_COLOR_WRITE_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace Rendering
{
    enum class BlendStateColorWrite
    {
        EnableRed = 1,
        EnableGreen = 2,
        EnableBlue = 4,
        EnableAlpha = 8,
        EnableAll = 15
    };
}

#endif  // RENDERING_STATE_BLEND_STATE_COLOR_WRITE_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 17:10)

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

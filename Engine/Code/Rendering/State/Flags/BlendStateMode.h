///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/02 22:25)

#ifndef RENDERING_STATE_BLEND_STATE_MODE_H
#define RENDERING_STATE_BLEND_STATE_MODE_H

#include "System/Helper/EnumMacro.h"

namespace Rendering
{
    enum class BlendStateMode
    {
        Zero,
        One,
        SourceColor,
        OneMinusSourceColor,
        SourceAlpha,
        OneMinusSourceAlpha,
        DestinationAlpha,
        OneMinusDestinationAlpha,
        DestinationColor,
        OneMinusDestinationColor,
        SourceAlphaSaturate,
        ConstantColor,
        OneMinusConstantColor,
        Source1Color,
        OneMinusSource1Color,
        Source1Alpha,
        OneMinusSource1Alpha,

        Count,
    };
}

#endif  // RENDERING_STATE_BLEND_STATE_MODE_H

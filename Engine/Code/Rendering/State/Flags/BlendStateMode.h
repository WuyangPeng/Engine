///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:24)

#ifndef RENDERING_STATE_BLEND_STATE_MODE_H
#define RENDERING_STATE_BLEND_STATE_MODE_H

#include "System/Helper/EnumOperator.h"

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

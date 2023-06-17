///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:25)

#ifndef RENDERING_STATE_SAMPLER_STATE_MODE_H
#define RENDERING_STATE_SAMPLER_STATE_MODE_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class SamplerStateMode
    {
        Wrap,
        Mirror,
        Clamp,
        Border,
        MirrorOnce,

        Count,
    };
}

#endif  // RENDERING_STATE_SAMPLER_STATE_MODE_H

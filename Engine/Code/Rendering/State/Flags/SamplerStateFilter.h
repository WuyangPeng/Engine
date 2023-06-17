///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:25)

#ifndef RENDERING_STATE_SAMPLER_STATE_FILTER_H
#define RENDERING_STATE_SAMPLER_STATE_FILTER_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class SamplerStateFilter
    {
        MinPMagPMipP,
        MinPMagPMipL,
        MinPMagLMipP,
        MinPMagLMipL,
        MinLMagPMipP,
        MinLMagPMipL,
        MinLMagLMipP,
        MinLMagLMipL,
        Anisotropic,

        ComparisonMinPMagPMipP,
        ComparisonMinPMagPMipL,
        ComparisonMinPMagLMipP,
        ComparisonMinPMagLMipL,
        ComparisonMinLMagPMipP,
        ComparisonMinLMagPMipL,
        ComparisonMinLMagLMipP,
        ComparisonMinLMagLMipL,
        ComparisonAnisotropic
    };
}

#endif  // RENDERING_STATE_SAMPLER_STATE_FILTER_H

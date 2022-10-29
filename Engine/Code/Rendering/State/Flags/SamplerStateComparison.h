///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/19 0:35)

#ifndef RENDERING_STATE_SAMPLER_STATE_COMPARISON_H
#define RENDERING_STATE_SAMPLER_STATE_COMPARISON_H

#include "System/Helper/EnumMacro.h"

namespace Rendering
{
    enum class SamplerStateComparison
    {
        Never,
        Less,
        Equal,
        LessEqual,
        Greater,
        NotEqual,
        GreaterEqual,
        Always
    };
}

#endif  // RENDERING_STATE_SAMPLER_STATE_COMPARISON_H

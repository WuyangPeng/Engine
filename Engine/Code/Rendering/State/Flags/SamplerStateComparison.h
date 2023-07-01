///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 11:06)

#ifndef RENDERING_STATE_SAMPLER_STATE_COMPARISON_H
#define RENDERING_STATE_SAMPLER_STATE_COMPARISON_H

#include "System/Helper/EnumOperator.h"

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

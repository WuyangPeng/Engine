///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/02 22:26)

#ifndef RENDERING_STATE_BLEND_STATE_OPERATION_H
#define RENDERING_STATE_BLEND_STATE_OPERATION_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class BlendStateOperation
    {
        Add,
        Subtract,
        ReverseSubtract,
        Min,
        Max,

        Count,
    };
}

#endif  // RENDERING_STATE_BLEND_STATE_OPERATION_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/04 16:09)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_WRITE_MASK_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_WRITE_MASK_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class DepthStencilStateWriteMask
    {
        Zero,
        All,

        Count
    };
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_WRITE_MASK_H

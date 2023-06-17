///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:25)

#ifndef RENDERING_STATE_RASTERIZER_STATE_FILL_H
#define RENDERING_STATE_RASTERIZER_STATE_FILL_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class RasterizerStateFill
    {
        Solid,
        Wireframe,

        Count,
    };
}

#endif  // RENDERING_STATE_RASTERIZER_STATE_FILL_H

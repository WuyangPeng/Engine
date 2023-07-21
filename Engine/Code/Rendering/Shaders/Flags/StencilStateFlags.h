///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:42)

#ifndef RENDERING_SHADERS_STENCIL_STATE_FLAGS_H
#define RENDERING_SHADERS_STENCIL_STATE_FLAGS_H

namespace Rendering::StencilStateFlags
{
    enum class CompareMode
    {
        Never,
        Less,
        Equal,
        LessEqual,
        Greater,
        NotEqual,
        GreaterEqual,
        Always,
        Quantity
    };

    enum class OperationType
    {
        Keep,
        Zero,
        Replace,
        Increment,
        Decrement,
        Invert,
        Quantity
    };
}

#endif  // RENDERING_SHADERS_STENCIL_STATE_FLAGS_H

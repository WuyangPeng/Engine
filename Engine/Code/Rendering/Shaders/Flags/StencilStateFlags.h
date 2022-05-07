///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 13:39)

#ifndef RENDERING_SHADERS_STENCIL_STATE_FLAGS_H
#define RENDERING_SHADERS_STENCIL_STATE_FLAGS_H

namespace Rendering
{
    namespace StencilStateFlags
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
}

#endif  // RENDERING_SHADERS_STENCIL_STATE_FLAGS_H

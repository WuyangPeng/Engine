///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/01 14:55)

#ifndef RENDERING_SHADERS_DEPTH_STATE_FLAGS_H
#define RENDERING_SHADERS_DEPTH_STATE_FLAGS_H

namespace Rendering::DepthStateFlags
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
}

#endif  // RENDERING_SHADERS_DEPTH_STATE_FLAGS_H

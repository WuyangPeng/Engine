/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:07)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_COMPARISON_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_COMPARISON_H

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class DepthStencilStateComparison
    {
        Never,
        Less,
        Equal,
        LessEqual,
        Greater,
        NotEqual,
        GreaterEqual,
        Always,

        Count
    };
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_COMPARISON_H

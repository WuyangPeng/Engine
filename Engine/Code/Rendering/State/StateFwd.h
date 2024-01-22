/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:06)

#ifndef RENDERING_STATE_FWD_H
#define RENDERING_STATE_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

namespace Rendering
{
    class DrawingState;
    class BlendStateTarget;
    class BlendState;
    class DepthStencilStateFace;
    class DepthStencilState;
    class RasterizerState;
    class SamplerState;

    CORE_TOOLS_SHARED_PTR_DECLARE(DrawingState);
    CORE_TOOLS_SHARED_PTR_DECLARE(BlendStateTarget);
    CORE_TOOLS_SHARED_PTR_DECLARE(BlendState);
    CORE_TOOLS_SHARED_PTR_DECLARE(DepthStencilStateFace);
    CORE_TOOLS_SHARED_PTR_DECLARE(DepthStencilState);
    CORE_TOOLS_SHARED_PTR_DECLARE(RasterizerState);
    CORE_TOOLS_SHARED_PTR_DECLARE(SamplerState);

    class GlobalState;

    enum class BlendStateColorWrite;
    enum class BlendStateMode;
    enum class BlendStateOperation;

    enum class DepthStencilStateComparison;
    enum class DepthStencilStateOperation;
    enum class DepthStencilStateWriteMask;

    enum class RasterizerStateCull;
    enum class RasterizerStateFill;

    enum class SamplerStateComparison;
    enum class SamplerStateFilter;
    enum class SamplerStateMode;
}

#endif  // RENDERING_STATE_FWD_H
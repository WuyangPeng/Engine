///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:26)

#ifndef RENDERING_STATE_FWD_H
#define RENDERING_STATE_FWD_H

namespace Rendering
{
    class DrawingState;
    class BlendStateTarget;
    class BlendState;
    class DepthStencilStateFace;
    class DepthStencilState;
    class RasterizerState;
    class SamplerState;

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
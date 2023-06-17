///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RASTERIZER_STATE_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RASTERIZER_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLRasterizerStateImpl
    {
    public:
        using ClassType = OpenGLRasterizerStateImpl;
        using OpenGLFrontFace = System::OpenGLFrontFace;
        using RasterizerStateCullFace = System::RasterizerStateCullFace;
        using RasterizerStateFillMode = System::RasterizerStateFillMode;

    public:
        OpenGLRasterizerStateImpl() noexcept;
        explicit OpenGLRasterizerStateImpl(const RasterizerState& rasterizerState);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static System::RasterizerStateFillMode GetRasterizerStateFillMode(RasterizerStateFill rasterizerStateFill);
        NODISCARD static System::RasterizerStateCullFace GetRasterizerStateCullFace(RasterizerStateCull rasterizerStateCull);

        NODISCARD RasterizerStateFillMode GetFillMode() const noexcept;
        NODISCARD RasterizerStateCullFace GetCullFace() const noexcept;
        NODISCARD OpenGLFrontFace GetFrontFace() const noexcept;
        NODISCARD float GetDepthScale() const noexcept;
        NODISCARD float GetDepthBias() const noexcept;
        NODISCARD bool IsEnableScissor() const noexcept;

    private:
        RasterizerStateFillMode fillMode;
        RasterizerStateCullFace cullFace;
        OpenGLFrontFace frontFace;
        float depthScale;
        float depthBias;
        bool enableScissor;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_RASTERIZER_STATE_IMPL_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/26 18:22)

#ifndef RENDERING_RENDERERS_OPENGL_RENDERER_H
#define RENDERING_RENDERERS_OPENGL_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "RendererImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLRenderer : public RendererImpl
    {
    public:
        using ClassType = OpenGLRenderer;
        using ParentType = RendererImpl;

    public:
        explicit OpenGLRenderer(const RendererBasis& basis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        RendererTypes GetRendererType() const noexcept override;

        void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) noexcept override;

        void SetCullState(const ConstCullStateSharedPtr& cullState) noexcept override;

        void SetDepthState(const ConstDepthStateSharedPtr& depthState) noexcept override;

        void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) noexcept override;

        void SetStencilState(const ConstStencilStateSharedPtr& stencilState) noexcept override;

        void SetWireState(const ConstWireStateSharedPtr& wireState) noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;

        Viewport GetViewport() const override;

        void SetDepthRange(const DepthRange& depthRange) noexcept override;

        DepthRange GetDepthRange() const override;

        void Resize(int width, int height) noexcept override;

        void ClearColorBuffer() noexcept override;

        void ClearDepthBuffer() noexcept override;

        void ClearStencilBuffer() noexcept override;

        void ClearBuffers() noexcept override;

        void ClearColorBuffer(int x, int y, int w, int h) noexcept override;

        void ClearDepthBuffer(int x, int y, int w, int h) noexcept override;

        void ClearStencilBuffer(int x, int y, int w, int h) noexcept override;

        void ClearBuffers(int x, int y, int w, int h) noexcept override;

        void DisplayColorBuffer() noexcept override;

        void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha) override;

        bool PreDraw() noexcept override;

        void PostDraw() noexcept override;

        void Draw(const uint8_t* screenBuffer, bool reflectY) noexcept override;

        void Draw(int x, int y, const Colour& color, const std::string& message) noexcept override;

    private:
        void DrawPrimitive(const ConstVisualSharedPtr& visual) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_RENDERER_H

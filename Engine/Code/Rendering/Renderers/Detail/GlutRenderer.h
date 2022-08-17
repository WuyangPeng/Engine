///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:14)

#ifndef RENDERING_RENDERERS_GLUT_RENDERER_H
#define RENDERING_RENDERERS_GLUT_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "RendererImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlutRenderer : public RendererImpl
    {
    public:
        using ClassType = GlutRenderer;
        using ParentType = RendererImpl;

    public:
        explicit GlutRenderer(const RendererBasis& basis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept override;

        void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) noexcept override;

        void SetCullState(const ConstCullStateSharedPtr& cullState) noexcept override;

        void SetDepthState(const ConstDepthStateSharedPtr& depthState) noexcept override;

        void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) noexcept override;

        void SetStencilState(const ConstStencilStateSharedPtr& stencilState) noexcept override;

        void SetWireState(const ConstWireStateSharedPtr& wireState) noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;

        NODISCARD Viewport GetViewport() const override;

        void SetDepthRange(const DepthRange& depthRange) noexcept override;

        NODISCARD DepthRange GetDepthRange() const override;

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

        NODISCARD bool PreDraw() noexcept override;

        void PostDraw() noexcept override;

        void Draw(const uint8_t* screenBuffer, bool reflectY) noexcept override;

        void Draw(int x, int y, const Colour& color, const std::string& message) noexcept override;

        NODISCARD bool HasDepthRange01() const noexcept override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        void DisplayColorBuffer(int syncInterval) noexcept override;

        void SetBlendState(const BlendStateSharedPtr& state) override;
        void SetDepthStencilState(const DepthStencilStateSharedPtr& state) override;
        void SetRasterizerState(const RasterizerStateSharedPtr& state) override;
        NODISCARD bool Update(const BufferSharedPtr& buffer) override;
        NODISCARD bool Update(const TextureSharedPtr& texture) override;

    private:
        void DrawPrimitive(const ConstVisualSharedPtr& visual) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_GLUT_RENDERER_H

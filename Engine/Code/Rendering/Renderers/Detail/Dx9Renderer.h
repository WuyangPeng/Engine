///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 10:59)

#ifndef RENDERING_RENDERERS_DX9_RENDERER_H
#define RENDERING_RENDERERS_DX9_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "RendererImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9Renderer : public RendererImpl
    {
    public:
        using ClassType = Dx9Renderer;
        using ParentType = RendererImpl;

    public:
        explicit Dx9Renderer(const RendererBasis& basis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept override;

        void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) override;

        void SetCullState(const ConstCullStateSharedPtr& cullState) override;

        void SetDepthState(const ConstDepthStateSharedPtr& depthState) override;

        void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) override;

        void SetStencilState(const ConstStencilStateSharedPtr& stencilState) override;

        void SetWireState(const ConstWireStateSharedPtr& wireState) override;

        void SetViewport(const Viewport& viewport) override;

        NODISCARD Viewport GetViewport() const override;

        void SetDepthRange(const DepthRange& depthRange) override;

        NODISCARD DepthRange GetDepthRange() const override;

        void Resize(int width, int height) override;

        void ClearColorBuffer() override;

        void ClearDepthBuffer() override;

        void ClearStencilBuffer() override;

        void ClearBuffers() override;

        void ClearColorBuffer(int x, int y, int w, int h) override;

        void ClearDepthBuffer(int x, int y, int w, int h) override;

        void ClearStencilBuffer(int x, int y, int w, int h) override;

        void ClearBuffers(int x, int y, int w, int h) override;

        void DisplayColorBuffer() override;

        void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha) override;

        NODISCARD bool PreDraw() override;

        void PostDraw() override;

        void Draw(const uint8_t* screenBuffer, bool reflectY) override;

        void Draw(int x, int y, const Colour& color, const std::string& message) override;

        NODISCARD bool HasDepthRange01() const override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        void DisplayColorBuffer(int syncInterval) noexcept override;

        void SetBlendState(const BlendStateSharedPtr& state) override;
        void SetDepthStencilState(const DepthStencilStateSharedPtr& state) override;
        void SetRasterizerState(const RasterizerStateSharedPtr& state) override;
        NODISCARD bool Update(const BufferSharedPtr& buffer) override;
        NODISCARD bool Update(const TextureSharedPtr& texture) override;

    private:
        void DrawPrimitive(const ConstVisualSharedPtr& visual) override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_RENDERER_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:10)

#ifndef RENDERING_RENDERERS_OPENGL_ES_RENDERER_H
#define RENDERING_RENDERERS_OPENGL_ES_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "RendererImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLESRenderer : public RendererImpl
    {
    public:
        using ClassType = OpenGLESRenderer;
        using ParentType = RendererImpl;
       
    public:
        explicit OpenGLESRenderer(const RendererBasis& basis);
        
        CLASS_INVARIANT_OVERRIDE_DECLARE;

		  RendererTypes GetRendererType() const noexcept override;

		  void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) override;


		  void SetCullState(const ConstCullStateSharedPtr& cullState) override;


		  void SetDepthState(const ConstDepthStateSharedPtr& depthState) override;


		  void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) override;


		  void SetStencilState(const ConstStencilStateSharedPtr& stencilState) override;


		  void SetWireState(const ConstWireStateSharedPtr& wireState) override;


		  void SetViewport(const Viewport& viewport) override;


		  Viewport GetViewport() const override;


		  void SetDepthRange(const DepthRange& depthRange) override;


		  DepthRange GetDepthRange() const override;


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


		  bool PreDraw() override;


		  void PostDraw() override;


		  void Draw(const uint8_t* screenBuffer, bool reflectY) override;


		  void Draw(int x, int y, const Colour& color, const std::string& message) override;

	private:
		  void DrawPrimitive(const ConstVisualSharedPtr& visual) override;

	};
}

#endif // RENDERING_RENDERERS_OPENGL_ES_RENDERER_H

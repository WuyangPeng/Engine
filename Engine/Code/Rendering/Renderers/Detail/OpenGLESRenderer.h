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
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual RendererTypes GetRendererType() const override;

		virtual void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState) override;


		virtual void SetCullState(const ConstCullStateSmartPointer& cullState) override;


		virtual void SetDepthState(const ConstDepthStateSmartPointer& depthState) override;


		virtual void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState) override;


		virtual void SetStencilState(const ConstStencilStateSmartPointer& stencilState) override;


		virtual void SetWireState(const ConstWireStateSmartPointer& wireState) override;


		virtual void SetViewport(const Viewport& viewport) override;


		virtual Viewport GetViewport() const override;


		virtual void SetDepthRange(const DepthRange& depthRange) override;


		virtual DepthRange GetDepthRange() const override;


		virtual void Resize(int width, int height) override;


		virtual void ClearColorBuffer() override;


		virtual void ClearDepthBuffer() override;


		virtual void ClearStencilBuffer() override;


		virtual void ClearBuffers() override;


		virtual void ClearColorBuffer(int x, int y, int w, int h) override;


		virtual void ClearDepthBuffer(int x, int y, int w, int h) override;


		virtual void ClearStencilBuffer(int x, int y, int w, int h) override;


		virtual void ClearBuffers(int x, int y, int w, int h) override;


		virtual void DisplayColorBuffer() override;


		virtual void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha) override;


		virtual bool PreDraw() override;


		virtual void PostDraw() override;


		virtual void Draw(const uint8_t* screenBuffer, bool reflectY) override;


		virtual void Draw(int x, int y, const Colour& color, const std::string& message) override;

	private:
		virtual void DrawPrimitive(const ConstVisualSmartPointer& visual) override;

	};
}

#endif // RENDERING_RENDERERS_OPENGL_ES_RENDERER_H

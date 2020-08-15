// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../Flags/RendererTypes.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include "System/Helper/PragmaWarning/Disable4100.h"
Rendering::OpenGLRenderer
	::OpenGLRenderer(const RendererBasis& basis)
	:ParentType{ basis }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,OpenGLRenderer)

Rendering::RendererTypes Rendering::OpenGLRenderer
	::GetRendererType() const
{
	return RendererTypes::OpenGL;
}

void Rendering::OpenGLRenderer::SetAlphaState(const ConstAlphaStateSmartPointer& alphaState)
{
	alphaState;
}

void Rendering::OpenGLRenderer::SetCullState(const ConstCullStateSmartPointer& cullState)
{
	cullState;
}

void Rendering::OpenGLRenderer::SetDepthState(const ConstDepthStateSmartPointer& depthState)
{
	depthState;
}

void Rendering::OpenGLRenderer::SetOffsetState(const ConstOffsetStateSmartPointer& offsetState)
{
	offsetState;
}

void Rendering::OpenGLRenderer::SetStencilState(const ConstStencilStateSmartPointer& stencilState)
{
	stencilState;
}

void Rendering::OpenGLRenderer::SetWireState(const ConstWireStateSmartPointer& wireState)
{
	wireState;
}

void Rendering::OpenGLRenderer::SetViewport(const Viewport& viewport)
{
	viewport;
}

Rendering::Viewport Rendering::OpenGLRenderer::GetViewport() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::SetDepthRange(const DepthRange& depthRange)
{
	depthRange;
}

Rendering::DepthRange Rendering::OpenGLRenderer::GetDepthRange() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::Resize(int width, int height)
{
	width; height;
}

void Rendering::OpenGLRenderer::ClearColorBuffer()
{
	 
}

void Rendering::OpenGLRenderer::ClearDepthBuffer(int x, int y, int w, int h)
{
	x; y; w; h;
}

void Rendering::OpenGLRenderer::ClearStencilBuffer(int x, int y, int w, int h)
{
	x; y; w; h;
}

void Rendering::OpenGLRenderer::ClearBuffers(int x, int y, int w, int h)
{
	x; y; w; h;
}

void Rendering::OpenGLRenderer::DisplayColorBuffer()
{
	 
}

void Rendering::OpenGLRenderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLRenderer::PreDraw()
{
	return true;
}

void Rendering::OpenGLRenderer::PostDraw()
{
	 
}

void Rendering::OpenGLRenderer::Draw(const uint8_t* screenBuffer, bool reflectY)
{
	screenBuffer; reflectY;
}

void Rendering::OpenGLRenderer::DrawPrimitive(const ConstVisualSmartPointer& visual)
{
	visual;
}

void Rendering::OpenGLRenderer::Draw(int x, int y, const Colour& color, const std::string& message)
{
	x; y; color; message;
}

void Rendering::OpenGLRenderer::ClearDepthBuffer()
{
	 
}

void Rendering::OpenGLRenderer::ClearStencilBuffer()
{
 
}

void Rendering::OpenGLRenderer::ClearBuffers()
{
	 
}

void Rendering::OpenGLRenderer::ClearColorBuffer(int x, int y, int w, int h)
{
	x; y; w; h;
}
#include STSTEM_WARNING_POP
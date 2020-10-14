// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:26)

#include "Rendering/RenderingExport.h"

#include "GlutRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../Flags/RendererTypes.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include "System/Helper/PragmaWarning/Disable4100.h"
Rendering:: GlutRenderer
	:: GlutRenderer(const RendererBasis& basis)
    :ParentType(basis)
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GlutRenderer)

Rendering::RendererTypes Rendering::GlutRenderer
	::GetRendererType() const
{
	return RendererTypes::Glut;
}

void Rendering::GlutRenderer::SetAlphaState(const ConstAlphaStateSharedPtr& alphaState)
{
	alphaState;
}

void Rendering::GlutRenderer::SetCullState(const ConstCullStateSharedPtr& cullState)
{
	cullState;
}

void Rendering::GlutRenderer::SetDepthState(const ConstDepthStateSharedPtr& depthState)
{
	depthState;
}

void Rendering::GlutRenderer::SetOffsetState(const ConstOffsetStateSharedPtr& offsetState)
{
	offsetState;
}

void Rendering::GlutRenderer::SetStencilState(const ConstStencilStateSharedPtr& stencilState)
{
	stencilState;
}

void Rendering::GlutRenderer::SetWireState(const ConstWireStateSharedPtr& wireState)
{
	wireState;
}

void Rendering::GlutRenderer::SetViewport(const Viewport& viewport)
{
	viewport;
}

Rendering::Viewport Rendering::GlutRenderer::GetViewport() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::SetDepthRange(const DepthRange& depthRange)
{
	depthRange;
}

Rendering::DepthRange Rendering::GlutRenderer::GetDepthRange() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::Resize(int width, int height)
{
	width; height;
}

void Rendering::GlutRenderer::ClearColorBuffer()
{
	 
}

void Rendering::GlutRenderer::ClearDepthBuffer(int x, int y, int w, int h)
{
	x; y; w; h;
}

void Rendering::GlutRenderer::ClearStencilBuffer(int x, int y, int w, int h)
{
	x; y; w; h;
}

void Rendering::GlutRenderer::ClearBuffers(int x, int y, int w, int h)
{
	x; y; w; h;
}

void Rendering::GlutRenderer::DisplayColorBuffer()
{
	 
}

void Rendering::GlutRenderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GlutRenderer::PreDraw()
{
	return true;
}

void Rendering::GlutRenderer::PostDraw()
{
	 
}

void Rendering::GlutRenderer::Draw(const uint8_t* screenBuffer, bool reflectY)
{
	screenBuffer; reflectY;
}

void Rendering::GlutRenderer::DrawPrimitive(const ConstVisualSharedPtr& visual)
{
	visual;
}

void Rendering::GlutRenderer::Draw(int x, int y, const Colour& color, const std::string& message)
{
	x; y; color; message;
}

void Rendering::GlutRenderer::ClearDepthBuffer()
{
	 
}

void Rendering::GlutRenderer::ClearStencilBuffer()
{
	 
}

void Rendering::GlutRenderer::ClearBuffers()
{
	 
}

void Rendering::GlutRenderer::ClearColorBuffer(int x, int y, int w, int h)
{
	x; y; w; h;
}

#include STSTEM_WARNING_POP
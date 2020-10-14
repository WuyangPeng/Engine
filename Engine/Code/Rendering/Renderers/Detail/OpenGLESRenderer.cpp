// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLESRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../Flags/RendererTypes.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include "System/Helper/PragmaWarning/Disable4100.h"
Rendering::OpenGLESRenderer
	::OpenGLESRenderer(const RendererBasis& basis)
	:ParentType{ basis }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,OpenGLESRenderer)

Rendering::RendererTypes Rendering::OpenGLESRenderer
	::GetRendererType() const noexcept
{
	return RendererTypes::OpenGLES;
}

void Rendering::OpenGLESRenderer::SetAlphaState(const ConstAlphaStateSharedPtr& alphaState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetCullState(const ConstCullStateSharedPtr& cullState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetDepthState(const ConstDepthStateSharedPtr& depthState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetOffsetState(const ConstOffsetStateSharedPtr& offsetState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetStencilState(const ConstStencilStateSharedPtr& stencilState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetWireState(const ConstWireStateSharedPtr& wireState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetViewport(const Viewport& viewport)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Rendering::Viewport Rendering::OpenGLESRenderer::GetViewport() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetDepthRange(const DepthRange& depthRange)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Rendering::DepthRange Rendering::OpenGLESRenderer::GetDepthRange() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::Resize(int width, int height)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearColorBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearDepthBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearStencilBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearBuffers(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::DisplayColorBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLESRenderer::PreDraw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::PostDraw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::Draw(const uint8_t* screenBuffer, bool reflectY)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::DrawPrimitive(const ConstVisualSharedPtr& visual)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::Draw(int x, int y, const Colour& color, const std::string& message)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearDepthBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearStencilBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearBuffers()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearColorBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP
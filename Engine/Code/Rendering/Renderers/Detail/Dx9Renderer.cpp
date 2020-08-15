// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 17:24)

#include "Rendering/RenderingExport.h"

#include "Dx9Renderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../Flags/RendererTypes.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include "System/Helper/PragmaWarning/Disable4100.h"
Rendering::Dx9Renderer
	::Dx9Renderer(const RendererBasis& basis)
	:ParentType{ basis }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,Dx9Renderer)

Rendering::RendererTypes Rendering::Dx9Renderer
	::GetRendererType() const noexcept
{
	return RendererTypes::Dx9;
}

void Rendering::Dx9Renderer::SetAlphaState(const ConstAlphaStateSmartPointer& alphaState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetCullState(const ConstCullStateSmartPointer& cullState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetDepthState(const ConstDepthStateSmartPointer& depthState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetOffsetState(const ConstOffsetStateSmartPointer& offsetState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetStencilState(const ConstStencilStateSmartPointer& stencilState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetWireState(const ConstWireStateSmartPointer& wireState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetViewport(const Viewport& viewport)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Rendering::Viewport Rendering::Dx9Renderer::GetViewport() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetDepthRange(const DepthRange& depthRange)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Rendering::DepthRange Rendering::Dx9Renderer::GetDepthRange() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::Resize(int width, int height)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearColorBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearDepthBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearStencilBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearBuffers(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::DisplayColorBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::Dx9Renderer::PreDraw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::PostDraw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::Draw(const uint8_t* screenBuffer, bool reflectY)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::DrawPrimitive(const ConstVisualSmartPointer& visual)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::Draw(int x, int y, const Colour& color, const std::string& message)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearDepthBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearStencilBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearBuffers()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearColorBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}
#include STSTEM_WARNING_POP
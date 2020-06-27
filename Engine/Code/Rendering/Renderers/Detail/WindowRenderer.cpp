// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:12)

#include "Rendering/RenderingExport.h"

#include "WindowRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../RendererBasis.h"
#include "../Flags/RendererTypes.h"
#include "System/Helper/PragmaWarning/Disable4100.h"

Rendering:: WindowRenderer
	:: WindowRenderer(const RendererBasis& basis)
    :ParentType(basis)
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WindowRenderer)

Rendering::RendererTypes Rendering::WindowRenderer
	::GetRendererType() const
{
	return RendererTypes::Window;
}

void Rendering::WindowRenderer::SetAlphaState(const ConstAlphaStateSmartPointer& alphaState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetCullState(const ConstCullStateSmartPointer& cullState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetDepthState(const ConstDepthStateSmartPointer& depthState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetOffsetState(const ConstOffsetStateSmartPointer& offsetState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetStencilState(const ConstStencilStateSmartPointer& stencilState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetWireState(const ConstWireStateSmartPointer& wireState)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetViewport(const Viewport& viewport)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Rendering::Viewport Rendering::WindowRenderer::GetViewport() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetDepthRange(const DepthRange& depthRange)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Rendering::DepthRange Rendering::WindowRenderer::GetDepthRange() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::Resize(int width, int height)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearColorBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearDepthBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearStencilBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearBuffers(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::DisplayColorBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::WindowRenderer::PreDraw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::PostDraw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::Draw(const uint8_t* screenBuffer, bool reflectY)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::DrawPrimitive(const ConstVisualSmartPointer& visual)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::Draw(int x, int y, const Colour& color, const std::string& message)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearDepthBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearStencilBuffer()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearBuffers()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearColorBuffer(int x, int y, int w, int h)
{
	throw std::logic_error("The method or operation is not implemented.");
}


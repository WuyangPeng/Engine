///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 15:29)

#include "Rendering/RenderingExport.h"

#include "WindowRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererBasis.h"

Rendering::WindowRenderer::WindowRenderer(const RendererBasis& basis)
    : ParentType{ basis }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WindowRenderer)

Rendering::RendererTypes Rendering::WindowRenderer::GetRendererType() const noexcept
{
    return RendererTypes::Window;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::WindowRenderer::SetAlphaState(MAYBE_UNUSED const ConstAlphaStateSharedPtr& alphaState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetCullState(MAYBE_UNUSED const ConstCullStateSharedPtr& cullState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetDepthState(MAYBE_UNUSED const ConstDepthStateSharedPtr& depthState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetOffsetState(MAYBE_UNUSED const ConstOffsetStateSharedPtr& offsetState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetStencilState(MAYBE_UNUSED const ConstStencilStateSharedPtr& stencilState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetWireState(MAYBE_UNUSED const ConstWireStateSharedPtr& wireState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::DrawPrimitive(MAYBE_UNUSED const ConstVisualSharedPtr& visual)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetBlendState(MAYBE_UNUSED const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetDepthStencilState(MAYBE_UNUSED const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetRasterizerState(MAYBE_UNUSED const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::WindowRenderer::Update(MAYBE_UNUSED const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::WindowRenderer::Update(MAYBE_UNUSED const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

void Rendering::WindowRenderer::SetViewport(MAYBE_UNUSED const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::Viewport Rendering::WindowRenderer::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetDepthRange(MAYBE_UNUSED const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::DepthRange Rendering::WindowRenderer::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::Resize(MAYBE_UNUSED int width, MAYBE_UNUSED int height)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearDepthBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearStencilBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearBuffers(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::DisplayColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::SetColorMask(MAYBE_UNUSED bool allowRed, MAYBE_UNUSED bool allowGreen, MAYBE_UNUSED bool allowBlue, MAYBE_UNUSED bool allowAlpha)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::WindowRenderer::PreDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::PostDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::Draw(MAYBE_UNUSED const uint8_t* screenBuffer, MAYBE_UNUSED bool reflectY)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::WindowRenderer::HasDepthRange01() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return false;
}

std::string Rendering::WindowRenderer::GetShaderName(MAYBE_UNUSED const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return "";
}

void Rendering::WindowRenderer::DisplayColorBuffer(MAYBE_UNUSED int syncInterval) noexcept
{
}

void Rendering::WindowRenderer::Draw(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED const Colour& color, MAYBE_UNUSED const std::string& message)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearDepthBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearStencilBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::WindowRenderer::ClearColorBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

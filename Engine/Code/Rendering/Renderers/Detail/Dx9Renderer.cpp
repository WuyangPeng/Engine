///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:01)

#include "Rendering/RenderingExport.h"

#include "Dx9Renderer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererParameter.h"

Rendering::Dx9Renderer::Dx9Renderer(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
    : ParentType{ RendererTypes::Dx11, RenderingEnvironment{ environmentParameter, rendererParameter }, rendererParameter.GetRendererBasis() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9Renderer)

Rendering::RendererTypes Rendering::Dx9Renderer::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::Dx11;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::Dx9Renderer::SetAlphaState(MAYBE_UNUSED const ConstAlphaStateSharedPtr& alphaState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetCullState(MAYBE_UNUSED const ConstCullStateSharedPtr& cullState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetDepthState(MAYBE_UNUSED const ConstDepthStateSharedPtr& depthState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetOffsetState(MAYBE_UNUSED const ConstOffsetStateSharedPtr& offsetState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetStencilState(MAYBE_UNUSED const ConstStencilStateSharedPtr& stencilState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetWireState(MAYBE_UNUSED const ConstWireStateSharedPtr& wireState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::DrawPrimitive(MAYBE_UNUSED const ConstVisualSharedPtr& visual)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetBlendState(MAYBE_UNUSED const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetDepthStencilState(MAYBE_UNUSED const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetRasterizerState(MAYBE_UNUSED const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::Dx9Renderer::Update(MAYBE_UNUSED const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::Dx9Renderer::Update(MAYBE_UNUSED const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

void Rendering::Dx9Renderer::SetViewport(MAYBE_UNUSED const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::Viewport Rendering::Dx9Renderer::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetDepthRange(MAYBE_UNUSED const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::DepthRange Rendering::Dx9Renderer::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::Resize(MAYBE_UNUSED int width, MAYBE_UNUSED int height)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearDepthBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearStencilBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearBuffers(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::DisplayColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::SetColorMask(MAYBE_UNUSED bool allowRed, MAYBE_UNUSED bool allowGreen, MAYBE_UNUSED bool allowBlue, MAYBE_UNUSED bool allowAlpha)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::Dx9Renderer::PreDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::PostDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::Draw(MAYBE_UNUSED const uint8_t* screenBuffer, MAYBE_UNUSED bool reflectY)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::Dx9Renderer::HasDepthRange01() const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::string Rendering::Dx9Renderer::GetShaderName(MAYBE_UNUSED const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::DisplayColorBuffer(MAYBE_UNUSED int syncInterval) noexcept
{
}

void Rendering::Dx9Renderer::Draw(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED const Colour& color, MAYBE_UNUSED const std::string& message)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearDepthBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearStencilBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::Dx9Renderer::ClearColorBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

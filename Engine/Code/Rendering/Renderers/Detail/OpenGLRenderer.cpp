///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderer.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "System/OpenGL/OpenGLBase.h"

Rendering::OpenGLRenderer::OpenGLRenderer(const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis)
    : ParentType{ RendererTypes::OpenGL, renderingEnvironment, basis }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRenderer)

Rendering::RendererTypes Rendering::OpenGLRenderer::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::OpenGL;
}

void Rendering::OpenGLRenderer::SetAlphaState(MAYBE_UNUSED const ConstAlphaStateSharedPtr& alphaState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::SetCullState(MAYBE_UNUSED const ConstCullStateSharedPtr& cullState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::SetDepthState(MAYBE_UNUSED const ConstDepthStateSharedPtr& depthState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::SetOffsetState(MAYBE_UNUSED const ConstOffsetStateSharedPtr& offsetState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::SetStencilState(MAYBE_UNUSED const ConstStencilStateSharedPtr& stencilState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::SetWireState(MAYBE_UNUSED const ConstWireStateSharedPtr& wireState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::SetViewport(MAYBE_UNUSED const Viewport& viewport) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

Rendering::Viewport Rendering::OpenGLRenderer::GetViewport() const
{
    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::SetDepthRange(MAYBE_UNUSED const DepthRange& depthRange) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

Rendering::DepthRange Rendering::OpenGLRenderer::GetDepthRange() const
{
    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::Resize(MAYBE_UNUSED int width, MAYBE_UNUSED int height) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearColorBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    const auto colour = GetClearColor();

    System::SetGLClearColor(colour.GetRed(), colour.GetGreen(), colour.GetBlue(), colour.GetAlpha());
}

void Rendering::OpenGLRenderer::ClearDepthBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearStencilBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearBuffers(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::DisplayColorBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::OpenGLRenderer::SetBlendState(MAYBE_UNUSED const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::SetDepthStencilState(MAYBE_UNUSED const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::SetRasterizerState(MAYBE_UNUSED const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLRenderer::Update(MAYBE_UNUSED const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::DrawPrimitive(MAYBE_UNUSED const ConstVisualSharedPtr& visual) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

bool Rendering::OpenGLRenderer::Update(MAYBE_UNUSED const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

void Rendering::OpenGLRenderer::SetColorMask(MAYBE_UNUSED bool allowRed, MAYBE_UNUSED bool allowGreen, MAYBE_UNUSED bool allowBlue, MAYBE_UNUSED bool allowAlpha)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLRenderer::PreDraw() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return true;
}

void Rendering::OpenGLRenderer::PostDraw() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::Draw(MAYBE_UNUSED const uint8_t* screenBuffer, MAYBE_UNUSED bool reflectY) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

bool Rendering::OpenGLRenderer::HasDepthRange01() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}

std::string Rendering::OpenGLRenderer::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return name;
}

void Rendering::OpenGLRenderer::DisplayColorBuffer(MAYBE_UNUSED int syncInterval) noexcept
{
}

void Rendering::OpenGLRenderer::Draw(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED const Colour& color, MAYBE_UNUSED const std::string& message) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearDepthBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearStencilBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearBuffers() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLRenderer::ClearColorBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

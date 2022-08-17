///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:14)

#include "Rendering/RenderingExport.h"

#include "GlutRenderer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

Rendering::GlutRenderer::GlutRenderer(const RendererBasis& basis)
    : ParentType{ basis }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GlutRenderer)

Rendering::RendererTypes Rendering::GlutRenderer::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::Glut;
}

void Rendering::GlutRenderer::SetAlphaState(MAYBE_UNUSED const ConstAlphaStateSharedPtr& alphaState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::SetCullState(MAYBE_UNUSED const ConstCullStateSharedPtr& cullState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::SetDepthState(MAYBE_UNUSED const ConstDepthStateSharedPtr& depthState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::SetOffsetState(MAYBE_UNUSED const ConstOffsetStateSharedPtr& offsetState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::SetStencilState(MAYBE_UNUSED const ConstStencilStateSharedPtr& stencilState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::SetWireState(MAYBE_UNUSED const ConstWireStateSharedPtr& wireState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::SetViewport(MAYBE_UNUSED const Viewport& viewport) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

Rendering::Viewport Rendering::GlutRenderer::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::SetDepthRange(MAYBE_UNUSED const DepthRange& depthRange) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

Rendering::DepthRange Rendering::GlutRenderer::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::Resize(MAYBE_UNUSED int width, MAYBE_UNUSED int height) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearColorBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearDepthBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearStencilBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearBuffers(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::DisplayColorBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::GlutRenderer::SetBlendState(MAYBE_UNUSED const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::SetDepthStencilState(MAYBE_UNUSED const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::SetRasterizerState(MAYBE_UNUSED const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GlutRenderer::Update(MAYBE_UNUSED const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GlutRenderer::DrawPrimitive(MAYBE_UNUSED const ConstVisualSharedPtr& visual) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

bool Rendering::GlutRenderer::Update(MAYBE_UNUSED const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

void Rendering::GlutRenderer::SetColorMask(MAYBE_UNUSED bool allowRed, MAYBE_UNUSED bool allowGreen, MAYBE_UNUSED bool allowBlue, MAYBE_UNUSED bool allowAlpha)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GlutRenderer::PreDraw() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return true;
}

void Rendering::GlutRenderer::PostDraw() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::Draw(MAYBE_UNUSED const uint8_t* screenBuffer, MAYBE_UNUSED bool reflectY) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

bool Rendering::GlutRenderer::HasDepthRange01() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}

std::string Rendering::GlutRenderer::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return name;
}

void Rendering::GlutRenderer::DisplayColorBuffer(MAYBE_UNUSED int syncInterval) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::Draw(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED const Colour& color, MAYBE_UNUSED const std::string& message) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearDepthBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearStencilBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearBuffers() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::GlutRenderer::ClearColorBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

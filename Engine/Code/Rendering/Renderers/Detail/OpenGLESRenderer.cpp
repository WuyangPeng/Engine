///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLESRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererParameter.h"

Rendering::OpenGLESRenderer::OpenGLESRenderer(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
    : ParentType{ RenderingEnvironment{ environmentParameter, rendererParameter }, rendererParameter.GetRendererBasis() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLESRenderer)

Rendering::RendererTypes Rendering::OpenGLESRenderer::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RendererTypes::OpenGLES;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::OpenGLESRenderer::SetAlphaState(MAYBE_UNUSED const ConstAlphaStateSharedPtr& alphaState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetCullState(MAYBE_UNUSED const ConstCullStateSharedPtr& cullState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetDepthState(MAYBE_UNUSED const ConstDepthStateSharedPtr& depthState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetOffsetState(MAYBE_UNUSED const ConstOffsetStateSharedPtr& offsetState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetStencilState(MAYBE_UNUSED const ConstStencilStateSharedPtr& stencilState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetWireState(MAYBE_UNUSED const ConstWireStateSharedPtr& wireState)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::DrawPrimitive(MAYBE_UNUSED const ConstVisualSharedPtr& visual)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetBlendState(MAYBE_UNUSED const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetDepthStencilState(MAYBE_UNUSED const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetRasterizerState(MAYBE_UNUSED const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLESRenderer::Update(MAYBE_UNUSED const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLESRenderer::Update(MAYBE_UNUSED const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

void Rendering::OpenGLESRenderer::SetViewport(MAYBE_UNUSED const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::Viewport Rendering::OpenGLESRenderer::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetDepthRange(MAYBE_UNUSED const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::DepthRange Rendering::OpenGLESRenderer::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::Resize(MAYBE_UNUSED int width, MAYBE_UNUSED int height)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearDepthBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearStencilBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearBuffers(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::DisplayColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::SetColorMask(MAYBE_UNUSED bool allowRed, MAYBE_UNUSED bool allowGreen, MAYBE_UNUSED bool allowBlue, MAYBE_UNUSED bool allowAlpha)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLESRenderer::PreDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::PostDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::Draw(MAYBE_UNUSED const uint8_t* screenBuffer, MAYBE_UNUSED bool reflectY)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLESRenderer::HasDepthRange01() const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::string Rendering::OpenGLESRenderer::GetShaderName(MAYBE_UNUSED const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::DisplayColorBuffer(MAYBE_UNUSED int syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::Draw(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED const Colour& color, MAYBE_UNUSED const std::string& message)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearDepthBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearStencilBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLESRenderer::ClearColorBuffer(MAYBE_UNUSED int x, MAYBE_UNUSED int y, MAYBE_UNUSED int w, MAYBE_UNUSED int h)
{
    RENDERING_CLASS_IS_VALID_9;

    throw std::logic_error("The method or operation is not implemented.");
}

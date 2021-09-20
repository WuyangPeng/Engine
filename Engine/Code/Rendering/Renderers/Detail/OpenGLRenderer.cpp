///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/26 18:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

Rendering::OpenGLRenderer::OpenGLRenderer(const RendererBasis& basis)
    : ParentType{ basis }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRenderer)

Rendering::RendererTypes Rendering::OpenGLRenderer::GetRendererType() const noexcept
{
    return RendererTypes::OpenGL;
}

void Rendering::OpenGLRenderer::SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) noexcept
{
    alphaState;
}

void Rendering::OpenGLRenderer::SetCullState(const ConstCullStateSharedPtr& cullState) noexcept
{
    cullState;
}

void Rendering::OpenGLRenderer::SetDepthState(const ConstDepthStateSharedPtr& depthState) noexcept
{
    depthState;
}

void Rendering::OpenGLRenderer::SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) noexcept
{
    offsetState;
}

void Rendering::OpenGLRenderer::SetStencilState(const ConstStencilStateSharedPtr& stencilState) noexcept
{
    stencilState;
}

void Rendering::OpenGLRenderer::SetWireState(const ConstWireStateSharedPtr& wireState) noexcept
{
    wireState;
}

void Rendering::OpenGLRenderer::SetViewport(const Viewport& viewport) noexcept
{
    viewport;
}

Rendering::Viewport Rendering::OpenGLRenderer::GetViewport() const 
{
    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::SetDepthRange(const DepthRange& depthRange) noexcept
{
    depthRange;
}

Rendering::DepthRange Rendering::OpenGLRenderer::GetDepthRange() const
{
    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::OpenGLRenderer::Resize(int width, int height) noexcept
{
    width;
    height;
}

void Rendering::OpenGLRenderer::ClearColorBuffer() noexcept
{
}

void Rendering::OpenGLRenderer::ClearDepthBuffer(int x, int y, int w, int h) noexcept
{
    x;
    y;
    w;
    h;
}

void Rendering::OpenGLRenderer::ClearStencilBuffer(int x, int y, int w, int h) noexcept
{
    x;
    y;
    w;
    h;
}

void Rendering::OpenGLRenderer::ClearBuffers(int x, int y, int w, int h) noexcept
{
    x;
    y;
    w;
    h;
}

void Rendering::OpenGLRenderer::DisplayColorBuffer() noexcept
{
}

void Rendering::OpenGLRenderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
    allowRed;
    allowGreen;
    allowBlue;
    allowAlpha;
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::OpenGLRenderer::PreDraw() noexcept
{
    return true;
}

void Rendering::OpenGLRenderer::PostDraw() noexcept
{
}

void Rendering::OpenGLRenderer::Draw(const uint8_t* screenBuffer, bool reflectY) noexcept
{
    screenBuffer;
    reflectY;
}

void Rendering::OpenGLRenderer::DrawPrimitive(const ConstVisualSharedPtr& visual) noexcept
{
    visual;
}

void Rendering::OpenGLRenderer::Draw(int x, int y, const Colour& color, const std::string& message) noexcept
{
    x;
    y;
    color;
    message;
}

void Rendering::OpenGLRenderer::ClearDepthBuffer() noexcept
{
}

void Rendering::OpenGLRenderer::ClearStencilBuffer() noexcept
{
}

void Rendering::OpenGLRenderer::ClearBuffers() noexcept
{
}

void Rendering::OpenGLRenderer::ClearColorBuffer(int x, int y, int w, int h) noexcept
{
    x;
    y;
    w;
    h;
}

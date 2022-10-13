///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/04 13:57)

#include "Rendering/RenderingExport.h"

#include "BaseRenderer.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/LocalEffects/Font.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/RasterizerState.h"

Rendering::BaseRenderer::BaseRenderer(const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis)
    : renderingEnvironment{ renderingEnvironment },
      renderingDevice{ renderingEnvironment.GetRenderingDevice() },

      rendererBasis{ basis },

      clearColor{ 1.0f, 1.0f, 1.0f, 1.0f },
      clearDepth{ 0.0f },
      clearStencil{ 0 },

      defaultFont{ std::make_shared<Font>() },
      activeFont{ defaultFont },

      defaultBlendState{ std::make_shared<BlendState>("BlendState") },
      activeBlendState{ defaultBlendState },
      defaultDepthStencilState{ std::make_shared<DepthStencilState>("DepthStencilState") },
      activeDepthStencilState{ defaultDepthStencilState },
      defaultRasterizerState{ std::make_shared<RasterizerState>("RasterizerState") },
      activeRasterizerState{ defaultRasterizerState }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::BaseRenderer::CreateDefaultGlobalState()
{
#if defined(RENDERING_USE_NAMED_OBJECTS)

    defaultBlendState->SetName("BaseRenderer::defaultBlendState");
    defaultDepthStencilState->SetName("BaseRenderer::defaultDepthStencilState");
    defaultRasterizerState->SetName("BaseRenderer::defaultRasterizerState");

#endif  // RENDERING_USE_NAMED_OBJECTS

    SetDefaultBlendState();
    SetDefaultDepthStencilState();
    SetDefaultRasterizerState();
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::BaseRenderer::IsValid() const noexcept
{
    if (defaultFont != nullptr &&
        activeFont != nullptr &&
        defaultBlendState != nullptr &&
        activeBlendState != nullptr &&
        defaultDepthStencilState != nullptr &&
        activeDepthStencilState != nullptr &&
        defaultRasterizerState != nullptr &&
        activeRasterizerState != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::BaseRenderer::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rendererBasis.GetWidth();
}

int Rendering::BaseRenderer::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rendererBasis.GetHeight();
}

Rendering::DataFormatType Rendering::BaseRenderer::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rendererBasis.GetColorFormat();
}

Rendering::DataFormatType Rendering::BaseRenderer::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rendererBasis.GetDepthStencilFormat();
}

int Rendering::BaseRenderer::GetNumMultisamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rendererBasis.GetNumMultisamples();
}

void Rendering::BaseRenderer::SetClearColor(const Colour& aClearColor) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    clearColor = aClearColor;
}

Rendering::BaseRenderer::Colour Rendering::BaseRenderer::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return clearColor;
}

void Rendering::BaseRenderer::SetClearDepth(float aClearDepth) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    clearDepth = aClearDepth;
}

float Rendering::BaseRenderer::GetClearDepth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return clearDepth;
}

void Rendering::BaseRenderer::SetClearStencil(int aClearStencil) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    clearStencil = aClearStencil;
}

int Rendering::BaseRenderer::GetClearStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return clearStencil;
}

void Rendering::BaseRenderer::SetFont(const FontSharedPtr& font)
{
    RENDERING_CLASS_IS_VALID_1;

    activeFont = font;

    CoreTools::DisableNoexcept();
}

Rendering::BaseRenderer::FontSharedPtr Rendering::BaseRenderer::GetFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeFont;
}

void Rendering::BaseRenderer::SetDefaultFont()
{
    RENDERING_CLASS_IS_VALID_1;

    SetFont(defaultFont);
}

Rendering::BaseRenderer::FontSharedPtr Rendering::BaseRenderer::GetDefaultFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultFont;
}

void Rendering::BaseRenderer::SetActiveBlendState(const BlendStateSharedPtr& state) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    activeBlendState = state;
}

Rendering::BaseRenderer::BlendStateSharedPtr Rendering::BaseRenderer::GetBlendState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeBlendState;
}

void Rendering::BaseRenderer::SetDefaultBlendState()
{
    RENDERING_CLASS_IS_VALID_1;

    SetBlendState(defaultBlendState);
}

Rendering::BaseRenderer::BlendStateSharedPtr Rendering::BaseRenderer::GetDefaultBlendState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultBlendState;
}

void Rendering::BaseRenderer::SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    activeDepthStencilState = state;
}

Rendering::BaseRenderer::DepthStencilStateSharedPtr Rendering::BaseRenderer::GetDepthStencilState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeDepthStencilState;
}

void Rendering::BaseRenderer::SetDefaultDepthStencilState()
{
    RENDERING_CLASS_IS_VALID_1;

    SetDepthStencilState(defaultDepthStencilState);
}

Rendering::BaseRenderer::DepthStencilStateSharedPtr Rendering::BaseRenderer::GetDefaultDepthStencilState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultDepthStencilState;
}

void Rendering::BaseRenderer::SetActiveRasterizerState(const RasterizerStateSharedPtr& state) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    activeRasterizerState = state;
}

Rendering::BaseRenderer::RasterizerStateSharedPtr Rendering::BaseRenderer::GetRasterizerState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeRasterizerState;
}

void Rendering::BaseRenderer::SetDefaultRasterizerState()
{
    RENDERING_CLASS_IS_VALID_1;

    SetRasterizerState(defaultRasterizerState);
}

Rendering::BaseRenderer::RasterizerStateSharedPtr Rendering::BaseRenderer::GetDefaultRasterizerState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultRasterizerState;
}

void Rendering::BaseRenderer::Release()
{
    RENDERING_CLASS_IS_VALID_1;

    renderingEnvironment.Release();
}

void Rendering::BaseRenderer::SwapBuffers()
{
    RENDERING_CLASS_IS_VALID_1;

    renderingDevice.SwapBuffers();
}

void Rendering::BaseRenderer::ResetSize()
{
    RENDERING_CLASS_IS_VALID_1;

    renderingDevice.ResetSize();
}

void Rendering::BaseRenderer::InitDevice()
{
    RENDERING_CLASS_IS_VALID_1;

    renderingDevice.InitDevice();
}

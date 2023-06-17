///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:39)

#include "Rendering/RenderingExport.h"

#include "BaseRenderer.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/LocalEffects/Font.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/RasterizerState.h"

Rendering::BaseRenderer::BaseRenderer(RendererTypes rendererTypes, const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis)
    : renderingEnvironment{ renderingEnvironment },
      renderingDevice{ renderingEnvironment.GetRenderingDevice() },

      rendererBasis{ basis },
      rendererObjectBridge{ RendererObjectBridge::Create() },

      clearColor{ 1.0f, 1.0f, 1.0f, 1.0f },
      clearDepth{ 0.0f },
      clearStencil{ 0 },

      defaultFont{ std::make_shared<Font>() },
      activeFont{ defaultFont },

      globalState{ rendererTypes, "BlendState", "DepthStencilState", "RasterizerState", rendererObjectBridge }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::BaseRenderer::IsValid() const noexcept
{
    if (defaultFont != nullptr &&
        activeFont != nullptr)
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

void Rendering::BaseRenderer::SetActiveBlendState(const BlendStateSharedPtr& state)  
{
    RENDERING_CLASS_IS_VALID_1;

    globalState.SetActiveBlendState(state);
}

Rendering::BaseRenderer::BlendStateSharedPtr Rendering::BaseRenderer::GetBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalState.GetActiveBlendState();
}

Rendering::BaseRenderer::BlendStateSharedPtr Rendering::BaseRenderer::GetDefaultBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalState.GetDefaultBlendState();
}

void Rendering::BaseRenderer::SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state)  
{
    RENDERING_CLASS_IS_VALID_1;

    globalState.SetActiveDepthStencilState(state);
}

Rendering::BaseRenderer::DepthStencilStateSharedPtr Rendering::BaseRenderer::GetDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalState.GetActiveDepthStencilState();
}

Rendering::BaseRenderer::DepthStencilStateSharedPtr Rendering::BaseRenderer::GetDefaultDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalState.GetDefaultDepthStencilState();
}

void Rendering::BaseRenderer::SetActiveRasterizerState(const RasterizerStateSharedPtr& state)  
{
    RENDERING_CLASS_IS_VALID_1;

    globalState.SetActiveRasterizerState(state);
}

Rendering::BaseRenderer::RasterizerStateSharedPtr Rendering::BaseRenderer::GetRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalState.GetActiveRasterizerState();
}

Rendering::BaseRenderer::RasterizerStateSharedPtr Rendering::BaseRenderer::GetDefaultRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalState.GetDefaultRasterizerState();
}

void Rendering::BaseRenderer::Release()
{
    RENDERING_CLASS_IS_VALID_1;

    globalState.DestroyDefaultGlobalState();
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
    globalState.CreateDefaultGlobalState();
}

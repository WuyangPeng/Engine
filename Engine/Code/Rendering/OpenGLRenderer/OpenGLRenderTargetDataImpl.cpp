///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLBindTexture.h"
#include "OpenGLMapping.h"
#include "OpenGLRenderTargetDataImpl.h" 
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

Rendering::OpenGLRenderTargetDataImpl::OpenGLRenderTargetDataImpl(BaseRenderer* renderer, const DrawTarget* renderTarget)
    : numTargets{ renderTarget != nullptr ? renderTarget->GetNumTargets() : 0 },
      width{ renderTarget != nullptr ? renderTarget->GetWidth() : 0 },
      height{ renderTarget != nullptr ? renderTarget->GetHeight() : 0 },
      format{ renderTarget != nullptr ? renderTarget->GetRenderTargetFormat() : DataFormatType::Unknown },
      hasMipmaps{ renderTarget != nullptr ? renderTarget->HasRenderTargetMipMaps() : false },
      hasDepthStencil{ renderTarget != nullptr ? renderTarget->HasDepthStencil() : false },
      colorTextures(numTargets),
      depthStencilTexture{ 0 },
      frameBuffer{ 0 },
      drawBuffers(numTargets),
      prevViewport{},
      prevDepthRange{}
{
    CreateFramebufferObject();
    const auto previousBind = CreateDrawBuffers(renderer, renderTarget);
    CreateDepthStencilTexture(renderer, renderTarget, previousBind);
    CheckFramebufferStatus();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::OpenGLRenderTargetDataImpl::CreateFramebufferObject() noexcept
{
    // 创建帧缓冲区对象。
}

System::OpenGLUInt Rendering::OpenGLRenderTargetDataImpl::CreateDrawBuffers(const BaseRenderer* renderer, const DrawTarget* aRenderTarget)
{
    const auto previousBind = GetBoundTexture(ShaderFlags::SamplerType::Sampler2D);

    if (renderer == nullptr || aRenderTarget == nullptr)
    {
        return previousBind;
    }

    for (auto index = 0; index < numTargets; ++index)
    {
        // auto colorTexture = aRenderTarget->GetRenderTargetTexture(index);
        // RENDERING_ASSERTION_1(!renderer->InTexture2DMap(colorTexture), "纹理不应该存在。\n");

        //   auto platformColorTexture = std::make_shared<PlatformTexture2D>(renderer, colorTexture.get());
        //  renderer->InsertInTexture2DMap(colorTexture, platformColorTexture);
        //  colorTextures.at(index) = platformColorTexture->GetTexture();
        drawBuffers.at(index) = static_cast<GLenum>(System::ColorAttachent::Color0) + index;

        // 绑定颜色纹理。

        // 附加纹理到帧缓冲区。
    }

    return previousBind;
}

void Rendering::OpenGLRenderTargetDataImpl::CreateDepthStencilTexture(const BaseRenderer* renderer, const DrawTarget* aRenderTarget, MAYBE_UNUSED UInt previousBind)
{
    if (renderer == nullptr || aRenderTarget == nullptr)
    {
        return;
    }

    auto aDepthStencilTexture = aRenderTarget->GetDepthStencilTexture();
    if (aDepthStencilTexture)
    {
        //  RENDERING_ASSERTION_1(!renderer->InTexture2DMap(aDepthStencilTexture), "纹理不应该存在。\n");

        //        auto platformDepthStencilTexture = make_shared<PlatformTexture2D>(renderer, aDepthStencilTexture.get());

        // renderer->InsertInTexture2DMap(aDepthStencilTexture, platformDepthStencilTexture);
        //    depthStencilTexture = platformDepthStencilTexture->GetTexture();

        // 绑定深度和模板纹理。

        // 附加深度纹理到帧缓冲区。

        // 附加模板纹理到帧缓冲区。
    }
}

void Rendering::OpenGLRenderTargetDataImpl::CheckFramebufferStatus() noexcept
{
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::OpenGLRenderTargetDataImpl::IsValid() const noexcept
{
    if (1 <= numTargets && colorTextures.size() == gsl::narrow_cast<size_t>(numTargets) &&
        drawBuffers.size() == gsl::narrow_cast<size_t>(numTargets) &&
        0 < frameBuffer)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::OpenGLRenderTargetDataImpl::Enable(MAYBE_UNUSED BaseRenderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    System::SetGLViewport(0, 0, width, height);
    System::SetGLDepthRange(0.0, 1.0);
}

void Rendering::OpenGLRenderTargetDataImpl::Disable(MAYBE_UNUSED BaseRenderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    System::SetGLViewport(prevViewport.at(0), prevViewport.at(1), prevViewport.at(2), prevViewport.at(3));
    System::SetGLDepthRange(prevDepthRange.at(0), prevDepthRange.at(1));
}

Rendering::ConstTexture2DSharedPtr Rendering::OpenGLRenderTargetDataImpl::ReadColor(MAYBE_UNUSED int index, BaseRenderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;

    Enable(renderer);

    auto texture = std::make_shared<Texture2D>(format, width, height, 1);

    Disable(renderer);

    return texture;
}

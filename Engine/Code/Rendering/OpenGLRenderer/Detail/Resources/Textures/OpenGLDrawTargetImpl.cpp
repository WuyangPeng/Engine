///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/26 15:05)

#include "Rendering/RenderingExport.h"

#include "OpenGLDrawTargetImpl.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"

#include <array>

Rendering::OpenGLDrawTargetImpl::OpenGLDrawTargetImpl(const DrawTargetSharedPtr& target,
                                                      const OpenGLTextureRenderTargetContainer& renderTargetTextures,
                                                      const OpenGLTextureDepthStencilSharedPtr& depthStencilTexture)
    : drawTarget{ target },
      renderTargetTextures{ renderTargetTextures },
      depthStencilTexture{ depthStencilTexture },
      frameBuffer{ 0 },
      saveViewportX{ 0 },
      saveViewportY{ 0 },
      saveViewportWidth{ 0 },
      saveViewportHeight{ 0 },
      saveViewportNear{ 0.0 },
      saveViewportFar{ 0.0 }
{
    if (boost::numeric_cast<int>(renderTargetTextures.size()) < target->GetNumTargets())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("DrawTargets的目标比提供的纹理多"s));
    }

    frameBuffer = System::GetGLGenFramebuffers();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLDrawTargetImpl::~OpenGLDrawTargetImpl() noexcept
{
    System::SetGLDeleteFramebuffers(frameBuffer);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLDrawTargetImpl)

void Rendering::OpenGLDrawTargetImpl::Enable()
{
    RENDERING_CLASS_IS_VALID_9;

    std::array<GLint, 4> intVals{};
    std::array<GLdouble, 2> doubleVals{};
    System::GetGLInteger(System::OpenGLQuery::Viewport, intVals.data());
    System::GetGLDouble(System::OpenGLQuery::DepthRange, doubleVals.data());
    saveViewportX = intVals.at(0);
    saveViewportY = intVals.at(1);
    saveViewportWidth = intVals.at(2);
    saveViewportHeight = intVals.at(3);
    saveViewportNear = doubleVals.at(0);
    saveViewportFar = doubleVals.at(1);

    const auto viewportWidth = boost::numeric_cast<OpenGLSize>(drawTarget->GetWidth());
    const auto viewportHeight = boost::numeric_cast<OpenGLSize>(drawTarget->GetHeight());
    System::SetGLViewport(0, 0, viewportWidth, viewportHeight);

    System::SetGLDepthRange(0.0, 1.0);

    System::SetGLBindFramebuffer(System::FrameBufferType::DrawFramebuffer, frameBuffer);

    if (depthStencilTexture != nullptr)
    {
        auto format = depthStencilTexture->GetTexture()->GetFormat();
        auto attachment = System::ColorAttachent::DepthAttachment;
        if (format == DataFormatType::D24UNormS8UInt)
        {
            attachment = System::ColorAttachent::DepthStencilAttachment;
        }

        System::SetGLFramebufferTexture2D(System::FrameBufferType::DrawFramebuffer, attachment, System::TextureTarget::Texture2D, depthStencilTexture->GetGLHandle(), 0);
    }

    const auto numTargets = drawTarget->GetNumTargets();
    std::vector<System::OpenGLEnum> useDrawBuffers{};
    for (auto i = 0; i < numTargets; ++i)
    {
        auto colorTarget = System::EnumCastUnderlying(System::ColorAttachent::Color0) + i;

        useDrawBuffers.emplace_back(colorTarget);

        auto textureRT = renderTargetTextures.at(i);
        System::SetGLFramebufferTexture2D(System::FrameBufferType::DrawFramebuffer, System::UnderlyingCastEnum<System::ColorAttachent>(colorTarget), System::TextureTarget::Texture2D, textureRT->GetGLHandle(), 0);
    }

    System::SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(useDrawBuffers.size()), useDrawBuffers.data());
}

void Rendering::OpenGLDrawTargetImpl::Disable()
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindFramebuffer(System::FrameBufferType::Framebuffer, 0);

    System::SetGLViewport(saveViewportX, saveViewportY, saveViewportWidth, saveViewportHeight);
    System::SetGLDepthRange(saveViewportNear, saveViewportFar);

    const auto numTargets = drawTarget->GetNumTargets();
    for (auto i = 0; i < numTargets; ++i)
    {
        auto textureRT = renderTargetTextures.at(i);
        if (textureRT->CanAutoGenerateMipmaps())
        {
            textureRT->GenerateMipmaps();
        }
    }
}

Rendering::OpenGLDrawTargetImpl::ConstOpenGLTextureRenderTargetSharedPtr Rendering::OpenGLDrawTargetImpl::GetRenderTargetTexture(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderTargetTextures.at(index);
}

Rendering::OpenGLDrawTargetImpl::ConstOpenGLTextureDepthStencilSharedPtr Rendering::OpenGLDrawTargetImpl::GetDepthStencilTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthStencilTexture;
}

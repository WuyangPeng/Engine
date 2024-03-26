/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 15:41)

#include "Rendering/RenderingExport.h"

#include "OpenGLDrawTargetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <array>

Rendering::OpenGLDrawTargetImpl::OpenGLDrawTargetImpl(const ConstDrawTargetSharedPtr& target,
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

    frameBuffer = System::GetGLGenFrameBuffers();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLDrawTargetImpl::~OpenGLDrawTargetImpl() noexcept
{
    System::SetGLDeleteFrameBuffers(frameBuffer);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLDrawTargetImpl)

void Rendering::OpenGLDrawTargetImpl::Enable()
{
    RENDERING_CLASS_IS_VALID_9;

    std::array<GLint, 4> viewport{};
    std::array<GLdouble, 2> depthRange{};
    GetGLInteger(System::OpenGLQuery::Viewport, viewport.data());
    GetGLDouble(System::OpenGLQuery::DepthRange, depthRange.data());
    saveViewportX = viewport.at(0);
    saveViewportY = viewport.at(1);
    saveViewportWidth = viewport.at(2);
    saveViewportHeight = viewport.at(3);
    saveViewportNear = depthRange.at(0);
    saveViewportFar = depthRange.at(1);

    const auto viewportWidth = boost::numeric_cast<OpenGLSize>(drawTarget->GetWidth());
    const auto viewportHeight = boost::numeric_cast<OpenGLSize>(drawTarget->GetHeight());
    System::SetGLViewport(0, 0, viewportWidth, viewportHeight);

    System::SetGLDepthRange(0.0, 1.0);

    SetGLBindFrameBuffer(System::FrameBufferType::DrawFrameBuffer, frameBuffer);

    if (depthStencilTexture != nullptr)
    {
        const auto format = depthStencilTexture->GetTexture()->GetFormat();
        auto attachment = System::ColorAttachment::DepthAttachment;
        if (format == DataFormatType::D24UNormS8UInt)
        {
            attachment = System::ColorAttachment::DepthStencilAttachment;
        }

        SetGLFrameBufferTexture2D(System::FrameBufferType::DrawFrameBuffer, attachment, System::TextureTarget::Texture2D, depthStencilTexture->GetGLHandle(), 0);
    }

    const auto numTargets = drawTarget->GetNumTargets();
    std::vector<System::OpenGLEnum> useDrawBuffers{};
    for (auto i = 0; i < numTargets; ++i)
    {
        auto colorTarget = System::EnumCastUnderlying(System::ColorAttachment::Color0) + i;

        useDrawBuffers.emplace_back(colorTarget);

        const auto textureRenderTarget = renderTargetTextures.at(i);
        SetGLFrameBufferTexture2D(System::FrameBufferType::DrawFrameBuffer, System::UnderlyingCastEnum<System::ColorAttachment>(colorTarget), System::TextureTarget::Texture2D, textureRenderTarget->GetGLHandle(), 0);
    }

    System::SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(useDrawBuffers.size()), useDrawBuffers.data());
}

void Rendering::OpenGLDrawTargetImpl::Disable()
{
    RENDERING_CLASS_IS_VALID_9;

    SetGLBindFrameBuffer(System::FrameBufferType::FrameBuffer, 0);

    System::SetGLViewport(saveViewportX, saveViewportY, saveViewportWidth, saveViewportHeight);
    System::SetGLDepthRange(saveViewportNear, saveViewportFar);

    const auto numTargets = drawTarget->GetNumTargets();
    for (auto i = 0; i < numTargets; ++i)
    {
        if (const auto textureRenderTarget = renderTargetTextures.at(i);
            textureRenderTarget->CanAutoGenerateMipmaps())
        {
            textureRenderTarget->GenerateMipmaps();
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

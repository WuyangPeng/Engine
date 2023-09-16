///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:40)

#include "Rendering/RenderingExport.h"

#include "OpenGLDrawTargetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
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
        THROW_EXCEPTION(SYSTEM_TEXT("DrawTargets��Ŀ����ṩ�������"s));
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

    System::SetGLBindFrameBuffer(System::FrameBufferType::DrawFrameBuffer, frameBuffer);

    if (depthStencilTexture != nullptr)
    {
        auto format = depthStencilTexture->GetTexture()->GetFormat();
        auto attachment = System::ColorAttachment::DepthAttachment;
        if (format == DataFormatType::D24UNormS8UInt)
        {
            attachment = System::ColorAttachment::DepthStencilAttachment;
        }

        System::SetGLFrameBufferTexture2D(System::FrameBufferType::DrawFrameBuffer, attachment, System::TextureTarget::Texture2D, depthStencilTexture->GetGLHandle(), 0);
    }

    const auto numTargets = drawTarget->GetNumTargets();
    std::vector<System::OpenGLEnum> useDrawBuffers{};
    for (auto i = 0; i < numTargets; ++i)
    {
        auto colorTarget = System::EnumCastUnderlying(System::ColorAttachment::Color0) + i;

        useDrawBuffers.emplace_back(colorTarget);

        auto textureRT = renderTargetTextures.at(i);
        System::SetGLFrameBufferTexture2D(System::FrameBufferType::DrawFrameBuffer, System::UnderlyingCastEnum<System::ColorAttachment>(colorTarget), System::TextureTarget::Texture2D, textureRT->GetGLHandle(), 0);
    }

    System::SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(useDrawBuffers.size()), useDrawBuffers.data());
}

void Rendering::OpenGLDrawTargetImpl::Disable()
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindFrameBuffer(System::FrameBufferType::FrameBuffer, 0);

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

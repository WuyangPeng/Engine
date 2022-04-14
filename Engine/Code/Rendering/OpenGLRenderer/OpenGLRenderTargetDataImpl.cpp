// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/29 11:26)

#include "Rendering/RenderingExport.h"

#include "OpenGLBindTexture.h"
#include "OpenGLMapping.h"
#include "OpenGLRenderTargetDataImpl.h"
#include "OpenGLTexture2D.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "Rendering/Resources/RenderTarget.h"

#include "Rendering/Renderers/PlatformTexture2D.h"
#include "Rendering/Renderers/Renderer.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
Rendering::OpenGLRenderTargetDataImpl::OpenGLRenderTargetDataImpl(Renderer* renderer, const RenderTarget* renderTarget)
    : m_NumTargets{ renderTarget->GetNumTargets() }, m_Width{ renderTarget->GetWidth() }, m_Height{ renderTarget->GetHeight() },
      m_Format{ renderTarget->GetFormat() }, m_HasMipmaps{ renderTarget->HasMipmaps() }, m_HasDepthStencil{ renderTarget->HasDepthStencil() },
      m_ColorTextures(m_NumTargets), m_DepthStencilTexture{ 0 }, m_FrameBuffer{ 0 }, m_DrawBuffers(m_NumTargets)
{
    m_PrevViewport[0] = 0;
    m_PrevViewport[1] = 0;
    m_PrevViewport[2] = 0;
    m_PrevViewport[3] = 0;
    m_PrevDepthRange[0] = 0.0;
    m_PrevDepthRange[1] = 0.0;

    CreateFramebufferObject();
    const UInt previousBind = CreateDrawBuffers(renderer, renderTarget);
    CreateDepthStencilTexture(renderer, renderTarget, previousBind);
    CheckFramebufferStatus();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::OpenGLRenderTargetDataImpl::CreateFramebufferObject() noexcept
{
    // 创建帧缓冲区对象。
    // m_FrameBuffer = System::GLGenFramebuffers();
}

System::OpenGLUInt Rendering::OpenGLRenderTargetDataImpl::CreateDrawBuffers(Renderer* renderer, const RenderTarget* renderTarget)
{
    const UInt previousBind = GetBoundTexture(ShaderFlags::SamplerType::Sampler2D);

    for (int index = 0; index < m_NumTargets; ++index)
    {
        ConstTexture2DSharedPtr colorTexture = renderTarget->GetColorTexture(index);
        RENDERING_ASSERTION_1(!renderer->InTexture2DMap(colorTexture), "纹理不应该存在。\n");

        std::shared_ptr<PlatformTexture2D> platformColorTexture(std::make_shared<PlatformTexture2D>(renderer, colorTexture.get()));
        renderer->InsertInTexture2DMap(colorTexture, platformColorTexture);
        m_ColorTextures[index] = platformColorTexture->GetTexture();
        //	m_DrawBuffers[index] = static_cast<GLenum>(System::ColorAttachent::Color0) + index;

        // 绑定颜色纹理。
        // System::BindColorTexture(m_ColorTextures[index],m_HasMipmaps);

        // 附加纹理到帧缓冲区。
        // System::AttachTextureToFramebuffer(m_DrawBuffers[index],m_ColorTextures[index]);
    }

    return previousBind;
}

void Rendering::OpenGLRenderTargetDataImpl::CreateDepthStencilTexture(Renderer* renderer, const RenderTarget* renderTarget, UInt previousBind)
{
    previousBind;
    ConstTexture2DSharedPtr depthStencilTexture = renderTarget->GetDepthStencilTexture();
    if (depthStencilTexture)
    {
        RENDERING_ASSERTION_1(!renderer->InTexture2DMap(depthStencilTexture), "纹理不应该存在。\n");

        std::shared_ptr<PlatformTexture2D> platformDepthStencilTexture{ make_shared<PlatformTexture2D>(renderer, depthStencilTexture.get()) };

        renderer->InsertInTexture2DMap(depthStencilTexture, platformDepthStencilTexture);
        m_DepthStencilTexture = platformDepthStencilTexture->GetTexture();

        // 绑定深度和模板纹理。
        // System::BindColorTexture(m_DepthStencilTexture,false);

        // 附加深度纹理到帧缓冲区。
        //System::AttachTextureToFramebuffer(static_cast<GLenum>(System::ColorAttachent::Depth), m_DepthStencilTexture);

        // 附加模板纹理到帧缓冲区。
        //System::AttachTextureToFramebuffer(static_cast<GLenum>(System::ColorAttachent::Stencil), m_DepthStencilTexture);
    }

   // System::SetGLBindTexture(System::TextureTarget::Texture2D, previousBind);
}

void Rendering::OpenGLRenderTargetDataImpl::CheckFramebufferStatus()
{
    CoreTools::DisableNoexcept();
    //     switch (System::GlCheckFramebufferStatus())
    //     {
    // 		case System::CheckFrambufferStatus::Complete:
    //             System::GlBindFramebuffer(0);
    //             break;
    // 		case System::CheckFrambufferStatus::IncompleteAttachment:
    //             RENDERING_ASSERTION_1(false, "Framebuffer附件不完备\n");
    // 	         break;
    // 		case System::CheckFrambufferStatus::IncompleteMissingAttachment:
    //             RENDERING_ASSERTION_1(false, "Framebuffer缺失附件不完备\n");
    //             break;
    // 		case System::CheckFrambufferStatus::IncompleteDuplicateAttachment:
    //             RENDERING_ASSERTION_1(false, "Framebuffer复制附件不完备\n");
    //             break;
    // 		case System::CheckFrambufferStatus::IncompleteDimensions:
    //             RENDERING_ASSERTION_1(false, "Framebuffer维度不完备\n");
    //             break;
    // 		case System::CheckFrambufferStatus::IncompleteFormats:
    //             RENDERING_ASSERTION_1(false, "Framebuffer格式不完备\n");
    //             break;
    // 		case System::CheckFrambufferStatus::IncompleteDrawBuffer:
    //             RENDERING_ASSERTION_1(false, "Framebuffer绘制缓冲区不完备\n");
    //             break;
    // 		case System::CheckFrambufferStatus::IncompleteReadBuffer:
    //             RENDERING_ASSERTION_1(false, "Framebuffer读缓冲区不完备\n");
    //             break;
    // 		case System::CheckFrambufferStatus::Unsupported:
    //             RENDERING_ASSERTION_1(false, "Framebuffer不支持\n");
    //             break;
    //         default:
    //             RENDERING_ASSERTION_1(false, "Framebuffer未知错误\n");
    //             break;
    // }
}

Rendering::OpenGLRenderTargetDataImpl::~OpenGLRenderTargetDataImpl()
{
    RENDERING_SELF_CLASS_IS_VALID_1;

    //m_FrameBuffer = System::GLDeleteFramebuffers(m_FrameBuffer);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::OpenGLRenderTargetDataImpl::IsValid() const noexcept
{
    if (1 <= m_NumTargets && m_ColorTextures.size() == static_cast<uint32_t>(m_NumTargets) &&
        m_DrawBuffers.size() == static_cast<uint32_t>(m_NumTargets) &&
        0 < m_FrameBuffer)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void Rendering::OpenGLRenderTargetDataImpl::Enable([[maybe_unused]] Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    //  System::GLBindFramebuffer(m_FrameBuffer);
    //System::GetGLDrawBuffers(m_NumTargets, &m_DrawBuffers[0]);

   // m_PrevViewport = System::GetGLInteger(System::OpenGLQuery::Viewport);
   // m_PrevDepthRange = System::GetGLDouble(System::OpenGLQuery::DepthRange);
    System::SetGLViewport(0, 0, m_Width, m_Height);
    System::SetGLDepthRange(0.0, 1.0);
}

void Rendering::OpenGLRenderTargetDataImpl::Disable([[maybe_unused]] Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    // System::GLBindFramebuffer(0);

    if (m_HasMipmaps)
    {
        const UInt previousBind = GetBoundTexture(ShaderFlags::SamplerType::Sampler2D);

        for (int i = 0; i < m_NumTargets; ++i)
        {
            //System::SetGLGenerateMipmap(System::TextureTarget::Texture2D,m_ColorTextures[i]);
        }

       // System::SetGLBindTexture(System::TextureTarget::Texture2D, previousBind);
    }

    System::SetGLViewport(m_PrevViewport[0], m_PrevViewport[1], m_PrevViewport[2], m_PrevViewport[3]);
    System::SetGLDepthRange(m_PrevDepthRange[0], m_PrevDepthRange[1]);
}

Rendering::ConstTexture2DSharedPtr
    Rendering::OpenGLRenderTargetDataImpl::ReadColor(MAYBE_UNUSED int index, Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;

    Enable(renderer);

    Texture2DSharedPtr texture(std::make_shared<Texture2D>(m_Format, m_Width, m_Height, 1));

    //System::SetGlReadBuffer(static_cast<GLenum>(System::ColorAttachent::Color0) + index);

    // System::GLReadPixels(m_Width,m_Height,System::TextureFormat(g_OpenGLTextureFormat[System::EnumCastUnderlying(m_Format)]),
    //                     System::OpenGLData(g_OpenGLTextureType[System::EnumCastUnderlying(m_Format)]),texture->GetTextureData(0));

    Disable(renderer);

    return texture;
}

#include STSTEM_WARNING_POP
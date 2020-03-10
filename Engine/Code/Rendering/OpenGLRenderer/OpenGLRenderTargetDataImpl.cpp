// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:26)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderTargetDataImpl.h"
#include "OpenGLTexture2D.h"
#include "OpenGLMapping.h"
#include "OpenGLBindTexture.h"
#include "Rendering/Resources/RenderTarget.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/PlatformTexture2D.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::OpenGLRenderTargetDataImpl
    ::OpenGLRenderTargetDataImpl (Renderer* renderer,const RenderTarget* renderTarget)
	:m_NumTargets{ renderTarget->GetNumTargets() }, m_Width{ renderTarget->GetWidth() }, m_Height{ renderTarget->GetHeight() },
	 m_Format{ renderTarget->GetFormat() }, m_HasMipmaps{ renderTarget->HasMipmaps() }, m_HasDepthStencil{ renderTarget->HasDepthStencil() },
	 m_ColorTextures( m_NumTargets ), m_DepthStencilTexture{ 0 }, m_FrameBuffer{ 0 }, m_DrawBuffers( m_NumTargets )
{
    m_PrevViewport[0] = 0;
    m_PrevViewport[1] = 0;
    m_PrevViewport[2] = 0;
    m_PrevViewport[3] = 0;
    m_PrevDepthRange[0] = 0.0;
    m_PrevDepthRange[1] = 0.0;
    
    CreateFramebufferObject();
    UInt previousBind = CreateDrawBuffers(renderer,renderTarget);
    CreateDepthStencilTexture(renderer,renderTarget,previousBind);
    CheckFramebufferStatus();
    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::OpenGLRenderTargetDataImpl
    ::CreateFramebufferObject()
{
    // ����֡����������
    m_FrameBuffer = System::GlGenFramebuffers();
}

System::OpenGLUInt Rendering::OpenGLRenderTargetDataImpl
    ::CreateDrawBuffers(Renderer* renderer,const RenderTarget* renderTarget)
{
    UInt previousBind = GetBoundTexture(ShaderFlags::SamplerType::Sampler2D);
 
    for (int index = 0; index < m_NumTargets; ++index)
    {
        ConstTexture2DSmartPointer colorTexture = renderTarget->GetColorTexture(index);
        RENDERING_ASSERTION_1(!renderer->InTexture2DMap(colorTexture.GetData()), "����Ӧ�ô��ڡ�\n");
        
		std::shared_ptr<PlatformTexture2D> platformColorTexture(new PlatformTexture2D(renderer,colorTexture.GetData()));
        renderer->InsertInTexture2DMap(colorTexture.GetData(), platformColorTexture);
        m_ColorTextures[index] = platformColorTexture->GetTexture();
		m_DrawBuffers[index] = static_cast<GLenum>(System::ColorAttachent::Color0) + index;
        
        // ����ɫ����
        System::BindColorTexture(m_ColorTextures[index],m_HasMipmaps);     
        
        // ��������֡��������
        System::AttachTextureToFramebuffer(m_DrawBuffers[index],m_ColorTextures[index]);
    }
    
    return previousBind;
}

void Rendering::OpenGLRenderTargetDataImpl
    ::CreateDepthStencilTexture(Renderer* renderer,const RenderTarget* renderTarget,UInt previousBind)
{
    ConstTexture2DSmartPointer depthStencilTexture = renderTarget->GetDepthStencilTexture();
    if (depthStencilTexture.IsValidPtr())
    {
        RENDERING_ASSERTION_1(!renderer->InTexture2DMap(depthStencilTexture.GetData()),"����Ӧ�ô��ڡ�\n");
        
		std::shared_ptr<PlatformTexture2D> platformDepthStencilTexture{ make_shared<PlatformTexture2D>(renderer,depthStencilTexture.GetData()) };
   
		renderer->InsertInTexture2DMap(depthStencilTexture.GetData(),platformDepthStencilTexture);
        m_DepthStencilTexture = platformDepthStencilTexture->GetTexture();
        
		// ����Ⱥ�ģ������
        System::BindColorTexture(m_DepthStencilTexture,false);
        
		// �����������֡��������
		System::AttachTextureToFramebuffer(static_cast<GLenum>(System::ColorAttachent::Depth), m_DepthStencilTexture);
        
        // ����ģ������֡��������
		System::AttachTextureToFramebuffer(static_cast<GLenum>(System::ColorAttachent::Stencil), m_DepthStencilTexture);
    }
    
	System::SetGlBindTexture(System::TextureTarget::Texture2D, previousBind);
}

void Rendering::OpenGLRenderTargetDataImpl
    ::CheckFramebufferStatus()
{
    switch (System::GlCheckFramebufferStatus())
    {
		case System::CheckFrambufferStatus::Complete:
            System::GlBindFramebuffer(0);
            break;
		case System::CheckFrambufferStatus::IncompleteAttachment:
            RENDERING_ASSERTION_1(false, "Framebuffer�������걸\n");
	         break;
		case System::CheckFrambufferStatus::IncompleteMissingAttachment:
            RENDERING_ASSERTION_1(false, "Framebufferȱʧ�������걸\n");
            break;
		case System::CheckFrambufferStatus::IncompleteDuplicateAttachment:
            RENDERING_ASSERTION_1(false, "Framebuffer���Ƹ������걸\n");
            break;
		case System::CheckFrambufferStatus::IncompleteDimensions:
            RENDERING_ASSERTION_1(false, "Framebufferά�Ȳ��걸\n");
            break;
		case System::CheckFrambufferStatus::IncompleteFormats:
            RENDERING_ASSERTION_1(false, "Framebuffer��ʽ���걸\n");
            break;
		case System::CheckFrambufferStatus::IncompleteDrawBuffer:
            RENDERING_ASSERTION_1(false, "Framebuffer���ƻ��������걸\n");
            break;
		case System::CheckFrambufferStatus::IncompleteReadBuffer:
            RENDERING_ASSERTION_1(false, "Framebuffer�����������걸\n");
            break;
		case System::CheckFrambufferStatus::Unsupported:
            RENDERING_ASSERTION_1(false, "Framebuffer��֧��\n");
            break;
        default:
            RENDERING_ASSERTION_1(false, "Framebufferδ֪����\n");
            break;
    }
}

Rendering::OpenGLRenderTargetDataImpl
    ::~OpenGLRenderTargetDataImpl()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    
    m_FrameBuffer = System::GlDeleteFramebuffers(m_FrameBuffer);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::OpenGLRenderTargetDataImpl
    ::IsValid() const noexcept
{
    if(1 <= m_NumTargets && m_ColorTextures.size() == static_cast<uint32_t>(m_NumTargets) &&
       m_DrawBuffers.size() == static_cast<uint32_t>(m_NumTargets) &&
       0 < m_FrameBuffer)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT


void Rendering::OpenGLRenderTargetDataImpl
    ::Enable (Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlBindFramebuffer(m_FrameBuffer);
	System::GetGlDrawBuffers(m_NumTargets, &m_DrawBuffers[0]);

	System::GetGlIntegerv(System::OpenGLQuery::Viewport, m_PrevViewport);
	System::GetGlDoublev(System::OpenGLQuery::DepthRange, m_PrevDepthRange);
    System::SetGlViewport(0, 0, m_Width, m_Height);
	System::SetGlDepthRange(0.0, 1.0);
    
    SYSTEM_UNUSED_ARG(renderer);
}

void Rendering::OpenGLRenderTargetDataImpl
   ::Disable (Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlBindFramebuffer(0);

    if (m_HasMipmaps)
    {
        UInt previousBind = GetBoundTexture(ShaderFlags::SamplerType::Sampler2D);
  
        for (int i = 0; i < m_NumTargets; ++i)
        {
			System::SetGlGenerateMipmap(System::TextureTarget::Texture2D,m_ColorTextures[i]);
        }
        
		System::SetGlBindTexture(System::TextureTarget::Texture2D, previousBind);
    }

    System::SetGlViewport(m_PrevViewport[0], m_PrevViewport[1], m_PrevViewport[2], m_PrevViewport[3]);
	System::SetGlDepthRange(m_PrevDepthRange[0], m_PrevDepthRange[1]);
    
    SYSTEM_UNUSED_ARG(renderer);
}

Rendering::ConstTexture2DSmartPointer
    Rendering::OpenGLRenderTargetDataImpl
    ::ReadColor (int index, Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;

    Enable(renderer);
    
    Texture2DSmartPointer texture(NEW0 Texture2D(m_Format, m_Width, m_Height, 1));

	System::SetGlReadBuffer(static_cast<GLenum>(System::ColorAttachent::Color0) + index);

    System::GlReadPixels(m_Width,m_Height,System::TextureFormat(g_OpenGLTextureFormat[System::EnumCastUnderlying(m_Format)]),
                         System::OpenGLData(g_OpenGLTextureType[System::EnumCastUnderlying(m_Format)]),texture->GetTextureData(0));

    Disable(renderer);

	return texture.PolymorphicCastConstObjectSmartPointer<ConstTexture2DSmartPointer>();
}


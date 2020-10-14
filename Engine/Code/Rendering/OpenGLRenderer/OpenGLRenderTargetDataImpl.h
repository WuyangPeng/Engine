// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:05)

#ifndef RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_IMPL_H
#define RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Rendering
{
	class Renderer;
	class RenderTarget;

    class RENDERING_HIDDEN_DECLARE OpenGLRenderTargetDataImpl : boost::noncopyable
    {
    public:
		using ClassType = OpenGLRenderTargetDataImpl;
        using UInt = System::OpenGLUInt;
        using Enum = System::OpenGLEnum;

    public:
        OpenGLRenderTargetDataImpl (Renderer* renderer,const RenderTarget* renderTarget); 
		virtual ~OpenGLRenderTargetDataImpl();
		OpenGLRenderTargetDataImpl(const OpenGLRenderTargetDataImpl&) = default;
		OpenGLRenderTargetDataImpl& operator=(const OpenGLRenderTargetDataImpl&) = default;
		OpenGLRenderTargetDataImpl( OpenGLRenderTargetDataImpl&&) = default;
		OpenGLRenderTargetDataImpl& operator=( OpenGLRenderTargetDataImpl&&) = default;
        
		CLASS_INVARIANT_DECLARE;

        // 渲染目标的操作。
        virtual void Enable (Renderer* renderer) noexcept;
		virtual void Disable (Renderer* renderer) noexcept;
        virtual ConstTexture2DSharedPtr ReadColor(int index,Renderer* renderer);
        
    private:
        void CreateFramebufferObject() noexcept;
        UInt CreateDrawBuffers(Renderer* renderer, const RenderTarget* renderTarget);
        void CreateDepthStencilTexture(Renderer* renderer,const RenderTarget* renderTarget,UInt previousBind);
        void CheckFramebufferStatus();
   
    private:
        int m_NumTargets;
        int m_Width;
        int m_Height;
        TextureFormat m_Format;
        bool m_HasMipmaps;
        bool m_HasDepthStencil;

        std::vector<UInt> m_ColorTextures;
        UInt m_DepthStencilTexture;
        UInt m_FrameBuffer;
        std::vector<Enum> m_DrawBuffers;
        int m_PrevViewport[4];
        double m_PrevDepthRange[2];
    };
}

#endif // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_IMPL_H

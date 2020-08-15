// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:04)

#ifndef RENDERING_RENDERERS_OPENGL_RENDER_TARGET_H
#define RENDERING_RENDERERS_OPENGL_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "OpenGLRenderTargetData.h"
#include "Rendering/Renderers/Detail/PlatformRenderTargetImpl.h"

namespace Rendering
{
	class Renderer;
	class RenderTarget;

    class OpenGLRenderTarget : public PlatformRenderTargetImpl
    {
    public:
		using ClassType = OpenGLRenderTarget;
		using ParentType = PlatformRenderTargetImpl;
        
    public:
        OpenGLRenderTarget (Renderer* renderer,const RenderTarget* renderTarget);
 
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

          void Enable (Renderer* renderer) noexcept override;
		  void Disable (Renderer* renderer) noexcept override;
          ConstTexture2DSmartPointer ReadColor(int index,Renderer* renderer) override;
   
    private:
        OpenGLRenderTargetData m_OpenGLRenderTargetData;
    };
}

#endif // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_H

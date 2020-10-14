// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:05)

#ifndef RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H
#define RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(OpenGLRenderTargetDataImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING); 

namespace Rendering
{
	class Renderer;
	class RenderTarget;

    class RENDERING_DEFAULT_DECLARE OpenGLRenderTargetData : private boost::noncopyable
    {
    public:
		NON_COPY_CLASSES_TYPE_DECLARE(OpenGLRenderTargetData);

    public:
        OpenGLRenderTargetData (Renderer* renderer,const RenderTarget* renderTarget);
        
		CLASS_INVARIANT_DECLARE;
		
		// 渲染目标的操作。
        void Enable (Renderer* renderer) noexcept;
		void Disable (Renderer* renderer) noexcept;
        ConstTexture2DSharedPtr ReadColor(int index,Renderer* renderer);

	private:
		IMPL_TYPE_DECLARE(OpenGLRenderTargetData);     
    };
}

#endif // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H

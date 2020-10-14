// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:31)

#ifndef RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H
#define RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Texture2D.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformRenderTargetImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class Renderer;
	class RenderTarget;
	class Texture2D;
	
	class RENDERING_DEFAULT_DECLARE PlatformRenderTarget : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformRenderTarget);		 

	public:
		PlatformRenderTarget (Renderer* renderer,const RenderTarget* renderTarget); 

		CLASS_INVARIANT_DECLARE;

		// 渲染目标的操作。
		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);
        ConstTexture2DSharedPtr ReadColor(int index,Renderer* renderer);
	
	private:
		IMPL_TYPE_DECLARE(PlatformRenderTarget);        
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H

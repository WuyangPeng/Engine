// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:06)

#ifndef RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_IMPL_H
#define RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture2D.h"

#include <map>
#include "../../Resources/RenderTarget.h"

namespace Rendering
{
    class Renderer;
	class RenderTarget;
	class PlatformRenderTarget;

	class RENDERING_HIDDEN_DECLARE RenderTargetManagementImpl
	{
	public:
		using ClassType = RenderTargetManagementImpl;
		using RenderTargetConstPtr = ConstRenderTargetSharedPtr;
		using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
	    using RendererPtr = std::shared_ptr<Renderer>;
		
	public:
		explicit RenderTargetManagementImpl(std::shared_ptr<Renderer> ptr);

		CLASS_INVARIANT_DECLARE;
        
        void Bind (RenderTargetConstPtr renderTarget);
        void Unbind (RenderTargetConstPtr renderTarget);
        void Enable (RenderTargetConstPtr renderTarget);
        void Disable (RenderTargetConstPtr renderTarget);
        ConstTexture2DSharedPtr ReadColor(int index,RenderTargetConstPtr renderTarget);

        PlatformRenderTargetSharedPtr GetResource (RenderTargetConstPtr renderTarget);
        
	private:
       using RenderTargetMap = std::map<RenderTargetConstPtr, PlatformRenderTargetSharedPtr>;

	private:
		std::weak_ptr<Renderer> m_Renderer;
	   RenderTargetMap m_RenderTargets;
	};
}

#endif // RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_IMPL_H



	
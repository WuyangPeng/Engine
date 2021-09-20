// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:39)

#ifndef RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H
#define RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Texture2D.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>
#include "../Resources/RenderTarget.h"

RENDERING_NON_COPY_EXPORT_IMPL(RenderTargetManagementImpl);


namespace Rendering
{
    class Renderer;
	class RenderTarget;
	class PlatformRenderTarget;

	class RENDERING_DEFAULT_DECLARE RenderTargetManagement  
	{
	public:
		NON_COPY_TYPE_DECLARE(RenderTargetManagement);
		using RenderTargetConstPtr = std::shared_ptr<const RenderTarget>;
		using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
	    using RendererPtr = std::shared_ptr<Renderer>;

	public:
		explicit RenderTargetManagement(RendererPtr ptr);
            ~RenderTargetManagement() noexcept = default;
                RenderTargetManagement(const RenderTargetManagement& rhs) noexcept = delete;
            RenderTargetManagement& operator=(const RenderTargetManagement& rhs) noexcept = delete;
                RenderTargetManagement(RenderTargetManagement&& rhs) noexcept = delete;
            RenderTargetManagement& operator=(RenderTargetManagement&& rhs) noexcept = delete;
		CLASS_INVARIANT_DECLARE;
        
        void Bind (RenderTargetConstPtr renderTarget);
        void Unbind (RenderTargetConstPtr renderTarget);
        void Enable (RenderTargetConstPtr renderTarget);
        void Disable (RenderTargetConstPtr renderTarget);
        ConstTexture2DSharedPtr ReadColor(int index,RenderTargetConstPtr renderTarget);

        PlatformRenderTargetSharedPtr GetResource (RenderTargetConstPtr renderTarget);
        
	private:
        PackageType impl;
	};
}

#endif // RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H



	
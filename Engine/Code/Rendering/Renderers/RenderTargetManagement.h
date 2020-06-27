// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:39)

#ifndef RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H
#define RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Texture2D.h"

#include <boost/noncopyable.hpp>
#include "../Resources/RenderTarget.h"

RENDERING_EXPORT_SHARED_PTR(RenderTargetManagementImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
    class Renderer;
	class RenderTarget;
	class PlatformRenderTarget;

	class RENDERING_DEFAULT_DECLARE RenderTargetManagement : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(RenderTargetManagement);
		using RenderTargetConstPtr = CoreTools::ConstThirdSubclassSmartPointer<RenderTarget>;
		using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
	    using RendererPtr = std::shared_ptr<Renderer>;

	public:
		explicit RenderTargetManagement(RendererPtr ptr);

		CLASS_INVARIANT_DECLARE;
        
        void Bind (RenderTargetConstPtr renderTarget);
        void Unbind (RenderTargetConstPtr renderTarget);
        void Enable (RenderTargetConstPtr renderTarget);
        void Disable (RenderTargetConstPtr renderTarget);
        ConstTexture2DSmartPointer ReadColor(int index,RenderTargetConstPtr renderTarget);

        PlatformRenderTargetSharedPtr GetResource (RenderTargetConstPtr renderTarget);
        
	private:
        IMPL_TYPE_DECLARE(RenderTargetManagement);
	};
}

#endif // RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H



	
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
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(OpenGLRenderTargetDataImpl);

namespace Rendering
{
	class Renderer;
	class RenderTarget;

    class RENDERING_DEFAULT_DECLARE OpenGLRenderTargetData
    {
    public:
		NON_COPY_TYPE_DECLARE(OpenGLRenderTargetData);

    public:
        OpenGLRenderTargetData (Renderer* renderer,const RenderTarget* renderTarget);
        ~OpenGLRenderTargetData() noexcept = default;
        OpenGLRenderTargetData(const OpenGLRenderTargetData& rhs) noexcept = delete;
        OpenGLRenderTargetData& operator=(const OpenGLRenderTargetData& rhs) noexcept = delete;
        OpenGLRenderTargetData(OpenGLRenderTargetData&& rhs) noexcept = delete;
        OpenGLRenderTargetData& operator=(OpenGLRenderTargetData&& rhs) noexcept = delete;
		CLASS_INVARIANT_DECLARE;
		
		// 渲染目标的操作。
        void Enable (Renderer* renderer) noexcept;
		void Disable (Renderer* renderer) noexcept;
        ConstTexture2DSharedPtr ReadColor(int index,Renderer* renderer);

	private:
        PackageType impl;   
    };
}

#endif // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H

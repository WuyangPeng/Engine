///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/24 21:07)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RENDER_TARGET_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTexture2.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/TextureRenderTarget.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureRenderTarget : public OpenGLTexture2
    {
    public:
        using ClassType = OpenGLTextureRenderTarget;
        using ParentType = OpenGLTexture2;

    public:
        OpenGLTextureRenderTarget(const TextureRenderTargetSharedPtr& textureRenderTarget, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTextureRenderTargetSharedPtr GetTextureRenderTarget() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_RENDER_TARGET_H
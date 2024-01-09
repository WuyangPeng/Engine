/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:48)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RENDER_TARGET_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTexture2.h"
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
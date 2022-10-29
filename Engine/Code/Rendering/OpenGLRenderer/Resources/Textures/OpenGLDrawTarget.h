///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/26 16:14)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DRAW_TARGET_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DRAW_TARGET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Base/RendererDrawTarget.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureDepthStencil.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureRenderTarget.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLDrawTarget, OpenGLDrawTargetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLDrawTarget : public RendererDrawTarget
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLDrawTarget);
        using ParentType = RendererDrawTarget;

        using OpenGLTextureRenderTargetSharedPtr = std::shared_ptr<OpenGLTextureRenderTarget>;
        using ConstOpenGLTextureRenderTargetSharedPtr = std::shared_ptr<const OpenGLTextureRenderTarget>;
        using OpenGLTextureRenderTargetContainer = std::vector<OpenGLTextureRenderTargetSharedPtr>;
        using OpenGLTextureDepthStencilSharedPtr = std::shared_ptr<OpenGLTextureDepthStencil>;
        using ConstOpenGLTextureDepthStencilSharedPtr = std::shared_ptr<const OpenGLTextureDepthStencil>;

    public:
        OpenGLDrawTarget(const DrawTargetSharedPtr& target,
                         const OpenGLTextureRenderTargetContainer& renderTargetTextures,
                         const OpenGLTextureDepthStencilSharedPtr& depthStencilTexture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstOpenGLTextureRenderTargetSharedPtr GetRenderTargetTexture(int index) const;

        NODISCARD ConstOpenGLTextureDepthStencilSharedPtr GetDepthStencilTexture() const noexcept;

        void Enable();
        void Disable();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DRAW_TARGET_H
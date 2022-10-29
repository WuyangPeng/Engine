///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/24 21:02)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTexture2.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/TextureDepthStencil.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureDepthStencil : public OpenGLTexture2
    {
    public:
        using ClassType = OpenGLTextureDepthStencil;
        using ParentType = OpenGLTexture2;

    public:
        OpenGLTextureDepthStencil(const TextureDepthStencilSharedPtr& textureDepthStencil, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTextureDepthStencilSharedPtr GetTextureDepthStencil() const;

        NODISCARD bool CanAutoGenerateMipmaps() const noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_H
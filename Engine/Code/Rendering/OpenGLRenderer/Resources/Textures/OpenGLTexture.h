/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/08 15:02)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/OpenGLRenderer/Resources/OpenGLResource.h"
#include "Rendering/Resources/Textures/Texture.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTexture : public OpenGLResource
    {
    public:
        using ClassType = OpenGLTexture;
        using ParentType = OpenGLResource;

        using OpenGLInt = System::OpenGLInt;
        using OpenGLData = System::OpenGLData;
        using TextureTarget = System::TextureTarget;
        using TextureTargetBinding = System::TextureTargetBinding;
        using TextureInternalFormat = System::TextureInternalFormat;
        using TextureExternalFormat = System::TextureExternalFormat;

    public:
        OpenGLTexture(const TextureSharedPtr& texture, const std::string& name, TextureTarget target, TextureTargetBinding targetBinding);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTextureSharedPtr GetTexture() const;

        NODISCARD TextureTarget GetTarget() const noexcept;
        NODISCARD TextureTargetBinding GetTargetBinding() const noexcept;

        NODISCARD static TextureInternalFormat GetGLTextureInternalFormat(DataFormatType dataFormatType);
        NODISCARD static TextureExternalFormat GetGLTextureExternalFormat(DataFormatType dataFormatType);
        NODISCARD static OpenGLData GetGLTextureExternalType(ChannelType channelType);

        NODISCARD OpenGLInt GetNumLevels() const noexcept;
        NODISCARD TextureInternalFormat GetInternalFormat() const noexcept;
        NODISCARD TextureExternalFormat GetExternalFormat() const noexcept;
        NODISCARD OpenGLData GetExternalType() const noexcept;

    private:
        TextureTarget target;
        TextureTargetBinding targetBinding;

        OpenGLInt numLevels;
        TextureInternalFormat internalFormat;
        TextureExternalFormat externalFormat;
        OpenGLData externalType;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_H
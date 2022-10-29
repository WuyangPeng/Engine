///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/24 11:07)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE2_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE2_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureSingle.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/Texture2D.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTexture2 : public OpenGLTextureSingle
    {
    public:
        using ClassType = OpenGLTexture2;
        using ParentType = OpenGLTextureSingle;

    public:
        OpenGLTexture2(const Texture2DSharedPtr& texture2D, const std::string& name);
        ~OpenGLTexture2() noexcept;
        OpenGLTexture2(const OpenGLTexture2& rhs) = default;
        OpenGLTexture2& operator=(const OpenGLTexture2& rhs) = default;
        OpenGLTexture2(OpenGLTexture2&& rhs) noexcept = default;
        OpenGLTexture2& operator=(OpenGLTexture2&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTexture2DSharedPtr GetTexture2D() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

        void Enable() noexcept override;

    protected:
        void LoadTextureLevel(int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE2_H
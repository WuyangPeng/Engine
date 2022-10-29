///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/24 11:07)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE3_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE3_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureSingle.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/Texture3D.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTexture3 : public OpenGLTextureSingle
    {
    public:
        using ClassType = OpenGLTexture3;
        using ParentType = OpenGLTextureSingle;

    public:
        OpenGLTexture3(const Texture3DSharedPtr& texture3D, const std::string& name);
        ~OpenGLTexture3() noexcept;
        OpenGLTexture3(const OpenGLTexture3& rhs) = default;
        OpenGLTexture3& operator=(const OpenGLTexture3& rhs) = default;
        OpenGLTexture3(OpenGLTexture3&& rhs) noexcept = default;
        OpenGLTexture3& operator=(OpenGLTexture3&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTexture3DSharedPtr GetTexture3D() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

        void Enable() noexcept override;

    protected:
        void LoadTextureLevel(int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE3_H
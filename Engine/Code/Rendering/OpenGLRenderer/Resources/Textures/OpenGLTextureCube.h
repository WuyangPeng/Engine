///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/26 10:44)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureArray.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/TextureCube.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureCube : public OpenGLTextureArray
    {
    public:
        using ClassType = OpenGLTextureCube;
        using ParentType = OpenGLTextureArray;

    public:
        OpenGLTextureCube(const TextureCubeSharedPtr& textureCube, const std::string& name);
        ~OpenGLTextureCube() noexcept;
        OpenGLTextureCube(const OpenGLTextureCube& rhs) = default;
        OpenGLTextureCube& operator=(const OpenGLTextureCube& rhs) = default;
        OpenGLTextureCube(OpenGLTextureCube&& rhs) noexcept = default;
        OpenGLTextureCube& operator=(OpenGLTextureCube&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTextureCubeSharedPtr GetTextureCube() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

        void Enable() noexcept override;

    protected:
        void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H

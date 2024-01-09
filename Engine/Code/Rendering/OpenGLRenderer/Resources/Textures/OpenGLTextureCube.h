/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:39)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureArray.h"
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

    protected:
        void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H

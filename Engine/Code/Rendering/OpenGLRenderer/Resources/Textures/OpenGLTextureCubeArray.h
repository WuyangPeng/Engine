/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:43)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_ARRAY_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureArray.h"
#include "Rendering/Resources/Textures/TextureCubeArray.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureCubeArray : public OpenGLTextureArray
    {
    public:
        using ClassType = OpenGLTextureCubeArray;
        using ParentType = OpenGLTextureArray;

    public:
        OpenGLTextureCubeArray(const TextureCubeArraySharedPtr& textureCubeArray, const std::string& name);
        ~OpenGLTextureCubeArray() noexcept;
        OpenGLTextureCubeArray(const OpenGLTextureCubeArray& rhs) = default;
        OpenGLTextureCubeArray& operator=(const OpenGLTextureCubeArray& rhs) = default;
        OpenGLTextureCubeArray(OpenGLTextureCubeArray&& rhs) noexcept = default;
        OpenGLTextureCubeArray& operator=(OpenGLTextureCubeArray&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTextureCubeArraySharedPtr GetTextureCubeArray() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

    protected:
        void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_ARRAY_H

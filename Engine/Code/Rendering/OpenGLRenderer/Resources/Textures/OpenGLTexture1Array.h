/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:15)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE1_ARRAY_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE1_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureArray.h"
#include "Rendering/Resources/Textures/Texture1DArray.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTexture1Array : public OpenGLTextureArray
    {
    public:
        using ClassType = OpenGLTexture1Array;
        using ParentType = OpenGLTextureArray;

    public:
        OpenGLTexture1Array(const Texture1DArraySharedPtr& texture1Array, const std::string& name);
        ~OpenGLTexture1Array() noexcept;
        OpenGLTexture1Array(const OpenGLTexture1Array& rhs) = default;
        OpenGLTexture1Array& operator=(const OpenGLTexture1Array& rhs) = default;
        OpenGLTexture1Array(OpenGLTexture1Array&& rhs) noexcept = default;
        OpenGLTexture1Array& operator=(OpenGLTexture1Array&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTexture1DArraySharedPtr GetTexture1DArray() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

    protected:
        void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE1_ARRAY_H
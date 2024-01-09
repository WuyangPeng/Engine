/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:25)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE2_ARRAY_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE2_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureArray.h"
#include "Rendering/Resources/Textures/Texture2DArray.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTexture2Array : public OpenGLTextureArray
    {
    public:
        using ClassType = OpenGLTexture2Array;
        using ParentType = OpenGLTextureArray;

    public:
        OpenGLTexture2Array(const Texture2DArraySharedPtr& texture2Array, const std::string& name);
        ~OpenGLTexture2Array() noexcept;
        OpenGLTexture2Array(const OpenGLTexture2Array& rhs) = default;
        OpenGLTexture2Array& operator=(const OpenGLTexture2Array& rhs) = default;
        OpenGLTexture2Array(OpenGLTexture2Array&& rhs) noexcept = default;
        OpenGLTexture2Array& operator=(OpenGLTexture2Array&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTexture2DArraySharedPtr GetTexture2DArray() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

    protected:
        void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE2_ARRAY_H
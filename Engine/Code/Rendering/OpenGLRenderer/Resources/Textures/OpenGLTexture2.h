///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:19)

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
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/23 21:34)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE1_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE1_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureSingle.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/Texture1D.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTexture1 : public OpenGLTextureSingle
    {
    public:
        using ClassType = OpenGLTexture1;
        using ParentType = OpenGLTextureSingle;

    public:
        OpenGLTexture1(const Texture1DSharedPtr& texture1D, const std::string& name);
        ~OpenGLTexture1() noexcept;
        OpenGLTexture1(const OpenGLTexture1& rhs) = default;
        OpenGLTexture1& operator=(const OpenGLTexture1& rhs) = default;
        OpenGLTexture1(OpenGLTexture1&& rhs) noexcept = default;
        OpenGLTexture1& operator=(OpenGLTexture1&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTexture1DSharedPtr GetTexture1D() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

        void Enable() noexcept override;

    protected:
        void LoadTextureLevel(int level, const ConstSpanIterator& data) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE1_H
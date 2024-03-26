/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 15:48)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_SINGLE_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_SINGLE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

#include <array>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLTextureSingleImpl
    {
    public:
        using ClassType = OpenGLTextureSingleImpl;

        using OpenGLUInt = System::OpenGLUnsignedInt;

    public:
        OpenGLTextureSingleImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLUInt GetLevelPixelUnpackBuffer(int index) const;
        NODISCARD OpenGLUInt GetLevelPixelPackBuffer(int index) const;

        void SetLevelPixelUnpackBuffer(int index, OpenGLUInt buffer);
        void SetLevelPixelPackBuffer(int index, OpenGLUInt buffer);

    private:
        using Container = std::array<OpenGLUInt, textureMaximumMipmapLevels>;

    private:
        Container levelPixelUnpackBuffer;
        Container levelPixelPackBuffer;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_SINGLE_IMPL_H
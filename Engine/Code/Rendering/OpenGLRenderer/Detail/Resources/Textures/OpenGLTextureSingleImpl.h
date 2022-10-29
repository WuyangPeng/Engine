///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/23 0:57)

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
        using OpenGLUInt = System::OpenGLUInt;

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
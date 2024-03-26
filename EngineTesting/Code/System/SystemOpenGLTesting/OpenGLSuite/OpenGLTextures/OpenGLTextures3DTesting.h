/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:40)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_3D_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_3D_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

namespace System
{
    class OpenGLTextures3DTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLTextures3DTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLTextures3DTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Textures3DTest(TextureTarget textureTarget);
        void DoTextures3DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat);
        void SetTextures3DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat);

    private:
        static constexpr auto width = 128;
        static constexpr auto height = 64;
        static constexpr auto depth = 32;
        static constexpr auto openGLData = OpenGLData::Byte;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_3D_TESTING_H
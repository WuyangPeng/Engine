///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 15:41)

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
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLTextures3DTest(TextureTarget textureTarget);
        void DoOpenGLTextures3DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat);

    private:
        static constexpr auto width = 128;
        static constexpr auto height = 64;
        static constexpr auto depth = 32;
        static constexpr auto openGLData = OpenGLData::Byte;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_3D_TESTING_H
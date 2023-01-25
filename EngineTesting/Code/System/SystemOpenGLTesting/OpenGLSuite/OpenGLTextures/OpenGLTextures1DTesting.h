///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 15:41)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_1D_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_1D_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

namespace System
{
    class OpenGLTextures1DTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLTextures1DTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLTextures1DTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLTextures1DTest();
        void DoOpenGLTextures1DTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureInternalFormat textureInternalFormat);

    private:
        static constexpr auto width = 256;
        static constexpr auto textureTarget = TextureTarget::Texture1D;
        static constexpr auto openGLData = OpenGLData::Byte;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_1D_TESTING_H
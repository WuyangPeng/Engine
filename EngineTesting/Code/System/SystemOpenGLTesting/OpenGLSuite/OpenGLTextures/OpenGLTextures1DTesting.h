/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:40)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_1D_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_1D_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"

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
        void DoRunUnitTest() override;
        void MainTest();

        void Textures1DTest();
        void DoTextures1DTest(TextureInternalFormat textureInternalFormat);
        void SetTextures1DTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureInternalFormat textureInternalFormat);

    private:
        static constexpr auto width = 256;
        static constexpr auto textureTarget = TextureTarget::Texture1D;
        static constexpr auto openGLData = OpenGLData::Byte;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_1D_TESTING_H
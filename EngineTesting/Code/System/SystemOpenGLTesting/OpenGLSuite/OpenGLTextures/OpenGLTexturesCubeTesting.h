///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/21 13:34)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

namespace System
{
    class OpenGLTexturesCubeTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLTexturesCubeTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLTexturesCubeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLTexturesCubeTest();
        void DoOpenGLTexturesCubeTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureInternalFormat textureInternalFormat);
        void GetGLTexturesLevelParameterTest();

        NODISCARD TexturesImageType GetTexturesData(TextureInternalFormat textureInternalFormat);
        NODISCARD TexturesImageType GetTexturesDataResult(TextureInternalFormat textureInternalFormat);

    private:
        static constexpr auto width = 256;
        static constexpr auto height = 256;
        static constexpr auto textureTarget = TextureTarget::TextureCubeMap;
        static constexpr auto openGLData = OpenGLData::Byte;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_TESTING_H
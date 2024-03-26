/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:40)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_TESTING_H

#include "OpenGLTexturesCubeArrayTesting.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void TexturesCubeTest();
        void DoTexturesCubeTest(TextureInternalFormat textureInternalFormat);
        void SetTexturesCubeTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureInternalFormat textureInternalFormat);
        void GetTexturesLevelParameterTest();
        void DoGetTexturesLevelParameterTest(TextureCubeMap target);

        NODISCARD TexturesImageType GetTexturesData(TextureInternalFormat textureInternalFormat) const;
        NODISCARD TexturesImageType GetTexturesDataResult(TextureInternalFormat textureInternalFormat) const;

    private:
        static constexpr auto width = 256;
        static constexpr auto height = 256;
        static constexpr auto textureTarget = TextureTarget::TextureCubeMap;
        static constexpr auto openGLData = OpenGLData::Byte;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_TESTING_H
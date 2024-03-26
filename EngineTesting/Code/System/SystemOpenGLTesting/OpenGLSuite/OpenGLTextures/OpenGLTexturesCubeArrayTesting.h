/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:40)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_ARRAY_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_ARRAY_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"

namespace System
{
    class OpenGLTexturesCubeArrayTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLTexturesCubeArrayTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLTexturesCubeArrayTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TexturesCubeTest();
        void DoTexturesCubeTest(TextureInternalFormat textureInternalFormat);
        void SetTexturesCubeTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture);
        void GetTexturesImageTest(TextureInternalFormat textureInternalFormat);
        void GetGLTexturesLevelParameterTest();

        NODISCARD TexturesImageType GetTexturesData(TextureInternalFormat textureInternalFormat) const;
        NODISCARD TexturesImageType GetTexturesDataResult(TextureInternalFormat textureInternalFormat) const;

    private:
        static constexpr auto width = 32;
        static constexpr auto height = 32;
        static constexpr auto depth = 6;
        static constexpr auto textureTarget = TextureTarget::TextureCubeMapArray;
        static constexpr auto openGLData = OpenGLData::Byte;

        static_assert(depth % 6 == 0, "depthֵ������6�ı�����");
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_TEXTURES_CUBE_ARRAY_TESTING_H
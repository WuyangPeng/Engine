/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/16 20:32)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_TEXTURES_IMAGE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_TEXTURES_IMAGE_H

#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Helper/UserMacro.h"

#include <vector>

namespace System
{

    class TexturesImage final
    {
    public:
        using ClassType = TexturesImage;

        using Container = std::vector<char>;

    public:
        TexturesImage(int width, int height, TextureExternalFormat textureExternalFormat, int texturesImageSize, OpenGLData openGLData) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Container GetTexturesImage() const;

        void SetTexturesSubImage2D(char imageValue, TextureCubeMap textureCubeMap);
        void GetTexturesImage2D(TextureCubeMap textureCubeMap);

    private:
        int width;
        int height;
        TextureExternalFormat textureExternalFormat;
        int texturesImageSize;
        OpenGLData openGLData;

        Container texturesImage;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_TEXTURES_IMAGE_H
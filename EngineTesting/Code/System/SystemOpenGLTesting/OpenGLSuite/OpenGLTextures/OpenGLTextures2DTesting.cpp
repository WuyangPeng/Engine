///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:28)

#include "OpenGLTextures2DTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTextures2DTesting::OpenGLTextures2DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTextures2DTesting)

void System::OpenGLTextures2DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLTextures2DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(OpenGLTextures2DTest, TextureTarget::Texture2D);
    ASSERT_NOT_THROW_EXCEPTION_1(OpenGLTextures2DTest, TextureTarget::Texture1DArray);
}

void System::OpenGLTextures2DTesting::OpenGLTextures2DTest(TextureTarget textureTarget)
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        const auto texture = GetGLGenTextures();
        ASSERT_LESS(0u, texture);

        ASSERT_NOT_THROW_EXCEPTION_3(DoOpenGLTextures2DTest, textureTarget, *iter, texture);

        ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTextureTest, texture);
    }
}

void System::OpenGLTextures2DTesting::DoOpenGLTextures2DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat, OpenGLInt texture)
{
    SetGLBindTexture(textureTarget, texture);

    SetGLTexturesStorage2D(textureTarget, 1, textureInternalFormat, width, height);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Width), width);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Height), height);

    ASSERT_NOT_THROW_EXCEPTION_2(GetTexturesImageTest, textureTarget, textureInternalFormat);

    SetGLGenerateMipmap(textureTarget);
}

void System::OpenGLTextures2DTesting::GetTexturesImageTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat)
{
    const auto texturesImageSize = width * height * GetTextureFormatSize(textureInternalFormat);

    const TexturesImageType texturesData(texturesImageSize, 121);
    SetGLTexturesSubImage2D(textureTarget, 0, 0, 0, width, height, GetTextureExternalFormat(textureInternalFormat), openGLData, texturesData.data());

    TexturesImageType result(texturesImageSize);
    GetGLTexturesImage(textureTarget, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, result.data());

    ASSERT_EQUAL(texturesData, result);
}

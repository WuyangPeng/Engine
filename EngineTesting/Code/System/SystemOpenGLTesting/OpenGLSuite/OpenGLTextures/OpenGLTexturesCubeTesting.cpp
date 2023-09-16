///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:28)

#include "OpenGLTexturesCubeTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTexturesCubeTesting::OpenGLTexturesCubeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTexturesCubeTesting)

void System::OpenGLTexturesCubeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLTexturesCubeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLTexturesCubeTest);
}

void System::OpenGLTexturesCubeTesting::OpenGLTexturesCubeTest()
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        if (*iter == TextureInternalFormat::R11F_G11F_B10F)
        {
            continue;
        }

        const auto texture = GetGLGenTextures();
        ASSERT_LESS(0u, texture);

        ASSERT_NOT_THROW_EXCEPTION_2(DoOpenGLTexturesCubeTest, *iter, texture);

        ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTextureTest, texture);
    }
}

void System::OpenGLTexturesCubeTesting::DoOpenGLTexturesCubeTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture)
{
    SetGLBindTexture(textureTarget, texture);

    SetGLTexturesStorage2D(textureTarget, 1, textureInternalFormat, width, height);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    ASSERT_NOT_THROW_EXCEPTION_0(GetGLTexturesLevelParameterTest);

    ASSERT_NOT_THROW_EXCEPTION_1(GetTexturesImageTest, textureInternalFormat);

    SetGLGenerateMipmap(textureTarget);
}

void System::OpenGLTexturesCubeTesting::GetGLTexturesLevelParameterTest()
{
    for (auto iter = GetTextureCubeMapBegin(); iter != GetTextureCubeMapEnd(); ++iter)
    {
        ASSERT_EQUAL(GetGLTexturesLevelParameter(*iter, 0, TextureLevelParameter::Width), width);
        ASSERT_EQUAL(GetGLTexturesLevelParameter(*iter, 0, TextureLevelParameter::Height), height);
    }
}

void System::OpenGLTexturesCubeTesting::GetTexturesImageTest(TextureInternalFormat textureInternalFormat)
{
    const auto texturesData = GetTexturesData(textureInternalFormat);
    const auto result = GetTexturesDataResult(textureInternalFormat);

    ASSERT_EQUAL(texturesData, result);
}

System::OpenGLTexturesCubeTesting::TexturesImageType System::OpenGLTexturesCubeTesting::GetTexturesData(TextureInternalFormat textureInternalFormat)
{
    const auto texturesImageSize = width * height * GetTextureFormatSize(textureInternalFormat);

    TexturesImageType texturesData{};
    auto imageValue = 'a';
    for (auto iter = GetTextureCubeMapBegin(); iter != GetTextureCubeMapEnd(); ++iter)
    {
        TexturesImageType image(texturesImageSize, imageValue);
        SetGLTexturesSubImage2D(*iter, 0, 0, 0, width, height, GetTextureExternalFormat(textureInternalFormat), openGLData, image.data());
        texturesData.insert(texturesData.cend(), image.cbegin(), image.cend());
        ++imageValue;
    }

    return texturesData;
}

System::OpenGLTexturesCubeTesting::TexturesImageType System::OpenGLTexturesCubeTesting::GetTexturesDataResult(TextureInternalFormat textureInternalFormat)
{
    const auto texturesImageSize = width * height * GetTextureFormatSize(textureInternalFormat);

    TexturesImageType result{};
    for (auto iter = GetTextureCubeMapBegin(); iter != GetTextureCubeMapEnd(); ++iter)
    {
        TexturesImageType image(texturesImageSize);
        GetGLTexturesImage(*iter, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, image.data());
        result.insert(result.cend(), image.cbegin(), image.cend());
    }

    return result;
}

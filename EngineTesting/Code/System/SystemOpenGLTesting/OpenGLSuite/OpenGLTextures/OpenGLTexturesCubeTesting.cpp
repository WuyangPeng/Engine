/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:37)

#include "OpenGLTexturesCubeTesting.h"
#include "Detail/TexturesImage.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(TexturesCubeTest);
}

void System::OpenGLTexturesCubeTesting::TexturesCubeTest()
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        if (*iter != TextureInternalFormat::R11F_G11F_B10F)
        {
            ASSERT_NOT_THROW_EXCEPTION_1(DoTexturesCubeTest, *iter);
        }
    }
}

void System::OpenGLTexturesCubeTesting::DoTexturesCubeTest(TextureInternalFormat textureInternalFormat)
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_2(SetTexturesCubeTest, textureInternalFormat, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLTexturesCubeTesting::SetTexturesCubeTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture)
{
    SetGLBindTexture(textureTarget, texture);

    SetGLTexturesStorage2D(textureTarget, 1, textureInternalFormat, width, height);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    ASSERT_NOT_THROW_EXCEPTION_0(GetTexturesLevelParameterTest);

    ASSERT_NOT_THROW_EXCEPTION_1(GetTexturesImageTest, textureInternalFormat);

    SetGLGenerateMipmap(textureTarget);
}

void System::OpenGLTexturesCubeTesting::GetTexturesLevelParameterTest()
{
    for (auto iter = GetTextureCubeMapBegin(); iter != GetTextureCubeMapEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetTexturesLevelParameterTest, *iter);
    }
}

void System::OpenGLTexturesCubeTesting::DoGetTexturesLevelParameterTest(TextureCubeMap target)
{
    ASSERT_EQUAL(GetGLTexturesLevelParameter(target, 0, TextureLevelParameter::Width), width);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(target, 0, TextureLevelParameter::Height), height);
}

void System::OpenGLTexturesCubeTesting::GetTexturesImageTest(TextureInternalFormat textureInternalFormat)
{
    const auto texturesData = GetTexturesData(textureInternalFormat);
    const auto result = GetTexturesDataResult(textureInternalFormat);

    ASSERT_EQUAL(texturesData, result);
}

System::OpenGLTexturesCubeTesting::TexturesImageType System::OpenGLTexturesCubeTesting::GetTexturesData(TextureInternalFormat textureInternalFormat) const
{
    const auto texturesImageSize = width * height * GetTextureFormatSize(textureInternalFormat);

    TexturesImage texturesImage{ width, height, GetTextureExternalFormat(textureInternalFormat), texturesImageSize, openGLData };
    auto imageValue = 'a';
    for (auto iter = GetTextureCubeMapBegin(); iter != GetTextureCubeMapEnd(); ++iter)
    {
        texturesImage.SetTexturesSubImage2D(imageValue, *iter);

        ++imageValue;
    }

    return texturesImage.GetTexturesImage();
}

System::OpenGLTexturesCubeTesting::TexturesImageType System::OpenGLTexturesCubeTesting::GetTexturesDataResult(TextureInternalFormat textureInternalFormat) const
{
    const auto texturesImageSize = width * height * GetTextureFormatSize(textureInternalFormat);

    TexturesImage texturesImage{ width, height, GetTextureExternalFormat(textureInternalFormat), texturesImageSize, openGLData };
    for (auto iter = GetTextureCubeMapBegin(); iter != GetTextureCubeMapEnd(); ++iter)
    {
        texturesImage.GetTexturesImage2D(*iter);
    }

    return texturesImage.GetTexturesImage();
}

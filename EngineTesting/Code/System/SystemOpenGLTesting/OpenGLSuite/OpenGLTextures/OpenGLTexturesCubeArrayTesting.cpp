/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:35)

#include "OpenGLTexturesCubeArrayTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTexturesCubeArrayTesting::OpenGLTexturesCubeArrayTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTexturesCubeArrayTesting)

void System::OpenGLTexturesCubeArrayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLTexturesCubeArrayTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TexturesCubeTest);
}

void System::OpenGLTexturesCubeArrayTesting::TexturesCubeTest()
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        if (*iter != TextureInternalFormat::DepthComponent32F &&
            *iter != TextureInternalFormat::Depth24Stencil8 &&
            *iter != TextureInternalFormat::DepthComponent16)
        {
            ASSERT_NOT_THROW_EXCEPTION_1(DoTexturesCubeTest, *iter);
        }
    }
}

void System::OpenGLTexturesCubeArrayTesting::DoTexturesCubeTest(TextureInternalFormat textureInternalFormat)
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_2(SetTexturesCubeTest, textureInternalFormat, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLTexturesCubeArrayTesting::SetTexturesCubeTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture)
{
    SetGLBindTexture(textureTarget, texture);

    SetGLTexturesStorage3D(textureTarget, 1, textureInternalFormat, width, height, depth);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    ASSERT_NOT_THROW_EXCEPTION_0(GetGLTexturesLevelParameterTest);

    ASSERT_NOT_THROW_EXCEPTION_1(GetTexturesImageTest, textureInternalFormat);

    SetGLGenerateMipmap(textureTarget);
}

void System::OpenGLTexturesCubeArrayTesting::GetGLTexturesLevelParameterTest()
{
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Width), width);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Height), height);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Depth), depth);
}

void System::OpenGLTexturesCubeArrayTesting::GetTexturesImageTest(TextureInternalFormat textureInternalFormat)
{
    const auto texturesData = GetTexturesData(textureInternalFormat);
    const auto result = GetTexturesDataResult(textureInternalFormat);

    ASSERT_EQUAL(texturesData, result);
}

System::OpenGLTexturesCubeArrayTesting::TexturesImageType System::OpenGLTexturesCubeArrayTesting::GetTexturesData(TextureInternalFormat textureInternalFormat) const
{
    const auto texturesImageSize = width * height * depth * GetTextureFormatSize(textureInternalFormat);

    TexturesImageType texturesData(texturesImageSize, 121);

    SetGLTexturesSubImage3D(textureTarget, 0, 0, 0, 0, width, height, depth, GetTextureExternalFormat(textureInternalFormat), openGLData, texturesData.data());

    return texturesData;
}

System::OpenGLTexturesCubeArrayTesting::TexturesImageType System::OpenGLTexturesCubeArrayTesting::GetTexturesDataResult(TextureInternalFormat textureInternalFormat) const
{
    const auto texturesImageSize = width * height * depth * GetTextureFormatSize(textureInternalFormat);

    TexturesImageType result(texturesImageSize);

    GetGLTexturesImage(textureTarget, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, result.data());

    return result;
}

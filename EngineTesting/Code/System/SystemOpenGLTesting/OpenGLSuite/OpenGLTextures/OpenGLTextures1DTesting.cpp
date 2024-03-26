/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:30)

#include "OpenGLTextures1DTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTextures1DTesting::OpenGLTextures1DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTextures1DTesting)

void System::OpenGLTextures1DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLTextures1DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Textures1DTest);
}

void System::OpenGLTextures1DTesting::Textures1DTest()
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoTextures1DTest, *iter);
    }
}

void System::OpenGLTextures1DTesting::DoTextures1DTest(TextureInternalFormat textureInternalFormat)
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_2(SetTextures1DTest, textureInternalFormat, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLTextures1DTesting::SetTextures1DTest(TextureInternalFormat textureInternalFormat, OpenGLInt texture)
{
    SetGLBindTexture(textureTarget, texture);

    SetGLTexturesStorage1D(textureTarget, 1, textureInternalFormat, width);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Width), width);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Height), 1);

    ASSERT_NOT_THROW_EXCEPTION_1(GetTexturesImageTest, textureInternalFormat);

    SetGLGenerateMipmap(textureTarget);
}

void System::OpenGLTextures1DTesting::GetTexturesImageTest(TextureInternalFormat textureInternalFormat)
{
    const auto texturesImageSize = width * GetTextureFormatSize(textureInternalFormat);

    const TexturesImageType texturesData(texturesImageSize, 121);
    SetGLTexturesSubImage1D(textureTarget, 0, 0, width, GetTextureExternalFormat(textureInternalFormat), openGLData, texturesData.data());

    TexturesImageType result(texturesImageSize);
    GetGLTexturesImage(textureTarget, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, result.data());

    ASSERT_EQUAL(texturesData, result);
}

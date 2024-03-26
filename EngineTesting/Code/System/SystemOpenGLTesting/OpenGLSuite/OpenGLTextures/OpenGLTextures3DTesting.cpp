/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:34)

#include "OpenGLTextures3DTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTextures3DTesting::OpenGLTextures3DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTextures3DTesting)

void System::OpenGLTextures3DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLTextures3DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(Textures3DTest, TextureTarget::Texture3D);
    ASSERT_NOT_THROW_EXCEPTION_1(Textures3DTest, TextureTarget::Texture2DArray);
}

void System::OpenGLTextures3DTesting::Textures3DTest(TextureTarget textureTarget)
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        if (*iter != TextureInternalFormat::DepthComponent32F &&
            *iter != TextureInternalFormat::Depth24Stencil8 &&
            *iter != TextureInternalFormat::DepthComponent16)
        {
            ASSERT_NOT_THROW_EXCEPTION_2(DoTextures3DTest, textureTarget, *iter);
        }
    }
}

void System::OpenGLTextures3DTesting::DoTextures3DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat)
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_3(SetTextures3DTest, textureTarget, textureInternalFormat, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLTextures3DTesting::SetTextures3DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat, OpenGLInt texture)
{
    SetGLBindTexture(textureTarget, texture);

    SetGLTexturesStorage3D(textureTarget, 1, textureInternalFormat, width, height, depth);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Width), width);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Height), height);
    ASSERT_EQUAL(GetGLTexturesLevelParameter(textureTarget, 0, TextureLevelParameter::Depth), depth);

    ASSERT_NOT_THROW_EXCEPTION_2(GetTexturesImageTest, textureTarget, textureInternalFormat);

    SetGLGenerateMipmap(textureTarget);
}

void System::OpenGLTextures3DTesting::GetTexturesImageTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat)
{
    const auto texturesImageSize = width * height * depth * GetTextureFormatSize(textureInternalFormat);

    const TexturesImageType texturesData(texturesImageSize, 123);
    SetGLTexturesSubImage3D(textureTarget, 0, 0, 0, 0, width, height, depth, GetTextureExternalFormat(textureInternalFormat), openGLData, texturesData.data());

    TexturesImageType result(texturesImageSize);
    GetGLTexturesImage(textureTarget, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, result.data());

    ASSERT_EQUAL(texturesData, result);
}

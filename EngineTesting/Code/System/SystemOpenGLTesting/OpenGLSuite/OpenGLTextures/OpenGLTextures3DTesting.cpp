///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 15:41)

#include "OpenGLTextures3DTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
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
    ASSERT_NOT_THROW_EXCEPTION_1(OpenGLTextures3DTest, TextureTarget::Texture3D);
    ASSERT_NOT_THROW_EXCEPTION_1(OpenGLTextures3DTest, TextureTarget::Texture2DArray);
}

void System::OpenGLTextures3DTesting::OpenGLTextures3DTest(TextureTarget textureTarget)
{
    for (auto iter = GetTextureInternalFormatsBegin(); iter != GetTextureInternalFormatsEnd(); ++iter)
    {
        if (*iter == TextureInternalFormat::DepthComponent32F ||
            *iter == TextureInternalFormat::Depth24Stencil8 ||
            *iter == TextureInternalFormat::DepthComponent16)
        {
            continue;
        }

        const auto texture = GetGLGenTextures();
        ASSERT_LESS(0u, texture);

        ASSERT_NOT_THROW_EXCEPTION_3(DoOpenGLTextures3DTest, textureTarget, *iter, texture);

        ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTextureTest, texture);
    }
}

void System::OpenGLTextures3DTesting::DoOpenGLTextures3DTest(TextureTarget textureTarget, TextureInternalFormat textureInternalFormat, OpenGLInt texture)
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

    TexturesImageType texturesData(texturesImageSize, 123);
    SetGLTexturesSubImage3D(textureTarget, 0, 0, 0, 0, width, height, depth, GetTextureExternalFormat(textureInternalFormat), openGLData, texturesData.data());

    TexturesImageType result(texturesImageSize);
    GetGLTexturesImage(textureTarget, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, result.data());

    ASSERT_EQUAL(texturesData, result);
}

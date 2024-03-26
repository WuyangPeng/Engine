/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/26 17:57)

#include "OpenGLActiveTextureTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLActiveTextureTesting::OpenGLActiveTextureTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLActiveTextureTesting)

void System::OpenGLActiveTextureTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLActiveTextureTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ActiveTextureTest);
}

void System::OpenGLActiveTextureTesting::ActiveTextureTest()
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DoActiveTextureTest, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLActiveTextureTesting::DoActiveTextureTest(OpenGLUnsignedInt texture)
{
    SetGLBindTexture(TextureTarget::Texture2D, texture);

    SetGLTexturesStorage2D(TextureTarget::Texture2D, 1, textureInternalFormat, width, height);

    SetGLPixelStore(PixelStore::PackAlignment, 1);
    SetGLPixelStore(PixelStore::UnpackAlignment, 1);

    const auto texturesImageSize = width * height * GetTextureFormatSize(textureInternalFormat);

    const TexturesImageType texturesData(texturesImageSize, 121);
    SetGLTexturesSubImage2D(TextureTarget::Texture2D, 0, 0, 0, width, height, GetTextureExternalFormat(textureInternalFormat), openGLData, texturesData.data());

    TexturesImageType result(texturesImageSize);
    GetGLTexturesImage(TextureTarget::Texture2D, 0, GetTextureExternalFormat(textureInternalFormat), openGLData, result.data());

    ASSERT_EQUAL(texturesData, result);

    SetGLGenerateMipmap(TextureTarget::Texture2D);

    SetGLActiveTexture(EnumCastUnderlying(TextureNumber::Type0));
    SetGLBindTexture(TextureTarget::Texture2D, texture);
    SetGLBindImageTexture(0, texture, 0, true, 0, BufferLocking::ReadOnly, EnumCastUnderlying(textureInternalFormat));
}
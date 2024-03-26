/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 20:32)

#include "TexturesImage.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

System::TexturesImage::TexturesImage(int width, int height, TextureExternalFormat textureExternalFormat, int texturesImageSize, OpenGLData openGLData) noexcept
    : width{ width }, height{ height }, textureExternalFormat{ textureExternalFormat }, texturesImageSize{ texturesImageSize }, openGLData{ openGLData }, texturesImage{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(System, TexturesImage)

System::TexturesImage::Container System::TexturesImage::GetTexturesImage() const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return texturesImage;
}

void System::TexturesImage::SetTexturesSubImage2D(char imageValue, TextureCubeMap textureCubeMap)
{
    SYSTEM_CLASS_IS_VALID_9;

    const Container image(texturesImageSize, imageValue);
    SetGLTexturesSubImage2D(textureCubeMap, 0, 0, 0, width, height, textureExternalFormat, openGLData, image.data());
    texturesImage.insert(texturesImage.cend(), image.cbegin(), image.cend());
}

void System::TexturesImage::GetTexturesImage2D(TextureCubeMap textureCubeMap)
{
    SYSTEM_CLASS_IS_VALID_9;

    Container image(texturesImageSize);
    GetGLTexturesImage(textureCubeMap, 0, textureExternalFormat, openGLData, image.data());
    texturesImage.insert(texturesImage.cend(), image.cbegin(), image.cend());
}

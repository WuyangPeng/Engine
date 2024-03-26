/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:48)

#include "OpenGLTexturesTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTexturesTestingBase::OpenGLTexturesTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      textureTargets{ TextureTarget::Texture1D,
                      TextureTarget::Texture2D,
                      TextureTarget::Texture3D,
                      TextureTarget::TextureCubeMap,
                      TextureTarget::Texture1DArray,
                      TextureTarget::Texture2DArray,
                      TextureTarget::TextureCubeMapArray },
      textureInternalFormats{ TextureInternalFormat::RGBA32F,
                              TextureInternalFormat::RGBA32UI,
                              TextureInternalFormat::RGBA32I,
                              TextureInternalFormat::RGB32F,
                              TextureInternalFormat::RGB32UI,
                              TextureInternalFormat::RGB32I,
                              TextureInternalFormat::RGBA16F,
                              TextureInternalFormat::RGBA16,
                              TextureInternalFormat::RGBA16UI,
                              TextureInternalFormat::RGBA16SNorm,
                              TextureInternalFormat::RGBA16I,
                              TextureInternalFormat::RG32F,
                              TextureInternalFormat::RG32UI,
                              TextureInternalFormat::RG32I,
                              TextureInternalFormat::R11F_G11F_B10F,
                              TextureInternalFormat::RGBA8,
                              TextureInternalFormat::RGBA8UI,
                              TextureInternalFormat::RGBA8SNorm,
                              TextureInternalFormat::RGBA8I,
                              TextureInternalFormat::RG16F,
                              TextureInternalFormat::RG16,
                              TextureInternalFormat::RG16UI,
                              TextureInternalFormat::R16SNorm,
                              TextureInternalFormat::R16I,
                              TextureInternalFormat::R32F,
                              TextureInternalFormat::R32UI,
                              TextureInternalFormat::R32I,
                              TextureInternalFormat::RG8,
                              TextureInternalFormat::RG8UI,
                              TextureInternalFormat::RG8SNorm,
                              TextureInternalFormat::RG8I,
                              TextureInternalFormat::R16F,
                              TextureInternalFormat::R16,
                              TextureInternalFormat::R16UI,
                              TextureInternalFormat::R8,
                              TextureInternalFormat::R8UI,
                              TextureInternalFormat::R8SNorm,
                              TextureInternalFormat::R8I,
                              TextureInternalFormat::RGB9E5,
                              TextureInternalFormat::RGB10A2,

                              TextureInternalFormat::DepthComponent32F,
                              TextureInternalFormat::Depth24Stencil8,
                              TextureInternalFormat::DepthComponent16 },
      textureFormat{ { TextureInternalFormat::RGBA32F, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGBA32UI, TextureExternalFormat::RGBAInteger },
                     { TextureInternalFormat::RGBA32I, TextureExternalFormat::RGBAInteger },
                     { TextureInternalFormat::RGB32F, TextureExternalFormat::RGB },
                     { TextureInternalFormat::RGB32UI, TextureExternalFormat::RGBInteger },
                     { TextureInternalFormat::RGB32I, TextureExternalFormat::RGBInteger },
                     { TextureInternalFormat::RGBA16F, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGBA16, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGBA16UI, TextureExternalFormat::RGBAInteger },
                     { TextureInternalFormat::RGBA16SNorm, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGBA16I, TextureExternalFormat::RGBAInteger },
                     { TextureInternalFormat::RG32F, TextureExternalFormat::RG },
                     { TextureInternalFormat::RG32UI, TextureExternalFormat::RGInteger },
                     { TextureInternalFormat::RG32I, TextureExternalFormat::RGInteger },
                     { TextureInternalFormat::R11F_G11F_B10F, TextureExternalFormat::RGB },
                     { TextureInternalFormat::RGBA8, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGBA8UI, TextureExternalFormat::RGBAInteger },
                     { TextureInternalFormat::RGBA8SNorm, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGBA8I, TextureExternalFormat::RGBAInteger },
                     { TextureInternalFormat::RG16F, TextureExternalFormat::RG },
                     { TextureInternalFormat::RG16, TextureExternalFormat::RG },
                     { TextureInternalFormat::RG16UI, TextureExternalFormat::RGInteger },
                     { TextureInternalFormat::R16SNorm, TextureExternalFormat::Red },
                     { TextureInternalFormat::R16I, TextureExternalFormat::RedInteger },
                     { TextureInternalFormat::R32F, TextureExternalFormat::Red },
                     { TextureInternalFormat::R32UI, TextureExternalFormat::RedInteger },
                     { TextureInternalFormat::R32I, TextureExternalFormat::RedInteger },
                     { TextureInternalFormat::RG8, TextureExternalFormat::RG },
                     { TextureInternalFormat::RG8UI, TextureExternalFormat::RGInteger },
                     { TextureInternalFormat::RG8SNorm, TextureExternalFormat::RG },
                     { TextureInternalFormat::RG8I, TextureExternalFormat::RGInteger },
                     { TextureInternalFormat::R16F, TextureExternalFormat::Red },
                     { TextureInternalFormat::R16, TextureExternalFormat::Red },
                     { TextureInternalFormat::R16UI, TextureExternalFormat::RedInteger },
                     { TextureInternalFormat::R8, TextureExternalFormat::Red },
                     { TextureInternalFormat::R8UI, TextureExternalFormat::RedInteger },
                     { TextureInternalFormat::R8SNorm, TextureExternalFormat::Red },
                     { TextureInternalFormat::R8I, TextureExternalFormat::RedInteger },
                     { TextureInternalFormat::RGB9E5, TextureExternalFormat::RGB },
                     { TextureInternalFormat::RGB565, TextureExternalFormat::RGB },
                     { TextureInternalFormat::RGB5A1, TextureExternalFormat::RGBA },
                     { TextureInternalFormat::RGB10A2, TextureExternalFormat::RGB },

                     { TextureInternalFormat::DepthComponent32F, TextureExternalFormat::DepthComponent },
                     { TextureInternalFormat::Depth24Stencil8, TextureExternalFormat::DepthComponent },
                     { TextureInternalFormat::DepthComponent16, TextureExternalFormat::DepthComponent } },
      textureFormatSize{ { TextureInternalFormat::RGBA32F, 4 },
                         { TextureInternalFormat::RGBA32UI, 4 },
                         { TextureInternalFormat::RGBA32I, 4 },
                         { TextureInternalFormat::RGB32F, 3 },
                         { TextureInternalFormat::RGB32UI, 3 },
                         { TextureInternalFormat::RGB32I, 3 },
                         { TextureInternalFormat::RGBA16F, 4 },
                         { TextureInternalFormat::RGBA16, 4 },
                         { TextureInternalFormat::RGBA16UI, 4 },
                         { TextureInternalFormat::RGBA16SNorm, 4 },
                         { TextureInternalFormat::RGBA16I, 4 },
                         { TextureInternalFormat::RG32F, 2 },
                         { TextureInternalFormat::RG32UI, 2 },
                         { TextureInternalFormat::RG32I, 2 },
                         { TextureInternalFormat::R11F_G11F_B10F, 3 },
                         { TextureInternalFormat::RGBA8, 4 },
                         { TextureInternalFormat::RGBA8UI, 4 },
                         { TextureInternalFormat::RGBA8SNorm, 4 },
                         { TextureInternalFormat::RGBA8I, 4 },
                         { TextureInternalFormat::RG16F, 2 },
                         { TextureInternalFormat::RG16, 2 },
                         { TextureInternalFormat::RG16UI, 2 },
                         { TextureInternalFormat::R16SNorm, 1 },
                         { TextureInternalFormat::R16I, 1 },
                         { TextureInternalFormat::R32F, 1 },
                         { TextureInternalFormat::R32UI, 1 },
                         { TextureInternalFormat::R32I, 1 },
                         { TextureInternalFormat::RG8, 2 },
                         { TextureInternalFormat::RG8UI, 2 },
                         { TextureInternalFormat::RG8SNorm, 2 },
                         { TextureInternalFormat::RG8I, 2 },
                         { TextureInternalFormat::R16F, 1 },
                         { TextureInternalFormat::R16, 1 },
                         { TextureInternalFormat::R16UI, 1 },
                         { TextureInternalFormat::R8, 1 },
                         { TextureInternalFormat::R8UI, 1 },
                         { TextureInternalFormat::R8SNorm, 1 },
                         { TextureInternalFormat::R8I, 1 },
                         { TextureInternalFormat::RGB9E5, 3 },
                         { TextureInternalFormat::RGB565, 4 },
                         { TextureInternalFormat::RGB5A1, 4 },
                         { TextureInternalFormat::RGB10A2, 3 },

                         { TextureInternalFormat::DepthComponent32F, 1 },
                         { TextureInternalFormat::Depth24Stencil8, 1 },
                         { TextureInternalFormat::DepthComponent16, 1 } },
      textureCubeMaps{ TextureCubeMap::PositiveX,
                       TextureCubeMap::NegativeX,
                       TextureCubeMap::PositiveY,
                       TextureCubeMap::NegativeY,
                       TextureCubeMap::PositiveZ,
                       TextureCubeMap::NegativeZ }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTexturesTestingBase)

void System::OpenGLTexturesTestingBase::DeleteTextureTest(OpenGLUnsignedInt texture) const noexcept
{
    SetGLDeleteTextures(texture);
}

void System::OpenGLTexturesTestingBase::DeleteTexturesTest(const TexturesType& textures) const noexcept
{
    SetGLDeleteTextures(bufferSize, textures.data());
}

System::OpenGLTexturesTestingBase::TextureTargetContainerConstIter System::OpenGLTexturesTestingBase::begin() const noexcept
{
    return textureTargets.cbegin();
}

System::OpenGLTexturesTestingBase::TextureTargetContainerConstIter System::OpenGLTexturesTestingBase::end() const noexcept
{
    return textureTargets.cend();
}

int System::OpenGLTexturesTestingBase::GetTextureTargetSize() const
{
    return boost::numeric_cast<int>(textureTargets.size());
}

System::OpenGLTexturesTestingBase::TextureInternalFormatContainerConstIter System::OpenGLTexturesTestingBase::GetTextureInternalFormatsBegin() const noexcept
{
    return textureInternalFormats.cbegin();
}

System::OpenGLTexturesTestingBase::TextureInternalFormatContainerConstIter System::OpenGLTexturesTestingBase::GetTextureInternalFormatsEnd() const noexcept
{
    return textureInternalFormats.cend();
}

System::OpenGLTexturesTestingBase::TextureCubeMapContainerConstIter System::OpenGLTexturesTestingBase::GetTextureCubeMapBegin() const noexcept
{
    return textureCubeMaps.cbegin();
}

System::OpenGLTexturesTestingBase::TextureCubeMapContainerConstIter System::OpenGLTexturesTestingBase::GetTextureCubeMapEnd() const noexcept
{
    return textureCubeMaps.cend();
}

System::TextureExternalFormat System::OpenGLTexturesTestingBase::GetTextureExternalFormat(TextureInternalFormat textureInternalFormat) const
{
    if (const auto iter = textureFormat.find(textureInternalFormat);
        iter != textureFormat.cend())
    {
        return iter->second;
    }

    return TextureExternalFormat::RGBA;
}

int System::OpenGLTexturesTestingBase::GetTextureFormatSize(TextureInternalFormat textureInternalFormat) const
{
    if (const auto iter = textureFormatSize.find(textureInternalFormat);
        iter != textureFormatSize.cend())
    {
        return iter->second;
    }

    return 1;
}

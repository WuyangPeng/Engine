/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 15:03)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Flags/ChannelType.h"

Rendering::OpenGLTexture::OpenGLTexture(const TextureSharedPtr& texture, const std::string& name, TextureTarget target, TextureTargetBinding targetBinding)
    : ParentType{ texture, name },
      target{ target },
      targetBinding{ targetBinding },
      numLevels{ texture->GetNumLevels() },
      internalFormat{ GetGLTextureInternalFormat(texture->GetFormat()) },
      externalFormat{ GetGLTextureExternalFormat(texture->GetFormat()) },
      externalType{ GetGLTextureExternalType(DataFormat::GetChannelType(texture->GetFormat())) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture)

Rendering::ConstTextureSharedPtr Rendering::OpenGLTexture::GetTexture() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture>(GetGraphicsObject());
}

System::TextureTarget Rendering::OpenGLTexture::GetTarget() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return target;
}

System::TextureTargetBinding Rendering::OpenGLTexture::GetTargetBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return targetBinding;
}

System::TextureInternalFormat Rendering::OpenGLTexture::GetGLTextureInternalFormat(DataFormatType dataFormatType)
{
    using Container = std::array<TextureInternalFormat, System::EnumCastUnderlying(DataFormatType::NumFormats)>;

    static Container container{
        TextureInternalFormat::None,  // Unknown
        TextureInternalFormat::None,  // R32G32B32A32Typeless
        TextureInternalFormat::RGBA32F,  // R32G32B32A32Float
        TextureInternalFormat::RGBA32UI,  // R32G32B32A32UInt
        TextureInternalFormat::RGBA32I,  // R32G32B32A32SInt
        TextureInternalFormat::None,  // R32G32B32Typeless
        TextureInternalFormat::RGB32F,  // R32G32B32Float
        TextureInternalFormat::RGB32UI,  // R32G32B32UInt
        TextureInternalFormat::RGB32I,  // R32G32B32SInt
        TextureInternalFormat::None,  // R16G16B16A16Typeless
        TextureInternalFormat::RGBA16F,  // R16G16B16A16Float
        TextureInternalFormat::RGBA16,  // R16G16B16A16UNorm
        TextureInternalFormat::RGBA16UI,  // R16G16B16A16UInt
        TextureInternalFormat::RGBA16SNorm,  // R16G16B16A16SNorm
        TextureInternalFormat::RGBA16I,  // R16G16B16A16SInt
        TextureInternalFormat::None,  // R32G32Typeless
        TextureInternalFormat::RG32F,  // R32G32Float
        TextureInternalFormat::RG32UI,  // R32G32UInt
        TextureInternalFormat::RG32I,  // R32G32SInt
        TextureInternalFormat::None,  // R32G8X24Typeless
        TextureInternalFormat::None,  // D32FloatS8X24UInt
        TextureInternalFormat::None,  // R32FloatX8X24Typeless
        TextureInternalFormat::None,  // X32TypelessG8X24UInt
        TextureInternalFormat::None,  // R10G10B10A2Typeless
        TextureInternalFormat::None,  // R10G10B10A2UNorm
        TextureInternalFormat::None,  // R10G10B10A2UInt
        TextureInternalFormat::R11F_G11F_B10F,  // R11G11B10Float
        TextureInternalFormat::None,  // R8G8B8A8Typeless
        TextureInternalFormat::RGBA8,  // R8G8B8A8UNorm
        TextureInternalFormat::RGBA8,  // R8G8B8A8UNormSRGB
        TextureInternalFormat::RGBA8UI,  // R8G8B8A8UInt
        TextureInternalFormat::RGBA8SNorm,  // R8G8B8A8SNorm
        TextureInternalFormat::RGBA8I,  // R8G8B8A8SInt
        TextureInternalFormat::None,  // R16G16Typeless
        TextureInternalFormat::RG16F,  // R16G16Float
        TextureInternalFormat::RG16,  // R16G16UNorm
        TextureInternalFormat::RG16UI,  // R16G16UInt
        TextureInternalFormat::R16SNorm,  // R16G16SNorm
        TextureInternalFormat::R16I,  // R16G16SInt
        TextureInternalFormat::None,  // R32Typeless
        TextureInternalFormat::DepthComponent32F,  // D32Float
        TextureInternalFormat::R32F,  // R32Float
        TextureInternalFormat::R32UI,  // R32UInt
        TextureInternalFormat::R32I,  // R32SInt
        TextureInternalFormat::None,  // R24G8Typeless
        TextureInternalFormat::Depth24Stencil8,  // D24UNormS8UInt
        TextureInternalFormat::None,  // R24UNormX8Typeless
        TextureInternalFormat::None,  // X24TypelessG8UInt
        TextureInternalFormat::None,  // R8G8Typeless
        TextureInternalFormat::RG8,  // R8G8UNorm
        TextureInternalFormat::RG8UI,  // R8G8UInt
        TextureInternalFormat::RG8SNorm,  // R8G8SNorm
        TextureInternalFormat::RG8I,  // R8G8SInt
        TextureInternalFormat::None,  // R16Typeless
        TextureInternalFormat::R16F,  // R16Float
        TextureInternalFormat::DepthComponent16,  // D16UNorm
        TextureInternalFormat::R16,  // R16UNorm
        TextureInternalFormat::R16UI,  // R16UInt
        TextureInternalFormat::R16SNorm,  // R16SNorm
        TextureInternalFormat::R16I,  // R16SInt
        TextureInternalFormat::None,  // R8Typeless
        TextureInternalFormat::R8,  // R8UNorm
        TextureInternalFormat::R8UI,  // R8UInt
        TextureInternalFormat::R8SNorm,  // R8SNorm
        TextureInternalFormat::R8I,  // R8SInt
        TextureInternalFormat::None,  // A8UNorm
        TextureInternalFormat::None,  // R1UNorm
        TextureInternalFormat::RGB9E5,  // R9G9B9E5SharedEXP
        TextureInternalFormat::None,  // R8G8B8G8UNorm
        TextureInternalFormat::None,  // G8R8G8B8UNorm
        TextureInternalFormat::None,  // BC1Typeless
        TextureInternalFormat::None,  // BC1UNorm
        TextureInternalFormat::None,  // BC1UNormSRGB
        TextureInternalFormat::None,  // BC2Typeless
        TextureInternalFormat::None,  // BC2UNorm
        TextureInternalFormat::None,  // BC2UNormSRGB
        TextureInternalFormat::None,  // BC3Typeless
        TextureInternalFormat::None,  // BC3UNorm
        TextureInternalFormat::None,  // BC3UNormSRGB
        TextureInternalFormat::None,  // BC4Typeless
        TextureInternalFormat::None,  // BC4UNorm
        TextureInternalFormat::None,  // BC4SNorm
        TextureInternalFormat::None,  // BC5UNormSRGB
        TextureInternalFormat::None,  // BC5UNorm
        TextureInternalFormat::None,  // BC5SNorm
        TextureInternalFormat::RGB565,  // B5G6R5UNorm
        TextureInternalFormat::RGB5A1,  // B5G5R5A1UNorm
        TextureInternalFormat::RGBA8,  // B8G8R8A8UNorm
        TextureInternalFormat::RGBA8,  // B8G8R8X8UNorm
        TextureInternalFormat::RGB10A2,  // R10G10B10XRBiasA2UNorm
        TextureInternalFormat::None,  // B8G8R8A8Typeless
        TextureInternalFormat::RGBA8,  // B8G8R8A8UNormSRGB
        TextureInternalFormat::None,  // B8G8R8X8Typeless
        TextureInternalFormat::RGBA8,  // B8G8R8X8UNormSRGB
        TextureInternalFormat::None,  // BC6HTypeless
        TextureInternalFormat::None,  // BC6HUF16
        TextureInternalFormat::None,  // BC6HSF16
        TextureInternalFormat::None,  // BC7Typeless
        TextureInternalFormat::None,  // BC7UNorm
        TextureInternalFormat::None,  // BC7UNormSRGB

        TextureInternalFormat::None,  // AYUV
        TextureInternalFormat::None,  // Y410
        TextureInternalFormat::None,  // Y416
        TextureInternalFormat::None,  // NV12
        TextureInternalFormat::None,  // P010
        TextureInternalFormat::None,  // P016
        TextureInternalFormat::None,  // Opaque420
        TextureInternalFormat::None,  // YUY2
        TextureInternalFormat::None,  // Y210
        TextureInternalFormat::None,  // Y216
        TextureInternalFormat::None,  // NV11
        TextureInternalFormat::None,  // AI44
        TextureInternalFormat::None,  // IA44
        TextureInternalFormat::None,  // P8
        TextureInternalFormat::None,  // A8P8
        TextureInternalFormat::None  // B4G4R4A4UNorm
    };

    return container.at(System::EnumCastUnderlying(dataFormatType));
}

System::TextureExternalFormat Rendering::OpenGLTexture::GetGLTextureExternalFormat(DataFormatType dataFormatType)
{
    using Container = std::array<TextureExternalFormat, System::EnumCastUnderlying(DataFormatType::NumFormats)>;

    static Container container{
        TextureExternalFormat::Unknown,  // Unknown
        TextureExternalFormat::RGBA,  // R32G32B32A32Typeless
        TextureExternalFormat::RGBA,  // R32G32B32A32Float
        TextureExternalFormat::RGBAInteger,  // R32G32B32A32UInt
        TextureExternalFormat::RGBAInteger,  // R32G32B32A32SInt
        TextureExternalFormat::RGB,  // R32G32B32Typeless
        TextureExternalFormat::RGB,  // R32G32B32Float
        TextureExternalFormat::RGBInteger,  // R32G32B32UInt
        TextureExternalFormat::RGBInteger,  // R32G32B32SInt
        TextureExternalFormat::RGBA,  // R16G16B16A16Typeless
        TextureExternalFormat::RGBA,  // R16G16B16A16Float
        TextureExternalFormat::RGBA,  // R16G16B16A16UNorm
        TextureExternalFormat::RGBAInteger,  // R16G16B16A16UInt
        TextureExternalFormat::RGBA,  // R16G16B16A16SNorm
        TextureExternalFormat::RGBAInteger,  // R16G16B16A16SInt
        TextureExternalFormat::RG,  // R32G32Typeless
        TextureExternalFormat::RG,  // R32G32Float
        TextureExternalFormat::RGInteger,  // R32G32UInt
        TextureExternalFormat::RGInteger,  // R32G32SInt
        TextureExternalFormat::Unknown,  // R32G8X24Typeless
        TextureExternalFormat::Unknown,  // D32FloatS8X24UInt
        TextureExternalFormat::Unknown,  // R32FloatX8X24Typeless
        TextureExternalFormat::Unknown,  // X32TypelessG8X24UInt
        TextureExternalFormat::RGBA,  // R10G10B10A2Typeless
        TextureExternalFormat::RGBA,  // R10G10B10A2UNorm
        TextureExternalFormat::RGBAInteger,  // R10G10B10A2UInt
        TextureExternalFormat::RGB,  // R11G11B10Float
        TextureExternalFormat::RGBA,  // R8G8B8A8Typeless
        TextureExternalFormat::RGBA,  // R8G8B8A8UNorm
        TextureExternalFormat::RGBA,  // R8G8B8A8UNormSRGB
        TextureExternalFormat::RGBAInteger,  // R8G8B8A8UInt
        TextureExternalFormat::RGBA,  // R8G8B8A8SNorm
        TextureExternalFormat::RGBAInteger,  // R8G8B8A8SInt
        TextureExternalFormat::RG,  // R16G16Typeless
        TextureExternalFormat::RG,  // R16G16Float
        TextureExternalFormat::RG,  // R16G16UNorm
        TextureExternalFormat::RGInteger,  // R16G16UInt
        TextureExternalFormat::RG,  // R16G16SNorm
        TextureExternalFormat::RGInteger,  // R16G16SInt
        TextureExternalFormat::Red,  // R32Typeless
        TextureExternalFormat::DepthComponent,  // D32Float
        TextureExternalFormat::Red,  // R32Float
        TextureExternalFormat::RedInteger,  // R32UInt
        TextureExternalFormat::RedInteger,  // R32SInt
        TextureExternalFormat::RG,  // R24G8Typeless
        TextureExternalFormat::DepthComponent,  // D24UNormS8UInt
        TextureExternalFormat::Unknown,  // R24UNormX8Typeless
        TextureExternalFormat::Unknown,  // X24TypelessG8UInt
        TextureExternalFormat::RG,  // R8G8Typeless
        TextureExternalFormat::RG,  // R8G8UNorm
        TextureExternalFormat::RGInteger,  // R8G8UInt
        TextureExternalFormat::RG,  // R8G8SNorm
        TextureExternalFormat::RGInteger,  // R8G8SInt
        TextureExternalFormat::Red,  // R16Typeless
        TextureExternalFormat::Red,  // R16Float
        TextureExternalFormat::DepthComponent,  // D16UNorm
        TextureExternalFormat::Red,  // R16UNorm
        TextureExternalFormat::RedInteger,  // R16UInt
        TextureExternalFormat::Red,  // R16SNorm
        TextureExternalFormat::RedInteger,  // R16SInt
        TextureExternalFormat::Red,  // R8Typeless
        TextureExternalFormat::Red,  // R8UNorm
        TextureExternalFormat::RedInteger,  // R8UInt
        TextureExternalFormat::Red,  // R8SNorm
        TextureExternalFormat::RedInteger,  // R8SInt
        TextureExternalFormat::Unknown,  // A8UNorm
        TextureExternalFormat::Unknown,  // R1UNorm
        TextureExternalFormat::Unknown,  // R9G9B9E5SharedEXP
        TextureExternalFormat::Unknown,  // R8G8B8G8UNorm
        TextureExternalFormat::Unknown,  // G8R8G8B8UNorm
        TextureExternalFormat::Unknown,  // BC1Typeless
        TextureExternalFormat::Unknown,  // BC1UNorm
        TextureExternalFormat::Unknown,  // BC1UNormSRGB
        TextureExternalFormat::Unknown,  // BC2Typeless
        TextureExternalFormat::Unknown,  // BC2UNorm
        TextureExternalFormat::Unknown,  // BC2UNormSRGB
        TextureExternalFormat::Unknown,  // BC3Typeless
        TextureExternalFormat::Unknown,  // BC3UNorm
        TextureExternalFormat::Unknown,  // BC3UNormSRGB
        TextureExternalFormat::Unknown,  // BC4Typeless
        TextureExternalFormat::Unknown,  // BC4UNorm
        TextureExternalFormat::Unknown,  // BC4SNorm
        TextureExternalFormat::Unknown,  // BC5Typeless
        TextureExternalFormat::Unknown,  // BC5UNorm
        TextureExternalFormat::Unknown,  // BC5SNorm
        TextureExternalFormat::BGR,  // B5G6R5UNorm
        TextureExternalFormat::BGRA,  // B5G5R5A1UNorm
        TextureExternalFormat::BGRA,  // B8G8R8A8UNorm
        TextureExternalFormat::BGRA,  // B8G8R8X8UNorm
        TextureExternalFormat::Unknown,  // R10G10B10XRBiasA2UNorm
        TextureExternalFormat::BGRA,  // B8G8R8A8Typeless
        TextureExternalFormat::BGRA,  // B8G8R8A8UNormSRGB
        TextureExternalFormat::BGRA,  // B8G8R8X8Typeless
        TextureExternalFormat::BGRA,  // B8G8R8X8UNormSRGB
        TextureExternalFormat::Unknown,  // BC6HTypeless
        TextureExternalFormat::Unknown,  // BC6HUF16
        TextureExternalFormat::Unknown,  // BC6HSF16
        TextureExternalFormat::Unknown,  // BC7Typeless
        TextureExternalFormat::Unknown,  // BC7UNorm
        TextureExternalFormat::Unknown,  // BC7UNormSRGB

        TextureExternalFormat::Unknown,  // AYUV
        TextureExternalFormat::Unknown,  // Y410
        TextureExternalFormat::Unknown,  // Y416
        TextureExternalFormat::Unknown,  // NV12
        TextureExternalFormat::Unknown,  // P010
        TextureExternalFormat::Unknown,  // P016
        TextureExternalFormat::Unknown,  // Opaque420
        TextureExternalFormat::Unknown,  // YUY2
        TextureExternalFormat::Unknown,  // Y210
        TextureExternalFormat::Unknown,  // Y216
        TextureExternalFormat::Unknown,  // NV11
        TextureExternalFormat::Unknown,  // AI44
        TextureExternalFormat::Unknown,  // IA44
        TextureExternalFormat::Unknown,  // P8
        TextureExternalFormat::Unknown,  // A8P8
        TextureExternalFormat::Unknown  // B4G4R4A4_UNORM
    };

    return container.at(System::EnumCastUnderlying(dataFormatType));
}

System::OpenGLData Rendering::OpenGLTexture::GetGLTextureExternalType(ChannelType channelType)
{
    using Container = std::array<OpenGLData, System::EnumCastUnderlying(ChannelType::NumChannelTypes)>;

    static Container container{
        OpenGLData::None,  // 不受支持的
        OpenGLData::Byte,  // BYTE
        OpenGLData::UnsignedByte,  // UBYTE
        OpenGLData::Short,  // SHORT
        OpenGLData::UnsignedShort,  // USHORT
        OpenGLData::Int,  // INT
        OpenGLData::UnsignedInt,  // UINT
        OpenGLData::HalfFloat,  // HALF_FLOAT
        OpenGLData::Float,  // FLOAT
        OpenGLData::Double,  // DOUBLE
        OpenGLData::Int2_10_10_10Rev,  // INT_10_10_2
        OpenGLData::UnsignedInt2_10_10_10Rev,  // UINT_10_10_2
        OpenGLData::UnsignedInt10F11F11FRev,  // FLOAT_11_11_10
        OpenGLData::UnsignedInt24_8  // UINT_24_8
    };

    return container.at(System::EnumCastUnderlying(channelType));
}

System::OpenGLInt Rendering::OpenGLTexture::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numLevels;
}

System::TextureInternalFormat Rendering::OpenGLTexture::GetInternalFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return internalFormat;
}

System::TextureExternalFormat Rendering::OpenGLTexture::GetExternalFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return externalFormat;
}

System::OpenGLData Rendering::OpenGLTexture::GetExternalType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return externalType;
}

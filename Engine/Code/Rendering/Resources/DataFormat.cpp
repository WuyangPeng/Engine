///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 12:33)

#include "Rendering/RenderingExport.h"

#include "DataFormat.h"
#include "Flags/ChannelType.h"

const std::string& Rendering::DataFormat::GetName(DataFormatType type)
{
    static const std::array<std::string, numFormats> name{ "Unknown",
                                                           "R32G32B32A32Typeless",
                                                           "R32G32B32A32Float",
                                                           "R32G32B32A32UInt",
                                                           "R32G32B32A32SInt",
                                                           "R32G32B32Typeless",
                                                           "R32G32B32Float",
                                                           "R32G32B32UInt",
                                                           "R32G32B32SInt",
                                                           "R16G16B16A16Typeless",
                                                           "R16G16B16A16Float",
                                                           "R16G16B16A16UNorm",
                                                           "R16G16B16A16UInt",
                                                           "R16G16B16A16SNorm",
                                                           "R16G16B16A16SInt",
                                                           "R32G32Typeless",
                                                           "R32G32Float",
                                                           "R32G32UInt",
                                                           "R32G32SInt",
                                                           "R32G8X24Typeless",
                                                           "D32FloatS8X24UInt",
                                                           "R32FloatX8X24Typeless",
                                                           "X32TypelessG8X24UInt",
                                                           "R10G10B10A2Typeless",
                                                           "R10G10B10A2UNorm",
                                                           "R10G10B10A2UInt",
                                                           "R11G11B10Float",
                                                           "R8G8B8A8Typeless",
                                                           "R8G8B8A8UNorm",
                                                           "R8G8B8A8UNormSRGB",
                                                           "R8G8B8A8UInt",
                                                           "R8G8B8A8SNorm",
                                                           "R8G8B8A8SInt",
                                                           "R16G16Typeless",
                                                           "R16G16Float",
                                                           "R16G16UNorm",
                                                           "R16G16UInt",
                                                           "R16G16SNorm",
                                                           "R16G16SInt",
                                                           "R32Typeless",
                                                           "D32Float",
                                                           "R32Float",
                                                           "R32UInt",
                                                           "R32SInt",
                                                           "R24G8Typeless",
                                                           "D24UNormS8UInt",
                                                           "R24UNormX8Typeless",
                                                           "X24TypelessG8UInt",
                                                           "R8G8Typeless",
                                                           "R8G8UNorm",
                                                           "R8G8UInt",
                                                           "R8G8SNorm",
                                                           "R8G8SInt",
                                                           "R16Typeless",
                                                           "R16Float",
                                                           "D16UNorm",
                                                           "R16UNorm",
                                                           "R16UInt",
                                                           "R16SNorm",
                                                           "R16SInt",
                                                           "R8Typeless",
                                                           "R8UNorm",
                                                           "R8UInt",
                                                           "R8SNorm",
                                                           "R8SInt",
                                                           "A8UNorm",
                                                           "R1UNorm",
                                                           "R9G9B9E5SharedEXP",
                                                           "R8G8B8G8UNorm",
                                                           "G8R8G8B8UNorm",
                                                           "BC1Typeless",
                                                           "BC1UNorm",
                                                           "BC1UNormSRGB",
                                                           "BC2Typeless",
                                                           "BC2UNorm",
                                                           "BC2UNormSRGB",
                                                           "BC3Typeless",
                                                           "BC3UNorm",
                                                           "BC3UNormSRGB",
                                                           "BC4Typeless",
                                                           "BC4UNorm",
                                                           "BC4SNorm",
                                                           "BC5Typeless",
                                                           "BC5UNorm",
                                                           "BC5SNorm",
                                                           "B5G6R5UNorm",
                                                           "B5G5R5A1UNorm",
                                                           "B8G8R8A8UNorm",
                                                           "B8G8R8x8UNorm",
                                                           "R10G10B10XRBiasA2UNorm",
                                                           "B8G8R8A8Typeless",
                                                           "B8G8R8A8UNormSRGB",
                                                           "B8G8R8x8Typeless",
                                                           "B8G8R8x8UNormSRGB",
                                                           "BC6HTypeless",
                                                           "BC6HUF16",
                                                           "BC6HSF16",
                                                           "BC7Typeless",
                                                           "BC7UNorm",
                                                           "BC7UNormSRGB",
                                                           "AYUV",
                                                           "Y410",
                                                           "Y416",
                                                           "NV12",
                                                           "P010",
                                                           "P016",
                                                           "Opaque420",
                                                           "YUY2",
                                                           "Y210",
                                                           "Y216",
                                                           "NV11",
                                                           "AI44",
                                                           "IA44",
                                                           "P8",
                                                           "A8P8",
                                                           "B4G4R4A4UNorm" };

    return name.at(System::EnumCastUnderlying(type));
}

int Rendering::DataFormat::GetNumBytesPerStruct(DataFormatType type)
{
    static const std::array<int, numFormats> numBytesPerStruct{
        0,  // Unknown
        16,  // R32G32B32A32Typeless
        16,  // R32G32B32A32Float
        16,  // R32G32B32A32UInt
        16,  // R32G32B32A32SInt
        12,  // R32G32B32Typeless
        12,  // R32G32B32Float
        12,  // R32G32B32UInt
        12,  // R32G32B32SInt
        8,  // R16G16B16A16Typeless
        8,  // R16G16B16A16Float
        8,  // R16G16B16A16UNorm
        8,  // R16G16B16A16UInt
        8,  // R16G16B16A16SNorm
        8,  // R16G16B16A16SInt
        8,  // R32G32Typeless
        8,  // R32G32Float
        8,  // R32G32UInt
        8,  // R32G32SInt
        8,  // R32G8X24Typeless
        4,  // D32FloatS8X24UInt
        4,  // R32FloatX8X24Typeless
        4,  // X32TypelessG8X24UInt
        4,  // R10G10B10A2Typeless
        4,  // R10G10B10A2UNorm
        4,  // R10G10B10A2UInt
        4,  // R11G11B10Float
        4,  // R8G8B8A8Typeless
        4,  // R8G8B8A8UNorm
        4,  // R8G8B8A8UNormSRGB
        4,  // R8G8B8A8UInt
        4,  // R8G8B8A8SNorm
        4,  // R8G8B8A8SInt
        4,  // R16G16Typeless
        4,  // R16G16Float
        4,  // R16G16UNorm
        4,  // R16G16UInt
        4,  // R16G16SNorm
        4,  // R16G16SInt
        4,  // R32Typeless
        4,  // D32Float
        4,  // R32Float
        4,  // R32UInt
        4,  // R32SInt
        4,  // R24G8Typeless
        4,  // D24UNormS8UInt
        4,  // R24UNormX8Typeless
        4,  // X24TypelessG8UInt
        2,  // R8G8Typeless
        2,  // R8G8UNorm
        2,  // R8G8UInt
        2,  // R8G8SNorm
        2,  // R8G8SInt
        2,  // R16Typeless
        2,  // R16Float
        2,  // D16UNorm
        2,  // R16UNorm
        2,  // R16UInt
        2,  // R16SNorm
        2,  // R16SInt
        1,  // R8Typeless
        1,  // R8UNorm
        1,  // R8UInt
        1,  // R8SNorm
        1,  // R8SInt
        1,  // A8UNorm
        0,  // R1UNorm
        2,  // R9G9B9E5SharedEXP
        2,  // R8G8B8G8UNorm
        2,  // G8R8G8B8UNorm
        0,  // BC1Typeless
        0,  // BC1UNorm
        0,  // BC1UNormSRGB
        0,  // BC2Typeless
        0,  // BC2UNorm
        0,  // BC2UNormSRGB
        0,  // BC3Typeless
        0,  // BC3UNorm
        0,  // BC3UNormSRGB
        0,  // BC4Typeless
        0,  // BC4UNorm
        0,  // BC4SNorm
        0,  // BC5Typeless
        0,  // BC5UNorm
        0,  // BC5SNorm
        2,  // B5G6R5UNorm
        2,  // B5G5R5A1UNorm
        4,  // B8G8R8A8UNorm
        4,  // B8G8R8X8UNorm
        4,  // R10G10B10XRBiasA2UNorm
        4,  // B8G8R8A8Typeless
        4,  // B8G8R8A8UNormSRGB
        4,  // B8G8R8X8Typeless
        4,  // B8G8R8X8UNormSRGB
        0,  // BC6HTypeless
        0,  // BC6HUF16
        0,  // BC6HSF16
        0,  // BC7Typeless
        0,  // BC7UNorm
        0,  // BC7UNormSRGB

        0,  // AYUV
        0,  // Y410
        0,  // Y416
        0,  // NV12
        0,  // P010
        0,  // P016
        0,  // Opaque420
        0,  // YUY2
        0,  // Y210
        0,  // Y216
        0,  // NV11
        0,  // AI44
        0,  // IA44
        0,  // P8
        0,  // A8P8
        0  // B4G4R4A4UNorm
    };

    return numBytesPerStruct.at(System::EnumCastUnderlying(type));
}

int Rendering::DataFormat::GetNumChannels(DataFormatType type)
{
    static const std::array<int, numFormats> numChannels{
        0,  // Unknown
        4,  // R32G32B32A32Typeless
        4,  // R32G32B32A32Float
        4,  // R32G32B32A32UInt
        4,  // R32G32B32A32SInt
        3,  // R32G32B32Typeless
        3,  // R32G32B32Float
        3,  // R32G32B32UInt
        3,  // R32G32B32SInt
        4,  // R16G16B16A16Typeless
        4,  // R16G16B16A16Float
        4,  // R16G16B16A16UNorm
        4,  // R16G16B16A16UInt
        4,  // R16G16B16A16SNorm
        4,  // R16G16B16A16SInt
        2,  // R32G32Typeless
        2,  // R32G32Float
        2,  // R32G32UInt
        2,  // R32G32SInt
        2,  // R32G8X24Typeless
        2,  // D32FloatS8X24UInt
        2,  // R32FloatX8X24Typeless
        2,  // X32TypelessG8X24UInt
        4,  // R10G10B10A2Typeless
        4,  // R10G10B10A2UNorm
        4,  // R10G10B10A2UInt
        3,  // R11G11B10Float
        4,  // R8G8B8A8Typeless
        4,  // R8G8B8A8UNorm
        4,  // R8G8B8A8UNormSRGB
        4,  // R8G8B8A8UInt
        4,  // R8G8B8A8SNorm
        4,  // R8G8B8A8SInt
        2,  // R16G16Typeless
        2,  // R16G16Float
        2,  // R16G16UNorm
        2,  // R16G16UInt
        2,  // R16G16SNorm
        2,  // R16G16SInt
        1,  // R32Typeless
        1,  // D32Float
        1,  // R32Float
        1,  // R32UInt
        1,  // R32SInt
        2,  // R24G8Typeless
        2,  // D24UNormS8UInt
        2,  // R24UNormX8Typeless
        2,  // X24TypelessG8UInt
        2,  // R8G8Typeless
        2,  // R8G8UNorm
        2,  // R8G8UInt
        2,  // R8G8SNorm
        2,  // R8G8SInt
        1,  // R16Typeless
        1,  // R16Float
        1,  // D16UNorm
        1,  // R16UNorm
        1,  // R16UInt
        1,  // R16SNorm
        1,  // R16SInt
        1,  // R8Typeless
        1,  // R8UNorm
        1,  // R8UInt
        1,  // R8SNorm
        1,  // R8SInt
        1,  // A8UNorm
        1,  // R1UNorm
        4,  // R9G9B9E5SharedEXP
        4,  // R8G8B8G8UNorm
        4,  // G8R8G8B8UNorm
        0,  // BC1Typeless
        0,  // BC1UNorm
        0,  // BC1UNorm_SRGB
        0,  // BC2Typeless
        0,  // BC2UNorm
        0,  // BC2UNorm_SRGB
        0,  // BC3Typeless
        0,  // BC3UNorm
        0,  // BC3UNormSRGB
        0,  // BC4Typeless
        0,  // BC4UNorm
        0,  // BC4SNorm
        0,  // BC5Typeless
        0,  // BC5UNorm
        0,  // BC5SNorm
        2,  // B5G6R5UNorm
        4,  // B5G5R5A1UNorm
        4,  // B8G8R8A8UNorm
        4,  // B8G8R8X8UNorm
        4,  // R10G10B10XRBiasA2UNorm
        4,  // B8G8R8A8Typeless
        4,  // B8G8R8A8UNormSRGB
        4,  // B8G8R8X8Typeless
        4,  // B8G8R8X8UNormSRGB
        0,  // BC6HTypeless
        0,  // BC6HUF16
        0,  // BC6HSF16
        0,  // BC7Typeless
        0,  // BC7UNorm
        0,  // BC7UNormSRGB

        0,  // AYUV
        0,  // Y410
        0,  // Y416
        0,  // NV12
        0,  // P010
        0,  // P016
        0,  // Opaque420
        0,  // YUY2
        0,  // Y210
        0,  // Y216
        0,  // NV11
        0,  // AI44
        0,  // IA44
        0,  // P8
        0,  // A8P8
        0  // B4G4R4A4UNorm
    };

    return numChannels.at(System::EnumCastUnderlying(type));
}

Rendering::ChannelType Rendering::DataFormat::GetChannelType(DataFormatType type)
{
    static const std::array<ChannelType, numFormats> channelType{
        ChannelType::UnSupported,  // Unknown
        ChannelType::UnSupported,  // R32G32B32A32Typeless
        ChannelType::Float,  // R32G32B32A32Float
        ChannelType::UInt,  // R32G32B32A32UInt
        ChannelType::Int,  // R32G32B32A32SInt
        ChannelType::UnSupported,  // R32G32B32Typeless
        ChannelType::Float,  // R32G32B32Float
        ChannelType::UInt,  // R32G32B32UInt
        ChannelType::Int,  // R32G32B32SInt
        ChannelType::UnSupported,  // R16G16B16A16Typeless
        ChannelType::HalfFloat,  // R16G16B16A16Float
        ChannelType::UShort,  // R16G16B16A16UNorm
        ChannelType::UShort,  // R16G16B16A16UInt
        ChannelType::Short,  // R16G16B16A16SNorm
        ChannelType::Short,  // R16G16B16A16SInt
        ChannelType::UnSupported,  // R32G32Typeless
        ChannelType::Float,  // R32G32Float
        ChannelType::UInt,  // R32G32UInt
        ChannelType::Int,  // R32G32SInt
        ChannelType::UnSupported,  // R32G8X24Typeless
        ChannelType::UnSupported,  // D32FloatS8X24UInt
        ChannelType::UnSupported,  // R32FloatX8X24Typeless
        ChannelType::UnSupported,  // X32TypelessG8X24UInt
        ChannelType::UnSupported,  // R10G10B10A2Typeless
        ChannelType::UInt_10_10_2,  // R10G10B10A2UNorm
        ChannelType::UInt_10_10_2,  // R10G10B10A2UInt
        ChannelType::Float_11_11_10,  // R11G11B10Float
        ChannelType::UnSupported,  // R8G8B8A8Typeless
        ChannelType::UByte,  // R8G8B8A8UNorm
        ChannelType::UByte,  // R8G8B8A8UNorm_SRGB
        ChannelType::UByte,  // R8G8B8A8UInt
        ChannelType::Byte,  // R8G8B8A8SNorm
        ChannelType::Byte,  // R8G8B8A8SInt
        ChannelType::UnSupported,  // R16G16Typeless
        ChannelType::Float,  // R16G16Float
        ChannelType::UShort,  // R16G16UNorm
        ChannelType::UShort,  // R16G16UInt
        ChannelType::Short,  // R16G16SNorm
        ChannelType::Short,  // R16G16SInt
        ChannelType::UnSupported,  // R32Typeless
        ChannelType::Float,  // D32Float
        ChannelType::Float,  // R32Float
        ChannelType::UInt,  // R32UInt
        ChannelType::Int,  // R32SInt
        ChannelType::UnSupported,  // R24G8Typeless
        ChannelType::UInt_24_8,  // D24UNormS8UInt
        ChannelType::UnSupported,  // R24UNormX8Typeless
        ChannelType::UnSupported,  // X24TypelessG8UInt
        ChannelType::UnSupported,  // R8G8Typeless
        ChannelType::UByte,  // R8G8UNorm
        ChannelType::UByte,  // R8G8UInt
        ChannelType::Byte,  // R8G8SNorm
        ChannelType::Byte,  // R8G8SInt
        ChannelType::UnSupported,  // R16Typeless
        ChannelType::HalfFloat,  // R16Float
        ChannelType::UShort,  // D16UNorm
        ChannelType::UShort,  // R16UNorm
        ChannelType::UShort,  // R16UInt
        ChannelType::Short,  // R16SNorm
        ChannelType::Short,  // R16SInt
        ChannelType::UnSupported,  // R8Typeless
        ChannelType::UByte,  // R8UNorm
        ChannelType::UByte,  // R8UInt
        ChannelType::Byte,  // R8SNorm
        ChannelType::Byte,  // R8SInt
        ChannelType::UnSupported,  // A8UNorm
        ChannelType::UnSupported,  // R1UNorm
        ChannelType::UnSupported,  // R9G9B9E5SharedEXP
        ChannelType::UnSupported,  // R8G8B8G8UNorm
        ChannelType::UnSupported,  // G8R8G8B8UNorm
        ChannelType::UnSupported,  // BC1Typeless
        ChannelType::UnSupported,  // BC1UNorm
        ChannelType::UnSupported,  // BC1UNormSRGB
        ChannelType::UnSupported,  // BC2Typeless
        ChannelType::UnSupported,  // BC2UNorm
        ChannelType::UnSupported,  // BC2UNormSRGB
        ChannelType::UnSupported,  // BC3Typeless
        ChannelType::UnSupported,  // BC3UNorm
        ChannelType::UnSupported,  // BC3UNormSRGB
        ChannelType::UnSupported,  // BC4Typeless
        ChannelType::UnSupported,  // BC4UNorm
        ChannelType::UnSupported,  // BC4SNorm
        ChannelType::UnSupported,  // BC5Typeless
        ChannelType::UnSupported,  // BC5UNorm
        ChannelType::UnSupported,  // BC5SNorm
        ChannelType::UnSupported,  // B5G6R5UNorm
        ChannelType::UnSupported,  // B5G5R5A1UNorm
        ChannelType::UnSupported,  // B8G8R8A8UNorm
        ChannelType::UnSupported,  // B8G8R8X8UNorm
        ChannelType::UnSupported,  // R10G10B10XRBiasA2UNorm
        ChannelType::UnSupported,  // B8G8R8A8Typeless
        ChannelType::UnSupported,  // B8G8R8A8UNormSRGB
        ChannelType::UnSupported,  // B8G8R8X8Typeless
        ChannelType::UnSupported,  // B8G8R8X8UNormSRGB
        ChannelType::UnSupported,  // BC6HTypeless
        ChannelType::UnSupported,  // BC6HUF16
        ChannelType::UnSupported,  // BC6HSF16
        ChannelType::UnSupported,  // BC7Typeless
        ChannelType::UnSupported,  // BC7UNorm
        ChannelType::UnSupported,  // BC7UNormSRGB

        ChannelType::UnSupported,  // AYUV
        ChannelType::UnSupported,  // Y410
        ChannelType::UnSupported,  // Y416
        ChannelType::UnSupported,  // NV12
        ChannelType::UnSupported,  // P010
        ChannelType::UnSupported,  // P016
        ChannelType::UnSupported,  // Opaque420
        ChannelType::UnSupported,  // YUY2
        ChannelType::UnSupported,  // Y210
        ChannelType::UnSupported,  // Y216
        ChannelType::UnSupported,  // NV11
        ChannelType::UnSupported,  // AI44
        ChannelType::UnSupported,  // IA44
        ChannelType::UnSupported,  // P8
        ChannelType::UnSupported,  // A8P8
        ChannelType::UnSupported  // B4G4R4A4UNorm
    };

    return channelType.at(System::EnumCastUnderlying(type));
}

bool Rendering::DataFormat::ConvertChannel(DataFormatType type)
{
    static const std::array<bool, numFormats> convertChannel{
        false,  // Unknown
        false,  // R32G32B32A32Typeless
        false,  // R32G32B32A32Float
        false,  // R32G32B32A32UInt
        false,  // R32G32B32A32SInt
        false,  // R32G32B32Typeless
        false,  // R32G32B32Float
        false,  // R32G32B32UInt
        false,  // R32G32B32SInt
        false,  // R16G16B16A16Typeless
        false,  // R16G16B16A16Float
        true,  // R16G16B16A16UNorm
        false,  // R16G16B16A16UInt
        true,  // R16G16B16A16SNorm
        false,  // R16G16B16A16SInt
        false,  // R32G32Typeless
        false,  // R32G32Float
        false,  // R32G32UInt
        false,  // R32G32SInt
        false,  // R32G8X24Typeless
        false,  // D32FloatS8X24UInt
        false,  // R32FloatX8X24Typeless
        false,  // X32TypelessG8X24UInt
        false,  // R10G10B10A2Typeless
        true,  // R10G10B10A2UNorm
        false,  // R10G10B10A2UInt
        false,  // R11G11B10Float
        false,  // R8G8B8A8Typeless
        true,  // R8G8B8A8UNorm
        true,  // R8G8B8A8UNormSRGB
        false,  // R8G8B8A8UInt
        true,  // R8G8B8A8SNorm
        false,  // R8G8B8A8SInt
        false,  // R16G16Typeless
        false,  // R16G16Float
        true,  // R16G16UNorm
        false,  // R16G16UInt
        true,  // R16G16SNorm
        false,  // R16G16SInt
        false,  // R32Typeless
        false,  // D32Float
        false,  // R32Float
        false,  // R32UInt
        false,  // R32SInt
        false,  // R24G8Typeless
        false,  // D24UNormS8UInt
        false,  // R24UNormX8Typeless
        false,  // X24TypelessG8UInt
        false,  // R8G8Typeless
        true,  // R8G8UNorm
        false,  // R8G8UInt
        true,  // R8G8SNorm
        false,  // R8G8SInt
        false,  // R16Typeless
        false,  // R16Float
        true,  // D16UNorm
        true,  // R16UNorm
        false,  // R16UInt
        true,  // R16SNorm
        false,  // R16SInt
        false,  // R8Typeless
        true,  // R8UNorm
        false,  // R8UInt
        true,  // R8SNorm
        false,  // R8SInt
        true,  // A8UNorm
        true,  // R1UNorm
        false,  // R9G9B9E5SharedEXP
        true,  // R8G8B8G8UNorm
        true,  // G8R8G8B8UNorm
        false,  // BC1Typeless
        true,  // BC1UNorm
        true,  // BC1UNormSRGB
        false,  // BC2Typeless
        true,  // BC2UNorm
        true,  // BC2UNormSRGB
        false,  // BC3Typeless
        true,  // BC3UNorm
        true,  // BC3UNorm_SRGB
        false,  // BC4Typeless
        true,  // BC4UNorm
        true,  // BC4SNorm
        false,  // BC5Typeless
        true,  // BC5UNorm
        true,  // BC5SNorm
        true,  // B5G6R5UNorm
        true,  // B5G5R5A1UNorm
        true,  // B8G8R8A8UNorm
        true,  // B8G8R8X8UNorm
        true,  // R10G10B10XRBiasA2UNorm
        false,  // B8G8R8A8Typeless
        true,  // B8G8R8A8UNormSRGB
        false,  // B8G8R8X8Typeless
        true,  // B8G8R8X8UNormSRGB
        false,  // BC6HTypeless
        false,  // BC6HUF16
        false,  // BC6HSF16
        false,  // BC7Typeless
        true,  // BC7UNorm
        true,  // BC7UNormSRGB

        false,  // AYUV
        false,  // Y410
        false,  // Y416
        false,  // NV12
        false,  // P010
        false,  // P016
        false,  // Opaque420
        false,  // YUY2
        false,  // Y210
        false,  // Y216
        false,  // NV11
        false,  // AI44
        false,  // IA44
        false,  // P8
        false,  // A8P8
        false  // B4G4R4A4UNorm
    };

    return convertChannel.at(System::EnumCastUnderlying(type));
}

bool Rendering::DataFormat::IsSupported(DataFormatType type)
{
    static const std::array<bool, numFormats> supported{
        false,  // Unknown
        true,  // R32G32B32A32Typeless
        true,  // R32G32B32A32Float
        true,  // R32G32B32A32UInt
        true,  // R32G32B32A32SInt
        true,  // R32G32B32Typeless
        true,  // R32G32B32Float
        true,  // R32G32B32UInt
        true,  // R32G32B32SInt
        true,  // R16G16B16A16Typeless
        true,  // R16G16B16A16Float
        true,  // R16G16B16A16UNorm
        true,  // R16G16B16A16UInt
        true,  // R16G16B16A16SNorm
        true,  // R16G16B16A16SInt
        true,  // R32G32Typeless
        true,  // R32G32Float
        true,  // R32G32UInt
        true,  // R32G32SInt
        true,  // R32G8X24Typeless
        true,  // D32FloatS8X24UInt
        true,  // R32FloatX8X24Typeless
        true,  // X32TypelessG8X24UInt
        true,  // R10G10B10A2Typeless
        true,  // R10G10B10A2UNorm
        true,  // R10G10B10A2UInt
        true,  // R11G11B10Float
        true,  // R8G8B8A8Typeless
        true,  // R8G8B8A8UNorm
        true,  // R8G8B8A8UNormSRGB
        true,  // R8G8B8A8UInt
        true,  // R8G8B8A8SNorm
        true,  // R8G8B8A8SInt
        true,  // R16G16Typeless
        true,  // R16G16Float
        true,  // R16G16UNorm
        true,  // R16G16UInt
        true,  // R16G16SNorm
        true,  // R16G16SInt
        true,  // R32Typeless
        true,  // D32Float
        true,  // R32Float
        true,  // R32UInt
        true,  // R32SInt
        true,  // R24G8Typeless
        true,  // D24UNormS8UInt
        true,  // R24UNormX8Typeless
        true,  // X24TypelessG8UInt
        true,  // R8G8Typeless
        true,  // R8G8UNorm
        true,  // R8G8UInt
        true,  // R8G8SNorm
        true,  // R8G8SInt
        true,  // R16Typeless
        true,  // R16Float
        true,  // D16UNorm
        true,  // R16UNorm
        true,  // R16UInt
        true,  // R16SNorm
        true,  // R16SInt
        true,  // R8Typeless
        true,  // R8UNorm
        true,  // R8UInt
        true,  // R8SNorm
        true,  // R8SInt
        true,  // A8UNorm
        false,  // R1UNorm
        true,  // R9G9B9E5SharedEXP
        true,  // R8G8B8G8UNorm
        true,  // G8R8G8B8UNorm
        false,  // BC1Typeless
        false,  // BC1UNorm
        false,  // BC1UNormSRGB
        false,  // BC2Typeless
        false,  // BC2UNorm
        false,  // BC2UNormSRGB
        false,  // BC3Typeless
        false,  // BC3UNorm
        false,  // BC3UNormSRGB
        false,  // BC4Typeless
        false,  // BC4UNorm
        false,  // BC4SNorm
        false,  // BC5Typeless
        false,  // BC5UNorm
        false,  // BC5SNorm
        true,  // B5G6R5UNorm
        true,  // B5G5R5A1UNorm
        true,  // B8G8R8A8UNorm
        true,  // B8G8R8X8UNorm
        true,  // R10G10B10XRBiasA2UNorm
        true,  // B8G8R8A8Typeless
        true,  // B8G8R8A8UNormSRGB
        true,  // B8G8R8X8Typeless
        true,  // B8G8R8X8UNormSRGB
        false,  // BC6HTypeless
        false,  // BC6HUF16
        false,  // BC6HSF16
        false,  // BC7Typeless
        false,  // BC7UNorm
        false,  // BC7UNormSRGB

        false,  // AYUV
        false,  // Y410
        false,  // Y416
        false,  // NV12
        false,  // P010
        false,  // P016
        false,  // Opaque420
        false,  // YUY2
        false,  // Y210
        false,  // Y216
        false,  // NV11
        false,  // AI44
        false,  // IA44
        false,  // P8
        false,  // A8P8
        false  // B4G4R4A4UNorm
    };

    return supported.at(System::EnumCastUnderlying(type));
}

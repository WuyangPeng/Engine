///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 13:48)

#ifndef RENDERING_RESOURCES_DATA_FORMAT_TYPE_H
#define RENDERING_RESOURCES_DATA_FORMAT_TYPE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace Rendering
{
    enum class DataFormatType
    {
        Unknown = 0,
        R32G32B32A32Typeless = 1,
        R32G32B32A32Float = 2,
        R32G32B32A32UInt = 3,
        R32G32B32A32SInt = 4,
        R32G32B32Typeless = 5,
        R32G32B32Float = 6,
        R32G32B32UInt = 7,
        R32G32B32SInt = 8,
        R16G16B16A16Typeless = 9,
        R16G16B16A16Float = 10,
        R16G16B16A16UNorm = 11,
        R16G16B16A16UInt = 12,
        R16G16B16A16SNorm = 13,
        R16G16B16A16SInt = 14,
        R32G32Typeless = 15,
        R32G32Float = 16,
        R32G32UInt = 17,
        R32G32SInt = 18,
        R32G8X24Typeless = 19,
        D32FloatS8X24UInt = 20,
        R32FloatX8X24Typeless = 21,
        X32TypelessG8X24UInt = 22,
        R10G10B10A2Typeless = 23,
        R10G10B10A2UNorm = 24,
        R10G10B10A2UInt = 25,
        R11G11B10Float = 26,
        R8G8B8A8Typeless = 27,
        R8G8B8A8UNorm = 28,
        R8G8B8A8UNormSRGB = 29,
        R8G8B8A8UInt = 30,
        R8G8B8A8SNorm = 31,
        R8G8B8A8SInt = 32,
        R16G16Typeless = 33,
        R16G16Float = 34,
        R16G16UNorm = 35,
        R16G16UInt = 36,
        R16G16SNorm = 37,
        R16G16SInt = 38,
        R32Typeless = 39,
        D32Float = 40,
        R32Float = 41,
        R32UInt = 42,
        R32SInt = 43,
        R24G8Typeless = 44,
        D24UNormS8UInt = 45,
        R24UNormX8Typeless = 46,
        X24TypelessG8UInt = 47,
        R8G8Typeless = 48,
        R8G8UNorm = 49,
        R8G8UInt = 50,
        R8G8SNorm = 51,
        R8G8SInt = 52,
        R16Typeless = 53,
        R16Float = 54,
        D16UNorm = 55,
        R16UNorm = 56,
        R16UInt = 57,
        R16SNorm = 58,
        R16SInt = 59,
        R8Typeless = 60,
        R8UNorm = 61,
        R8UInt = 62,
        R8SNorm = 63,
        R8SInt = 64,
        A8UNorm = 65,
        R1UNorm = 66,
        R9G9B9E5SharedEXP = 67,
        R8G8B8G8UNorm = 68,
        G8R8G8B8UNorm = 69,
        BC1Typeless = 70,
        BC1UNorm = 71,
        BC1UNormSRGB = 72,
        BC2Typeless = 73,
        BC2UNorm = 74,
        BC2UNormSRGB = 75,
        BC3Typeless = 76,
        BC3UNorm = 77,
        BC3UNormSRGB = 78,
        BC4Typeless = 79,
        BC4UNorm = 80,
        BC4SNorm = 81,
        BC5Typeless = 82,
        BC5UNorm = 83,
        BC5SNorm = 84,
        B5G6R5UNorm = 85,
        B5G5R5A1UNorm = 86,
        B8G8R8A8UNorm = 87,
        B8G8R8X8UNorm = 88,
        R10G10B10XRBiasA2UNorm = 89,
        B8G8R8A8Typeless = 90,
        B8G8R8A8UNormSRGB = 91,
        B8G8R8X8Typeless = 92,
        B8G8R8X8UNormSRGB = 93,
        BC6HTypeless = 94,
        BC6HUF16 = 95,
        BC6HSF16 = 96,
        BC7Typeless = 97,
        BC7UNorm = 98,
        BC7UNormSRGB = 99,

        AYUV = 100,
        Y410 = 101,
        Y416 = 102,
        NV12 = 103,
        P010 = 104,
        P016 = 105,
        Opaque420 = 106,
        YUY2 = 107,
        Y210 = 108,
        Y216 = 109,
        NV11 = 110,
        AI44 = 111,
        IA44 = 112,
        P8 = 113,
        A8P8 = 114,
        B4G4R4A4UNorm = 115,
        NumFormats = 116,
    };

    ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(DataFormatType)
    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(DataFormatType)
}

#endif  // RENDERING_RESOURCES_DATA_FORMAT_TYPE_H

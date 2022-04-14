///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 11:32)

#ifndef RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H
#define RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H

#include "HalfFloat.h"
#include "Flags/TextureFormat.h"

#include <array>

namespace Rendering
{
    struct TrueType
    {
    };

    struct FalseType
    {
    };

    template <TextureFormat Format>
    struct ColourTextureFormatTraits;

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R5G6B5>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 3;
        static constexpr auto step = 2;

        static constexpr auto redMaxValue = 0x1F;
        static constexpr auto greenMaxValue = 0x3F;
        static constexpr auto blueMaxValue = 0x1F;
        static constexpr auto alphaMaxValue = 0;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 5;
        static constexpr auto greenBytes = 6;
        static constexpr auto blueBytes = 5;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint16_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 0,
            Green = 1,
            Blue = 2,
            Alpha = -1,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ redMaxValue, greenMaxValue, blueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A1R5G5B5>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 2;

        static constexpr auto redMaxValue = 0x1F;
        static constexpr auto greenMaxValue = 0x1F;
        static constexpr auto blueMaxValue = 0x1F;
        static constexpr auto alphaMaxValue = 0x01;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 5;
        static constexpr auto greenBytes = 5;
        static constexpr auto blueBytes = 5;
        static constexpr auto alphaBytes = 1;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint16_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 1,
            Green = 2,
            Blue = 3,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue, redMaxValue, greenMaxValue, blueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A4R4G4B4>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 2;

        static constexpr auto redMaxValue = 0x0F;
        static constexpr auto greenMaxValue = 0x0F;
        static constexpr auto blueMaxValue = 0x0F;
        static constexpr auto alphaMaxValue = 0x0F;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 4;
        static constexpr auto greenBytes = 4;
        static constexpr auto blueBytes = 4;
        static constexpr auto alphaBytes = 4;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint16_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 1,
            Green = 2,
            Blue = 3,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue, redMaxValue, greenMaxValue, blueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 1;
        static constexpr auto step = 1;

        static constexpr auto redMaxValue = 0;
        static constexpr auto greenMaxValue = 0;
        static constexpr auto blueMaxValue = 0;
        static constexpr auto alphaMaxValue = 0xFF;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 0;
        static constexpr auto greenBytes = 0;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 8;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint8_t;
        using RedType = FalseType;
        using GreenType = FalseType;
        using BlueType = FalseType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = -1,
            Green = -1,
            Blue = -1,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::L8>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 1;
        static constexpr auto step = 1;

        static constexpr auto redMaxValue = 0;
        static constexpr auto greenMaxValue = 0;
        static constexpr auto blueMaxValue = 0;
        static constexpr auto alphaMaxValue = 0;
        static constexpr auto luminanceMaxValue = 0xFF;

        static constexpr auto redBytes = 0;
        static constexpr auto greenBytes = 0;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 8;

        using ColourType = uint8_t;
        using BytesType = uint8_t;
        using RedType = FalseType;
        using GreenType = FalseType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = TrueType;

        enum class Channel
        {
            Red = -1,
            Green = -1,
            Blue = -1,
            Alpha = -1,
            Luminance = 0,
        };

        static constexpr std::array<int, arraySize> maxValue{ luminanceMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8L8>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 2;
        static constexpr auto step = 2;

        static constexpr auto redMaxValue = 0;
        static constexpr auto greenMaxValue = 0;
        static constexpr auto blueMaxValue = 0;
        static constexpr auto alphaMaxValue = 0xFF;
        static constexpr auto luminanceMaxValue = 0xFF;

        static constexpr auto redBytes = 0;
        static constexpr auto greenBytes = 0;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 8;
        static constexpr auto luminanceBytes = 8;

        using ColourType = uint8_t;
        using BytesType = uint8_t;
        using RedType = FalseType;
        using GreenType = FalseType;
        using BlueType = FalseType;
        using AlphaType = TrueType;
        using LuminanceType = TrueType;

        enum class Channel
        {
            Red = -1,
            Green = -1,
            Blue = -1,
            Alpha = 0,
            Luminance = 1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue, luminanceMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R8G8B8>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 3;
        static constexpr auto step = 3;

        static constexpr auto redMaxValue = 0xFF;
        static constexpr auto greenMaxValue = 0xFF;
        static constexpr auto blueMaxValue = 0xFF;
        static constexpr auto alphaMaxValue = 0;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 8;
        static constexpr auto greenBytes = 8;
        static constexpr auto blueBytes = 8;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint8_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 0,
            Green = 1,
            Blue = 2,
            Alpha = -1,
            Luminance = 1,
        };

        static constexpr std::array<int, arraySize> maxValue{ redMaxValue, greenMaxValue, blueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8R8G8B8>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 4;

        static constexpr auto redMaxValue = 0xFF;
        static constexpr auto greenMaxValue = 0xFF;
        static constexpr auto blueMaxValue = 0xFF;
        static constexpr auto alphaMaxValue = 0xFF;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 8;
        static constexpr auto greenBytes = 8;
        static constexpr auto blueBytes = 8;
        static constexpr auto alphaBytes = 8;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint8_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 1,
            Green = 2,
            Blue = 3,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue, redMaxValue, greenMaxValue, blueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8B8G8R8>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 4;

        static constexpr auto redMaxValue = 0xFF;
        static constexpr auto greenMaxValue = 0xFF;
        static constexpr auto blueMaxValue = 0xFF;
        static constexpr auto alphaMaxValue = 0xFF;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 8;
        static constexpr auto greenBytes = 8;
        static constexpr auto blueBytes = 8;
        static constexpr auto alphaBytes = 8;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint8_t;
        using BytesType = uint8_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 3,
            Green = 2,
            Blue = 1,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue, blueMaxValue, greenMaxValue, redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::L16>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 1;
        static constexpr auto step = 2;

        static constexpr auto redMaxValue = 0;
        static constexpr auto greenMaxValue = 0;
        static constexpr auto blueMaxValue = 0;
        static constexpr auto alphaMaxValue = 0;
        static constexpr auto luminanceMaxValue = 0xFFFF;

        static constexpr auto redBytes = 0;
        static constexpr auto greenBytes = 0;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 16;

        using ColourType = uint16_t;
        using BytesType = uint16_t;
        using RedType = FalseType;
        using GreenType = FalseType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = TrueType;

        enum class Channel
        {
            Red = -1,
            Green = -1,
            Blue = -1,
            Alpha = -1,
            Luminance = 0,
        };

        static constexpr std::array<int, arraySize> maxValue{ luminanceMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::G16R16>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 2;
        static constexpr auto step = 4;

        static constexpr auto redMaxValue = 0xFFFF;
        static constexpr auto greenMaxValue = 0xFFFF;
        static constexpr auto blueMaxValue = 0;
        static constexpr auto alphaMaxValue = 0;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 16;
        static constexpr auto greenBytes = 16;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint16_t;
        using BytesType = uint16_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 1,
            Green = 0,
            Blue = -1,
            Alpha = -1,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ greenMaxValue, redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A16B16G16R16>
    {
        static constexpr auto minValue = 0;
        static constexpr auto isFloatingPoint = false;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 8;

        static constexpr auto redMaxValue = 0xFFFF;
        static constexpr auto greenMaxValue = 0xFFFF;
        static constexpr auto blueMaxValue = 0xFFFF;
        static constexpr auto alphaMaxValue = 0xFFFF;
        static constexpr auto luminanceMaxValue = 0;

        static constexpr auto redBytes = 16;
        static constexpr auto greenBytes = 16;
        static constexpr auto blueBytes = 16;
        static constexpr auto alphaBytes = 16;
        static constexpr auto luminanceBytes = 0;

        using ColourType = uint16_t;
        using BytesType = uint16_t;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 3,
            Green = 2,
            Blue = 1,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<int, arraySize> maxValue{ alphaMaxValue, blueBytes, greenBytes, redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R16F>
    {
        static constexpr auto minValue = 0.0f;
        static constexpr auto isFloatingPoint = true;
        static constexpr auto arraySize = 1;
        static constexpr auto step = 2;

        static constexpr auto redMaxValue = 1.0f;
        static constexpr auto greenMaxValue = 0.0f;
        static constexpr auto blueMaxValue = 0.0f;
        static constexpr auto alphaMaxValue = 0.0f;
        static constexpr auto luminanceMaxValue = 0.0f;

        static constexpr auto redBytes = 16;
        static constexpr auto greenBytes = 0;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = float;
        using BytesType = HalfFloat::OriginalType;
        using RedType = TrueType;
        using GreenType = FalseType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 0,
            Green = -1,
            Blue = -1,
            Alpha = -1,
            Luminance = -1,
        };

        static constexpr std::array<float, arraySize> maxValue{ redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::G16R16F>
    {
        static constexpr auto minValue = 0.0f;
        static constexpr auto isFloatingPoint = true;
        static constexpr auto arraySize = 2;
        static constexpr auto step = 4;

        static constexpr auto redMaxValue = 1.0f;
        static constexpr auto greenMaxValue = 1.0f;
        static constexpr auto blueMaxValue = 0.0f;
        static constexpr auto alphaMaxValue = 0.0f;
        static constexpr auto luminanceMaxValue = 0.0f;

        static constexpr auto redBytes = 16;
        static constexpr auto greenBytes = 16;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = float;
        using BytesType = HalfFloat::OriginalType;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 1,
            Green = 0,
            Blue = -1,
            Alpha = -1,
            Luminance = -1,
        };

        static constexpr std::array<float, arraySize> maxValue{ greenMaxValue, redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>
    {
        static constexpr auto minValue = 0.0f;
        static constexpr auto isFloatingPoint = true;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 8;

        static constexpr auto redMaxValue = 1.0f;
        static constexpr auto greenMaxValue = 1.0f;
        static constexpr auto blueMaxValue = 1.0f;
        static constexpr auto alphaMaxValue = 1.0f;
        static constexpr auto luminanceMaxValue = 0.0f;

        static constexpr auto redBytes = 16;
        static constexpr auto greenBytes = 16;
        static constexpr auto blueBytes = 16;
        static constexpr auto alphaBytes = 16;
        static constexpr auto luminanceBytes = 0;

        using ColourType = float;
        using BytesType = HalfFloat::OriginalType;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 3,
            Green = 2,
            Blue = 1,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<float, arraySize> maxValue{ alphaMaxValue, blueBytes, greenBytes, redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R32F>
    {
        static constexpr auto minValue = 0.0f;
        static constexpr auto isFloatingPoint = true;
        static constexpr auto arraySize = 1;
        static constexpr auto step = 4;

        static constexpr auto redMaxValue = 1.0f;
        static constexpr auto greenMaxValue = 0.0f;
        static constexpr auto blueMaxValue = 0.0f;
        static constexpr auto alphaMaxValue = 0.0f;
        static constexpr auto luminanceMaxValue = 0.0f;

        static constexpr auto redBytes = 32;
        static constexpr auto greenBytes = 0;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = float;
        using BytesType = float;
        using RedType = TrueType;
        using GreenType = FalseType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 0,
            Green = -1,
            Blue = -1,
            Alpha = -1,
            Luminance = -1,
        };

        static constexpr std::array<float, arraySize> maxValue{ redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::G32R32F>
    {
        static constexpr auto minValue = 0.0f;
        static constexpr auto isFloatingPoint = true;
        static constexpr auto arraySize = 2;
        static constexpr auto step = 8;

        static constexpr auto redMaxValue = 1.0f;
        static constexpr auto greenMaxValue = 1.0f;
        static constexpr auto blueMaxValue = 0.0f;
        static constexpr auto alphaMaxValue = 0.0f;
        static constexpr auto luminanceMaxValue = 0.0f;

        static constexpr auto redBytes = 32;
        static constexpr auto greenBytes = 32;
        static constexpr auto blueBytes = 0;
        static constexpr auto alphaBytes = 0;
        static constexpr auto luminanceBytes = 0;

        using ColourType = float;
        using BytesType = float;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = FalseType;
        using AlphaType = FalseType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 1,
            Green = 0,
            Blue = -1,
            Alpha = -1,
            Luminance = -1,
        };

        static constexpr std::array<float, arraySize> maxValue{ greenBytes, redMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>
    {
        static constexpr auto minValue = 0.0f;
        static constexpr auto isFloatingPoint = true;
        static constexpr auto arraySize = 4;
        static constexpr auto step = 16;

        static constexpr auto redMaxValue = 1.0f;
        static constexpr auto greenMaxValue = 1.0f;
        static constexpr auto blueMaxValue = 1.0f;
        static constexpr auto alphaMaxValue = 1.0f;
        static constexpr auto luminanceMaxValue = 0.0f;

        static constexpr auto redBytes = 32;
        static constexpr auto greenBytes = 32;
        static constexpr auto blueBytes = 32;
        static constexpr auto alphaBytes = 32;
        static constexpr auto luminanceBytes = 0;

        using ColourType = float;
        using BytesType = float;
        using RedType = TrueType;
        using GreenType = TrueType;
        using BlueType = TrueType;
        using AlphaType = TrueType;
        using LuminanceType = FalseType;

        enum class Channel
        {
            Red = 3,
            Green = 2,
            Blue = 1,
            Alpha = 0,
            Luminance = -1,
        };

        static constexpr std::array<float, arraySize> maxValue{ alphaMaxValue, blueBytes, greenBytes, redMaxValue };
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H

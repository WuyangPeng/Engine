//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/20 17:41)

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
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 3;
        static constexpr auto sm_Step = 2;

        static constexpr auto sm_RedMaxValue = 0x1F;
        static constexpr auto sm_GreenMaxValue = 0x3F;
        static constexpr auto sm_BlueMaxValue = 0x1F;
        static constexpr auto sm_AlphaMaxValue = 0;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 5;
        static constexpr auto sm_GreenBytes = 6;
        static constexpr auto sm_BlueBytes = 5;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_RedMaxValue, sm_GreenMaxValue, sm_BlueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A1R5G5B5>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 2;

        static constexpr auto sm_RedMaxValue = 0x1F;
        static constexpr auto sm_GreenMaxValue = 0x1F;
        static constexpr auto sm_BlueMaxValue = 0x1F;
        static constexpr auto sm_AlphaMaxValue = 0x01;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 5;
        static constexpr auto sm_GreenBytes = 5;
        static constexpr auto sm_BlueBytes = 5;
        static constexpr auto sm_AlphaBytes = 1;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_RedMaxValue, sm_GreenMaxValue, sm_BlueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A4R4G4B4>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 2;

        static constexpr auto sm_RedMaxValue = 0x0F;
        static constexpr auto sm_GreenMaxValue = 0x0F;
        static constexpr auto sm_BlueMaxValue = 0x0F;
        static constexpr auto sm_AlphaMaxValue = 0x0F;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 4;
        static constexpr auto sm_GreenBytes = 4;
        static constexpr auto sm_BlueBytes = 4;
        static constexpr auto sm_AlphaBytes = 4;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_RedMaxValue, sm_GreenMaxValue, sm_BlueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 1;
        static constexpr auto sm_Step = 1;

        static constexpr auto sm_RedMaxValue = 0;
        static constexpr auto sm_GreenMaxValue = 0;
        static constexpr auto sm_BlueMaxValue = 0;
        static constexpr auto sm_AlphaMaxValue = 0xFF;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 0;
        static constexpr auto sm_GreenBytes = 0;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 8;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::L8>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 1;
        static constexpr auto sm_Step = 1;

        static constexpr auto sm_RedMaxValue = 0;
        static constexpr auto sm_GreenMaxValue = 0;
        static constexpr auto sm_BlueMaxValue = 0;
        static constexpr auto sm_AlphaMaxValue = 0;
        static constexpr auto sm_LuminanceMaxValue = 0xFF;

        static constexpr auto sm_RedBytes = 0;
        static constexpr auto sm_GreenBytes = 0;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 8;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_LuminanceMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8L8>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 2;
        static constexpr auto sm_Step = 2;

        static constexpr auto sm_RedMaxValue = 0;
        static constexpr auto sm_GreenMaxValue = 0;
        static constexpr auto sm_BlueMaxValue = 0;
        static constexpr auto sm_AlphaMaxValue = 0xFF;
        static constexpr auto sm_LuminanceMaxValue = 0xFF;

        static constexpr auto sm_RedBytes = 0;
        static constexpr auto sm_GreenBytes = 0;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 8;
        static constexpr auto sm_LuminanceBytes = 8;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_LuminanceMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R8G8B8>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 3;
        static constexpr auto sm_Step = 3;

        static constexpr auto sm_RedMaxValue = 0xFF;
        static constexpr auto sm_GreenMaxValue = 0xFF;
        static constexpr auto sm_BlueMaxValue = 0xFF;
        static constexpr auto sm_AlphaMaxValue = 0;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 8;
        static constexpr auto sm_GreenBytes = 8;
        static constexpr auto sm_BlueBytes = 8;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_RedMaxValue, sm_GreenMaxValue, sm_BlueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8R8G8B8>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 4;

        static constexpr auto sm_RedMaxValue = 0xFF;
        static constexpr auto sm_GreenMaxValue = 0xFF;
        static constexpr auto sm_BlueMaxValue = 0xFF;
        static constexpr auto sm_AlphaMaxValue = 0xFF;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 8;
        static constexpr auto sm_GreenBytes = 8;
        static constexpr auto sm_BlueBytes = 8;
        static constexpr auto sm_AlphaBytes = 8;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_RedMaxValue, sm_GreenMaxValue, sm_BlueMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A8B8G8R8>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 4;

        static constexpr auto sm_RedMaxValue = 0xFF;
        static constexpr auto sm_GreenMaxValue = 0xFF;
        static constexpr auto sm_BlueMaxValue = 0xFF;
        static constexpr auto sm_AlphaMaxValue = 0xFF;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 8;
        static constexpr auto sm_GreenBytes = 8;
        static constexpr auto sm_BlueBytes = 8;
        static constexpr auto sm_AlphaBytes = 8;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_BlueMaxValue, sm_GreenMaxValue, sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::L16>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 1;
        static constexpr auto sm_Step = 2;

        static constexpr auto sm_RedMaxValue = 0;
        static constexpr auto sm_GreenMaxValue = 0;
        static constexpr auto sm_BlueMaxValue = 0;
        static constexpr auto sm_AlphaMaxValue = 0;
        static constexpr auto sm_LuminanceMaxValue = 0xFFFF;

        static constexpr auto sm_RedBytes = 0;
        static constexpr auto sm_GreenBytes = 0;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 16;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_LuminanceMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::G16R16>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 2;
        static constexpr auto sm_Step = 4;

        static constexpr auto sm_RedMaxValue = 0xFFFF;
        static constexpr auto sm_GreenMaxValue = 0xFFFF;
        static constexpr auto sm_BlueMaxValue = 0;
        static constexpr auto sm_AlphaMaxValue = 0;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 16;
        static constexpr auto sm_GreenBytes = 16;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_GreenMaxValue, sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A16B16G16R16>
    {
        static constexpr auto sm_MinValue = 0;
        static constexpr auto sm_IsFloatingPoint = false;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 8;

        static constexpr auto sm_RedMaxValue = 0xFFFF;
        static constexpr auto sm_GreenMaxValue = 0xFFFF;
        static constexpr auto sm_BlueMaxValue = 0xFFFF;
        static constexpr auto sm_AlphaMaxValue = 0xFFFF;
        static constexpr auto sm_LuminanceMaxValue = 0;

        static constexpr auto sm_RedBytes = 16;
        static constexpr auto sm_GreenBytes = 16;
        static constexpr auto sm_BlueBytes = 16;
        static constexpr auto sm_AlphaBytes = 16;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<int, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_BlueBytes, sm_GreenBytes, sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R16F>
    {
        static constexpr auto sm_MinValue = 0.0f;
        static constexpr auto sm_IsFloatingPoint = true;
        static constexpr auto sm_ArraySize = 1;
        static constexpr auto sm_Step = 2;

        static constexpr auto sm_RedMaxValue = 1.0f;
        static constexpr auto sm_GreenMaxValue = 0.0f;
        static constexpr auto sm_BlueMaxValue = 0.0f;
        static constexpr auto sm_AlphaMaxValue = 0.0f;
        static constexpr auto sm_LuminanceMaxValue = 0.0f;

        static constexpr auto sm_RedBytes = 16;
        static constexpr auto sm_GreenBytes = 0;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<float, sm_ArraySize> sm_MaxValue{ sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::G16R16F>
    {
        static constexpr auto sm_MinValue = 0.0f;
        static constexpr auto sm_IsFloatingPoint = true;
        static constexpr auto sm_ArraySize = 2;
        static constexpr auto sm_Step = 4;

        static constexpr auto sm_RedMaxValue = 1.0f;
        static constexpr auto sm_GreenMaxValue = 1.0f;
        static constexpr auto sm_BlueMaxValue = 0.0f;
        static constexpr auto sm_AlphaMaxValue = 0.0f;
        static constexpr auto sm_LuminanceMaxValue = 0.0f;

        static constexpr auto sm_RedBytes = 16;
        static constexpr auto sm_GreenBytes = 16;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<float, sm_ArraySize> sm_MaxValue{ sm_GreenMaxValue, sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>
    {
        static constexpr auto sm_MinValue = 0.0f;
        static constexpr auto sm_IsFloatingPoint = true;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 8;

        static constexpr auto sm_RedMaxValue = 1.0f;
        static constexpr auto sm_GreenMaxValue = 1.0f;
        static constexpr auto sm_BlueMaxValue = 1.0f;
        static constexpr auto sm_AlphaMaxValue = 1.0f;
        static constexpr auto sm_LuminanceMaxValue = 0.0f;

        static constexpr auto sm_RedBytes = 16;
        static constexpr auto sm_GreenBytes = 16;
        static constexpr auto sm_BlueBytes = 16;
        static constexpr auto sm_AlphaBytes = 16;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<float, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_BlueBytes, sm_GreenBytes, sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::R32F>
    {
        static constexpr auto sm_MinValue = 0.0f;
        static constexpr auto sm_IsFloatingPoint = true;
        static constexpr auto sm_ArraySize = 1;
        static constexpr auto sm_Step = 4;

        static constexpr auto sm_RedMaxValue = 1.0f;
        static constexpr auto sm_GreenMaxValue = 0.0f;
        static constexpr auto sm_BlueMaxValue = 0.0f;
        static constexpr auto sm_AlphaMaxValue = 0.0f;
        static constexpr auto sm_LuminanceMaxValue = 0.0f;

        static constexpr auto sm_RedBytes = 32;
        static constexpr auto sm_GreenBytes = 0;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<float, sm_ArraySize> sm_MaxValue{ sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::G32R32F>
    {
        static constexpr auto sm_MinValue = 0.0f;
        static constexpr auto sm_IsFloatingPoint = true;
        static constexpr auto sm_ArraySize = 2;
        static constexpr auto sm_Step = 8;

        static constexpr auto sm_RedMaxValue = 1.0f;
        static constexpr auto sm_GreenMaxValue = 1.0f;
        static constexpr auto sm_BlueMaxValue = 0.0f;
        static constexpr auto sm_AlphaMaxValue = 0.0f;
        static constexpr auto sm_LuminanceMaxValue = 0.0f;

        static constexpr auto sm_RedBytes = 32;
        static constexpr auto sm_GreenBytes = 32;
        static constexpr auto sm_BlueBytes = 0;
        static constexpr auto sm_AlphaBytes = 0;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<float, sm_ArraySize> sm_MaxValue{ sm_GreenBytes, sm_RedMaxValue };
    };

    template <>
    struct ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>
    {
        static constexpr auto sm_MinValue = 0.0f;
        static constexpr auto sm_IsFloatingPoint = true;
        static constexpr auto sm_ArraySize = 4;
        static constexpr auto sm_Step = 16;

        static constexpr auto sm_RedMaxValue = 1.0f;
        static constexpr auto sm_GreenMaxValue = 1.0f;
        static constexpr auto sm_BlueMaxValue = 1.0f;
        static constexpr auto sm_AlphaMaxValue = 1.0f;
        static constexpr auto sm_LuminanceMaxValue = 0.0f;

        static constexpr auto sm_RedBytes = 32;
        static constexpr auto sm_GreenBytes = 32;
        static constexpr auto sm_BlueBytes = 32;
        static constexpr auto sm_AlphaBytes = 32;
        static constexpr auto sm_LuminanceBytes = 0;

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

        static constexpr std::array<float, sm_ArraySize> sm_MaxValue{ sm_AlphaMaxValue, sm_BlueBytes, sm_GreenBytes, sm_RedMaxValue };
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H

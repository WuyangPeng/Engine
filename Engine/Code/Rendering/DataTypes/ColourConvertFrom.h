//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/20 15:50)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_H

#include "Rendering/RenderingDll.h"

#include "DataTypesFwd.h"
#include "Flags/TextureFormat.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Base/SpanIterator.h"

#include <vector>

namespace Rendering
{
    // 从指定的格式转换为Colour<float>。
    class RENDERING_DEFAULT_DECLARE ColourConvertFrom
    {
    public:
        using ClassType = ColourConvertFrom;
        using InTexelsType = std::vector<char>;
        using OutTexelsType = std::vector<FloatColour>;
        using InTexelsTypeConstIter = InTexelsType::const_iterator;
        using SpanConstIterator = CoreTools::SpanIterator<InTexelsTypeConstIter>;

    public:
        static constexpr auto sm_ConvertFromQuantity = System::EnumCastUnderlying(TextureFormat::Quantity);

        // 从指定的格式转换到Colour<float>。

        // outTexels的长度为inTexels的长度 / 2。
        static OutTexelsType ConvertFromR5G6B5(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 2。
        static OutTexelsType ConvertFromA1R5G5B5(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 2。
        static OutTexelsType ConvertFromA4R4G4B4(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度。
        static OutTexelsType ConvertFromA8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度。
        static OutTexelsType ConvertFromL8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 2。
        static OutTexelsType ConvertFromA8L8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 3。
        static OutTexelsType ConvertFromR8G8B8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 4。
        static OutTexelsType ConvertFromA8R8G8B8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 4。
        static OutTexelsType ConvertFromA8B8G8R8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 2。
        static OutTexelsType ConvertFromL16(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 4。
        static OutTexelsType ConvertFromG16R16(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 8。
        static OutTexelsType ConvertFromA16B16G16R16(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 2。
        static OutTexelsType ConvertFromR16F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 4。
        static OutTexelsType ConvertFromG16R16F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 8。
        static OutTexelsType ConvertFromA16B16G16R16F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 4。
        static OutTexelsType ConvertFromR32F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 8。
        static OutTexelsType ConvertFromG32R32F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 / 16。
        static OutTexelsType ConvertFromA32B32G32R32F(const InTexelsType& inTexels);

        using ConvertFromFunction = OutTexelsType (*)(const InTexelsType&);
        static ConvertFromFunction GetConvertFromFunction(TextureFormat Format);

    private:
        template <TextureFormat Format>
        static constexpr float GetSmallRed(uint16_t current) noexcept
        {
            constexpr auto redMaxValue = ColourTextureFormatTraits<Format>::sm_RedMaxValue;
            constexpr auto redShift = ColourTextureFormatTraits<Format>::sm_BlueBytes + ColourTextureFormatTraits<Format>::sm_GreenBytes;

            static_assert(redMaxValue != 0);

            return static_cast<float>((current & (redMaxValue << redShift)) >> redShift) / static_cast<float>(redMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float GetSmallGreen(uint16_t current) noexcept
        {
            constexpr auto greenMaxValue = ColourTextureFormatTraits<Format>::sm_GreenMaxValue;
            constexpr auto greenShift = ColourTextureFormatTraits<Format>::sm_BlueBytes;

            static_assert(greenMaxValue != 0);

            return static_cast<float>((current & (greenMaxValue << greenShift)) >> greenShift) / static_cast<float>(greenMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float GetSmallBlue(uint16_t current) noexcept
        {
            constexpr auto blueMaxValue = ColourTextureFormatTraits<Format>::sm_BlueMaxValue;

            static_assert(blueMaxValue != 0);

            return static_cast<float>(current & blueMaxValue) / static_cast<float>(blueMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float GetSmallAlpha(uint16_t current) noexcept
        {
            constexpr auto alphaMaxValue = ColourTextureFormatTraits<Format>::sm_AlphaMaxValue;
            constexpr auto alphaShift = ColourTextureFormatTraits<Format>::sm_BlueBytes + ColourTextureFormatTraits<Format>::sm_GreenBytes + ColourTextureFormatTraits<Format>::sm_RedBytes;

            static_assert(alphaMaxValue != 0);

            return static_cast<float>((current & (alphaMaxValue << alphaShift)) >> alphaShift) / static_cast<float>(alphaMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float Get16BitRed(uint16_t current) noexcept
        {
            constexpr auto redMaxValue = ColourTextureFormatTraits<Format>::sm_RedMaxValue;

            static_assert(redMaxValue != 0);

            return static_cast<float>(current) / static_cast<float>(redMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float Get16BitGreen(uint16_t current) noexcept
        {
            constexpr auto greenMaxValue = ColourTextureFormatTraits<Format>::sm_GreenMaxValue;

            static_assert(greenMaxValue != 0);

            return static_cast<float>(current) / static_cast<float>(greenMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float Get16BitBlue(uint16_t current) noexcept
        {
            constexpr auto blueMaxValue = ColourTextureFormatTraits<Format>::sm_BlueMaxValue;

            static_assert(blueMaxValue != 0);

            return static_cast<float>(current) / static_cast<float>(blueMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float Get16BitAlpha(uint16_t current) noexcept
        {
            constexpr auto alphaMaxValue = ColourTextureFormatTraits<Format>::sm_AlphaMaxValue;

            static_assert(alphaMaxValue != 0);

            return static_cast<float>(current) / static_cast<float>(alphaMaxValue);
        }

        template <TextureFormat Format>
        static constexpr float Get16BitLuminance(uint16_t current) noexcept
        {
            constexpr auto luminanceMaxValue = ColourTextureFormatTraits<Format>::sm_LuminanceMaxValue;

            static_assert(luminanceMaxValue != 0);

            return static_cast<float>(current) / static_cast<float>(luminanceMaxValue);
        }

        template <TextureFormat Format>
        static auto Increase(SpanConstIterator& source)
        {
            using BytesType = typename ColourTextureFormatTraits<Format>::BytesType;

            return source.Increase<BytesType>();
        }

        template <TextureFormat Format>
        static float GetHalfFloat(SpanConstIterator& source);
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_H

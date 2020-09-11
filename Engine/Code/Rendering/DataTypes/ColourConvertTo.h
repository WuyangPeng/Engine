//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/22 1:23)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H

#include "Rendering/RenderingDll.h"

#include "Colour.h" 
#include "ColourTextureFormatTraits.h"
#include "Flags/TextureFormat.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Base/SpanIterator.h"

#include <vector>

namespace Rendering
{
    // 从Colour<float>转换为指定的格式。
    class RENDERING_DEFAULT_DECLARE ColourConvertTo
    {
    public:
        using ClassType = ColourConvertTo;
        using InTexelsType = std::vector<FloatColour>;
        using OutTexelsType = std::vector<char>;
        using OutTexelsTypeIter = OutTexelsType::iterator;
        using SpanIterator = CoreTools::SpanIterator<OutTexelsTypeIter>;

    public:
        static constexpr auto sm_ConvertToQuantity = System::EnumCastUnderlying(TextureFormat::Quantity);

        // 从Colour<float>转换到指定的格式。

        // outTexels的长度为inTexels的长度 * 2。
        static OutTexelsType ConvertToR5G6B5(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 2。
        static OutTexelsType ConvertToA1R5G5B5(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 2。
        static OutTexelsType ConvertToA4R4G4B4(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度。
        static OutTexelsType ConvertToA8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度。
        static OutTexelsType ConvertToL8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 2。
        static OutTexelsType ConvertToA8L8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 3。
        static OutTexelsType ConvertToR8G8B8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 4。
        static OutTexelsType ConvertToA8R8G8B8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 4。
        static OutTexelsType ConvertToA8B8G8R8(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 2。
        static OutTexelsType ConvertToL16(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 4。
        static OutTexelsType ConvertToG16R16(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 8。
        static OutTexelsType ConvertToA16B16G16R16(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 2。
        static OutTexelsType ConvertToR16F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 4。
        static OutTexelsType ConvertToG16R16F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 8。
        static OutTexelsType ConvertToA16B16G16R16F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 4。
        static OutTexelsType ConvertToR32F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 8。
        static OutTexelsType ConvertToG32R32F(const InTexelsType& inTexels);

        // outTexels的长度为inTexels的长度 * 16。
        static OutTexelsType ConvertToA32B32G32R32F(const InTexelsType& inTexels);

        using ConvertToFunction = OutTexelsType (*)(const InTexelsType&);
        static ConvertToFunction GetConvertToFunction(TextureFormat Format);

    private:
        template <TextureFormat Format>
        static constexpr auto GetRed(const FloatColour& colour) noexcept
        {
            return static_cast<uint16_t>(colour.GetRed() * ColourTextureFormatTraits<Format>::sm_RedMaxValue + 0.5f);
        }

        template <TextureFormat Format>
        static constexpr auto GetGreen(const FloatColour& colour) noexcept
        {
            return static_cast<uint16_t>(colour.GetGreen() * ColourTextureFormatTraits<Format>::sm_GreenMaxValue + 0.5f);
        }

        template <TextureFormat Format>
        static constexpr auto GetBlue(const FloatColour& colour) noexcept
        {
            return static_cast<uint16_t>(colour.GetBlue() * ColourTextureFormatTraits<Format>::sm_BlueMaxValue + 0.5f);
        }

        template <TextureFormat Format>
        static constexpr auto GetAlpha(const FloatColour& colour) noexcept
        {
            return static_cast<uint16_t>(colour.GetAlpha() * ColourTextureFormatTraits<Format>::sm_AlphaMaxValue + 0.5f);
        }

        template <TextureFormat Format>
        static constexpr auto GetLuminance(const FloatColour& colour) noexcept
        {
            return static_cast<uint16_t>(colour.GetRed() * ColourTextureFormatTraits<Format>::sm_LuminanceMaxValue + 0.5f);
        }

        template <TextureFormat Format>
        static uint16_t GetSmall(const FloatColour& colour) noexcept;

        template <TextureFormat Format>
        static void Increase(SpanIterator& source, typename ColourTextureFormatTraits<Format>::BytesType value);

        template <TextureFormat Format>
        static OutTexelsType ConvertToSmall(const InTexelsType& inTexels);

        template <TextureFormat Format>
        static void IncreaseHalfFloat(SpanIterator& source, float halfFloat);
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_DETAIL_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_DETAIL_H

#include "ColourConvertTo.h"
#include "ColourDetail.h"
#include "ColourTextureFormatTraits.h"
#include "Detail/TexelsToCheckDetail.h"
#include "CoreTools/Base/SpanIteratorDetail.h"

template <Rendering::TextureFormat Format>
uint16_t Rendering::ColourConvertTo::GetSmall(const FloatColour& colour) noexcept
{
    const auto red = GetRed<Format>(colour);
    const auto green = GetGreen<Format>(colour);
    const auto blue = GetBlue<Format>(colour);

    constexpr auto greenShift = ColourTextureFormatTraits<Format>::blueBytes;
    constexpr auto redShift = greenShift + ColourTextureFormatTraits<Format>::greenBytes;

    auto result = blue;
    result |= (green << greenShift);
    result |= (red << redShift);

    if constexpr (std::is_same_v<ColourTextureFormatTraits<Format>::AlphaType, TrueType>)
    {
        const auto alpha = GetAlpha<Format>(colour);
        constexpr auto alphaShift = redShift + ColourTextureFormatTraits<Format>::redBytes;

        result |= (alpha << alphaShift);
    }

    return result;
}

template <Rendering::TextureFormat Format>
void Rendering::ColourConvertTo::Increase(SpanIterator& source, typename ColourTextureFormatTraits<Format>::BytesType value)
{
    source.Increase(value);
}

template <Rendering::TextureFormat Format>
Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToSmall(const InTexelsType& inTexels)
{
    TexelsToCheck<Format> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const auto result = GetSmall<Format>(source);

        Increase<Format>(target, result);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

template <Rendering::TextureFormat Format>
void Rendering::ColourConvertTo::IncreaseHalfFloat(SpanIterator& source, float halfFloat)
{
    const auto result = HalfFloat{ halfFloat }.ToOriginalType();

    source.Increase(result);
}

#endif  // RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_DETAIL_H

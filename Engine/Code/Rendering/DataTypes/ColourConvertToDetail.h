//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/22 13:01)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_DETAIL_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_DETAIL_H

#include "ColourConvertTo.h"
#include "ColourDetail.h"
#include "ColourTextureFormatTraits.h"
#include "Detail/TexelsToCheckDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"

template <Rendering::TextureFormat Format>
uint16_t Rendering::ColourConvertTo::GetSmall(const FloatColour& colour) noexcept
{
    const auto red = GetRed<Format>(colour);
    const auto green = GetGreen<Format>(colour);
    const auto blue = GetBlue<Format>(colour);

    constexpr auto greenShift = ColourTextureFormatTraits<Format>::sm_BlueBytes;
    constexpr auto redShift = greenShift + ColourTextureFormatTraits<Format>::sm_GreenBytes;

    auto result = blue;
    result |= (green << greenShift);
    result |= (red << redShift);

    if constexpr (std::is_same_v<ColourTextureFormatTraits<Format>::AlphaType, TrueType>)
    {
        const auto alpha = GetAlpha<Format>(colour);
        constexpr auto alphaShift = redShift + ColourTextureFormatTraits<Format>::sm_RedBytes;

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
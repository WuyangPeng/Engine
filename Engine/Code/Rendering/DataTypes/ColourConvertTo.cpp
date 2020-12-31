//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/22 11:14)

#include "Rendering/RenderingExport.h"

#include "ColourConvertToDetail.h"
#include "HalfFloat.h"

#include <array>

using std::array;

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToR5G6B5(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R5G6B5;

    return ConvertToSmall<textureFormat>(inTexels);
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA1R5G5B5(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A1R5G5B5;

    return ConvertToSmall<textureFormat>(inTexels);
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA4R4G4B4(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A4R4G4B4;

    return ConvertToSmall<textureFormat>(inTexels);
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const ByteColour colour{ source };

        const auto alpha = colour.GetAlpha();

        Increase<textureFormat>(target, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToL8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::L8;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const ByteColour colour{ source };

        const auto luminance = colour.GetRed();

        Increase<textureFormat>(target, luminance);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA8L8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8L8;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const ByteColour colour{ source };

        const auto luminance = colour.GetRed();
        const auto alpha = colour.GetAlpha();

        Increase<textureFormat>(target, luminance);
        Increase<textureFormat>(target, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToR8G8B8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R8G8B8;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const ByteColour colour{ source };

        const auto blue = colour.GetBlue();
        const auto green = colour.GetGreen();
        const auto red = colour.GetRed();

        Increase<textureFormat>(target, blue);
        Increase<textureFormat>(target, green);
        Increase<textureFormat>(target, red);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA8R8G8B8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8R8G8B8;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const ByteColour colour{ source };

        const auto blue = colour.GetBlue();
        const auto green = colour.GetGreen();
        const auto red = colour.GetRed();
        const auto alpha = colour.GetAlpha();

        Increase<textureFormat>(target, blue);
        Increase<textureFormat>(target, green);
        Increase<textureFormat>(target, red);
        Increase<textureFormat>(target, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA8B8G8R8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8B8G8R8;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const ByteColour colour{ source };

        const auto red = colour.GetRed();
        const auto green = colour.GetGreen();
        const auto blue = colour.GetBlue();
        const auto alpha = colour.GetAlpha();

        Increase<textureFormat>(target, red);
        Increase<textureFormat>(target, green);
        Increase<textureFormat>(target, blue);
        Increase<textureFormat>(target, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToL16(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::L16;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const auto luminance = GetLuminance<textureFormat>(source);

        Increase<textureFormat>(target, luminance);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToG16R16(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::G16R16;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const auto red = GetRed<textureFormat>(source);
        const auto green = GetGreen<textureFormat>(source);

        Increase<textureFormat>(target, red);
        Increase<textureFormat>(target, green);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA16B16G16R16(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A16B16G16R16;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        const auto red = GetRed<textureFormat>(source);
        const auto green = GetGreen<textureFormat>(source);
        const auto blue = GetBlue<textureFormat>(source);
        const auto alpha = GetAlpha<textureFormat>(source);

        Increase<textureFormat>(target, red);
        Increase<textureFormat>(target, green);
        Increase<textureFormat>(target, blue);
        Increase<textureFormat>(target, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToR16F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R16F;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        IncreaseHalfFloat<textureFormat>(target, source.GetRed());
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToG16R16F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::G16R16F;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        IncreaseHalfFloat<textureFormat>(target, source.GetRed());
        IncreaseHalfFloat<textureFormat>(target, source.GetGreen());
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA16B16G16R16F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A16B16G16R16F;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        IncreaseHalfFloat<textureFormat>(target, source.GetRed());
        IncreaseHalfFloat<textureFormat>(target, source.GetGreen());
        IncreaseHalfFloat<textureFormat>(target, source.GetBlue());
        IncreaseHalfFloat<textureFormat>(target, source.GetAlpha());
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToR32F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R32F;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        Increase<textureFormat>(target, source.GetRed());
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToG32R32F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::G32R32F;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        Increase<textureFormat>(target, source.GetRed());
        Increase<textureFormat>(target, source.GetGreen());
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::OutTexelsType Rendering::ColourConvertTo::ConvertToA32B32G32R32F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A32B32G32R32F;

    TexelsToCheck<textureFormat> texelsCheck{ inTexels.size() };

    OutTexelsType outTexels(texelsCheck.GetOutTexelsLength());
    SpanIterator target{ outTexels.begin(), outTexels.end(), outTexels.begin() };

    for (const auto& source : inTexels)
    {
        Increase<textureFormat>(target, source.GetRed());
        Increase<textureFormat>(target, source.GetGreen());
        Increase<textureFormat>(target, source.GetBlue());
        Increase<textureFormat>(target, source.GetAlpha());
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertTo::ConvertToFunction Rendering::ColourConvertTo::GetConvertToFunction(TextureFormat textureFormat)
{
    using FunctionContainer = array<ConvertToFunction, sm_ConvertToQuantity>;

    static FunctionContainer functionContainer{ nullptr,
                                                &ConvertToR5G6B5,
                                                &ConvertToA1R5G5B5,
                                                &ConvertToA4R4G4B4,
                                                &ConvertToA8,
                                                &ConvertToL8,
                                                &ConvertToA8L8,
                                                &ConvertToR8G8B8,
                                                &ConvertToA8R8G8B8,
                                                &ConvertToA8B8G8R8,
                                                &ConvertToL16,
                                                &ConvertToG16R16,
                                                &ConvertToA16B16G16R16,
                                                &ConvertToR16F,
                                                &ConvertToG16R16F,
                                                &ConvertToA16B16G16R16F,
                                                &ConvertToR32F,
                                                &ConvertToG32R32F,
                                                &ConvertToA32B32G32R32F,
                                                nullptr,
                                                nullptr,
                                                nullptr,
                                                nullptr };

    return functionContainer.at(System::EnumCastUnderlying(textureFormat));
}

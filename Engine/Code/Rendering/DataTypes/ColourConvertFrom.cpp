///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 13:16)

#include "Rendering/RenderingExport.h"

#include "ColourConvertFromDetail.h"
#include "ColourDetail.h"
#include "ColourTextureFormatTraits.h"
#include "Detail/TexelsFromCheckDetail.h"
#include "CoreTools/Base/SpanIteratorDetail.h"

#include <array>

using std::array;

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromR5G6B5(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R5G6B5;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto current = Increase<textureFormat>(source);

        const auto red = GetSmallRed<textureFormat>(current);
        const auto green = GetSmallGreen<textureFormat>(current);
        const auto blue = GetSmallBlue<textureFormat>(current);

        outTexels.emplace_back(red, green, blue, 0.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA1R5G5B5(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A1R5G5B5;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto current = Increase<textureFormat>(source);

        const auto red = GetSmallRed<textureFormat>(current);
        const auto green = GetSmallGreen<textureFormat>(current);
        const auto blue = GetSmallBlue<textureFormat>(current);
        const auto alpha = GetSmallAlpha<textureFormat>(current);

        outTexels.emplace_back(red, green, blue, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA4R4G4B4(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A4R4G4B4;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto current = Increase<textureFormat>(source);

        const auto red = GetSmallRed<textureFormat>(current);
        const auto green = GetSmallGreen<textureFormat>(current);
        const auto blue = GetSmallBlue<textureFormat>(current);
        const auto alpha = GetSmallAlpha<textureFormat>(current);

        outTexels.emplace_back(red, green, blue, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto alpha = Increase<textureFormat>(source);

        const ByteColour colour{ 0, 0, 0, alpha };

        outTexels.emplace_back(colour);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromL8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::L8;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto luminance = Increase<textureFormat>(source);

        const ByteColour colour{ luminance, luminance, luminance, 255 };

        outTexels.emplace_back(colour);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA8L8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8L8;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto luminance = Increase<textureFormat>(source);
        auto alpha = Increase<textureFormat>(source);

        const ByteColour colour{ luminance, luminance, luminance, alpha };

        outTexels.emplace_back(colour);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromR8G8B8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R8G8B8;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto blue = Increase<textureFormat>(source);
        const auto green = Increase<textureFormat>(source);
        const auto red = Increase<textureFormat>(source);

        const ByteColour colour{ red, green, blue, 0 };

        outTexels.emplace_back(colour);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA8R8G8B8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8R8G8B8;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto blue = Increase<textureFormat>(source);
        const auto green = Increase<textureFormat>(source);
        const auto red = Increase<textureFormat>(source);
        const auto alpha = Increase<textureFormat>(source);

        const ByteColour colour{ red, green, blue, alpha };

        outTexels.emplace_back(colour);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA8B8G8R8(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A8B8G8R8;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = Increase<textureFormat>(source);
        const auto green = Increase<textureFormat>(source);
        const auto blue = Increase<textureFormat>(source);
        const auto alpha = Increase<textureFormat>(source);

        const ByteColour colour{ red, green, blue, alpha };

        outTexels.emplace_back(colour);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromL16(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::L16;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        auto current = Increase<textureFormat>(source);

        const auto luminance = Get16BitLuminance<textureFormat>(current);

        outTexels.emplace_back(luminance, luminance, luminance, 1.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromG16R16(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::G16R16;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = Get16BitRed<textureFormat>(Increase<textureFormat>(source));
        const auto green = Get16BitGreen<textureFormat>(Increase<textureFormat>(source));

        outTexels.emplace_back(red, green, 0.0f, 0.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA16B16G16R16(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A16B16G16R16;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = Get16BitRed<textureFormat>(Increase<textureFormat>(source));
        const auto green = Get16BitGreen<textureFormat>(Increase<textureFormat>(source));
        const auto blue = Get16BitBlue<textureFormat>(Increase<textureFormat>(source));
        const auto alpha = Get16BitAlpha<textureFormat>(Increase<textureFormat>(source));

        outTexels.emplace_back(red, green, blue, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromR16F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R16F;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = GetHalfFloat<textureFormat>(source);

        outTexels.emplace_back(red, 0.0f, 0.0f, 0.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromG16R16F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::G16R16F;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = GetHalfFloat<textureFormat>(source);
        const auto green = GetHalfFloat<textureFormat>(source);

        outTexels.emplace_back(red, green, 0.0f, 0.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA16B16G16R16F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A16B16G16R16F;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = GetHalfFloat<textureFormat>(source);
        const auto green = GetHalfFloat<textureFormat>(source);
        const auto blue = GetHalfFloat<textureFormat>(source);
        const auto alpha = GetHalfFloat<textureFormat>(source);

        outTexels.emplace_back(red, green, blue, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromR32F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::R32F;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = source.Increase<float>();

        outTexels.emplace_back(red, 0.0f, 0.0f, 0.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromG32R32F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::G32R32F;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = source.Increase<float>();
        const auto green = source.Increase<float>();

        outTexels.emplace_back(red, green, 0.0f, 0.0f);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::OutTexelsType Rendering::ColourConvertFrom::ConvertFromA32B32G32R32F(const InTexelsType& inTexels)
{
    constexpr auto textureFormat = TextureFormat::A32B32G32R32F;

    TexelsFromCheck<textureFormat> texelsCheck{ inTexels.size() };
    texelsCheck.CheckInTexels();

    OutTexelsType outTexels{};
    SpanConstIterator source{ inTexels.begin(), inTexels.end(), inTexels.begin() };

    const auto outTexelsLength = texelsCheck.GetOutTexelsLength();
    for (auto i = 0u; i < outTexelsLength; ++i)
    {
        const auto red = source.Increase<float>();
        const auto green = source.Increase<float>();
        const auto blue = source.Increase<float>();
        const auto alpha = source.Increase<float>();

        outTexels.emplace_back(red, green, blue, alpha);
    }

    texelsCheck.CheckOutTexels(outTexels.size());

    return outTexels;
}

Rendering::ColourConvertFrom::ConvertFromFunction Rendering::ColourConvertFrom::GetConvertFromFunction(TextureFormat textureFormat)
{
    using FunctionContainer = array<ConvertFromFunction, convertFromQuantity>;

    static FunctionContainer functionContainer{ nullptr,
                                                &ConvertFromR5G6B5,
                                                &ConvertFromA1R5G5B5,
                                                &ConvertFromA4R4G4B4,
                                                &ConvertFromA8,
                                                &ConvertFromL8,
                                                &ConvertFromA8L8,
                                                &ConvertFromR8G8B8,
                                                &ConvertFromA8R8G8B8,
                                                &ConvertFromA8B8G8R8,
                                                &ConvertFromL16,
                                                &ConvertFromG16R16,
                                                &ConvertFromA16B16G16R16,
                                                &ConvertFromR16F,
                                                &ConvertFromG16R16F,
                                                &ConvertFromA16B16G16R16F,
                                                &ConvertFromR32F,
                                                &ConvertFromG32R32F,
                                                &ConvertFromA32B32G32R32F,
                                                nullptr,
                                                nullptr,
                                                nullptr,
                                                nullptr };

    return functionContainer.at(System::EnumCastUnderlying(textureFormat));
}

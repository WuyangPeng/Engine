///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 13:48)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H

#include "Rendering/RenderingDll.h"

#include "Colour.h"
#include "ColourTextureFormatTraits.h"
#include "Flags/TextureFormat.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIterator.h"

#include <gsl/util>
#include <vector>

namespace Rendering
{
    // ��Colour<float>ת��Ϊָ���ĸ�ʽ��
    class RENDERING_DEFAULT_DECLARE ColourConvertTo
    {
    public:
        using ClassType = ColourConvertTo;
        using InTexelsType = std::vector<FloatColour>;
        using OutTexelsType = std::vector<char>;
        using OutTexelsTypeIter = OutTexelsType::iterator;
        using SpanIterator = CoreTools::SpanIterator<OutTexelsTypeIter>;

    public:
        static constexpr auto convertToQuantity = System::EnumCastUnderlying(TextureFormat::Quantity);

        // ��Colour<float>ת����ָ���ĸ�ʽ��

        // outTexels�ĳ���ΪinTexels�ĳ��� * 2��
        NODISCARD static OutTexelsType ConvertToR5G6B5(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 2��
        NODISCARD static OutTexelsType ConvertToA1R5G5B5(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 2��
        NODISCARD static OutTexelsType ConvertToA4R4G4B4(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��ȡ�
        NODISCARD static OutTexelsType ConvertToA8(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��ȡ�
        NODISCARD static OutTexelsType ConvertToL8(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 2��
        NODISCARD static OutTexelsType ConvertToA8L8(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 3��
        NODISCARD static OutTexelsType ConvertToR8G8B8(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 4��
        NODISCARD static OutTexelsType ConvertToA8R8G8B8(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 4��
        NODISCARD static OutTexelsType ConvertToA8B8G8R8(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 2��
        NODISCARD static OutTexelsType ConvertToL16(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 4��
        NODISCARD static OutTexelsType ConvertToG16R16(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 8��
        NODISCARD static OutTexelsType ConvertToA16B16G16R16(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 2��
        NODISCARD static OutTexelsType ConvertToR16F(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 4��
        NODISCARD static OutTexelsType ConvertToG16R16F(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 8��
        NODISCARD static OutTexelsType ConvertToA16B16G16R16F(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 4��
        NODISCARD static OutTexelsType ConvertToR32F(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 8��
        NODISCARD static OutTexelsType ConvertToG32R32F(const InTexelsType& inTexels);

        // outTexels�ĳ���ΪinTexels�ĳ��� * 16��
        NODISCARD static OutTexelsType ConvertToA32B32G32R32F(const InTexelsType& inTexels);

        using ConvertToFunction = OutTexelsType (*)(const InTexelsType&);
        static ConvertToFunction GetConvertToFunction(TextureFormat Format);

    private:
        template <TextureFormat Format>
        NODISCARD static constexpr auto GetRed(const FloatColour& colour) noexcept
        {
            return gsl::narrow_cast<uint16_t>(gsl::narrow_cast<int>(colour.GetRed() * ColourTextureFormatTraits<Format>::redMaxValue + 0.5f));
        }

        template <TextureFormat Format>
        NODISCARD static constexpr auto GetGreen(const FloatColour& colour) noexcept
        {
            return gsl::narrow_cast<uint16_t>(gsl::narrow_cast<int>(colour.GetGreen() * ColourTextureFormatTraits<Format>::greenMaxValue + 0.5f));
        }

        template <TextureFormat Format>
        NODISCARD static constexpr auto GetBlue(const FloatColour& colour) noexcept
        {
            return gsl::narrow_cast<uint16_t>(gsl::narrow_cast<int>(colour.GetBlue() * ColourTextureFormatTraits<Format>::blueMaxValue + 0.5f));
        }

        template <TextureFormat Format>
        NODISCARD static constexpr auto GetAlpha(const FloatColour& colour) noexcept
        {
            return gsl::narrow_cast<uint16_t>(gsl::narrow_cast<int>(colour.GetAlpha() * ColourTextureFormatTraits<Format>::alphaMaxValue + 0.5f));
        }

        template <TextureFormat Format>
        NODISCARD static constexpr auto GetLuminance(const FloatColour& colour) noexcept
        {
            return gsl::narrow_cast<uint16_t>(gsl::narrow_cast<int>(colour.GetRed() * ColourTextureFormatTraits<Format>::luminanceMaxValue + 0.5f));
        }

        template <TextureFormat Format>
        NODISCARD static uint16_t GetSmall(const FloatColour& colour) noexcept;

        template <TextureFormat Format>
        static void Increase(SpanIterator& source, typename ColourTextureFormatTraits<Format>::BytesType value);

        template <TextureFormat Format>
        NODISCARD static OutTexelsType ConvertToSmall(const InTexelsType& inTexels);

        template <TextureFormat Format>
        static void IncreaseHalfFloat(SpanIterator& source, float halfFloat);
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H

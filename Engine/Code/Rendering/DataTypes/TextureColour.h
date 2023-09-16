///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:56)

#ifndef RENDERING_DATA_TYPES_TEXTURE_COLOUR_H
#define RENDERING_DATA_TYPES_TEXTURE_COLOUR_H

#include "ColourTextureFormatTraits.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <array>
#include <type_traits>

// 颜色类会将值截断为[minValue,maxValue]，
// 如果要求颜色类的平均值，先将Clamp值设置为false，然后再进行数值运算，之后将Clamp值重新设置为true。
namespace Rendering
{
    template <TextureFormat Format>
    class TextureColour : private boost::additive<TextureColour<Format>, boost::multipliable<TextureColour<Format>, boost::equality_comparable<TextureColour<Format>>>>
    {
    public:
        using ClassType = TextureColour<Format>;
        using ValueType = typename ColourTextureFormatTraits<Format>::ColourType;
        using Channel = typename ColourTextureFormatTraits<Format>::Channel;
        using MinType = decltype(ColourTextureFormatTraits<Format>::minValue);

        using RedType = typename ColourTextureFormatTraits<Format>::RedType;
        using GreenType = typename ColourTextureFormatTraits<Format>::GreenType;
        using BlueType = typename ColourTextureFormatTraits<Format>::BlueType;
        using AlphaType = typename ColourTextureFormatTraits<Format>::AlphaType;
        using LuminanceType = typename ColourTextureFormatTraits<Format>::LuminanceType;

        static constexpr auto redIndex = System::EnumCastUnderlying(Channel::Red);
        static constexpr auto greenIndex = System::EnumCastUnderlying(Channel::Green);
        static constexpr auto blueIndex = System::EnumCastUnderlying(Channel::Blue);
        static constexpr auto alphaIndex = System::EnumCastUnderlying(Channel::Alpha);
        static constexpr auto luminanceIndex = System::EnumCastUnderlying(Channel::Luminance);

    public:
        constexpr TextureColour() noexcept
            : colour{}, isClamp{ true }
        {
        }

        constexpr TextureColour(ValueType red, ValueType green, ValueType blue, ValueType alpha) noexcept
            : colour{}, isClamp{ true }
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(std::is_same_v<AlphaType, TrueType>, "AlphaType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= redIndex && redIndex < arraySize);
            static_assert(0 <= greenIndex && greenIndex < arraySize);
            static_assert(0 <= blueIndex && blueIndex < arraySize);
            static_assert(0 <= alphaIndex && alphaIndex < arraySize);

            SetColour(red, green, blue, alpha);
        }

        // 如果存在alpha，则设为最大值
        TextureColour(ValueType red, ValueType green, ValueType blue) noexcept
            : colour{}, isClamp{ true }
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= redIndex && redIndex < arraySize);
            static_assert(0 <= greenIndex && greenIndex < arraySize);
            static_assert(0 <= blueIndex && blueIndex < arraySize);

            if constexpr (alphaIndex != -1)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

                colour[alphaIndex] = alphaMaxValue;

#include SYSTEM_WARNING_POP
            }

            SetColour(red, green, blue);
        }

        TextureColour(ValueType value0, ValueType value1) noexcept;

        explicit TextureColour(ValueType value) noexcept;

        // 只有当成员是一致时（alpha成员除外），才允许转换
        template <TextureFormat RhsFormat>
        TextureColour(const TextureColour<RhsFormat>& colour);

        template <TextureFormat RhsFormat>
        TextureColour& operator=(const TextureColour<RhsFormat>& colour);

        CLASS_INVARIANT_DECLARE;

        constexpr void SetColour(ValueType red, ValueType green, ValueType blue, ValueType alpha) noexcept
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(std::is_same_v<AlphaType, TrueType>, "AlphaType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= redIndex && redIndex < arraySize);
            static_assert(0 <= greenIndex && greenIndex < arraySize);
            static_assert(0 <= blueIndex && blueIndex < arraySize);
            static_assert(0 <= alphaIndex && alphaIndex < arraySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

            colour[redIndex] = red;
            colour[greenIndex] = green;
            colour[blueIndex] = blue;
            colour[alphaIndex] = alpha;

#include SYSTEM_WARNING_POP

            Standardization();
        }

        constexpr void SetColour(ValueType red, ValueType green, ValueType blue) noexcept
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= redIndex && redIndex < arraySize);
            static_assert(0 <= greenIndex && greenIndex < arraySize);
            static_assert(0 <= blueIndex && blueIndex < arraySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

            colour[redIndex] = red;
            colour[greenIndex] = green;
            colour[blueIndex] = blue;

#include SYSTEM_WARNING_POP

            Standardization();
        }

        void SetColour(ValueType value1, ValueType value2) noexcept;

        void SetColour(ValueType value) noexcept;

        NODISCARD bool IsClamp() const noexcept;
        void SetClamp(bool newIsClamp) noexcept;

        NODISCARD ValueType GetRed() const noexcept;
        NODISCARD ValueType GetGreen() const noexcept;
        NODISCARD ValueType GetBlue() const noexcept;
        NODISCARD ValueType GetAlpha() const noexcept;
        NODISCARD ValueType GetLuminance() const noexcept;
        NODISCARD const ValueType* GetPoint() const noexcept;
        NODISCARD ValueType operator[](int index) const;

        void SetRed(ValueType red) noexcept;
        void SetGreen(ValueType green) noexcept;
        void SetBlue(ValueType blue) noexcept;
        void SetAlpha(ValueType alpha) noexcept;
        void SetLuminance(ValueType luminance) noexcept;

        TextureColour& operator+=(const TextureColour& rhs) noexcept;
        TextureColour& operator-=(const TextureColour& rhs) noexcept;
        TextureColour& operator*=(const TextureColour& rhs);

        template <typename RhsType>
        TextureColour& operator*=(RhsType rhs);
        template <typename RhsType>
        TextureColour& operator/=(RhsType rhs);

    private:
        static constexpr auto minValue = ColourTextureFormatTraits<Format>::minValue;
        static constexpr auto redMaxValue = ColourTextureFormatTraits<Format>::redMaxValue;
        static constexpr auto greenMaxValue = ColourTextureFormatTraits<Format>::greenMaxValue;
        static constexpr auto blueMaxValue = ColourTextureFormatTraits<Format>::blueMaxValue;
        static constexpr auto alphaMaxValue = ColourTextureFormatTraits<Format>::alphaMaxValue;
        static constexpr auto luminanceMaxValue = ColourTextureFormatTraits<Format>::luminanceMaxValue;

        static constexpr auto isFloatingPoint = ColourTextureFormatTraits<Format>::isFloatingPoint;
        static constexpr auto arraySize = ColourTextureFormatTraits<Format>::arraySize;
        static constexpr auto maxValue = ColourTextureFormatTraits<Format>::maxValue;

        static_assert((redIndex == -1) || (0 <= redIndex && redIndex < arraySize));
        static_assert((greenIndex == -1) || (0 <= greenIndex && greenIndex < arraySize));
        static_assert((blueIndex == -1) || (0 <= blueIndex && blueIndex < arraySize));
        static_assert((alphaIndex == -1) || (0 <= alphaIndex && alphaIndex < arraySize));
        static_assert((luminanceIndex == -1) || (0 <= luminanceIndex && luminanceIndex < arraySize));

    private:
        NODISCARD static constexpr ValueType Clamp(ValueType colour, ValueType max) noexcept
        {
            if (colour < minValue)
                return minValue;
            else if (max < colour)
                return max;
            else
                return colour;
        }

        constexpr void Standardization() noexcept
        {
            Standardization<redIndex>(std::is_same<RedType, TrueType>(), redMaxValue);
            Standardization<greenIndex>(std::is_same<GreenType, TrueType>(), greenMaxValue);
            Standardization<blueIndex>(std::is_same<BlueType, TrueType>(), blueMaxValue);
            Standardization<alphaIndex>(std::is_same<AlphaType, TrueType>(), alphaMaxValue);
            Standardization<luminanceIndex>(std::is_same<LuminanceType, TrueType>(), luminanceMaxValue);
        }

        template <int Index>
        constexpr void Standardization(const std::false_type&, [[maybe_unused]] ValueType maxValue) noexcept
        {
        }

        template <int Index>
        constexpr void Standardization(const std::true_type&, ValueType maxValue) noexcept
        {
            if (isClamp)
            {
                static_assert(0 <= Index && Index < arraySize, "index is crossing!");

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

                colour[Index] = Clamp(colour[Index], maxValue);

#include SYSTEM_WARNING_POP
            }
        }

        template <TextureFormat RhsFormat>
        void ConvertingColourFormat(const TextureColour<RhsFormat>& colour);

        template <TextureFormat RhsFormat, int Index, int RhsIndex, bool HaveBit>
        void Converting(const TextureColour<RhsFormat>& colour,
                        MinType maxValue,
                        typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                        const std::integral_constant<bool, HaveBit>&);

        template <TextureFormat RhsFormat, int Index, int RhsIndex>
        void Converting(MAYBE_UNUSED const TextureColour<RhsFormat>& colour,
                        MAYBE_UNUSED MinType maxValue,
                        MAYBE_UNUSED typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                        const std::false_type&) noexcept;

        template <TextureFormat RhsFormat, bool HaveAlpha, bool RhsHaveAlpha>
        void ConvertingAlpha(MAYBE_UNUSED const TextureColour<RhsFormat>& textureColour,
                             const std::integral_constant<bool, HaveAlpha>&,
                             const std::integral_constant<bool, RhsHaveAlpha>&) noexcept;

        template <TextureFormat RhsFormat>
        void ConvertingAlpha(const TextureColour<RhsFormat>& textureColour, const std::true_type&, const std::true_type&);

        template <TextureFormat RhsFormat>
        void ConvertingAlpha(const TextureColour<RhsFormat>& textureColour, const std::true_type&, const std::false_type&) noexcept;

        template <TextureFormat RhsFormat, int Index, int RhsIndex, bool IsFloatingPoint, bool RhsIsFloatingPoint>
        void ConvertingBit(const TextureColour<RhsFormat>& colour,
                           MinType maxValue,
                           typename TextureColour<RhsFormat>::MinType rhsMinValue,
                           typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                           const std::integral_constant<bool, IsFloatingPoint>&,
                           const std::integral_constant<bool, RhsIsFloatingPoint>&);

        template <TextureFormat RhsFormat, int Index, int RhsIndex>
        void ConvertingBit(const TextureColour<RhsFormat>& colour,
                           MinType maxValue,
                           typename TextureColour<RhsFormat>::MinType rhsMinValue,
                           typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                           const std::false_type&, const std::true_type&);

        template <int Index, bool HaveBit>
        void Multiply(const std::integral_constant<bool, HaveBit>&, MinType maxValue, const TextureColour& textureColour);
        template <int Index>
        void Multiply(const std::false_type&, MAYBE_UNUSED MinType maxValue, MAYBE_UNUSED const TextureColour& textureColour) noexcept;

        template <typename RhsType, bool RhsIsFloatingPoint>
        void Divide(RhsType rhs, const std::integral_constant<bool, RhsIsFloatingPoint>&);

        template <typename RhsType>
        void Divide(RhsType rhs, const std::false_type&);

    private:
        std::array<ValueType, arraySize> colour{};
        bool isClamp{ true };
    };

    template <TextureFormat Format>
    NODISCARD bool Approximate(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs, typename TextureColour<Format>::ValueType epsilon);

    template <TextureFormat Format>
    NODISCARD bool operator==(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs);

    template <TextureFormat LhsFormat, typename RhsType>
    NODISCARD const TextureColour<LhsFormat> operator*(const TextureColour<LhsFormat>& lhs, RhsType rhs);
    template <typename LhsType, TextureFormat RhsFormat>
    NODISCARD const TextureColour<RhsFormat> operator*(LhsType lhs, const TextureColour<RhsFormat>& rhs);
    template <TextureFormat LhsFormat, typename RhsType>
    NODISCARD const TextureColour<LhsFormat> operator/(const TextureColour<LhsFormat>& lhs, RhsType rhs);
}

#endif  // RENDERING_DATA_TYPES_TEXTURE_COLOUR_H

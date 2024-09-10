///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H
#define RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H

#include "TextureColour.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>::TextureColour(ValueType value0, ValueType value1) noexcept
    : colour{}, isClamp{ true }
{
    constexpr auto valid1 = std::is_same_v<RedType, TrueType> &&
                            std::is_same_v<GreenType, TrueType> &&
                            !std::is_same_v<BlueType, TrueType> &&
                            !std::is_same_v<LuminanceType, TrueType> &&
                            !std::is_same_v<AlphaType, TrueType>;

    constexpr auto valid2 = !std::is_same_v<RedType, TrueType> &&
                            !std::is_same_v<GreenType, TrueType> &&
                            !std::is_same_v<BlueType, TrueType> &&
                            std::is_same_v<LuminanceType, TrueType> &&
                            std::is_same_v<AlphaType, TrueType>;

    static_assert(valid1 || valid2, "Format type is error!");

    SetColour(value0, value1);

    RENDERING_SELF_CLASS_IS_VALID_3;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetColour(ValueType value1, ValueType value2) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    colour[0] = value1;
    colour[1] = value2;
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A8L8>::SetColour(ValueType alpha, ValueType luminance) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::G16R16>::SetColour(ValueType green, ValueType red) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::G16R16F>::SetColour(ValueType green, ValueType red) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::G32R32F>::SetColour(ValueType green, ValueType red) noexcept;

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>::TextureColour(ValueType value) noexcept
    : colour{}, isClamp{ true }
{
    static_assert(!std::is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!std::is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");

    SetColour(value);

    RENDERING_SELF_CLASS_IS_VALID_3;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetColour(ValueType value) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    colour[0] = value;
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A8>::SetColour(ValueType alpha) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::L8>::SetColour(ValueType luminance) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::L16>::SetColour(ValueType luminance) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::R16F>::SetColour(ValueType red) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::R32F>::SetColour(ValueType red) noexcept;

template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
Rendering::TextureColour<Format>::TextureColour(const TextureColour<RhsFormat>& colour)
{
    static_assert(std::is_same_v<RedType, typename TextureColour<RhsFormat>::RedType>, "RedType isn't same!");
    static_assert(std::is_same_v<GreenType, typename TextureColour<RhsFormat>::GreenType>, "GreenType isn't same!");
    static_assert(std::is_same_v<BlueType, typename TextureColour<RhsFormat>::BlueType>, "BlueType isn't same!");
    static_assert(std::is_same_v<LuminanceType, typename TextureColour<RhsFormat>::LuminanceType>, "LuminanceType isn't same!");

    ConvertingColourFormat(colour);

    RENDERING_SELF_CLASS_IS_VALID_3;
}

template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator=(const TextureColour<RhsFormat>& colour)
{
    static_assert(std::is_same_v<RedType, typename TextureColour<RhsFormat>::RedType>, "RedType isn't same!");
    static_assert(std::is_same_v<GreenType, typename TextureColour<RhsFormat>::GreenType>, "GreenType isn't same!");
    static_assert(std::is_same_v<BlueType, typename TextureColour<RhsFormat>::BlueType>, "BlueType isn't same!");
    static_assert(std::is_same_v<LuminanceType, typename TextureColour<RhsFormat>::LuminanceType>, "LuminanceType isn't same!");

    RENDERING_CLASS_IS_VALID_3;

    ConvertingColourFormat(colour);

    return *this;
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>::ConvertingColourFormat(const TextureColour<RhsFormat>& colour)
{
    constexpr auto rhsRedMaxValue = ColourTextureFormatTraits<RhsFormat>::redMaxValue;
    constexpr auto rhsGreenMaxValue = ColourTextureFormatTraits<RhsFormat>::greenMaxValue;
    constexpr auto rhsBlueMaxValue = ColourTextureFormatTraits<RhsFormat>::blueMaxValue;
    constexpr auto rhsLuminanceMaxValue = ColourTextureFormatTraits<RhsFormat>::luminanceMaxValue;

    Converting<RhsFormat, redIndex, TextureColour<RhsFormat>::redIndex>(colour, redMaxValue, rhsRedMaxValue, std::is_same<typename ColourTextureFormatTraits<Format>::RedType, TrueType>());
    Converting<RhsFormat, greenIndex, TextureColour<RhsFormat>::greenIndex>(colour, greenMaxValue, rhsGreenMaxValue, std::is_same<typename ColourTextureFormatTraits<Format>::GreenType, TrueType>());
    Converting<RhsFormat, blueIndex, TextureColour<RhsFormat>::blueIndex>(colour, blueMaxValue, rhsBlueMaxValue, std::is_same<typename ColourTextureFormatTraits<Format>::BlueType, TrueType>());
    ConvertingAlpha(colour, std::is_same<AlphaType, TrueType>(), std::is_same<typename TextureColour<RhsFormat>::AlphaType, TrueType>());
    Converting<RhsFormat, luminanceIndex, TextureColour<RhsFormat>::luminanceIndex>(colour, luminanceMaxValue, rhsLuminanceMaxValue, std::is_same<typename ColourTextureFormatTraits<Format>::LuminanceType, TrueType>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex, bool HaveBit>
void Rendering::TextureColour<Format>::Converting(const TextureColour<RhsFormat>& colour, MinType maxValue, typename TextureColour<RhsFormat>::MinType rhsMaxValue, const std::integral_constant<bool, HaveBit>&)
{
    constexpr auto rhsMinValue = ColourTextureFormatTraits<RhsFormat>::minValue;

    ConvertingBit<RhsFormat, Index, RhsIndex>(colour,
                                              maxValue,
                                              rhsMinValue,
                                              rhsMaxValue,
                                              std::integral_constant<bool, isFloatingPoint>(),
                                              std::integral_constant<bool, ColourTextureFormatTraits<RhsFormat>::isFloatingPoint>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex>
void Rendering::TextureColour<Format>::Converting(MAYBE_UNUSED const TextureColour<RhsFormat>& colour, MAYBE_UNUSED MinType maxValue, MAYBE_UNUSED typename TextureColour<RhsFormat>::MinType rhsMaxValue, const std::false_type&) noexcept
{
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, bool HaveAlpha, bool RhsHaveAlpha>
void Rendering::TextureColour<Format>::ConvertingAlpha(MAYBE_UNUSED const TextureColour<RhsFormat>& colour, const std::integral_constant<bool, HaveAlpha>&, const std::integral_constant<bool, RhsHaveAlpha>&) noexcept
{
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>::ConvertingAlpha(const TextureColour<RhsFormat>& colour, const std::true_type&, const std::true_type&)
{
    constexpr auto rhsAlphaMaxValue = ColourTextureFormatTraits<RhsFormat>::alphaMaxValue;

    Converting<RhsFormat, alphaIndex, TextureColour<RhsFormat>::alphaIndex>(colour, alphaMaxValue, rhsAlphaMaxValue, std::is_same<typename ColourTextureFormatTraits<Format>::AlphaType, TrueType>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>::ConvertingAlpha([[maybe_unused]] const TextureColour<RhsFormat>& textureColour, const std::true_type&, const std::false_type&) noexcept
{
    static_assert(0 <= alphaIndex && alphaIndex < arraySize, "index is crossing!");

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    colour[alphaIndex] = alphaMaxValue;

#include SYSTEM_WARNING_POP
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex, bool IsFloatingPoint, bool RhsIsFloatingPoint>
void Rendering::TextureColour<Format>::ConvertingBit(const TextureColour<RhsFormat>& textureColour,
                                                     MinType maxValue,
                                                     typename TextureColour<RhsFormat>::MinType rhsMinValue,
                                                     typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                                                     const std::integral_constant<bool, IsFloatingPoint>&,
                                                     const std::integral_constant<bool, RhsIsFloatingPoint>&)
{
    static_assert(0 <= Index && Index < arraySize, "index is crossing!");
    static_assert(0 <= RhsIndex && RhsIndex < ColourTextureFormatTraits<RhsFormat>::arraySize, "index is crossing!");

    using RhsValueType = typename TextureColour<RhsFormat>::ValueType;

    const auto rhsFormatDistance = rhsMaxValue - rhsMinValue;
    const auto lhsFormatDistance = maxValue - minValue;
    const auto difference = textureColour[RhsIndex] - rhsMinValue;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
#include SYSTEM_WARNING_DISABLE(26467)

    colour[Index] = boost::numeric_cast<ValueType>(difference * lhsFormatDistance / rhsFormatDistance) + minValue;

#include SYSTEM_WARNING_POP
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex>
void Rendering::TextureColour<Format>::ConvertingBit(const TextureColour<RhsFormat>& textureColour,
                                                     MinType maxValue,
                                                     typename TextureColour<RhsFormat>::MinType rhsMinValue,
                                                     typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                                                     const std::false_type&,
                                                     const std::true_type&)
{
    static_assert(0 <= Index && Index < arraySize, "index is crossing!");
    static_assert(0 <= RhsIndex && RhsIndex < ColourTextureFormatTraits<RhsFormat>::arraySize, "index is crossing!");

    using RhsValueType = typename TextureColour<RhsFormat>::ValueType;

    const auto rhsFormatDistance = rhsMaxValue - rhsMinValue;
    const auto lhsFormatDistance = maxValue - minValue;
    const auto difference = textureColour[RhsIndex] - rhsMinValue;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
#include SYSTEM_WARNING_DISABLE(26467)

    colour[Index] = boost::numeric_cast<ValueType>(difference * lhsFormatDistance / rhsFormatDistance + 0.5f) + minValue;

#include SYSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT

template <Rendering::TextureFormat Format>
bool Rendering::TextureColour<Format>::IsValid() const noexcept
{
    if (!isClamp)
    {
        return true;
    }

    try
    {
        auto iter = maxValue.cbegin();
        for (auto value : colour)
        {
            if (iter == maxValue.cend())
            {
                return false;
            }

            if (value < minValue || *iter < value)
            {
                return false;
            }

            ++iter;
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <Rendering::TextureFormat Format>
bool Rendering::TextureColour<Format>::IsClamp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_3;

    return isClamp;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetClamp(bool newIsClamp) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    if (isClamp == false && newIsClamp == true)
    {
        isClamp = true;
        Standardization();
    }

    isClamp = newIsClamp;
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetRed() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::RedType, TrueType>, "RedType is TrueType!");
    static_assert(0 <= redIndex && redIndex < arraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    return colour[redIndex];

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetGreen() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(0 <= greenIndex && greenIndex < arraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    return colour[greenIndex];

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetBlue() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::BlueType, TrueType>, "BlueType is TrueType!");
    static_assert(0 <= blueIndex && blueIndex < arraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    return colour[blueIndex];

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetAlpha() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::AlphaType, TrueType>, "AlphaType is TrueType!");
    static_assert(0 <= alphaIndex && alphaIndex < arraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    return colour[alphaIndex];

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetLuminance() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::LuminanceType, Rendering::TrueType>, "LuminanceType is TrueType!");
    static_assert(0 <= luminanceIndex && luminanceIndex < arraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    return colour[luminanceIndex];

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::ValueType* Rendering::TextureColour<Format>::GetPoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_3;

    return colour.data();
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::operator[](int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_3;

    return colour.at(index);
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetRed(ValueType red) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::RedType, TrueType>, "RedType is TrueType!");
    static_assert(0 <= redIndex && redIndex < arraySize);

    RENDERING_CLASS_IS_VALID_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    colour[redIndex] = red;

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetGreen(ValueType green) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(0 <= greenIndex && greenIndex < arraySize);

    RENDERING_CLASS_IS_VALID_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    colour[greenIndex] = green;

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetBlue(ValueType blue) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::BlueType, TrueType>, "BlueType is TrueType!");
    static_assert(0 <= blueIndex && blueIndex < arraySize);

    RENDERING_CLASS_IS_VALID_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    colour[blueIndex] = blue;

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetAlpha(ValueType alpha) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::AlphaType, TrueType>, "AlphaType is TrueType!");
    static_assert(0 <= alphaIndex && alphaIndex < arraySize);

    RENDERING_CLASS_IS_VALID_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    colour[alphaIndex] = alpha;

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetLuminance(ValueType luminance) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::LuminanceType, TrueType>, "LuminanceType is TrueType!");
    static_assert(0 <= luminanceIndex && luminanceIndex < arraySize);

    RENDERING_CLASS_IS_VALID_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    colour[luminanceIndex] = luminance;

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator+=(const TextureColour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    auto rhsIter = rhs.colour.cbegin();
    for (auto& value : colour)
    {
        if (rhsIter != rhs.colour.cend())
        {
            value += *rhsIter;
        }

        ++rhsIter;
    }

    Standardization();

    return *this;
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator-=(const TextureColour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    auto rhsIter = rhs.colour.cbegin();
    for (auto& value : colour)
    {
        if (rhsIter != rhs.colour.cend())
        {
            value -= *rhsIter;
        }

        ++rhsIter;
    }

    Standardization();

    return *this;
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator*=(const TextureColour& rhs)
{
    RENDERING_CLASS_IS_VALID_3;

    Multiply<redIndex>(std::is_same<RedType, TrueType>(), redMaxValue, rhs);
    Multiply<greenIndex>(std::is_same<GreenType, TrueType>(), greenMaxValue, rhs);
    Multiply<blueIndex>(std::is_same<BlueType, TrueType>(), blueMaxValue, rhs);
    Multiply<alphaIndex>(std::is_same<AlphaType, TrueType>(), alphaMaxValue, rhs);
    Multiply<luminanceIndex>(std::is_same<LuminanceType, TrueType>(), luminanceMaxValue, rhs);

    Standardization();

    return *this;
}

template <Rendering::TextureFormat Format>
template <int Index, bool HaveBit>
void Rendering::TextureColour<Format>::Multiply(const std::integral_constant<bool, HaveBit>&, MinType maxValue, const TextureColour& textureColour)
{
    static_assert(0 <= Index && Index < arraySize, "index is crossing!");

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
#include SYSTEM_WARNING_DISABLE(26467)

    colour[Index] = boost::numeric_cast<ValueType>(textureColour[Index] * textureColour[Index] / maxValue);

#include SYSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
template <int Index>
void Rendering::TextureColour<Format>::Multiply(const std::false_type&, MAYBE_UNUSED MinType maxValue, MAYBE_UNUSED const TextureColour& textureColour) noexcept
{
}

template <Rendering::TextureFormat Format>
template <typename RhsType>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator*=(RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType is arithmetic!");

    RENDERING_CLASS_IS_VALID_3;

    for (auto& value : colour)
    {
        auto multiply = value * rhs;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26467)

        value = boost::numeric_cast<ValueType>(multiply);

#include SYSTEM_WARNING_POP
    }

    Standardization();

    return *this;
}

template <Rendering::TextureFormat Format>
template <typename RhsType>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator/=(RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType is arithmetic!");

    RENDERING_CLASS_IS_VALID_3;

    Divide(rhs, std::is_floating_point<RhsType>());

    return *this;
}

// private
template <Rendering::TextureFormat Format>
template <typename RhsType, bool RhsIsFloatingPoint>
void Rendering::TextureColour<Format>::Divide(RhsType rhs, const std::integral_constant<bool, RhsIsFloatingPoint>&)
{
    if (Mathematics::Math<RhsType>::FAbs(rhs) <= Mathematics::Math<RhsType>::GetZeroTolerance())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    for (auto& value : colour)
    {
        auto divide = value / rhs;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26467)

        value = boost::numeric_cast<ValueType>(divide);

#include SYSTEM_WARNING_POP
    }

    Standardization();
}

// private
template <Rendering::TextureFormat Format>
template <typename RhsType>
void Rendering::TextureColour<Format>::Divide(RhsType rhs, const std::false_type&)
{
    if (rhs == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    for (auto& value : colour)
    {
        auto divide = value / rhs;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26467)

        value = boost::numeric_cast<ValueType>(divide);

#include SYSTEM_WARNING_POP
    }

    Standardization();
}

template <Rendering::TextureFormat Format>
bool Rendering::Approximate(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs, typename TextureColour<Format>::ValueType epsilon)
{
    static_assert(ColourTextureFormatTraits<Format>::isFloatingPoint, "Format is Floating Point!");

    using ValueType = typename TextureColour<Format>::ValueType;

    for (auto i = 0; i < ColourTextureFormatTraits<Format>::arraySize; ++i)
    {
        if (epsilon < Mathematics::Math<ValueType>::FAbs(lhs[i] - rhs[i]))
        {
            return false;
        }
    }

    return true;
}

template <Rendering::TextureFormat Format>
bool Rendering::operator==(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs)
{
    static_assert(!ColourTextureFormatTraits<Format>::isFloatingPoint, "Format isn't Floating Point!");

    for (auto i = 0; i < ColourTextureFormatTraits<Format>::arraySize; ++i)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }

    return true;
}

template <Rendering::TextureFormat LhsFormat, typename RhsType>
const Rendering::TextureColour<LhsFormat> Rendering::operator*(const TextureColour<LhsFormat>& lhs, RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType is arithmetic!");

    return TextureColour<LhsFormat>(lhs) *= rhs;
}

template <typename LhsType, Rendering::TextureFormat RhsFormat>
const Rendering::TextureColour<RhsFormat> Rendering::operator*(LhsType lhs, const TextureColour<RhsFormat>& rhs)
{
    static_assert(std::is_arithmetic_v<LhsType>, "LhsType is arithmetic!");

    return TextureColour<RhsFormat>(rhs) *= lhs;
}

template <Rendering::TextureFormat LhsFormat, typename RhsType>
const Rendering::TextureColour<LhsFormat> Rendering::operator/(const TextureColour<LhsFormat>& lhs, RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType is arithmetic!");

    return TextureColour<LhsFormat>(lhs) /= rhs;
}

#endif  // RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H
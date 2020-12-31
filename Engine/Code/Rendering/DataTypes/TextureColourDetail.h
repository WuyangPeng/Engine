//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/25 13:10)

#ifndef RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H
#define RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H

#include "TextureColour.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>::TextureColour(ValueType value1, ValueType value2) noexcept
    : m_Colour{}, m_IsClamp{ true }
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

    SetColour(value1, value2);

    RENDERING_SELF_CLASS_IS_VALID_3;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetColour(ValueType value1, ValueType value2) noexcept
{
    static_assert(false, "TextureFormat is error!");

    RENDERING_CLASS_IS_VALID_3;

    m_Colour[0] = value1;
    m_Colour[1] = value2;
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
    : m_Colour{}, m_IsClamp{ true }
{
    static_assert(!std::is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!std::is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");

    SetColour(value);

    RENDERING_SELF_CLASS_IS_VALID_3;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetColour(ValueType value) noexcept
{
    static_assert(false, "TextureFormat is error!");

    RENDERING_CLASS_IS_VALID_3;

    m_Colour[0] = value;
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
    static_assert(std::is_same_v<RedType, TextureColour<RhsFormat>::RedType>, "RedType isn't same!");
    static_assert(std::is_same_v<GreenType, TextureColour<RhsFormat>::GreenType>, "GreenType isn't same!");
    static_assert(std::is_same_v<BlueType, TextureColour<RhsFormat>::BlueType>, "BlueType isn't same!");
    static_assert(std::is_same_v<LuminanceType, TextureColour<RhsFormat>::LuminanceType>, "LuminanceType isn't same!");

    ConvertingColourFormat(colour);

    RENDERING_SELF_CLASS_IS_VALID_3;
}

template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator=(const TextureColour<RhsFormat>& colour)
{
    static_assert(std::is_same_v<RedType, TextureColour<RhsFormat>::RedType>, "RedType isn't same!");
    static_assert(std::is_same_v<GreenType, TextureColour<RhsFormat>::GreenType>, "GreenType isn't same!");
    static_assert(std::is_same_v<BlueType, TextureColour<RhsFormat>::BlueType>, "BlueType isn't same!");
    static_assert(std::is_same_v<LuminanceType, TextureColour<RhsFormat>::LuminanceType>, "LuminanceType isn't same!");

    RENDERING_CLASS_IS_VALID_3;

    ConvertingColourFormat(colour);

    return *this;
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>::ConvertingColourFormat(const TextureColour<RhsFormat>& colour)
{
    constexpr auto rhsRedMaxValue = ColourTextureFormatTraits<RhsFormat>::sm_RedMaxValue;
    constexpr auto rhsGreenMaxValue = ColourTextureFormatTraits<RhsFormat>::sm_GreenMaxValue;
    constexpr auto rhsBlueMaxValue = ColourTextureFormatTraits<RhsFormat>::sm_BlueMaxValue;
    constexpr auto rhsLuminanceMaxValue = ColourTextureFormatTraits<RhsFormat>::sm_LuminanceMaxValue;

    Converting<RhsFormat, sm_Red, TextureColour<RhsFormat>::sm_Red>(colour, sm_RedMaxValue, rhsRedMaxValue, std::is_same<ColourTextureFormatTraits<Format>::RedType, TrueType>());
    Converting<RhsFormat, sm_Green, TextureColour<RhsFormat>::sm_Green>(colour, sm_GreenMaxValue, rhsGreenMaxValue, std::is_same<ColourTextureFormatTraits<Format>::GreenType, TrueType>());
    Converting<RhsFormat, sm_Blue, TextureColour<RhsFormat>::sm_Blue>(colour, sm_BlueMaxValue, rhsBlueMaxValue, std::is_same<ColourTextureFormatTraits<Format>::BlueType, TrueType>());
    ConvertingAlpha(colour, std::is_same<AlphaType, TrueType>(), std::is_same<TextureColour<RhsFormat>::AlphaType, TrueType>());
    Converting<RhsFormat, sm_Luminance, TextureColour<RhsFormat>::sm_Luminance>(colour, sm_LuminanceMaxValue, rhsLuminanceMaxValue, std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, TrueType>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex, bool HaveBit>
void Rendering::TextureColour<Format>::Converting(const TextureColour<RhsFormat>& colour, MinType maxValue, typename TextureColour<RhsFormat>::MinType rhsMaxValue, const std::integral_constant<bool, HaveBit>&)
{
    constexpr auto rhsMinValue = ColourTextureFormatTraits<RhsFormat>::sm_MinValue;

    ConvertingBit<RhsFormat, Index, RhsIndex>(colour, maxValue, rhsMinValue, rhsMaxValue, std::integral_constant<bool, sm_IsFloatingPoint>(),
                                              std::integral_constant<bool, ColourTextureFormatTraits<RhsFormat>::sm_IsFloatingPoint>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex>
void Rendering::TextureColour<Format>::Converting([[maybe_unused]] const TextureColour<RhsFormat>& colour, [[maybe_unused]] MinType maxValue, [[maybe_unused]] typename TextureColour<RhsFormat>::MinType rhsMaxValue, const std::false_type&) noexcept
{
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, bool HaveAlpha, bool RhsHaveAlpha>
void Rendering::TextureColour<Format>::ConvertingAlpha([[maybe_unused]] const TextureColour<RhsFormat>& colour, const std::integral_constant<bool, HaveAlpha>&, const std::integral_constant<bool, RhsHaveAlpha>&) noexcept
{
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>::ConvertingAlpha(const TextureColour<RhsFormat>& colour, const std::true_type&, const std::true_type&)
{
    constexpr auto rhsAlphaMaxValue = ColourTextureFormatTraits<RhsFormat>::sm_AlphaMaxValue;

    Converting<RhsFormat, sm_Alpha, TextureColour<RhsFormat>::sm_Alpha>(colour, sm_AlphaMaxValue, rhsAlphaMaxValue, std::is_same<ColourTextureFormatTraits<Format>::AlphaType, TrueType>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>::ConvertingAlpha([[maybe_unused]] const TextureColour<RhsFormat>& colour, const std::true_type&, const std::false_type&) noexcept
{
    static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize, "index is crossing!");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Alpha] = sm_AlphaMaxValue;
#include STSTEM_WARNING_POP
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex, bool IsFloatingPoint, bool RhsIsFloatingPoint>
void Rendering::TextureColour<Format>::ConvertingBit(const TextureColour<RhsFormat>& colour, MinType maxValue, typename TextureColour<RhsFormat>::MinType rhsMinValue,
                                                     typename TextureColour<RhsFormat>::MinType rhsMaxValue, const std::integral_constant<bool, IsFloatingPoint>&,
                                                     const std::integral_constant<bool, RhsIsFloatingPoint>&)
{
    static_assert(0 <= Index && Index < sm_ArraySize, "index is crossing!");
    static_assert(0 <= RhsIndex && RhsIndex < ColourTextureFormatTraits<RhsFormat>::sm_ArraySize, "index is crossing!");

    using RhsValueType = typename TextureColour<RhsFormat>::ValueType;

    const auto rhsFormatDistance = rhsMaxValue - rhsMinValue;
    const auto lhsFormatDistance = maxValue - sm_MinValue;
    const auto difference = colour[RhsIndex] - rhsMinValue;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[Index] = boost::numeric_cast<ValueType>(difference * lhsFormatDistance / rhsFormatDistance) + sm_MinValue;
#include STSTEM_WARNING_POP
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat, int Index, int RhsIndex>
void Rendering::TextureColour<Format>::ConvertingBit(const TextureColour<RhsFormat>& colour, MinType maxValue, typename TextureColour<RhsFormat>::MinType rhsMinValue,
                                                     typename TextureColour<RhsFormat>::MinType rhsMaxValue, const std::false_type&, const std::true_type&)
{
    static_assert(0 <= Index && Index < sm_ArraySize, "index is crossing!");
    static_assert(0 <= RhsIndex && RhsIndex < ColourTextureFormatTraits<RhsFormat>::sm_ArraySize, "index is crossing!");

    using RhsValueType = typename TextureColour<RhsFormat>::ValueType;

    const auto rhsFormatDistance = rhsMaxValue - rhsMinValue;
    const auto lhsFormatDistance = maxValue - sm_MinValue;
    const auto difference = colour[RhsIndex] - rhsMinValue;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[Index] = boost::numeric_cast<ValueType>(difference * lhsFormatDistance / rhsFormatDistance + 0.5f) + sm_MinValue;
#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::TextureFormat Format>
bool Rendering::TextureColour<Format>::IsValid() const noexcept
{
    if (!m_IsClamp)
    {
        return true;
    }

    try
    {
        auto iter = sm_MaxValue.cbegin();
        for (auto value : m_Colour)
        {
            if (iter == sm_MaxValue.cend())
            {
                return false;
            }

            if (value < sm_MinValue || *iter < value)
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

    return m_IsClamp;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetClamp(bool isClamp) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    if (m_IsClamp == false && isClamp == true)
    {
        m_IsClamp = true;
        Standardization();
    }

    m_IsClamp = isClamp;
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetRed() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::RedType, TrueType>, "RedType is TrueType!");
    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    return m_Colour[sm_Red];
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetGreen() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    return m_Colour[sm_Green];
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetBlue() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::BlueType, TrueType>, "BlueType is TrueType!");
    static_assert(0 <= sm_Blue && sm_Blue < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    return m_Colour[sm_Blue];
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetAlpha() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::AlphaType, TrueType>, "AlphaType is TrueType!");
    static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    return m_Colour[sm_Alpha];
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::GetLuminance() const noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::LuminanceType, Rendering::TrueType>, "LuminanceType is TrueType!");
    static_assert(0 <= sm_Luminance && sm_Luminance < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_CONST_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    return m_Colour[sm_Luminance];
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::ValueType* Rendering::TextureColour<Format>::GetPoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_3;

    return m_Colour.data();
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::ValueType Rendering::TextureColour<Format>::operator[](int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_3;

    return m_Colour.at(index);
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetRed(ValueType red) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::RedType, TrueType>, "RedType is TrueType!");
    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Red] = red;
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetGreen(ValueType green) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Green] = green;
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetBlue(ValueType blue) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::BlueType, TrueType>, "BlueType is TrueType!");
    static_assert(0 <= sm_Blue && sm_Blue < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Blue] = blue;
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetAlpha(ValueType alpha) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::AlphaType, TrueType>, "AlphaType is TrueType!");
    static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Alpha] = alpha;
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>::SetLuminance(ValueType luminance) noexcept
{
    static_assert(std::is_same_v<TextureColour<Format>::LuminanceType, TrueType>, "LuminanceType is TrueType!");
    static_assert(0 <= sm_Luminance && sm_Luminance < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Luminance] = luminance;
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator+=(const TextureColour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_3;

    auto rhsIter = rhs.m_Colour.cbegin();
    for (auto& value : m_Colour)
    {
        if (rhsIter != rhs.m_Colour.cend())
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

    auto rhsIter = rhs.m_Colour.cbegin();
    for (auto& value : m_Colour)
    {
        if (rhsIter != rhs.m_Colour.cend())
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

    Multiply<sm_Red>(std::is_same<RedType, TrueType>(), sm_RedMaxValue, rhs);
    Multiply<sm_Green>(std::is_same<GreenType, TrueType>(), sm_GreenMaxValue, rhs);
    Multiply<sm_Blue>(std::is_same<BlueType, TrueType>(), sm_BlueMaxValue, rhs);
    Multiply<sm_Alpha>(std::is_same<AlphaType, TrueType>(), sm_AlphaMaxValue, rhs);
    Multiply<sm_Luminance>(std::is_same<LuminanceType, TrueType>(), sm_LuminanceMaxValue, rhs);

    Standardization();

    return *this;
}

template <Rendering::TextureFormat Format>
template <int Index, bool HaveBit>
void Rendering::TextureColour<Format>::Multiply(const std::integral_constant<bool, HaveBit>&, MinType maxValue, const TextureColour& colour)
{
    static_assert(0 <= Index && Index < sm_ArraySize, "index is crossing!");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[Index] = boost::numeric_cast<ValueType>(m_Colour[Index] * colour[Index] / maxValue);
#include STSTEM_WARNING_POP
}

template <Rendering::TextureFormat Format>
template <int Index>
void Rendering::TextureColour<Format>::Multiply(const std::false_type&, [[maybe_unused]] MinType maxValue, [[maybe_unused]] const TextureColour& colour) noexcept
{
}

template <Rendering::TextureFormat Format>
template <typename RhsType>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>::operator*=(RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType is arithmetic!");

    RENDERING_CLASS_IS_VALID_3;

    for (auto& value : m_Colour)
    {
        auto multiply = value * rhs;
        value = boost::numeric_cast<ValueType>(multiply);
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

    for (auto& value : m_Colour)
    {
        auto divide = value / rhs;
        value = boost::numeric_cast<ValueType>(divide);
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

    for (auto& value : m_Colour)
    {
        auto divide = value / rhs;
        value = boost::numeric_cast<ValueType>(divide);
    }

    Standardization();
}

template <Rendering::TextureFormat Format>
bool Rendering ::Approximate(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs, typename TextureColour<Format>::ValueType epsilon)
{
    static_assert(ColourTextureFormatTraits<Format>::sm_IsFloatingPoint, "Format is Floating Point!");

    using ValueType = typename TextureColour<Format>::ValueType;

    for (auto i = 0; i < ColourTextureFormatTraits<Format>::sm_ArraySize; ++i)
    {
        if (epsilon < Mathematics::Math<ValueType>::FAbs(lhs[i] - rhs[i]))
        {
            return false;
        }
    }

    return true;
}

template <Rendering::TextureFormat Format>
bool Rendering ::operator==(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs)
{
    static_assert(!ColourTextureFormatTraits<Format>::sm_IsFloatingPoint, "Format isn't Floating Point!");

    for (auto i = 0; i < ColourTextureFormatTraits<Format>::sm_ArraySize; ++i)
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
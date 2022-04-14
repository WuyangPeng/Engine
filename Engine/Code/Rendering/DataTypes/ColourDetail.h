///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 14:45)

#ifndef RENDERING_DATA_TYPES_COLOUR_DETAIL_H
#define RENDERING_DATA_TYPES_COLOUR_DETAIL_H

#include "Colour.h"

#if !defined(RENDERING_EXPORT_TEMPLATE) || defined(RENDERING_INCLUDED_COLOUR_ACHIEVE)

    #include "ColourAchieve.h"

#endif  // !defined(RENDERING_EXPORT_TEMPLATE) || defined(RENDERING_INCLUDED_COLOUR_ACHIEVE)

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <iostream>

template <typename T>
template <typename RhsType>
Rendering::Colour<T>::Colour(const Colour<RhsType>& colour)
    : red{}, green{}, blue{}, alpha{}, isClamp{ colour.IsClamp() }
{
    try
    {
        ConvertingColourFormat(colour, std::is_floating_point<T>(), std::is_floating_point<RhsType>());
    }
    catch (const boost::bad_numeric_cast& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Debug, Rendering)
            << error
            << LOG_SINGLETON_TRIGGER_ASSERT;

        THROW_EXCEPTION(SYSTEM_TEXT("颜色数据转换失败。"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>::operator=(const Colour<RhsType>& colour)
{
    RENDERING_CLASS_IS_VALID_1;

    isClamp = colour.IsClamp();

    try
    {
        ConvertingColourFormat(colour, std::is_floating_point<T>(), std::is_floating_point<RhsType>());
    }
    catch (const boost::bad_numeric_cast& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Debug, Rendering)
            << error
            << LOG_SINGLETON_TRIGGER_ASSERT;

        THROW_EXCEPTION(SYSTEM_TEXT("颜色数据转换失败。"s));
    }

    return *this;
}

// private
template <typename T>
template <typename RhsType, bool TIsFloatingPoint, bool RhsIsFloatingPoint>
void Rendering::Colour<T>::ConvertingColourFormat(const Colour<RhsType>& colour,
                                                  const std::integral_constant<bool, TIsFloatingPoint>&,
                                                  const std::integral_constant<bool, RhsIsFloatingPoint>&)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26467)

    InitColour(boost::numeric_cast<T>(colour.GetRed()),
               boost::numeric_cast<T>(colour.GetGreen()),
               boost::numeric_cast<T>(colour.GetBlue()),
               boost::numeric_cast<T>(colour.GetAlpha()));

#include STSTEM_WARNING_POP
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>::ConvertingColourFormat(const Colour<RhsType>& colour, const std::true_type&, const std::false_type&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating point!");
    static_assert(std::is_integral_v<RhsType>, "RhsType isn't integral!");

    const auto redFloatingPoint = ConvertingIntegralToFloatingPoint(colour.GetRed());
    const auto greenFloatingPoint = ConvertingIntegralToFloatingPoint(colour.GetGreen());
    const auto blueFloatingPoint = ConvertingIntegralToFloatingPoint(colour.GetBlue());
    const auto alphaFloatingPoint = ConvertingIntegralToFloatingPoint(colour.GetAlpha());

    InitColour(redFloatingPoint, greenFloatingPoint, blueFloatingPoint, alphaFloatingPoint);
}

// static
// private
template <typename T>
template <typename RhsType>
T Rendering::Colour<T>::ConvertingIntegralToFloatingPoint(RhsType rhs)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating point!");
    static_assert(std::is_integral_v<RhsType>, "RhsType isn't integral!");

    constexpr auto rhsTypeDistance = ColourDefaultTraits<RhsType>::maxValue - ColourDefaultTraits<RhsType>::minValue;
    constexpr auto lhsTypeDistance = maxValue - minValue;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26467)

    return (boost::numeric_cast<T>(rhs) - ColourDefaultTraits<RhsType>::minValue) * lhsTypeDistance / rhsTypeDistance + minValue;

#include STSTEM_WARNING_POP
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>::ConvertingColourFormat(const Colour<RhsType>& colour, const std::false_type&, const std::true_type&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral!");
    static_assert(std::is_floating_point_v<RhsType>, "RhsType isn't floating point!");

    const auto redFloatingPoint = ConvertingFloatingPointToIntegral(colour.GetRed());
    const auto greenFloatingPoint = ConvertingFloatingPointToIntegral(colour.GetGreen());
    const auto blueFloatingPoint = ConvertingFloatingPointToIntegral(colour.GetBlue());
    const auto alphaFloatingPoint = ConvertingFloatingPointToIntegral(colour.GetAlpha());

    InitColour(redFloatingPoint, greenFloatingPoint, blueFloatingPoint, alphaFloatingPoint);
}

// static
// private
template <typename T>
template <typename RhsType>
T Rendering::Colour<T>::ConvertingFloatingPointToIntegral(RhsType rhs)
{
    static_assert(std::is_integral_v<T>, "T isn't integral!");
    static_assert(std::is_floating_point_v<RhsType>, "RhsType isn't floating point!");

    constexpr auto rhsTypeDistance = ColourDefaultTraits<RhsType>::maxValue - ColourDefaultTraits<RhsType>::minValue;
    constexpr auto lhsTypeDistance = maxValue - minValue;

    return boost::numeric_cast<T>((rhs - ColourDefaultTraits<RhsType>::minValue) * lhsTypeDistance / rhsTypeDistance + minValue + static_cast<RhsType>(0.5f));
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>::operator*=(RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType isn't arithmetic!");

    RENDERING_CLASS_IS_VALID_1;

    red *= boost::numeric_cast<T>(rhs);
    green *= boost::numeric_cast<T>(rhs);
    blue *= boost::numeric_cast<T>(rhs);
    alpha *= boost::numeric_cast<T>(rhs);

    Standardization();

    return *this;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>::operator/=(RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType isn't arithmetic!");

    RENDERING_CLASS_IS_VALID_1;

    Divide(rhs, std::is_floating_point<RhsType>());

    return *this;
}

// private
template <typename T>
template <typename RhsType, bool RhsIsFloatingPoint>
void Rendering::Colour<T>::Divide(RhsType rhs, const std::integral_constant<bool, RhsIsFloatingPoint>&)
{
    if (Mathematics::Math<RhsType>::FAbs(rhs) <= Mathematics::Math<RhsType>::GetZeroTolerance())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    red /= boost::numeric_cast<T>(rhs);
    green /= boost::numeric_cast<T>(rhs);
    blue /= boost::numeric_cast<T>(rhs);
    alpha /= boost::numeric_cast<T>(rhs);

    Standardization();
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>::Divide(RhsType rhs, const std::false_type&)
{
    if (rhs == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    red /= boost::numeric_cast<T>(rhs);
    green /= boost::numeric_cast<T>(rhs);
    blue /= boost::numeric_cast<T>(rhs);
    alpha /= boost::numeric_cast<T>(rhs);

    Standardization();
}

template <typename T>
bool Rendering::Approximate(const Colour<T>& lhs, const Colour<T>& rhs, T epsilon) noexcept
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating point!");

    return Mathematics::Math<T>::FAbs(lhs.GetRed() - rhs.GetRed()) <= epsilon &&
           Mathematics::Math<T>::FAbs(lhs.GetGreen() - rhs.GetGreen()) <= epsilon &&
           Mathematics::Math<T>::FAbs(lhs.GetBlue() - rhs.GetBlue()) <= epsilon &&
           Mathematics::Math<T>::FAbs(lhs.GetAlpha() - rhs.GetAlpha()) <= epsilon;
}

template <typename T>
bool Rendering::operator==(const Rendering::Colour<T>& lhs, const Rendering::Colour<T>& rhs) noexcept
{
    if constexpr (std::is_integral_v<T>)
    {
        return lhs.GetRed() == rhs.GetRed() &&
               lhs.GetGreen() == rhs.GetGreen() &&
               lhs.GetBlue() == rhs.GetBlue() &&
               lhs.GetAlpha() == rhs.GetAlpha();
    }
    else
    {
        return Approximate(lhs, rhs, Mathematics::Math<T>::GetZeroTolerance());
    }
}

template <typename LhsType, typename RhsType>
const Rendering::Colour<LhsType> Rendering::operator*(const Colour<LhsType>& lhs, RhsType rhs)
{
    static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

    return Colour<LhsType>(lhs) *= rhs;
}

template <typename LhsType, typename RhsType>
const Rendering::Colour<RhsType> Rendering::operator*(LhsType lhs, const Colour<RhsType>& rhs)
{
    static_assert(std::is_arithmetic<LhsType>::value, "LhsType isn't arithmetic!");

    return Colour<RhsType>(rhs) *= lhs;
}

template <typename LhsType, typename RhsType>
const Rendering::Colour<LhsType> Rendering::operator/(const Colour<LhsType>& lhs, RhsType rhs)
{
    static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

    return Colour<LhsType>(lhs) /= rhs;
}

template <typename T>
std::ostream& Rendering::operator<<(std::ostream& os, const Colour<T>& colour)
{
    static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

    os << "red = " << colour.GetRed() << " green = " << colour.GetGreen() << " blue = " << colour.GetBlue() << " alpha = " << colour.GetAlpha();

    return os;
}

#endif  // RENDERING_DATA_TYPES_COLOUR_DETAIL_H
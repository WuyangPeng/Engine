//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 23:09)

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
    : m_Red{}, m_Green{}, m_Blue{}, m_Alpha{}, m_IsClamp{ colour.IsClamp() }
{
    try
    {
        ConvertingColourFormat(colour, std::is_floating_point<T>(), std::is_floating_point<RhsType>());
    }
    catch (const boost::bad_numeric_cast& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Debug, Rendering)
            << error
            << CoreTools::LogAppenderIOManageSign::TriggerAssert;

        THROW_EXCEPTION(SYSTEM_TEXT("颜色数据转换失败。"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>::operator=(const Colour<RhsType>& colour)
{
    RENDERING_CLASS_IS_VALID_1;

    m_IsClamp = colour.IsClamp();

    try
    {
        ConvertingColourFormat(colour, std::is_floating_point<T>(), std::is_floating_point<RhsType>());
    }
    catch (const boost::bad_numeric_cast& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Debug, Rendering)
            << error
            << CoreTools::LogAppenderIOManageSign::TriggerAssert;

        THROW_EXCEPTION(SYSTEM_TEXT("颜色数据转换失败。"s));
    }

    return *this;
}

// private
template <typename T>
template <typename RhsType, bool TIsFloatingPoint, bool RhsIsFloatingPoint>
void Rendering::Colour<T>::ConvertingColourFormat(const Colour<RhsType>& colour, const std::integral_constant<bool, TIsFloatingPoint>&,
                                                  const std::integral_constant<bool, RhsIsFloatingPoint>&)
{
    InitColour(boost::numeric_cast<T>(colour.GetRed()), boost::numeric_cast<T>(colour.GetGreen()),
               boost::numeric_cast<T>(colour.GetBlue()), boost::numeric_cast<T>(colour.GetAlpha()));
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>::ConvertingColourFormat(const Colour<RhsType>& colour, const std::true_type&, const std::false_type&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating point!");
    static_assert(std::is_integral_v<RhsType>, "RhsType isn't integral!");

    const auto red = ConvertingIntegralToFloatingPoint(colour.GetRed());
    const auto green = ConvertingIntegralToFloatingPoint(colour.GetGreen());
    const auto blue = ConvertingIntegralToFloatingPoint(colour.GetBlue());
    const auto alpha = ConvertingIntegralToFloatingPoint(colour.GetAlpha());

    InitColour(red, green, blue, alpha);
}

// static
// private
template <typename T>
template <typename RhsType>
T Rendering::Colour<T>::ConvertingIntegralToFloatingPoint(RhsType rhs)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating point!");
    static_assert(std::is_integral_v<RhsType>, "RhsType isn't integral!");

    constexpr auto rhsTypeDistance = ColourDefaultTraits<RhsType>::sm_MaxValue - ColourDefaultTraits<RhsType>::sm_MinValue;
    constexpr auto lhsTypeDistance = sm_MaxValue - sm_MinValue;

    return (boost::numeric_cast<T>(rhs) - ColourDefaultTraits<RhsType>::sm_MinValue) * lhsTypeDistance / rhsTypeDistance + sm_MinValue;
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>::ConvertingColourFormat(const Colour<RhsType>& colour, const std::false_type&, const std::true_type&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral!");
    static_assert(std::is_floating_point_v<RhsType>, "RhsType isn't floating point!");

    const auto red = ConvertingFloatingPointToIntegral(colour.GetRed());
    const auto green = ConvertingFloatingPointToIntegral(colour.GetGreen());
    const auto blue = ConvertingFloatingPointToIntegral(colour.GetBlue());
    const auto alpha = ConvertingFloatingPointToIntegral(colour.GetAlpha());

    InitColour(red, green, blue, alpha);
}

// static
// private
template <typename T>
template <typename RhsType>
T Rendering::Colour<T>::ConvertingFloatingPointToIntegral(RhsType rhs)
{
    static_assert(std::is_integral_v<T>, "T isn't integral!");
    static_assert(std::is_floating_point_v<RhsType>, "RhsType isn't floating point!");

    constexpr auto rhsTypeDistance = ColourDefaultTraits<RhsType>::sm_MaxValue - ColourDefaultTraits<RhsType>::sm_MinValue;
    constexpr auto lhsTypeDistance = sm_MaxValue - sm_MinValue;

    return boost::numeric_cast<T>((rhs - ColourDefaultTraits<RhsType>::sm_MinValue) * lhsTypeDistance / rhsTypeDistance + sm_MinValue + static_cast<RhsType>(0.5f));
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>::operator*=(RhsType rhs)
{
    static_assert(std::is_arithmetic_v<RhsType>, "RhsType isn't arithmetic!");

    RENDERING_CLASS_IS_VALID_1;

    m_Red *= boost::numeric_cast<T>(rhs);
    m_Green *= boost::numeric_cast<T>(rhs);
    m_Blue *= boost::numeric_cast<T>(rhs);
    m_Alpha *= boost::numeric_cast<T>(rhs);

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

    m_Red /= boost::numeric_cast<T>(rhs);
    m_Green /= boost::numeric_cast<T>(rhs);
    m_Blue /= boost::numeric_cast<T>(rhs);
    m_Alpha /= boost::numeric_cast<T>(rhs);

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

    m_Red /= boost::numeric_cast<T>(rhs);
    m_Green /= boost::numeric_cast<T>(rhs);
    m_Blue /= boost::numeric_cast<T>(rhs);
    m_Alpha /= boost::numeric_cast<T>(rhs);

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
        return lhs.GetRed() == rhs.GetRed() && lhs.GetGreen() == rhs.GetGreen() &&
               lhs.GetBlue() == rhs.GetBlue() && lhs.GetAlpha() == rhs.GetAlpha();
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
const Rendering::Colour<LhsType> Rendering ::operator/(const Colour<LhsType>& lhs, RhsType rhs)
{
    static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

    return Colour<LhsType>(lhs) /= rhs;
}

template <typename T>
std::ostream& Rendering ::operator<<(std::ostream& os, const Colour<T>& colour)
{
    static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

    os << "red = " << colour.GetRed() << " green = " << colour.GetGreen()
       << " blue = " << colour.GetBlue() << " alpha = " << colour.GetAlpha();

    return os;
}

#endif  // RENDERING_DATA_TYPES_COLOUR_DETAIL_H
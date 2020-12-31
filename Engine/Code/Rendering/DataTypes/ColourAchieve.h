//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/25 20:54)

#ifndef RENDERING_DATA_TYPES_COLOUR_ACHIEVE_H
#define RENDERING_DATA_TYPES_COLOUR_ACHIEVE_H

#include "Colour.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <gsl/gsl_util>

// private
template <typename T>
void Rendering::Colour<T>::InitColour(T red, T green, T blue, T alpha) noexcept
{
    m_Red = red;
    m_Green = green;
    m_Blue = blue;
    m_Alpha = alpha;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Rendering::Colour<T>::IsValid() const noexcept
{
    if (!m_IsClamp)
    {
        return true;
    }

    if (m_Red < sm_MinValue || sm_MaxValue < m_Red)
    {
        return false;
    }

    if (m_Green < sm_MinValue || sm_MaxValue < m_Green)
    {
        return false;
    }

    if (m_Blue < sm_MinValue || sm_MaxValue < m_Blue)
    {
        return false;
    }

    if (m_Alpha < sm_MinValue || sm_MaxValue < m_Alpha)
    {
        return false;
    }

    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Rendering::Colour<T>::SetClamp(bool isClamp) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (m_IsClamp == false && isClamp == true)
    {
        m_IsClamp = true;
        Standardization();
    }

    m_IsClamp = isClamp;
}

template <typename T>
bool Rendering::Colour<T>::IsClamp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_IsClamp;
}

template <typename T>
T Rendering::Colour<T>::GetRed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Red;
}

template <typename T>
T Rendering::Colour<T>::GetGreen() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Green;
}

template <typename T>
T Rendering::Colour<T>::GetBlue() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Blue;
}

template <typename T>
T Rendering::Colour<T>::GetAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Alpha;
}

template <typename T>
const typename Rendering::Colour<T>::ArrayType Rendering::Colour<T>::GetPoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ArrayType result{ m_Red, m_Green, m_Blue, m_Alpha };

    return result;
}

template <typename T>
void Rendering::Colour<T>::SetColour(T red, T green, T blue, T alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    SetRed(red);
    SetGreen(green);
    SetBlue(blue);
    SetAlpha(alpha);
}

template <typename T>
void Rendering::Colour<T>::SetRed(T red) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Red = red;

    StandardizationRed();
}

template <typename T>
void Rendering::Colour<T>::SetGreen(T green) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Green = green;

    StandardizationGreen();
}

template <typename T>
void Rendering::Colour<T>::SetBlue(T blue) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Blue = blue;

    StandardizationBlue();
}

template <typename T>
void Rendering::Colour<T>::SetAlpha(T alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Alpha = alpha;

    StandardizationAlpha();
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>::operator+=(const Colour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Red += rhs.m_Red;
    m_Green += rhs.m_Green;
    m_Blue += rhs.m_Blue;
    m_Alpha += rhs.m_Alpha;

    Standardization();

    return *this;
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>::operator-=(const Colour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Red -= rhs.m_Red;
    m_Green -= rhs.m_Green;
    m_Blue -= rhs.m_Blue;
    m_Alpha -= rhs.m_Alpha;

    Standardization();

    return *this;
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>::operator*=(const Colour& rhs) noexcept(std::is_floating_point_v<T>)
{
    static_assert(sm_MaxValue != 0, "sm_MaxValue != 0");

    RENDERING_CLASS_IS_VALID_1;

    if constexpr (std::is_floating_point<T>())
    {
        m_Red *= rhs.m_Red;
        m_Green *= rhs.m_Green;
        m_Blue *= rhs.m_Blue;
        m_Alpha *= rhs.m_Alpha;

        m_Red /= sm_MaxValue;
        m_Green /= sm_MaxValue;
        m_Blue /= sm_MaxValue;
        m_Alpha /= sm_MaxValue;
    }
    else
    {
        const auto redMultiply = gsl::narrow_cast<int>(m_Red) * gsl::narrow_cast<int>(rhs.m_Red);
        m_Red = boost::numeric_cast<T>(redMultiply / sm_MaxValue);

        const auto greenMultiply = gsl::narrow_cast<int>(m_Green) * gsl::narrow_cast<int>(rhs.m_Green);
        m_Green = boost::numeric_cast<T>(greenMultiply / sm_MaxValue);

        const auto blueMultiply = gsl::narrow_cast<int>(m_Blue) * gsl::narrow_cast<int>(rhs.m_Blue);
        m_Blue = boost::numeric_cast<T>(blueMultiply / sm_MaxValue);

        const auto alphaMultiply = gsl::narrow_cast<int>(m_Alpha) * gsl::narrow_cast<int>(rhs.m_Alpha);
        m_Alpha = boost::numeric_cast<T>(alphaMultiply / sm_MaxValue);
    }

    Standardization();

    return *this;
}

#endif  // RENDERING_DATA_TYPES_COLOUR_ACHIEVE_H
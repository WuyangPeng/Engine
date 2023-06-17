///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:54)

#ifndef RENDERING_DATA_TYPES_COLOUR_ACHIEVE_H
#define RENDERING_DATA_TYPES_COLOUR_ACHIEVE_H

#include "Colour.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <gsl/util>

// private
template <typename T>
void Rendering::Colour<T>::InitColour(T newRed, T newGreen, T newBlue, T newAlpha) noexcept
{
    red = newRed;
    green = newGreen;
    blue = newBlue;
    alpha = newAlpha;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Rendering::Colour<T>::IsValid() const noexcept
{
    if (!isClamp)
    {
        return true;
    }

    if (red < minValue || maxValue < red)
    {
        return false;
    }

    if (green < minValue || maxValue < green)
    {
        return false;
    }

    if (blue < minValue || maxValue < blue)
    {
        return false;
    }

    if (alpha < minValue || maxValue < alpha)
    {
        return false;
    }

    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Rendering::Colour<T>::SetClamp(bool newIsClamp) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (isClamp == false && newIsClamp == true)
    {
        isClamp = true;
        Standardization();
    }

    isClamp = newIsClamp;
}

template <typename T>
bool Rendering::Colour<T>::IsClamp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return isClamp;
}

template <typename T>
T Rendering::Colour<T>::GetRed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return red;
}

template <typename T>
T Rendering::Colour<T>::GetGreen() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return green;
}

template <typename T>
T Rendering::Colour<T>::GetBlue() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return blue;
}

template <typename T>
T Rendering::Colour<T>::GetAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return alpha;
}

template <typename T>
typename Rendering::Colour<T>::ArrayType Rendering::Colour<T>::GetPoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ArrayType result{ red, green, blue, alpha };

    return result;
}

template <typename T>
void Rendering::Colour<T>::SetColour(T newRed, T newGreen, T newBlue, T newAlpha) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    SetRed(newRed);
    SetGreen(newGreen);
    SetBlue(newBlue);
    SetAlpha(newAlpha);
}

template <typename T>
void Rendering::Colour<T>::SetRed(T newRed) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    red = newRed;

    StandardizationRed();
}

template <typename T>
void Rendering::Colour<T>::SetGreen(T newGreen) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    green = newGreen;

    StandardizationGreen();
}

template <typename T>
void Rendering::Colour<T>::SetBlue(T newBlue) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    blue = newBlue;

    StandardizationBlue();
}

template <typename T>
void Rendering::Colour<T>::SetAlpha(T newAlpha) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    alpha = newAlpha;

    StandardizationAlpha();
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>::operator+=(const Colour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    red += rhs.red;
    green += rhs.green;
    blue += rhs.blue;
    alpha += rhs.alpha;

    Standardization();

    return *this;
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>::operator-=(const Colour& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    red -= rhs.red;
    green -= rhs.green;
    blue -= rhs.blue;
    alpha -= rhs.alpha;

    Standardization();

    return *this;
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>::operator*=(const Colour& rhs) noexcept(std::is_floating_point_v<T>)
{
    static_assert(maxValue != 0, "maxValue != 0");

    RENDERING_CLASS_IS_VALID_1;

    if constexpr (std::is_floating_point<T>())
    {
        red *= rhs.red;
        green *= rhs.green;
        blue *= rhs.blue;
        alpha *= rhs.alpha;

        red /= maxValue;
        green /= maxValue;
        blue /= maxValue;
        alpha /= maxValue;
    }
    else
    {
        const auto redMultiply = gsl::narrow_cast<int>(red) * gsl::narrow_cast<int>(rhs.red);
        red = boost::numeric_cast<T>(redMultiply / maxValue);

        const auto greenMultiply = gsl::narrow_cast<int>(green) * gsl::narrow_cast<int>(rhs.green);
        green = boost::numeric_cast<T>(greenMultiply / maxValue);

        const auto blueMultiply = gsl::narrow_cast<int>(blue) * gsl::narrow_cast<int>(rhs.blue);
        blue = boost::numeric_cast<T>(blueMultiply / maxValue);

        const auto alphaMultiply = gsl::narrow_cast<int>(alpha) * gsl::narrow_cast<int>(rhs.alpha);
        alpha = boost::numeric_cast<T>(alphaMultiply / maxValue);
    }

    Standardization();

    return *this;
}

#endif  // RENDERING_DATA_TYPES_COLOUR_ACHIEVE_H
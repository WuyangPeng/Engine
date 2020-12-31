///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 15:13)

#ifndef MATHEMATICS_BASE_MATH_DETAIL_H
#define MATHEMATICS_BASE_MATH_DETAIL_H

#include "Math.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATH_ACHIEVE)

    #include "MathAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATH_ACHIEVE)

#include "System/Helper/PragmaWarning/MathConstants.h"

// Math<float> constexpr函数特化。

template <>
constexpr float Mathematics::Math<float>::GetZeroTolerance() noexcept
{
    return 1e-06f;
}

template <>
constexpr float Mathematics::Math<float>::GetPI() noexcept
{
    return boost::math::constants::pi<float>();
}

// Math<double> constexpr函数特化。

template <>
constexpr double Mathematics::Math<double>::GetZeroTolerance() noexcept
{
    return 1e-08;
}

template <>
constexpr double Mathematics::Math<double>::GetPI() noexcept
{
    return boost::math::constants::pi<double>();
}

// 默认

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetZeroTolerance() noexcept
{
    return GetValue(0);
}

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetPI() noexcept
{
    return GetValue(3);
}

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetTwoPI() noexcept
{
    return GetValue(2) * GetPI();
}

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetHalfPI() noexcept
{
    return GetPI() / GetValue(2);
}

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetQuarterPI() noexcept
{
    return GetPI() / GetValue(4);
}

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetInversePI() noexcept
{
    return GetValue(1) / GetPI();
}

template <typename Real>
constexpr Real Mathematics::Math<Real>::GetInverseTwoPI() noexcept
{
    return GetValue(1) / GetTwoPI();
}

#endif  // MATHEMATICS_BASE_MATH_DETAIL_H
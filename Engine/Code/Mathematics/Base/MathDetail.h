///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 15:13)

#ifndef MATHEMATICS_BASE_MATH_DETAIL_H
#define MATHEMATICS_BASE_MATH_DETAIL_H

#include "Math.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATH_ACHIEVE)

    #include "MathAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATH_ACHIEVE)

#include "System/Helper/PragmaWarning/MathConstants.h"

// Ĭ��

template <typename Real>
inline constexpr Real Mathematics::Math<Real>::GetZeroTolerance() noexcept
{
    return GetValue(0);
}

template <typename Real>
inline constexpr Real Mathematics::Math<Real>::GetPI() noexcept
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

// Math<float> constexpr�����ػ���

template <>
inline constexpr float Mathematics::Math<float>::GetZeroTolerance() noexcept
{
    return 1e-06f;
}

template <>
inline constexpr float Mathematics::Math<float>::GetPI() noexcept
{
    return boost::math::constants::pi<float>();
}

// Math<double> constexpr�����ػ���

template <>
inline constexpr double Mathematics::Math<double>::GetZeroTolerance() noexcept
{
    return 1e-08;
}

template <>
inline constexpr double Mathematics::Math<double>::GetPI() noexcept
{
    return boost::math::constants::pi<double>();
}

#endif  // MATHEMATICS_BASE_MATH_DETAIL_H
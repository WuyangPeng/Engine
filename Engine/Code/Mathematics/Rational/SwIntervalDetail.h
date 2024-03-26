/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 13:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_SW_INTERVAL_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_SW_INTERVAL_DETAIL_H

#include "SwInterval.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineReduction.h"

#include <cfenv>

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>::SwInterval() noexcept
    : endpoints{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>::SwInterval(T e) noexcept
    : endpoints{ e, e }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>::SwInterval(T e0, T e1)
    : endpoints{ e0, e1 }
{
    if (endpoints.at(1) < endpoints.at(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的间隔"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>::SwInterval(EndpointsType endpoint)
    : endpoints{ std::move(endpoint) }
{
    if (endpoints.at(1) < endpoints.at(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的间隔"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_floating_point_v<T>)
bool Mathematics::SwInterval<T>::IsValid() const noexcept
{
    try
    {
        return endpoints.at(0) <= endpoints.at(1);
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_floating_point_v<T>)
T Mathematics::SwInterval<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endpoints.at(index);
}

template <typename T>
requires(std::is_floating_point_v<T>)
typename Mathematics::SwInterval<T>::EndpointsType Mathematics::SwInterval<T>::GetEndpoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endpoints;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Add(T u, T v)
{
    SwInterval w{};

    const auto add = u + v;
    w.endpoints.at(0) = std::nextafter(add, -max);
    w.endpoints.at(1) = std::nextafter(add, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Sub(T u, T v)
{
    SwInterval w{};

    const auto add = u - v;
    w.endpoints.at(0) = std::nextafter(add, -max);
    w.endpoints.at(1) = std::nextafter(add, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Mul(T u, T v)
{
    SwInterval w{};

    const auto add = u * v;
    w.endpoints.at(0) = std::nextafter(add, -max);
    w.endpoints.at(1) = std::nextafter(add, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Div(T u, T v)
{
    if (v != zero)
    {
        SwInterval w{};

        const auto add = u / v;
        w.endpoints.at(0) = std::nextafter(add, -max);
        w.endpoints.at(1) = std::nextafter(add, +max);

        return w;
    }
    else
    {
        /// 除以零不会得到一个确定的区间。只需返回整组实数。
        return Reals();
    }
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Add(T u0, T u1, T v0, T v1)
{
    SwInterval w{};

    w.endpoints.at(0) = std::nextafter(u0 + v0, -max);
    w.endpoints.at(1) = std::nextafter(u1 + v1, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Sub(T u0, T u1, T v0, T v1)
{
    SwInterval w{};

    w.endpoints.at(0) = std::nextafter(u0 - v1, -max);
    w.endpoints.at(1) = std::nextafter(u1 - v0, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Mul(T u0, T u1, T v0, T v1)
{
    SwInterval w{};

    w.endpoints.at(0) = std::nextafter(u0 * v0, -max);
    w.endpoints.at(1) = std::nextafter(u1 * v1, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Mul2(T u0, T u1, T v0, T v1)
{
    const auto u0Mv1 = std::nextafter(u0 * v1, -max);
    const auto u1Mv0 = std::nextafter(u1 * v0, -max);

    const auto u0Mv0 = std::nextafter(u0 * v0, +max);
    const auto u1Mv1 = std::nextafter(u1 * v1, +max);

    return SwInterval{ std::min(u0Mv1, u1Mv0), std::max(u0Mv0, u1Mv1) };
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Div(T u0, T u1, T v0, T v1)
{
    SwInterval w{};

    w.endpoints.at(0) = std::nextafter(u0 / v1, -max);
    w.endpoints.at(1) = std::nextafter(u1 / v0, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Reciprocal(T v0, T v1)
{
    SwInterval w{};

    w.endpoints.at(0) = std::nextafter(one / v1, -max);
    w.endpoints.at(1) = std::nextafter(one / v0, +max);

    return w;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::ReciprocalDown(T v)
{
    const auto recpv = std::nextafter(one / v, -max);

    return SwInterval{ recpv, +inf };
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::ReciprocalUp(T v)
{
    const auto recpv = std::nextafter(one / v, +max);
    return SwInterval{ -inf, recpv };
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::Reals()
{
    return SwInterval{ -inf, +inf };
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T> Mathematics::SwInterval<T>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return SwInterval{ -endpoints.at(1), -endpoints.at(0) };
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator+=(T rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this + rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator+=(const SwInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this + rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator-=(T rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this - rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator-=(const SwInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this - rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator*=(T rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this * rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator*=(const SwInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this * rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator/=(T rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this / rhs;

    return *this;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Mathematics::SwInterval<T>& Mathematics::SwInterval<T>::operator/=(const SwInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this / rhs;

    return *this;
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator+(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    return SwInterval<T>::Add(lhs[0], lhs[1], rhs[0], rhs[1]);
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator+(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    return SwInterval<T>::Add(lhs, lhs, rhs[0], rhs[1]);
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator+(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>)
{
    return SwInterval<T>::Add(lhs[0], lhs[1], rhs, rhs);
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator-(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    return SwInterval<T>::Sub(lhs[0], lhs[1], rhs[0], rhs[1]);
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator-(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    return SwInterval<T>::Sub(lhs, lhs, rhs[0], rhs[1]);
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator-(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>)
{
    return SwInterval<T>::Sub(lhs[0], lhs[1], rhs, rhs);
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator*(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    constexpr T zero{ 0 };
    if (lhs[0] >= zero)
    {
        if (rhs[0] >= zero)
        {
            return SwInterval<T>::Mul(lhs[0], lhs[1], rhs[0], rhs[1]);
        }
        else if (rhs[1] <= zero)
        {
            return SwInterval<T>::Mul(lhs[1], lhs[0], rhs[0], rhs[1]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return SwInterval<T>::Mul(lhs[1], lhs[1], rhs[0], rhs[1]);
        }
    }
    else if (lhs[1] <= zero)
    {
        if (rhs[0] >= zero)
        {
            return SwInterval<T>::Mul(lhs[0], lhs[1], rhs[1], rhs[0]);
        }
        else if (rhs[1] <= zero)
        {
            return SwInterval<T>::Mul(lhs[1], lhs[0], rhs[1], rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return SwInterval<T>::Mul(lhs[0], lhs[0], rhs[1], rhs[0]);
        }
    }
    else  // lhs[0] < 0 < lhs[1]
    {
        if (rhs[0] >= zero)
        {
            return SwInterval<T>::Mul(lhs[0], lhs[1], rhs[1], rhs[1]);
        }
        else if (rhs[1] <= zero)
        {
            return SwInterval<T>::Mul(lhs[1], lhs[0], rhs[0], rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return SwInterval<T>::Mul2(lhs[0], lhs[1], rhs[0], rhs[1]);
        }
    }
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator*(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    const T zero{ 0 };
    if (lhs >= zero)
    {
        return SwInterval<T>::Mul(lhs, lhs, rhs[0], rhs[1]);
    }
    else
    {
        return SwInterval<T>::Mul(lhs, lhs, rhs[1], rhs[0]);
    }
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator*(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>)
{
    constexpr T zero{ 0 };
    if (rhs >= zero)
    {
        return SwInterval<T>::Mul(lhs[0], lhs[1], rhs, rhs);
    }
    else
    {
        return SwInterval<T>::Mul(lhs[1], lhs[0], rhs, rhs);
    }
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator/(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    constexpr T zero{ 0 };
    if (rhs[0] > zero || rhs[1] < zero)
    {
        return lhs * SwInterval<T>::Reciprocal(rhs[0], rhs[1]);
    }
    else
    {
        if (rhs[0] == zero)
        {
            return lhs * SwInterval<T>::ReciprocalDown(rhs[1]);
        }
        else if (rhs[1] == zero)
        {
            return lhs * SwInterval<T>::ReciprocalUp(rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return SwInterval<T>::Reals();
        }
    }
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator/(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>)
{
    const T zero{ 0 };
    if (rhs[0] > zero || rhs[1] < zero)
    {
        return lhs * SwInterval<T>::Reciprocal(rhs[0], rhs[1]);
    }
    else
    {
        if (rhs[0] == zero)
        {
            return lhs * SwInterval<T>::ReciprocalDown(rhs[1]);
        }
        else if (rhs[1] == zero)
        {
            return lhs * SwInterval<T>::ReciprocalUp(rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return SwInterval<T>::Reals();
        }
    }
}

template <typename T>
Mathematics::SwInterval<T> Mathematics::operator/(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>)
{
    constexpr T zero{ 0 };
    if (rhs > zero)
    {
        return SwInterval<T>::Div(lhs[0], lhs[1], rhs, rhs);
    }
    else if (rhs < zero)
    {
        return SwInterval<T>::Div(lhs[1], lhs[0], rhs, rhs);
    }
    else  // rhs = 0
    {
        return SwInterval<T>::Reals();
    }
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_SW_INTERVAL_DETAIL_H

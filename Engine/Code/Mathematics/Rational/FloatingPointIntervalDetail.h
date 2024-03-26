/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 13:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_FLOATING_POINT_INTERVAL_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_FLOATING_POINT_INTERVAL_DETAIL_H

#include "FloatingPointInterval.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineReduction.h"

#include <cfenv>

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>::FloatingPointInterval() noexcept
    : endpoints{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>::FloatingPointInterval(const FloatingPointType& e) noexcept
    : endpoints{ e, e }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>::FloatingPointInterval(const FloatingPointType& e0, const FloatingPointType& e1)
    : endpoints{ e0, e1 }
{
    if (endpoints.at(1) < endpoints.at(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的间隔"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>::FloatingPointInterval(EndpointsType endpoint)
    : endpoints{ std::move(endpoint) }
{
    if (endpoints.at(1) < endpoints.at(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的间隔"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
bool Mathematics::FloatingPointInterval<FloatingPointType>::IsValid() const noexcept
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

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
FloatingPointType Mathematics::FloatingPointInterval<FloatingPointType>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endpoints.at(index);
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
typename Mathematics::FloatingPointInterval<FloatingPointType>::EndpointsType Mathematics::FloatingPointInterval<FloatingPointType>::GetEndpoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endpoints;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Add(const FloatingPointType& u, const FloatingPointType& v)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u + v;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u + v;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Sub(const FloatingPointType& u, const FloatingPointType& v)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u - v;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u - v;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Mul(const FloatingPointType& u, const FloatingPointType& v)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u * v;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u * v;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Div(const FloatingPointType& u, const FloatingPointType& v)
{
    constexpr FloatingPointType zero{};
    if (v != zero)
    {
        FloatingPointInterval w{};

        const auto saveMode = std::fegetround();
        std::fesetround(FE_DOWNWARD);
        w.endpoints.at(0) = u / v;
        std::fesetround(FE_UPWARD);
        w.endpoints.at(1) = u / v;
        std::fesetround(saveMode);

        return w;
    }
    else
    {
        /// 除以零不会得到一个确定的区间。只需返回整组实数。
        return Reals();
    }
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
FloatingPointType Mathematics::FloatingPointInterval<FloatingPointType>::ProductLowerBound(const EndpointsType& u, const EndpointsType& v)
{
    constexpr FloatingPointType zero{};
    FloatingPointType w0{};
    if (u.at(0) >= zero)
    {
        if (v.at(0) >= zero)
        {
            w0 = u.at(0) * v.at(0);
        }
        else if (v.at(1) <= zero)
        {
            w0 = u.at(1) * v.at(0);
        }
        else
        {
            w0 = u.at(1) * v.at(0);
        }
    }
    else if (u.at(1) <= zero)
    {
        if (v.at(0) >= zero)
        {
            w0 = u.at(0) * v.at(1);
        }
        else if (v.at(1) <= zero)
        {
            w0 = u.at(1) * v.at(1);
        }
        else
        {
            w0 = u.at(0) * v.at(1);
        }
    }
    else
    {
        if (v.at(0) >= zero)
        {
            w0 = u.at(0) * v.at(1);
        }
        else if (v.at(1) <= zero)
        {
            w0 = u.at(1) * v.at(0);
        }
        else
        {
            w0 = u.at(0) * v.at(0);
        }
    }
    return w0;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
FloatingPointType Mathematics::FloatingPointInterval<FloatingPointType>::ProductUpperBound(const EndpointsType& u, const EndpointsType& v)
{
    constexpr FloatingPointType zero{};
    FloatingPointType w1{};
    if (u.at(0) >= zero)
    {
        if (v.at(0) >= zero)
        {
            w1 = u.at(1) * v.at(1);
        }
        else if (v.at(1) <= zero)
        {
            w1 = u.at(0) * v.at(1);
        }
        else
        {
            w1 = u.at(1) * v.at(1);
        }
    }
    else if (u.at(1) <= zero)
    {
        if (v.at(0) >= zero)
        {
            w1 = u.at(1) * v.at(0);
        }
        else if (v.at(1) <= zero)
        {
            w1 = u.at(0) * v.at(0);
        }
        else
        {
            w1 = u.at(0) * v.at(0);
        }
    }
    else
    {
        if (v.at(0) >= zero)
        {
            w1 = u.at(1) * v.at(1);
        }
        else if (v.at(1) <= zero)
        {
            w1 = u.at(0) * v.at(0);
        }
        else
        {
            w1 = u.at(1) * v.at(1);
        }
    }
    return w1;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Add(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u0 + v0;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u1 + v1;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Sub(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u0 - v1;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u1 - v0;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Mul(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u0 * v0;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u1 * v1;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Mul2(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1)
{
    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    const auto u0Mv1 = u0 * v1;
    const auto u1Mv0 = u1 * v0;
    std::fesetround(FE_UPWARD);
    const auto u0Mv0 = u0 * v0;
    const auto u1Mv1 = u1 * v1;
    std::fesetround(saveMode);

    return FloatingPointInterval{ std::min(u0Mv1, u1Mv0), std::max(u0Mv0, u1Mv1) };
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Div(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1)
{
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = u0 / v1;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = u1 / v0;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Reciprocal(const FloatingPointType& v0, const FloatingPointType& v1)
{
    constexpr FloatingPointType one{ 1 };
    FloatingPointInterval w{};

    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    w.endpoints.at(0) = one / v1;
    std::fesetround(FE_UPWARD);
    w.endpoints.at(1) = one / v0;
    std::fesetround(saveMode);

    return w;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::ReciprocalDown(const FloatingPointType& v)
{
    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    const auto recpv = FloatingPointType{ 1 } / v;
    std::fesetround(saveMode);
    constexpr auto inf = std::numeric_limits<FloatingPointType>::infinity();
    return FloatingPointInterval{ recpv, +inf };
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::ReciprocalUp(const FloatingPointType& v)
{
    const auto saveMode = std::fegetround();
    std::fesetround(FE_DOWNWARD);
    const auto recpv = FloatingPointType{ 1 } / v;
    std::fesetround(saveMode);
    constexpr auto inf = std::numeric_limits<FloatingPointType>::infinity();
    return FloatingPointInterval{ -inf, recpv };
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::Reals()
{
    constexpr auto inf = std::numeric_limits<FloatingPointType>::infinity();

    return FloatingPointInterval{ -inf, +inf };
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::FloatingPointInterval<FloatingPointType>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return FloatingPointInterval{ -endpoints.at(1), -endpoints.at(0) };
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator+=(const FloatingPointType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this + rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator+=(const FloatingPointInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this + rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator-=(const FloatingPointType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this - rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator-=(const FloatingPointInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this - rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator*=(const FloatingPointType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this * rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator*=(const FloatingPointInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this * rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator/=(const FloatingPointType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this / rhs;

    return *this;
}

template <typename FloatingPointType>
requires(std::is_floating_point_v<FloatingPointType>)
Mathematics::FloatingPointInterval<FloatingPointType>& Mathematics::FloatingPointInterval<FloatingPointType>::operator/=(const FloatingPointInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this / rhs;

    return *this;
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator+(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    return FloatingPointInterval<FloatingPointType>::Add(lhs[0], lhs[1], rhs[0], rhs[1]);
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator+(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    return FloatingPointInterval<FloatingPointType>::Add(lhs, lhs, rhs[0], rhs[1]);
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator+(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    return FloatingPointInterval<FloatingPointType>::Add(lhs[0], lhs[1], rhs, rhs);
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator-(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    return FloatingPointInterval<FloatingPointType>::Sub(lhs[0], lhs[1], rhs[0], rhs[1]);
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator-(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    return FloatingPointInterval<FloatingPointType>::Sub(lhs, lhs, rhs[0], rhs[1]);
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator-(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    return FloatingPointInterval<FloatingPointType>::Sub(lhs[0], lhs[1], rhs, rhs);
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator*(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    constexpr FloatingPointType zero{ 0 };
    if (lhs[0] >= zero)
    {
        if (rhs[0] >= zero)
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[0], lhs[1], rhs[0], rhs[1]);
        }
        else if (rhs[1] <= zero)
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[1], lhs[0], rhs[0], rhs[1]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[1], lhs[1], rhs[0], rhs[1]);
        }
    }
    else if (lhs[1] <= zero)
    {
        if (rhs[0] >= zero)
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[0], lhs[1], rhs[1], rhs[0]);
        }
        else if (rhs[1] <= zero)
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[1], lhs[0], rhs[1], rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[0], lhs[0], rhs[1], rhs[0]);
        }
    }
    else  // lhs[0] < 0 < lhs[1]
    {
        if (rhs[0] >= zero)
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[0], lhs[1], rhs[1], rhs[1]);
        }
        else if (rhs[1] <= zero)
        {
            return FloatingPointInterval<FloatingPointType>::Mul(lhs[1], lhs[0], rhs[0], rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return FloatingPointInterval<FloatingPointType>::Mul2(lhs[0], lhs[1], rhs[0], rhs[1]);
        }
    }
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator*(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    const FloatingPointType zero{ 0 };
    if (lhs >= zero)
    {
        return FloatingPointInterval<FloatingPointType>::Mul(lhs, lhs, rhs[0], rhs[1]);
    }
    else
    {
        return FloatingPointInterval<FloatingPointType>::Mul(lhs, lhs, rhs[1], rhs[0]);
    }
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator*(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    constexpr FloatingPointType zero{ 0 };
    if (rhs >= zero)
    {
        return FloatingPointInterval<FloatingPointType>::Mul(lhs[0], lhs[1], rhs, rhs);
    }
    else
    {
        return FloatingPointInterval<FloatingPointType>::Mul(lhs[1], lhs[0], rhs, rhs);
    }
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator/(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    constexpr FloatingPointType zero{ 0 };
    if (rhs[0] > zero || rhs[1] < zero)
    {
        return lhs * FloatingPointInterval<FloatingPointType>::Reciprocal(rhs[0], rhs[1]);
    }
    else
    {
        if (rhs[0] == zero)
        {
            return lhs * FloatingPointInterval<FloatingPointType>::ReciprocalDown(rhs[1]);
        }
        else if (rhs[1] == zero)
        {
            return lhs * FloatingPointInterval<FloatingPointType>::ReciprocalUp(rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return FloatingPointInterval<FloatingPointType>::Reals();
        }
    }
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator/(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    const FloatingPointType zero{ 0 };
    if (rhs[0] > zero || rhs[1] < zero)
    {
        return lhs * FloatingPointInterval<FloatingPointType>::Reciprocal(rhs[0], rhs[1]);
    }
    else
    {
        if (rhs[0] == zero)
        {
            return lhs * FloatingPointInterval<FloatingPointType>::ReciprocalDown(rhs[1]);
        }
        else if (rhs[1] == zero)
        {
            return lhs * FloatingPointInterval<FloatingPointType>::ReciprocalUp(rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return FloatingPointInterval<FloatingPointType>::Reals();
        }
    }
}

template <typename FloatingPointType>
Mathematics::FloatingPointInterval<FloatingPointType> Mathematics::operator/(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>)
{
    constexpr FloatingPointType zero{ 0 };
    if (rhs > zero)
    {
        return FloatingPointInterval<FloatingPointType>::Div(lhs[0], lhs[1], rhs, rhs);
    }
    else if (rhs < zero)
    {
        return FloatingPointInterval<FloatingPointType>::Div(lhs[1], lhs[0], rhs, rhs);
    }
    else  // rhs = 0
    {
        return FloatingPointInterval<FloatingPointType>::Reals();
    }
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_FLOATING_POINT_INTERVAL_DETAIL_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 13:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_INTERVAL_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_INTERVAL_DETAIL_H

#include "ArbitraryPrecisionInterval.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineReduction.h"

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::CreateZero() noexcept(noexcept(ArbitraryPrecisionType::CreateZero()))
{
    return ArbitraryPrecisionInterval{ CoreTools::DisableNotThrow::Disable };
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ArbitraryPrecisionInterval(CoreTools::DisableNotThrow disableNotThrow) noexcept(noexcept(ArbitraryPrecisionType::CreateZero()))
    : endpoints{ ArbitraryPrecisionType::CreateZero(), ArbitraryPrecisionType::CreateZero() }
{
    System::UnusedFunction(disableNotThrow);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ArbitraryPrecisionInterval(const ArbitraryPrecisionType& e) noexcept
    : endpoints{ e, e }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ArbitraryPrecisionInterval(const ArbitraryPrecisionType& e0, const ArbitraryPrecisionType& e1)
    : endpoints{ e0, e1 }
{
    if (endpoints.at(1) < endpoints.at(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的间隔"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ArbitraryPrecisionInterval(EndpointsType endpoint)
    : endpoints{ std::move(endpoint) }
{
    if (endpoints.at(1) < endpoints.at(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的间隔"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
bool Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::IsValid() const noexcept
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

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
ArbitraryPrecisionType Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endpoints.at(index);
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
typename Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::EndpointsType Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::GetEndpoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endpoints;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Add(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u + v;
    w.endpoints.at(1) = w.endpoints.at(0);

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Sub(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u - v;
    w.endpoints.at(1) = w.endpoints.at(0);

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u * v;
    w.endpoints.at(1) = w.endpoints.at(0);

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Div(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const auto zero = ArbitraryPrecisionType::CreateZero();
    if (v != zero)
    {
        auto w = ArbitraryPrecisionInterval::CreateZero();

        w.endpoints.at(0) = u / v;
        w.endpoints.at(1) = w.endpoints.at(0);

        return w;
    }
    else
    {
        /// 除以零不会得到一个确定的区间。只需返回整组实数。
        return Reals();
    }
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Add(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u0 + v0;
    w.endpoints.at(1) = u1 + v1;

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Sub(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u0 - v1;
    w.endpoints.at(1) = u1 - v0;

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u0 * v0;
    w.endpoints.at(1) = u1 * v1;

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul2(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1)
{
    const auto u0Mv1 = u0 * v1;
    const auto u1Mv0 = u1 * v0;
    const auto u0Mv0 = u0 * v0;
    const auto u1Mv1 = u1 * v1;

    return ArbitraryPrecisionInterval{ std::min(u0Mv1, u1Mv0), std::max(u0Mv0, u1Mv1) };
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Div(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = u0 / v1;
    w.endpoints.at(1) = u1 / v0;

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reciprocal(const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType one{ 1 };
    auto w = ArbitraryPrecisionInterval::CreateZero();

    w.endpoints.at(0) = one / v1;
    w.endpoints.at(1) = one / v0;

    return w;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ReciprocalDown(const ArbitraryPrecisionType& v) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const auto recpv = ArbitraryPrecisionType{ 1 } / v;

    ArbitraryPrecisionType posinf{ 0 };
    posinf.SetSign(+2);

    return ArbitraryPrecisionInterval{ recpv, posinf };
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ReciprocalUp(const ArbitraryPrecisionType& v) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const auto recpv = ArbitraryPrecisionType{ 1 } / v;

    ArbitraryPrecisionType neginf{ 0 };
    neginf.SetSign(-2);

    return ArbitraryPrecisionInterval{ neginf, recpv };
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reals()
{
    auto posinf = ArbitraryPrecisionType::CreateZero();
    auto neginf = ArbitraryPrecisionType::CreateZero();

    posinf.SetSign(+2);
    neginf.SetSign(-2);

    return ArbitraryPrecisionInterval{ neginf, posinf };
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ArbitraryPrecisionInterval{ -endpoints.at(1), -endpoints.at(0) };
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator+=(const ArbitraryPrecisionType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this + rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator+=(const ArbitraryPrecisionInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this + rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator-=(const ArbitraryPrecisionType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this - rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator-=(const ArbitraryPrecisionInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this - rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator*=(const ArbitraryPrecisionType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this * rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator*=(const ArbitraryPrecisionInterval& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this * rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator/=(const ArbitraryPrecisionType& rhs) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this / rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>& Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType>::operator/=(const ArbitraryPrecisionInterval& rhs) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = *this / rhs;

    return *this;
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator+(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Add(lhs[0], lhs[1], rhs[0], rhs[1]);
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator+(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Add(lhs, lhs, rhs[0], rhs[1]);
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator+(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Add(lhs[0], lhs[1], rhs, rhs);
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator-(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Sub(lhs[0], lhs[1], rhs[0], rhs[1]);
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator-(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Sub(lhs, lhs, rhs[0], rhs[1]);
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator-(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Sub(lhs[0], lhs[1], rhs, rhs);
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator*(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType zero{ 0 };
    if (lhs[0] >= zero)
    {
        if (rhs[0] >= zero)
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[0], lhs[1], rhs[0], rhs[1]);
        }
        else if (rhs[1] <= zero)
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[1], lhs[0], rhs[0], rhs[1]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[1], lhs[1], rhs[0], rhs[1]);
        }
    }
    else if (lhs[1] <= zero)
    {
        if (rhs[0] >= zero)
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[0], lhs[1], rhs[1], rhs[0]);
        }
        else if (rhs[1] <= zero)
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[1], lhs[0], rhs[1], rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[0], lhs[0], rhs[1], rhs[0]);
        }
    }
    else  // lhs[0] < 0 < lhs[1]
    {
        if (rhs[0] >= zero)
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[0], lhs[1], rhs[1], rhs[1]);
        }
        else if (rhs[1] <= zero)
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[1], lhs[0], rhs[0], rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul2(lhs[0], lhs[1], rhs[0], rhs[1]);
        }
    }
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator*(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType zero{ 0 };
    if (lhs >= zero)
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs, lhs, rhs[0], rhs[1]);
    }
    else
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs, lhs, rhs[1], rhs[0]);
    }
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator*(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType zero{ 0 };
    if (rhs >= zero)
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[0], lhs[1], rhs, rhs);
    }
    else
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Mul(lhs[1], lhs[0], rhs, rhs);
    }
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator/(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value && CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType zero{ 0 };
    if (rhs[0] > zero || rhs[1] < zero)
    {
        return lhs * ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reciprocal(rhs[0], rhs[1]);
    }
    else
    {
        if (rhs[0] == zero)
        {
            return lhs * ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ReciprocalDown(rhs[1]);
        }
        else if (rhs[1] == zero)
        {
            return lhs * ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ReciprocalUp(rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reals();
        }
    }
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator/(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value && CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType zero{ 0 };
    if (rhs[0] > zero || rhs[1] < zero)
    {
        return lhs * ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reciprocal(rhs[0], rhs[1]);
    }
    else
    {
        if (rhs[0] == zero)
        {
            return lhs * ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ReciprocalDown(rhs[1]);
        }
        else if (rhs[1] == zero)
        {
            return lhs * ArbitraryPrecisionInterval<ArbitraryPrecisionType>::ReciprocalUp(rhs[0]);
        }
        else  // rhs[0] < 0 < rhs[1]
        {
            return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reals();
        }
    }
}

template <typename ArbitraryPrecisionType>
Mathematics::ArbitraryPrecisionInterval<ArbitraryPrecisionType> Mathematics::operator/(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value && CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value)
{
    const ArbitraryPrecisionType zero{ 0 };
    if (rhs > zero)
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Div(lhs[0], lhs[1], rhs, rhs);
    }
    else if (rhs < zero)
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Div(lhs[1], lhs[0], rhs, rhs);
    }
    else  // rhs = 0
    {
        return ArbitraryPrecisionInterval<ArbitraryPrecisionType>::Reals();
    }
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_INTERVAL_DETAIL_H

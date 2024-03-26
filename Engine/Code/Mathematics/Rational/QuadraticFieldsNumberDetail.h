///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.7 (2024/03/04 10:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_QUADRATIC_FIELDS_NUMBER_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_QUADRATIC_FIELDS_NUMBER_DETAIL_H

#include "QuadraticFieldsNumber.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumber() noexcept
    : x{}, d{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumber(Real d) noexcept
    : x{}, d{ d }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumber(const QuadraticFieldsNumberMinus1& x0, QuadraticFieldsNumberMinus1& x1, Real d) noexcept
    : x{ x0, x1 }, d{ d }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumber(const Container& x, Real d) noexcept
    : x{ x }, d{ d }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(0 < N)
bool Mathematics::QuadraticFieldsNumber<Real, N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(0 < N)
typename Mathematics::QuadraticFieldsNumber<Real, N>::Container Mathematics::QuadraticFieldsNumber<Real, N>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real, int N>
requires(0 < N)
void Mathematics::QuadraticFieldsNumber<Real, N>::SetX(const Container& aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real, int N>
requires(0 < N)
Real Mathematics::QuadraticFieldsNumber<Real, N>::GetD() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return d;
}

template <typename Real, int N>
requires(0 < N)
void Mathematics::QuadraticFieldsNumber<Real, N>::SetD(Real aD) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    d = aD;
}

template <typename Real, int N>
requires(0 < N)
typename Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumberMinus1 Mathematics::QuadraticFieldsNumber<Real, N>::GetX(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x.at(index);
}

template <typename Real, int N>
requires(0 < N)
void Mathematics::QuadraticFieldsNumber<Real, N>::SetX(int index, const QuadraticFieldsNumberMinus1& aX)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.at(index) = aX;
}

template <typename Real, int N>
requires(0 < N)
const typename Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumberMinus1& Mathematics::QuadraticFieldsNumber<Real, N>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x.at(index);
}

template <typename Real, int N>
requires(0 < N)
typename Mathematics::QuadraticFieldsNumber<Real, N>::QuadraticFieldsNumberMinus1& Mathematics::QuadraticFieldsNumber<Real, N>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(QuadraticFieldsNumberMinus1, index);
}

template <typename Real>
Mathematics::QuadraticFieldsNumber<Real, 1>::QuadraticFieldsNumber() noexcept
    : x{}, d{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::QuadraticFieldsNumber<Real, 1>::QuadraticFieldsNumber(Real d) noexcept
    : x{}, d{ d }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::QuadraticFieldsNumber<Real, 1>::QuadraticFieldsNumber(Real x0, Real x1, Real d) noexcept
    : x{ x0, x1 }, d{ d }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::QuadraticFieldsNumber<Real, 1>::QuadraticFieldsNumber(const Container& x, Real d) noexcept
    : x{ x }, d{ d }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuadraticFieldsNumber<Real, 1>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::QuadraticFieldsNumber<Real, 1>::Container Mathematics::QuadraticFieldsNumber<Real, 1>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
void Mathematics::QuadraticFieldsNumber<Real, 1>::SetX(const Container& aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
Real Mathematics::QuadraticFieldsNumber<Real, 1>::GetD() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return d;
}

template <typename Real>
void Mathematics::QuadraticFieldsNumber<Real, 1>::SetD(Real aD) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    d = aD;
}

template <typename Real>
Real Mathematics::QuadraticFieldsNumber<Real, 1>::GetX(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x.at(index);
}

template <typename Real>
void Mathematics::QuadraticFieldsNumber<Real, 1>::SetX(int index, Real aX)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x.at(index) = aX;
}

template <typename Real>
const Real& Mathematics::QuadraticFieldsNumber<Real, 1>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x.at(index);
}

template <typename Real>
Real& Mathematics::QuadraticFieldsNumber<Real, 1>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator+(const QuadraticFieldsNumber<Real, N>& self)
{
    return self;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator-(const QuadraticFieldsNumber<Real, N>& self)
{
    return QuadraticFieldsNumber{ -self.GetX(0), -self.GetX(1), self.GetD() };
}

template <typename Real, int N>
requires(0 < N)
void Mathematics::Check(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
#ifdef MATHEMATICS_USE_ASSERT_ON_QUADRATIC_FIELDS_NUMBER_MISMATCHED_D

    MATHEMATICS_ASSERTION_0(lhs.GetD() == rhs.GetD(), "d值不匹配");

#endif  // MATHEMATICS_USE_ASSERT_ON_QUADRATIC_FIELDS_NUMBER_MISMATCHED_D
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator+=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    Check(lhs, rhs);

    lhs[0] += rhs[0];
    lhs[1] += rhs[1];

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator+=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    lhs[0] += rhs;

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator-=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    Check(lhs, rhs);

    lhs[0] -= rhs[0];
    lhs[1] -= rhs[1];

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator-=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    lhs[0] -= rhs;

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator*=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    Check(lhs, rhs);

    auto x0 = lhs[0] * rhs[0] + lhs[1] * rhs[1] * lhs.GetD();
    auto x1 = lhs[0] * rhs[1] + lhs[1] * rhs[0];
    lhs[0] = x0;
    lhs[1] = x1;

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator*=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    lhs[0] *= rhs;
    lhs[1] *= rhs;

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator/=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    Check(lhs, rhs);

    auto denominator = rhs[0] * rhs[0] - rhs[1] * rhs[1] * lhs.GetD();
    auto numerator0 = lhs[0] * rhs[0] - lhs[1] * rhs[1] * lhs.GetD();
    auto numerator1 = lhs[1] * rhs[0] - lhs[0] * rhs[1];
    lhs[0] = numerator0 / denominator;
    lhs[1] = numerator1 / denominator;

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N>& Mathematics::operator/=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    lhs[0] /= rhs;
    lhs[1] /= rhs;

    return lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator+(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto result = lhs;

    result += rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator+(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    auto result = lhs;

    result += rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator+(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto result = rhs;

    result += lhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator-(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto result = lhs;

    result -= rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator-(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    auto result = lhs;

    result -= rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator-(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    return -rhs + lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator*(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto result = lhs;

    result *= rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator*(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    auto result = lhs;

    result *= rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator*(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto result = rhs;

    result *= lhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator/(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto result = lhs;

    result /= rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator/(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs)
{
    auto result = lhs;

    result /= rhs;

    return result;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator/(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    auto denominator = rhs[0] * rhs[0] - rhs[1] * rhs[1] * rhs.GetD();
    auto x0 = (lhs * rhs[0]) / denominator;
    auto x1 = -(lhs * rhs[1]) / denominator;

    return QuadraticFieldsNumber{ x0, x1, rhs.GetD() };
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator==(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    Check(lhs, rhs);

    if (lhs.GetD() == Real{} || lhs[1] == rhs[1])
    {
        return lhs[0] == rhs[0];
    }
    else if (rhs[1] < lhs[1])
    {
        if (rhs[0] <= lhs[0])
        {
            return false;
        }
        else  // q0.x[0] < q1.x[0]
        {
            const auto diff = lhs - rhs;

            return diff[0] * diff[0] == diff[1] * diff[1] * diff.GetD();
        }
    }
    else  // q0.x[1] < q1.x[1]
    {
        if (lhs[0] <= rhs[0])
        {
            return false;
        }
        else  // q0.x[0] > q1.x[0]
        {
            const auto diff = lhs - rhs;

            return diff[0] * diff[0] == diff[1] * diff[1] * diff.GetD();
        }
    }
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator!=(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator<(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    Check(lhs, rhs);

    if (lhs.GetD() == Real{} || lhs[1] == rhs[1])
    {
        return lhs[0] < rhs[0];
    }
    else if (rhs[1] < lhs[1])
    {
        if (rhs[0] <= lhs[0])
        {
            return false;
        }
        else  // q0.x[0] < q1.x[0]
        {
            const auto diff = lhs - rhs;

            return diff[1] * diff[1] * diff.GetD() < diff[0] * diff[0];
        }
    }
    else  // q0.x[1] < q1.x[1]
    {
        if (lhs[0] <= rhs[0])
        {
            return true;
        }
        else  // q0.x[0] > q1.x[0]
        {
            const auto diff = lhs - rhs;

            return diff[0] * diff[0] < diff[1] * diff[1] * diff.GetD();
        }
    }
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator<=(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator>(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    return rhs < lhs;
}

template <typename Real, int N>
requires(0 < N)
Mathematics::QuadraticFieldsNumber<Real, N> Mathematics::operator>=(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_QUADRATIC_FIELDS_NUMBER_DETAIL_H

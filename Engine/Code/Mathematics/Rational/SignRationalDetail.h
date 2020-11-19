///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:52)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_DETAIL_H

#include "ConversionRationalDetail.h"
#include "IntegerDetail.h"
#include "RationalConversionDetail.h"
#include "SignRational.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <iostream>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <int N>
Mathematics::SignRational<N>::SignRational()
    : m_Numerator{}, m_Denominator{ 1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <int N>
Mathematics::SignRational<N>::SignRational(const Integer& numerator)
    : m_Numerator{ numerator }, m_Denominator{ 1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
Mathematics::SignRational<N>::SignRational(const Integer& numerator, const Integer& denominator)
    : m_Numerator{ numerator }, m_Denominator{ denominator }
{
    EliminatePowersOfTwo();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
template <typename T>
Mathematics::SignRational<N>::SignRational(T numerator)
    : m_Numerator{ 0 }, m_Denominator{ 1 }
{
    ConvertToRational(numerator);

    EliminatePowersOfTwo();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
template <typename T>
void Mathematics::SignRational<N>::ConvertToRational(T value)
{
    const ConversionRational<T> convert{ value };

    if (convert.IsCanConversion<N>())
    {
        m_Numerator = convert.GetNumerator<N>();
        m_Denominator = convert.GetDenominator<N>();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

template <int N>
template <typename T>
Mathematics::SignRational<N>::SignRational(T numerator, T denominator)
    : m_Numerator{ numerator }, m_Denominator{ denominator }
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    EliminatePowersOfTwo();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::SignRational<N>::IsValid() const noexcept
{
    if (m_Denominator.IsZero())
        return false;
    else
        return true;
}
#endif  // OPEN_CLASS_INVARIANT

// private
template <int N>
void Mathematics::SignRational<N>::EliminatePowersOfTwo()
{
    if (m_Numerator == Integer{ 0 })
    {
        // 分子是零。
        m_Denominator = Integer{ 1 };

        return;
    }

    const auto shift = GetPowers();

    if (0 < shift)
    {
        m_Numerator >>= shift;
        m_Denominator >>= shift;
    }
}

// private
template <int N>
int Mathematics::SignRational<N>::GetPowers() const
{
    auto numerator = m_Numerator.GetAbsoluteValue();
    auto denominator = m_Denominator.GetAbsoluteValue();

    if (0 < (numerator[0] & 1) || 0 < (denominator[0] & 1))
    {
        // 没有一个项能被2整除（快速退出）
        return 0;
    }

    const auto blockNumerator = numerator.GetTrailingBlock();
    const auto blockDenominator = denominator.GetTrailingBlock();

    MATHEMATICS_ASSERTION_0(0 <= blockDenominator, "分母必须不为零！\n");

    const auto minBlock = (blockNumerator < blockDenominator ? blockNumerator : blockDenominator);

    const auto bitNumerator = numerator.GetTrailingBit(blockNumerator);
    const auto bitDenominator = denominator.GetTrailingBit(blockDenominator);

    const auto minBit = (bitNumerator < bitDenominator ? bitNumerator : bitDenominator);
    const auto shift = 16 * minBlock + minBit;

    return shift;
}

template <int N>
typename const Mathematics::SignRational<N>::Integer Mathematics::SignRational<N>::GetNumerator() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Numerator;
}

template <int N>
typename const Mathematics::SignRational<N>::Integer Mathematics::SignRational<N>::GetDenominator() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Denominator;
}

template <int N>
void Mathematics::SignRational<N>::Set(const Integer& numerator, const Integer& denominator)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator = numerator;
    m_Denominator = denominator;

    EliminatePowersOfTwo();
}

template <int N>
const Mathematics::SignRational<N> Mathematics::SignRational<N>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return SignRational{ -m_Numerator, m_Denominator };
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator+=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator = m_Numerator * rhs.m_Denominator + m_Denominator * rhs.m_Numerator;
    m_Denominator *= rhs.m_Denominator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator-=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator = m_Numerator * rhs.m_Denominator - m_Denominator * rhs.m_Numerator;
    m_Denominator *= rhs.m_Denominator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator*=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator *= rhs.m_Numerator;
    m_Denominator *= rhs.m_Denominator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator/=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator *= rhs.m_Denominator;
    m_Denominator *= rhs.m_Numerator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator+=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator += rhs * m_Denominator;

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator-=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator -= rhs * m_Denominator;

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator*=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Numerator *= rhs;

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator/=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Denominator *= rhs;

    return *this;
}

template <int N>
const Mathematics::SignRational<N> Mathematics::SignRational<N>::Abs() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (GetSign() == NumericalValueSymbol::Positive)
        return *this;
    else
        return -(*this);
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::SignRational<N>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (m_Denominator.GetSign() == m_Numerator.GetSign())
        return NumericalValueSymbol::Positive;
    else
        return NumericalValueSymbol::Negative;
}

template <int N>
template <typename T>
T Mathematics::SignRational<N>::ConvertTo() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    RationalConversion<N, T> rationalConversion{ *this };

    return rationalConversion.GetValue();
}

template <int N>
const Mathematics::SignRational<N> Mathematics::operator-(const Integer<N>& integer, const SignRational<N>& rational)
{
    return SignRational<N>{ integer } - rational;
}

template <int N>
const Mathematics::SignRational<N> Mathematics::operator/(const Integer<N>& integer, const SignRational<N>& rational)
{
    return SignRational<N>{ integer } / rational;
}

template <int N>
bool Mathematics::operator==(const SignRational<N>& lhs, const SignRational<N>& rhs)
{
    return lhs.GetNumerator() * rhs.GetDenominator() == lhs.GetDenominator() * rhs.GetNumerator();
}

template <int N>
bool Mathematics::operator<(const SignRational<N>& lhs, const SignRational<N>& rhs)
{
    auto product0 = lhs.GetNumerator() * rhs.GetDenominator();
    auto product1 = lhs.GetDenominator() * rhs.GetNumerator();
    if (Integer<N>{ 0 } < lhs.GetDenominator())
    {
        return (Integer<N>{ 0 } < rhs.GetDenominator() ? product0 < product1 : product1 < product0);
    }
    else
    {
        return (Integer<N>{ 0 } < rhs.GetDenominator() ? product1 < product0 : product0 < product1);
    }
}

template <int N>
std::ostream& Mathematics::operator<<(std::ostream& os, const SignRational<N>& rational)
{
    os << "numerator = " << rational.GetNumerator() << " denominator = " << rational.GetDenominator();

    return os;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_DETAIL_H

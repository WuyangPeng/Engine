///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 16:40)

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

template <int N>
Mathematics::SignRational<N>::SignRational() noexcept
    : numerator{}, denominator{ Integer::CreateOne() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
Mathematics::SignRational<N>::SignRational(const Integer& numerator) noexcept
    : numerator{ numerator }, denominator{ Integer::CreateOne() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
Mathematics::SignRational<N>::SignRational(const Integer& numerator, const Integer& denominator)
    : numerator{ numerator }, denominator{ denominator }
{
    EliminatePowersOfTwo();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
template <typename T>
Mathematics::SignRational<N>::SignRational(T numerator)
    : numerator{ 0 }, denominator{ 1 }
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
        numerator = convert.GetNumerator<N>();
        denominator = convert.GetDenominator<N>();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

template <int N>
template <typename T>
Mathematics::SignRational<N>::SignRational(T numerator, T denominator)
    : numerator{ numerator }, denominator{ denominator }
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    EliminatePowersOfTwo();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N>
bool Mathematics::SignRational<N>::IsValid() const noexcept
{
    if (denominator.IsZero())
        return false;
    else
        return true;
}

#endif  // OPEN_CLASS_INVARIANT

// private
template <int N>
void Mathematics::SignRational<N>::EliminatePowersOfTwo()
{
    if (numerator == Integer{ 0 })
    {
        // 分子是零。
        denominator = Integer{ 1 };

        return;
    }

    const auto shift = GetPowers();

    if (0 < shift)
    {
        numerator >>= shift;
        denominator >>= shift;
    }
}

// private
template <int N>
int Mathematics::SignRational<N>::GetPowers() const
{
    auto numeratorAbsoluteValue = numerator.GetAbsoluteValue();
    auto denominatorAbsoluteValue = denominator.GetAbsoluteValue();

    if (0 < (numeratorAbsoluteValue[0] & 1) || 0 < (denominatorAbsoluteValue[0] & 1))
    {
        // 没有一个项能被2整除（快速退出）
        return 0;
    }

    const auto blockNumerator = numeratorAbsoluteValue.GetTrailingBlock();
    const auto blockDenominator = denominatorAbsoluteValue.GetTrailingBlock();

    MATHEMATICS_ASSERTION_0(0 <= blockDenominator, "分母必须不为零！\n");

    const auto minBlock = (blockNumerator < blockDenominator ? blockNumerator : blockDenominator);

    const auto bitNumerator = numeratorAbsoluteValue.GetTrailingBit(blockNumerator);
    const auto bitDenominator = denominatorAbsoluteValue.GetTrailingBit(blockDenominator);

    const auto minBit = (bitNumerator < bitDenominator ? bitNumerator : bitDenominator);
    const auto shift = 16 * minBlock + minBit;

    return shift;
}

template <int N>
typename Mathematics::SignRational<N>::Integer Mathematics::SignRational<N>::GetNumerator() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numerator;
}

template <int N>
typename Mathematics::SignRational<N>::Integer Mathematics::SignRational<N>::GetDenominator() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return denominator;
}

template <int N>
void Mathematics::SignRational<N>::Set(const Integer& newNumerator, const Integer& newDenominator)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator = newNumerator;
    denominator = newDenominator;

    EliminatePowersOfTwo();
}

template <int N>
Mathematics::SignRational<N> Mathematics::SignRational<N>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return SignRational{ -numerator, denominator };
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator+=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    denominator *= rhs.denominator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator-=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    denominator *= rhs.denominator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator*=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator *= rhs.numerator;
    denominator *= rhs.denominator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator/=(const SignRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator *= rhs.denominator;
    denominator *= rhs.numerator;

    EliminatePowersOfTwo();

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator+=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator += rhs * denominator;

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator-=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator -= rhs * denominator;

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator*=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    numerator *= rhs;

    return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>::operator/=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    denominator *= rhs;

    return *this;
}

template <int N>
Mathematics::SignRational<N> Mathematics::SignRational<N>::Abs() const
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

    if (denominator.GetSign() == numerator.GetSign())
        return NumericalValueSymbol::Positive;
    else
        return NumericalValueSymbol::Negative;
}

template <int N>
template <typename T>
T Mathematics::SignRational<N>::ConvertTo() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const RationalConversion<N, T> rationalConversion{ *this };

    return rationalConversion.GetValue();
}

template <int N>
Mathematics::SignRational<N> Mathematics::operator-(const Integer<N>& integer, const SignRational<N>& rational)
{
    return SignRational<N>{ integer } - rational;
}

template <int N>
Mathematics::SignRational<N> Mathematics::operator/(const Integer<N>& integer, const SignRational<N>& rational)
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
    const auto product0 = lhs.GetNumerator() * rhs.GetDenominator();
    const auto product1 = lhs.GetDenominator() * rhs.GetNumerator();
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

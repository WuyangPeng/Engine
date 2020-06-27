// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 10:21)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_DETAIL_H

#include "SignRational.h"
#include "IntegerDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "ConversionRationalDetail.h"
#include "RationalConversionDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

template <int N>
Mathematics::SignRational<N>
	::SignRational()
	:m_Numerator{}, m_Denominator{ 1 }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
Mathematics::SignRational<N>
	::SignRational(const Integer& numerator)
	:m_Numerator{ numerator }, m_Denominator{ 1 }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
Mathematics::SignRational<N>
	::SignRational(const Integer& numerator, const Integer& denominator)
	:m_Numerator{ numerator }, m_Denominator{ denominator }
{
	EliminatePowersOfTwo();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
template<typename T>
Mathematics::SignRational<N>
	::SignRational(T numerator)
	:m_Numerator{ 0 }, m_Denominator{ 1 }
{
	ConvertToRational(numerator);

	EliminatePowersOfTwo();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
template<typename T>
void Mathematics::SignRational<N>
	::ConvertToRational(T value)
{
	ConversionRational<T> convert{ value };

	if (convert.IsCanConversion<N>())
	{
		m_Numerator = convert.GetNumerator<N>();
		m_Denominator = convert.GetDenominator<N>();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"));
	}
}

template <int N>
template<typename T>
Mathematics::SignRational<N>
	::SignRational(T numerator, T denominator)
	:m_Numerator{ numerator }, m_Denominator{ denominator }
{
	static_assert(std::is_integral_v<T>, "T isn't integral.");

	EliminatePowersOfTwo();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::SignRational<N>
	::IsValid() const noexcept
{
	if (m_Denominator.IsZero())
		return false;
	else
		return true;
}
#endif // OPEN_CLASS_INVARIANT

// private
template <int N>
void Mathematics::SignRational<N>
	::EliminatePowersOfTwo()
{
	if (m_Numerator == Integer{ 0 })
	{
		// 分子是零。
		m_Denominator = Integer{ 1 };

		return;
	}

	auto shift = GetPowers();

	if (0 < shift)
	{
		m_Numerator >>= shift;
		m_Denominator >>= shift;
	}
}

// private
template <int N>
int Mathematics::SignRational<N>
	::GetPowers() const
{
	auto numerator = m_Numerator.GetAbsoluteValue();
	auto denominator = m_Denominator.GetAbsoluteValue();

	if (0 < (numerator[0] & 1) || 0 < (denominator[0] & 1))
	{
		// 没有一个项能被2整除（快速退出）
		return 0;
	}

	auto blockNumerator = numerator.GetTrailingBlock();
	auto blockDenominator = denominator.GetTrailingBlock();

	MATHEMATICS_ASSERTION_0(0 <= blockDenominator, "分母必须不为零！\n");

	auto minBlock = (blockNumerator < blockDenominator ? blockNumerator : blockDenominator);

	auto bitNumerator = numerator.GetTrailingBit(blockNumerator);
	auto bitDenominator = denominator.GetTrailingBit(blockDenominator);

	auto minBit = (bitNumerator < bitDenominator ? bitNumerator : bitDenominator);
	auto shift = 16 * minBlock + minBit;

	return shift;
}

template <int N>
typename const Mathematics::SignRational<N>::Integer Mathematics::SignRational<N>
	::GetNumerator() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Numerator;
}

template <int N>
typename const Mathematics::SignRational<N>::Integer Mathematics::SignRational<N>
	::GetDenominator() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Denominator;
}

template <int N>
void Mathematics::SignRational<N>
	::Set(const Integer& numerator, const Integer& denominator)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator = numerator;
	m_Denominator = denominator;

	EliminatePowersOfTwo();
}

template <int N>
const Mathematics::SignRational<N> Mathematics::SignRational<N>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return SignRational{ -m_Numerator,m_Denominator };
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator+=(const SignRational& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator = m_Numerator * rhs.m_Denominator + m_Denominator * rhs.m_Numerator;
	m_Denominator *= rhs.m_Denominator;

	EliminatePowersOfTwo();

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator-=(const SignRational& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator = m_Numerator * rhs.m_Denominator - m_Denominator * rhs.m_Numerator;
	m_Denominator *= rhs.m_Denominator;

	EliminatePowersOfTwo();

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator*=(const SignRational& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator *= rhs.m_Numerator;
	m_Denominator *= rhs.m_Denominator;

	EliminatePowersOfTwo();

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator/=(const SignRational& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator *= rhs.m_Denominator;
	m_Denominator *= rhs.m_Numerator;

	EliminatePowersOfTwo();

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator+=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator += rhs * m_Denominator;

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator-=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator -= rhs * m_Denominator;

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator*=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Numerator *= rhs;

	return *this;
}

template <int N>
Mathematics::SignRational<N>& Mathematics::SignRational<N>
	::operator/=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Denominator *= rhs;

	return *this;
}

template <int N>
const Mathematics::SignRational<N> Mathematics::SignRational<N>
	::Abs() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (GetSign() == NumericalValueSymbol::Positive)
		return *this;
	else
		return -(*this);
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::SignRational<N>
	::GetSign() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (m_Denominator.GetSign() == m_Numerator.GetSign())
		return NumericalValueSymbol::Positive;
	else
		return NumericalValueSymbol::Negative;
}

template <int N>
template<typename T>
T Mathematics::SignRational<N>
	::ConvertTo() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	RationalConversion<N, T> rationalConversion{ *this };

	return rationalConversion.GetValue();
}

template <int N>
const Mathematics::SignRational<N> Mathematics
	::operator-(const Integer<N>& integer, const SignRational<N>& rational)
{
	return SignRational<N>{ integer } -rational;
}

template <int N>
const Mathematics::SignRational<N>	Mathematics
	::operator/(const Integer<N>& integer, const SignRational<N>& rational)
{
	return SignRational<N>{ integer } / rational;
}

template <int N>
bool Mathematics
	::operator==(const SignRational<N>& lhs, const SignRational<N>& rhs)
{
	return lhs.GetNumerator() * rhs.GetDenominator() == lhs.GetDenominator() * rhs.GetNumerator();
}

template <int N>
bool Mathematics
	::operator<(const SignRational<N>& lhs, const SignRational<N>& rhs)
{
	auto firstProduct = lhs.GetNumerator() * rhs.GetDenominator();
	auto secondProduct = lhs.GetDenominator() * rhs.GetNumerator();
	if (Integer<N>{ 0 } < lhs.GetDenominator())
	{
		return (Integer<N>{ 0 } < rhs.GetDenominator() ? firstProduct < secondProduct : secondProduct < firstProduct);
	}
	else
	{
		return (Integer<N>{ 0 } < rhs.GetDenominator() ? secondProduct < firstProduct : firstProduct < secondProduct);
	}
}

template <int N>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const SignRational<N>& rational)
{
	os << "numerator = " << rational.GetNumerator() << " denominator = " << rational.GetDenominator();

	return os;
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_DETAIL_H

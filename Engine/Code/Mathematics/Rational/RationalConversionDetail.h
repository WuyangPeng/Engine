// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 13:50)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_DETAIL_H

#include "RationalConversion.h"
#include "SignRationalDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <type_traits>

template <int N, typename T>
Mathematics::RationalConversion<N, T>
	::RationalConversion(const Rational& rational)
	:m_AbsNumerator{ rational.GetNumerator().GetAbsoluteValue() }, m_AbsDenominator{ rational.GetDenominator().GetAbsoluteValue() },
	 m_Shifting{ m_AbsNumerator.IsZero()? 0 :( m_AbsNumerator.GetLeadingBit() - m_AbsDenominator.GetLeadingBit()) }, m_Symbol{ rational.GetSign() }, m_Value{}, m_Mantissa{}
{
	if (!m_AbsNumerator.IsZero())
	{
		Init(TraitsType{});
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
} 

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::Init(const SignedIntegerType&) 
{
	static_assert(std::is_integral_v<T>, "T isn't integral.");

	InitToIntegral();

	if (m_Symbol == NumericalValueSymbol::Negative)
	{
		m_Value = -m_Value;
	}
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::Init(const UnsignedIntegerType&) 
{
	static_assert(std::is_integral_v<T>, "T isn't integral.");

	InitToIntegral();
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::Init(const FloatType&)
{
	static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

	InitToFloatingPoint();
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::Init(const DoubleType&)
{
	static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

	InitToFloatingPoint();
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::InitToFloatingPoint()
{
	using IntegerType = typename TraitsType::IntegerType;
	
	CorrectWithShifting();

	if (m_Shifting <= static_cast<int>(TraitsType::g_RealExponentDifference))
	{
		CalculateMantissa();		
	}
	else
	{
		// 大于max_normal_float。
		THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"));
	}

	Negative();

	auto mantissa = boost::numeric_cast<IntegerType>(m_Mantissa);

	m_Value = *(reinterpret_cast<T*>(&mantissa));
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::CorrectWithShifting()
{
	// 有理数的形式为N/D = 2^{nbit-dbit}*(1+n)/(1+d)所示，
	// 其中n和d是在范围[0,1）。转换到N'/D' = (1+n)/(1+d)。
	if (0 < m_Shifting)
	{
		m_AbsDenominator <<= m_Shifting;
	}
	else if (m_Shifting < 0)
	{
		m_AbsNumerator <<= -m_Shifting;
	}

	// 表示(1+n)/(1+d) = 1+m，其中m在[0,1)，我们需要n >= d。
	// 如果n < d，转换为N"/D" = (2*(1+n))/(1+d) = 1+m，这是在 [0,1)。
	if (m_AbsNumerator < m_AbsDenominator)
	{
		m_AbsNumerator <<= 1;
		--m_Shifting;
	}
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::CalculateMantissa()
{
	using IntegerType = typename TraitsType::IntegerType;

	int realExponentDifference = TraitsType::g_RealExponentDifference;
	int exponentShifting = TraitsType::g_ExponentShifting;

	// -1074 double
	// -149 float
	if (-realExponentDifference - exponentShifting + 1 <= m_Shifting)
	{
		IntegerType exponent{ 0 };
		IntegerType bit{ 0 };
		IntegerType shift{ 0 };
		if (-realExponentDifference < m_Shifting)
		{
			// normal_float, 1.c * 2^{e - 127}
			exponent = m_Shifting + realExponentDifference;
			bit = 1;
			shift = 0;
		}
		else
		{
			// subnormal_float, 0.c * 2^{-126}
			exponent = 0;
			bit = 0;
			m_AbsDenominator <<= 1;
			shift = -(m_Shifting + realExponentDifference);
		}

		auto beginMask = (IntegerType(1) << (exponentShifting - 1)) >> shift;

		for (auto mask = beginMask; 0 < mask; mask >>= 1)
		{
			if (bit == 1)
			{
				m_AbsNumerator -= m_AbsDenominator;
			}
			m_AbsNumerator <<= 1;

			if (m_AbsDenominator <= m_AbsNumerator)
			{
				bit = 1;
				m_Mantissa |= mask;
			}
			else
			{
				bit = 0;
			}
		}		

		m_Mantissa = (exponent << exponentShifting) | m_Mantissa;
	}
	else
	{
		// 小于 min_subnormal_float, 截断为0。
		m_Mantissa = 0;
	}
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::Negative() 
{
	if (m_Symbol == NumericalValueSymbol::Negative)
	{
		m_Mantissa |= TraitsType::g_Symbol;
	}
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>
	::InitToIntegral()
{
	auto division = m_AbsNumerator / m_AbsDenominator;

	m_Value = division.GetValue<T>();
}
 
#ifdef OPEN_CLASS_INVARIANT
template <int N,typename T>
bool Mathematics::RationalConversion<N, T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int N, typename T>
T Mathematics::RationalConversion<N, T>
	::GetValue() const 
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_DETAIL_H





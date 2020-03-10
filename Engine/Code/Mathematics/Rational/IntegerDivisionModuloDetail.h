// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 13:26)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H

#include "IntegerDivisionModulo.h"
#include "IntegerDataDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerMultiplicationDetail.h"
#include "IntegerDivisionMultipleDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/UnusedMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <int N>
Mathematics::IntegerDivisionModulo<N>
	::IntegerDivisionModulo( const IntegerData& division,const IntegerData& modulo )
	:m_Numerator{ division }, m_Denominator{ modulo }, m_AbsNumerator{ IntegerDataAnalysis(m_Numerator).GetAbsoluteValue() },
	 m_AbsDenominator{ IntegerDataAnalysis(m_Denominator).GetAbsoluteValue() }, m_Quotient{}, m_Remainder{}
{
	if (!m_Numerator.IsZero() && !m_Denominator.IsZero())
	{	
		Calculate();
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>
	::Calculate()
{	
	// 计算中使用绝对值的分子值和分母值。	
	auto compare = IntegerData::UnsignedDataCompare(m_AbsNumerator,m_AbsDenominator);
	if (compare == NumericalValueSymbol::Negative)
	{
		// 分子 < 分母:  numerator = 0 * denominator + numerator
		m_Quotient.SetZero();
		m_Remainder = m_Numerator;		
	}
	else if (compare == NumericalValueSymbol::Zero)
	{
		// 分子 == 分母:  numerator = 1 * denominator + 0
		m_Quotient = IntegerData{ 1 };
		m_Remainder.SetZero();
	}
	else
	{
		// 分子 > 分母, 使用除法计算商和余数
		if (IntegerData{ sm_Low } < m_AbsDenominator)
		{
			DivisionMultiple();			
		}
		else
		{
			DivisionSingle();			
		}

		// 应用分子和分母的原始符号。
		if(m_Numerator.GetSign() != m_Denominator.GetSign())
		{
			IntegerDataAmend<N> integerDataAmend{ m_Quotient };
			integerDataAmend.Negative();
		}

		if(m_Numerator.GetSign() == NumericalValueSymbol::Negative)
		{
			IntegerDataAmend<N> integerDataAmend{ m_Remainder };
			integerDataAmend.Negative();			
		}		
	}	
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>
	::DivisionSingle()
{
	// 分母是单个的“位”。
	auto denominator = sm_Low & boost::numeric_cast<uint32_t>(m_AbsDenominator[0]);

	// 获取分子。
	IntegerDataAnalysis numeratorAnalysis{ m_AbsNumerator };
	auto start = numeratorAnalysis.GetLeadingBlock();

	uint32_t remainderDigit{ 0 };

	// 得到商。
	auto lastNonZero = -1;
	for (auto index = start; 0 <= index; --index)
	{
		auto highDigit = remainderDigit;
		remainderDigit = sm_Low & boost::numeric_cast<uint32_t>(m_AbsNumerator[index]);
		auto numerator = (highDigit << 16) | remainderDigit;
		auto quotient = numerator / denominator;
		remainderDigit = numerator - quotient * denominator;
		m_Quotient[index] = boost::numeric_cast<uint16_t>(quotient & sm_Low);

		if (lastNonZero == -1 && 0 < quotient)
		{
			lastNonZero = index;
		}	
	}

	MATHEMATICS_ASSERTION_1(0 <= lastNonZero, "异常的结果\n");

	// 得到余数
	if (remainderDigit & sm_High)
	{
		m_Remainder = IntegerData{ remainderDigit };
	}
	else
	{
		m_Remainder = IntegerData{ boost::numeric_cast<uint16_t>(remainderDigit) };
	}
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>
	::DivisionMultiple()
{
	IntegerDivisionMultiple<N> divisionMultiple{ m_AbsNumerator,m_AbsDenominator };

	m_Quotient = divisionMultiple.GetQuotient();
	m_Remainder = divisionMultiple.GetRemainder();

	CalculateRemainder();
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>
	::CalculateRemainder()
{
	// 余数比除数大，要继续计算
	constexpr auto maxLoop = 20;

	auto loop = 0;
	while (m_AbsDenominator <= m_Remainder)
	{
		MATHEMATICS_ASSERTION_1(loop < maxLoop, "计算量过大！");

		if (m_AbsDenominator == m_Remainder)
		{
			IntegerDataOperator<N> quotientOperator{ m_Quotient };

			quotientOperator += IntegerData{ 1 };
			m_Remainder.SetZero();
		}
		else if (m_AbsDenominator < m_Remainder)
		{
			IntegerDivisionMultiple<N> divisionMultiple{ m_Remainder, m_AbsDenominator };

			IntegerDataOperator<N> quotientOperator{ m_Quotient };

			quotientOperator += divisionMultiple.GetQuotient();
			m_Remainder = divisionMultiple.GetRemainder();
		}

		++loop;		
	}	

	SYSTEM_UNUSED_ARG(maxLoop);
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerDivisionModulo<N>
	::IsValid() const noexcept
{
	try
	{
		if (!m_Denominator.IsZero() &&
			m_AbsNumerator == IntegerDataAnalysis(m_Numerator).GetAbsoluteValue() &&
			m_AbsDenominator == IntegerDataAnalysis(m_Denominator).GetAbsoluteValue() &&
			IntegerDataAnalysis{ m_Remainder }.GetAbsoluteValue() < IntegerDataAnalysis{ m_Denominator }.GetAbsoluteValue() &&
			IsCorrect())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}	
}

template <int N>
bool Mathematics::IntegerDivisionModulo<N>
	::IsCorrect() const  
{
	IntegerMultiplication<N> multiplication{ m_Denominator , m_Quotient };
	auto correct = m_Numerator - multiplication.GetMultiplication() - m_Remainder;
 
	if(correct.IsZero())
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT


template <int N>
typename const Mathematics::IntegerDivisionModulo<N>::IntegerData
	Mathematics::IntegerDivisionModulo<N>
	::GetQuotient() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quotient;
}

template <int N>
typename const Mathematics::IntegerDivisionModulo<N>::IntegerData 
	Mathematics::IntegerDivisionModulo<N>
	::GetRemainder() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Remainder;
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H





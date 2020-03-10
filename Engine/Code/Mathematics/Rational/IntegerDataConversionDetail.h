// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 11:38)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_DETAIL_H

#include "IntegerDataConversion.h"
#include "IntegerDataDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <boost/limits.hpp>
#include <type_traits>

template <int N,typename T>
Mathematics::IntegerDataConversion<N,T>
	::IntegerDataConversion( const IntegerData& data )
	:m_AbsData{ IntegerDataAnalysis<N>(data).GetAbsoluteValue() },m_Shifting{ m_AbsData.IsZero() ? 0 : IntegerDataAnalysis<N>(m_AbsData).GetLeadingBit() },
	 m_Mantissa{ 0 },m_Symbol{ data.GetSign() }, m_Value{}
{
	if (!m_AbsData.IsZero())
	{
		Init(TraitsType{});
	}	

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
} 

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::Init( const SignedIntegerType& )
{
	static_assert(std::is_integral_v<T>, "T isn't integral.");

	if(m_Shifting <= sizeof(T) * 8 - 1)
	{	
		auto copySize = m_Shifting / 8 + 1;
		memcpy(&m_Mantissa, &m_AbsData[0], copySize);
		m_Value = boost::numeric_cast<T>(m_Mantissa);

		SignedIntegerNegative();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"));
	}	
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::Init( const UnsignedIntegerType& )
{
	static_assert(std::is_integral_v<T>, "T isn't integral.");

	if (m_Shifting <= sizeof(T) * 8 && m_Symbol == NumericalValueSymbol::Positive)
	{
		auto copySize = m_Shifting / 8 + 1;
		memcpy(&m_Mantissa, &m_AbsData[0], copySize);
		m_Value = boost::numeric_cast<T>(m_Mantissa);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"));
	}
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::Init( const FloatType& )
{
	static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

	InitToFloatingPoint();
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::Init( const DoubleType& )
{
	static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

	InitToFloatingPoint();
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::InitToFloatingPoint()
{
	static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

 	if (m_Shifting <= TraitsType::g_RealExponentDifference)
	{	
		CalculateMantissa();
		CalculateConversionValue();			
		Negative();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"));
	}
}


// private
template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>
	::CalculateConversionValue()
{	
	using IntegerType = typename TraitsType::IntegerType;

	IntegerType mantissa = (TraitsType::g_Mantissa & m_Mantissa);
	
	// 去掉mantissa的最高位
	IntegerType highest{ 1 };
	highest <<= TraitsType::g_ExponentShifting;
		  
	mantissa &= ~highest;
	
	auto exponent = ((static_cast<IntegerType>(m_Shifting) + TraitsType::g_RealExponentDifference) << TraitsType::g_ExponentShifting);
	exponent &= TraitsType::g_Exponent;
	
	auto conversion = exponent | mantissa;
		
	m_Value = *(reinterpret_cast<const T*>(&conversion));
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::CalculateMantissa()
{
	using IntegerType = typename TraitsType::IntegerType;

	auto maxMantissaBit = TraitsType::g_ExponentShifting;

	// 将m_AbsData移位到同maxMantissaBit对齐
	auto maxMantissaBitRemainder = maxMantissaBit % 16;
	auto shiftingRemainder = m_Shifting % 16;
	int difference = maxMantissaBitRemainder - shiftingRemainder;

	if (difference < 0)
		difference += 16;

	if (difference != 0)
	{
		IntegerDataOperator<N> integerDataOperator{ m_AbsData };
		integerDataOperator <<= difference;
	}

	int index = IntegerDataAnalysis<N>(m_AbsData).GetLeadingBlock();

	index -= (sizeof(IntegerType) / sizeof(uint16_t) - 1);

	memcpy(&m_Mantissa, &m_AbsData[index], sizeof(IntegerType));	
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::Negative()
{
	if (m_Symbol == NumericalValueSymbol::Negative)
	{
		m_Value = -m_Value;
	}		
}

// private
template <int N,typename T>
void Mathematics::IntegerDataConversion<N, T>
	::SignedIntegerNegative()
{
	if(m_Symbol == NumericalValueSymbol::Negative) 
	{
		if(m_Value <= std::numeric_limits<T>::max())
		{
			m_Value = -m_Value;
		}
		else
		{
			THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"));
		}		
	}
}
 
#ifdef OPEN_CLASS_INVARIANT
template <int N,typename T>
bool Mathematics::IntegerDataConversion<N,T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int N,typename T>
T Mathematics::IntegerDataConversion<N,T>
	::GetValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}
 
#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_DETAIL_H





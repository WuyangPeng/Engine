// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 11:55)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H

#include "IntegerDataOperator.h"
#include "IntegerData.h"
#include "IntegerDataAnalysisDetail.h"
#include "ConversionIntegerDetail.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerMultiplicationDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/format.hpp>

template <int N>
Mathematics::IntegerDataOperator<N>
	::IntegerDataOperator(IntegerData& master)
	:m_Master{ master }, m_Amend{ master }, m_Analysis{ master }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerDataOperator<N>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator+=(const IntegerData& rhs) 
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto symbel = m_Master.GetSign();

	uint32_t carry{ 0 };
	for (auto index = 0u; index < sm_IntSize; ++index)
	{
		auto lhsBit = m_Master[index];
		auto rhsBit = rhs[index];
		auto sum = lhsBit + rhsBit + carry;
		m_Amend.FromUnsignedInt(index, sum);
		carry = (sum & sm_Carry) ? 1 : 0;
	}

	// 测试溢出
	if (symbel == rhs.GetSign() && m_Master.GetSign() != symbel)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("IntegerData加减溢出\n"));
	}

	return *this;	
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator-=(const IntegerData& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDataAnalysis integerDataAnalysis{ rhs };
	*this += (-integerDataAnalysis);

	return *this;
}


template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator<<=( int shift )
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(0 <=  shift,"shift必须大于或等于零");

	// 16位块要移位的数目。
	auto blocks = shift / 16;
	if (sm_IntLast < blocks)
	{
		return *this;
	}

	if (0 < blocks)
	{
		int shiftLaterIndex = sm_IntLast;
		int shiftBeforeIndex = sm_IntLast - blocks;
		while(0 <= shiftBeforeIndex)
		{
			m_Master[shiftLaterIndex] = m_Master[shiftBeforeIndex];

			--shiftBeforeIndex;
			--shiftLaterIndex;
		}

		m_Amend.SetValue(0,shiftLaterIndex + 1,0);
	}

	// 遗留的位要移位的数量
	auto bits = shift % 16;
	if (0 < bits)
	{
		for (auto index = sm_IntLast; 1 <= index; --index)
		{
			auto value = m_Analysis.ToUnsignedInt(index - 1, index);
			value <<= bits;
			m_Amend.FromUnsignedInt(index, ((sm_High & value) >> 16));
		}

		auto value = m_Analysis.ToUnsignedInt(0);
		value <<= bits;
		m_Amend.FromUnsignedInt(0, (sm_Low & value));
	}

	return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator>>=( int shift )
{
	MATHEMATICS_CLASS_IS_VALID_9;	
	MATHEMATICS_ASSERTION_1(0 <=  shift,"shift必须大于或等于零");
	
	// 16位块要移位的数目。
	auto blocks = shift / 16;
	if (sm_IntLast < blocks)
	{
		return *this;
	}

	if (0 < blocks)
	{
		auto shiftLaterIndex = 0;
		auto shiftBeforeIndex = blocks;
		while(shiftBeforeIndex <= sm_IntLast)
		{
			m_Master[shiftLaterIndex] = m_Master[shiftBeforeIndex];

			++shiftBeforeIndex;
			++shiftLaterIndex;
		}

		if (m_Master.GetSign() == NumericalValueSymbol::Positive)
		{
			m_Amend.SetValue(shiftLaterIndex,sm_IntSize,0);
		}
		else
		{
			m_Amend.SetValue(shiftLaterIndex,sm_IntSize,sm_Positive);			
		}		
	}

	// 遗留的位要移位的数量
	auto bits = shift % 16;
	if (0 < bits)
	{
		for (auto i = 0; i <= sm_IntLast - 1; ++i)
		{
			auto value = m_Analysis.ToUnsignedInt(i, i + 1);
			value >>= bits;
			m_Amend.FromUnsignedInt(i, value);
		}

		auto value = m_Analysis.ToUnsignedInt(sm_IntLast);
		if (m_Master.GetSign() == NumericalValueSymbol::Negative)
		{
			value |= sm_High;  // 符号扩展
		}
		value >>= bits;
		m_Amend.FromUnsignedInt(sm_IntLast, value);
	}

	return *this;
}


template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator*=(const IntegerData& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerMultiplication<N> multiplication{ m_Master,rhs };
	
	m_Master = multiplication.GetMultiplication();

	return *this;
}


template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator/=( const IntegerData& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDivisionModulo<N> divisionModulo{ m_Master,rhs };

	m_Master = divisionModulo.GetQuotient();

	return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>
	::operator%=( const IntegerData& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDivisionModulo<N> divisionModulo{ m_Master,rhs };

	m_Master = divisionModulo.GetRemainder();

	return *this;
}

template <int N>
Mathematics::IntegerData<N> Mathematics
	::operator+(const IntegerData<N>& lhs, const IntegerData<N>& rhs) 
{
	IntegerData<N> sum{ lhs };
	IntegerDataOperator<N> dataOperator{ sum };
	dataOperator += rhs;

	return sum;
}

template <int N>
Mathematics::IntegerData<N> Mathematics
	::operator-(const IntegerData<N>& lhs, const IntegerData<N>& rhs) 
{
	IntegerData<N> sum{ lhs };
	IntegerDataOperator<N> dataOperator{ sum };
	dataOperator -= rhs;

	return sum;
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H





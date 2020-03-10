// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 11:42)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H

#include "IntegerData.h"
#include "ConversionIntegerDetail.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <boost/format.hpp>

template <int N>
Mathematics::IntegerData<N>
	::IntegerData()
{
	SetZero();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
void Mathematics::IntegerData<N>
	::SetZero()
{
	for(auto i = 0;i < sm_IntSize;++i)
	{
		m_Buffer[i] = 0;
	}
}

template <int N>
Mathematics::IntegerData<N>
	::IntegerData(const std::vector<uint16_t>& data) 
{
	SetZero();
	Init(boost::numeric_cast<int>(data.size()),&data[0]);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template <int Other>
Mathematics::IntegerData<N>
	::IntegerData( const IntegerData<Other>& rhs )
{
	SetZero();
	Init(2 * Other,&rhs[0]);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template<typename T>
Mathematics::IntegerData<N>
	::IntegerData( T value )
{
	SetZero();
	Init(value);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <int N>
template<typename T>
void Mathematics::IntegerData<N>
	::Init( T value )
{
	ConversionInteger<T> conversion{ value };

	auto beginBlock = boost::numeric_cast<uint32_t>(conversion.GetBeginBlock());
	auto mantissa = conversion.GetShiftingMantissa();
	auto mantissaSize = conversion.GetMantissaSize();
	auto copySize = conversion.GetCopySize();

	std::vector<uint16_t> data(mantissaSize);
	auto endBlock = beginBlock + (copySize + 1) / sizeof(uint16_t);

	if (beginBlock < data.size() && beginBlock < endBlock && endBlock <= data.size() && copySize <= sizeof(uint64_t) / sizeof(uint8_t))
	{	
		memcpy(&data[beginBlock], &mantissa, copySize);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("����Խ�磡"));
	}

	Init(boost::numeric_cast<int>(data.size()), &data[0]);

	auto symbol = conversion.GetSymbol();
	if (symbol == NumericalValueSymbol::Negative)
	{		
		IntegerDataAmend<N> amend{ *this };
		amend.Negative();
	}
}
 
template <int N>
bool Mathematics::IntegerData<N>
	::IsZero() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	for (auto i = 0u; i < sm_IntSize; ++i)
	{
		if (m_Buffer[i] != 0)
		{
			return false;
		}
	}

	return true;
}


template <int N>
void Mathematics::IntegerData<N>
	::Init( int count,const uint16_t* data )
{
	if(count <= sm_IntSize)
	{
		const auto sizeBytes = count * sizeof(uint16_t);

		memcpy(m_Buffer, &data[0], sizeBytes);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�����ֵ�����"));
	}	
}

template <int N>
Mathematics::IntegerData<N>
	::IntegerData( int count,const uint16_t* data )
{
	SetZero();
	Init(count,data);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::IntegerData<N>
	::IntegerData(const IntegerData& rhs)
{
	memcpy(m_Buffer, rhs.m_Buffer, sm_IntBytes);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::IntegerData<N>& Mathematics::IntegerData<N>
	::operator=(const IntegerData& rhs) 
{
	MATHEMATICS_CLASS_IS_VALID_9;

	memcpy(m_Buffer, rhs.m_Buffer, sm_IntBytes);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerData<N>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int N>
void Mathematics::IntegerData<N>
	::SwapBigEndian()
{
	 MATHEMATICS_CLASS_IS_VALID_9;

#ifdef CORE_TOOLS_BIG_ENDIAN
	 for (auto i = 0u; i <= N; ++i)
	 {
		 std::swap(m_Buffer[2 * i],m_Buffer[2 * i + 1]);
	 }
#endif // CORE_TOOLS_BIG_ENDIAN
}

template <int N>
void Mathematics::IntegerData<N>
	::SetBit(int index, bool on)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize * 16, "��������");

	auto block = index / 16;
	auto bit = index % 16;
	if (on)
	{
		m_Buffer[block] |= (1 << bit);
	}
	else
	{
		m_Buffer[block] &= ~(1 << bit);
	}
}

template <int N>
bool Mathematics::IntegerData<N>
	::GetBit( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize * 16, "��������");

	auto block = index / 16;
	auto bit = index % 16;

	return (m_Buffer[block] & (1 << bit)) != 0;
}

template <int N>
uint16_t& Mathematics::IntegerData<N>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index <= sm_IntLast,"��������");

	return m_Buffer[index];
}

template <int N>
const uint16_t& Mathematics::IntegerData<N>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index <= sm_IntLast,"��������");

	return m_Buffer[index];
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::IntegerData<N>
	::GetSign() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return (m_Buffer[sm_IntLast] & 0x8000) ? NumericalValueSymbol::Negative : NumericalValueSymbol::Positive;
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::IntegerData<N>
	::UnsignedDataCompare( const IntegerData& lhs, const IntegerData& rhs )
{
	for (int index = static_cast<int>(sm_IntLast); 0 <= index; --index)
	{
		if (lhs[index] < rhs[index])
		{
			return NumericalValueSymbol::Negative;
		}
		else if (rhs[index] < lhs[index])
		{
			return NumericalValueSymbol::Positive;
		}
	}

	return NumericalValueSymbol::Zero;
}

template <int N>
bool Mathematics
	::operator==(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
{
	return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Zero;
}

template <int N>
bool Mathematics
	::operator<( const IntegerData<N>& lhs,const IntegerData<N>& rhs )
{
	auto lhsSymbol = lhs.GetSign();
	auto rhsSymbol = rhs.GetSign();
	if (lhsSymbol == NumericalValueSymbol::Positive)
	{
		if (rhsSymbol == NumericalValueSymbol::Positive)
		{
			return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Negative;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (rhsSymbol == NumericalValueSymbol::Positive)
		{
			return true;
		}
		else
		{
			return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Negative;
		}
	}
}

template <int N>
std::ostream& Mathematics
	::operator<<( std::ostream& os,const IntegerData<N>& integerData )
{
	auto symbol = integerData.GetSign();

	if(symbol == NumericalValueSymbol::Negative)
	{	
		IntegerData<N> negativeIntegerData{ integerData };
		IntegerDataAmend<N> amend{ negativeIntegerData };
		amend.Negative();
		os << "-" << negativeIntegerData;

		return os;
	}
	else
	{
		if(!integerData.IsZero())
		{
			IntegerDataAnalysis<N> integerDataAnalysis{ integerData };

			os << integerDataAnalysis;	
		}
		else
		{
			os << "0";
		}			

		return os;
	}	
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H





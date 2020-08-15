// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 10:15)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DETAIL_H

#include "Integer.h"
#include "IntegerDivisionModuloDetail.h"
#include "IntegerDataDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerMultiplicationDetail.h"
#include "IntegerDataConversionDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26455)
template <int N>
Mathematics::Integer<N>
	::Integer()
	:m_IntegerData{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::Integer<N>
	::Integer(const std::vector<uint16_t>& data)
	:m_IntegerData{ data }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::Integer<N>
	::Integer(int count, const uint16_t* data)
	:m_IntegerData{ count,data }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template<typename T>
Mathematics::Integer<N>
	::Integer(T value)
	:m_IntegerData{ value }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template <int Other>
Mathematics::Integer<N>
	::Integer(const Integer<Other>& rhs)
	:m_IntegerData{ 2 * Other,&rhs[0] }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::Integer<N>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int N>
bool Mathematics::Integer<N>
	::IsZero() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData.IsZero();
}

template <int N>
void Mathematics::Integer<N>
	::SetZero()
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData.SetZero();
}

template <int N>
Mathematics::NumericalValueSymbol
Mathematics::Integer<N>
	::GetSign() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData.GetSign();
}

template <int N>
uint16_t& Mathematics::Integer<N>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	return m_IntegerData[index];
}

template <int N>
const uint16_t& Mathematics::Integer<N>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData[index];
}

template <int N>
const Mathematics::Integer<N> Mathematics::Integer<N>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	Integer integer;
	const IntegerDataAnalysis<N> analysis{ m_IntegerData };
	integer.m_IntegerData = -analysis;

	return integer;
}

template <int N>
const Mathematics::Integer<N> Mathematics::Integer<N>
	::GetAbsoluteValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	Integer integer;
	IntegerDataAnalysis<N> analysis{ m_IntegerData };
	integer.m_IntegerData = analysis.GetAbsoluteValue();

	return integer;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator+=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDataOperator<N> integerDataOperator{ m_IntegerData };

	integerDataOperator += rhs.m_IntegerData;

	return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator-=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	*this += (-rhs);

	return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator*=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerMultiplication<N> multiplication{ m_IntegerData,rhs.m_IntegerData };

	m_IntegerData = multiplication.GetMultiplication();

	return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator/=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDivisionModulo divisionModulo{ m_IntegerData,rhs.m_IntegerData };

	m_IntegerData = divisionModulo.GetQuotient();

	return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator%=(const Integer& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDivisionModulo divisionModulo(m_IntegerData, rhs.m_IntegerData);

	m_IntegerData = divisionModulo.GetRemainder();

	return *this;
}

template <int N>
const Mathematics::IntegerDivisionModulo<N> Mathematics::Integer<N>
	::GetDivisionModulo(const Integer& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_9;

	IntegerDivisionModulo divisionModulo{ m_IntegerData,rhs.m_IntegerData };

	return divisionModulo;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator<<=(int shift)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(0 <= shift, "shift必须大于或等于零");

	IntegerDataOperator<N> integerDataOperator{ m_IntegerData };

	integerDataOperator <<= shift;

	return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>
	::operator>>=(int shift)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(0 <= shift, "shift必须大于或等于零");

	IntegerDataOperator<N> integerDataOperator{ m_IntegerData };

	integerDataOperator >>= shift;

	return *this;
}

template <int N>
int Mathematics::Integer<N>
	::GetLeadingBit() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataAnalysis<N> analysis{ m_IntegerData };

	return analysis.GetLeadingBit();
}

template <int N>
int Mathematics::Integer<N>
	::GetTrailingBit() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataAnalysis<N> analysis{ m_IntegerData };

	return analysis.GetTrailingBit();
}

template <int N>
int Mathematics::Integer<N>
	::GetLeadingBit(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataAnalysis<N> analysis{ m_IntegerData };

	return analysis.GetLeadingBit(index);
}

template <int N>
int Mathematics::Integer<N>
	::GetTrailingBit(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataAnalysis<N> analysis{ m_IntegerData };

	return analysis.GetTrailingBit(index);
}

template <int N>
int Mathematics::Integer<N>
	::GetLeadingBlock() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataAnalysis<N> analysis{ m_IntegerData };

	return analysis.GetLeadingBlock();
}

template <int N>
int Mathematics::Integer<N>
	::GetTrailingBlock() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataAnalysis<N> analysis{ m_IntegerData };

	return analysis.GetTrailingBlock();
}

template <int N>
void Mathematics::Integer<N>
	::SetBit(int index, bool on)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_IntegerData.SetBit(index, on);
}

template <int N>
bool Mathematics::Integer<N>
	::GetBit(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData.GetBit(index);
}

template <int N>
bool Mathematics::Integer<N>
	::operator==(const Integer& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData == rhs.m_IntegerData;
}

template <int N>
bool Mathematics::Integer<N>
	::operator<(const Integer& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IntegerData < rhs.m_IntegerData;
}

template <int N>
template <typename T>
T Mathematics::Integer<N>
	::GetValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	IntegerDataConversion<N, T> conversion{ m_IntegerData };

	return conversion.GetValue();
}

template <int N>
void Mathematics::Integer<N>
	::Print(std::ostream& os) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	os << m_IntegerData;
}

template <int N>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const Integer<N>& integer)
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	integer.Print(os);

	return os;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_RATIONAL_INTEGER_DETAIL_H





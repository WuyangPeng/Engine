// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 10:09)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H

#include "IntegerDataAmend.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <int N>
Mathematics::IntegerDataAmend<N>
	::IntegerDataAmend(IntegerData& master)
	:m_Master{ master }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerDataAmend<N>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int N>
void Mathematics::IntegerDataAmend<N>
	::Negative()
{
	auto sign = m_Master.GetSign();

	// 位取反
	for (auto i = 0u; i < sm_IntSize; ++i)
	{
		m_Master[i] = ~m_Master[i];
	}

	// 加1（发生在进位和添加零到“result”）。
	uint32_t carry{ 1 };
	for (auto i = 0u; i < sm_IntSize; ++i)
	{
		auto bit = m_Master[i];
		auto sum = bit + carry;
		FromUnsignedInt(i, sum);
		carry = (sum & sm_Carry) ? 1 : 0;
	}

	if (sign == m_Master.GetSign() && !m_Master.IsZero())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Integer溢出！\n"));
	}
}

template <int N>
void Mathematics::IntegerDataAmend<N>
	::FromUnsignedInt(int index, uint32_t value)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize, "索引错误！");

	m_Master[index] = boost::numeric_cast<uint16_t>(value & sm_Low);
}

template <int N>
void Mathematics::IntegerDataAmend<N>
	::SetValue(int beginIndex, int endIndex, uint32_t value)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= beginIndex && beginIndex <= sm_IntSize, "begin索引错误！");
	MATHEMATICS_ASSERTION_0(0 <= endIndex && endIndex <= sm_IntSize, "end索引错误！");
	MATHEMATICS_ASSERTION_1(beginIndex <= endIndex, "begin索引大于end索引！");

	for (auto index = beginIndex; index < endIndex; ++index)
	{
		FromUnsignedInt(index, value);
	}
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H





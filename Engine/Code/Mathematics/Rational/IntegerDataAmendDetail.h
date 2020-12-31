///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:00)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H

#include "IntegerDataAmend.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::IntegerDataAmend<N>::IntegerDataAmend(IntegerData& master) noexcept
    : m_Master{ master }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerDataAmend<N>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int N>
void Mathematics::IntegerDataAmend<N>::Negative()
{
    const auto sign = m_Master.GetSign();

    // 位取反
    for (auto i = 0; i < sm_IntSize; ++i)
    {
        m_Master[i] = ~m_Master[i];
    }

    // 加1（发生在进位和添加零到“result”）。
    auto carry = 1u;
    for (auto i = 0; i < sm_IntSize; ++i)
    {
        const auto bit = m_Master[i];
        const auto sum = bit + carry;
        FromUnsignedInt(i, sum);
        carry = (sum & sm_Carry) ? 1 : 0;
    }

    if (sign == m_Master.GetSign() && !m_Master.IsZero())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Integer溢出！\n"s));
    }
}

template <int N>
void Mathematics::IntegerDataAmend<N>::FromUnsignedInt(int index, uint32_t value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Master[index] = boost::numeric_cast<uint16_t>(value & sm_Low);
}

template <int N>
void Mathematics::IntegerDataAmend<N>::SetValue(int beginIndex, int endIndex, uint32_t value)
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

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H

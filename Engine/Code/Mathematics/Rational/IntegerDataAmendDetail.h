/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:17)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H

#include "IntegerDataAmend.h"
#include "IntegerDataDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <int N>
Mathematics::IntegerDataAmend<N>::IntegerDataAmend(IntegerDataType& master) noexcept
    : master{ master }
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
    const auto sign = master.GetSign();

    // 位取反
    for (auto i = 0; i < intSize; ++i)
    {
        master[i] = ~master[i];
    }

    // 加1（发生在进位和添加零到“result”）。
    auto carry = 1u;
    for (auto i = 0; i < intSize; ++i)
    {
        const auto bit = master[i];
        const auto sum = bit + carry;
        FromUnsignedInt(i, sum);
        carry = (sum & integerCarry) ? 1 : 0;
    }

    if (sign == master.GetSign() && !master.IsZero())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Integer溢出！\n"s));
    }
}

template <int N>
void Mathematics::IntegerDataAmend<N>::FromUnsignedInt(int index, uint32_t value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    master[index] = boost::numeric_cast<uint16_t>(value & low);
}

template <int N>
void Mathematics::IntegerDataAmend<N>::SetValue(int beginIndex, int endIndex, uint32_t value)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= beginIndex && beginIndex <= intSize, "begin索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= endIndex && endIndex <= intSize, "end索引错误！");
    MATHEMATICS_ASSERTION_1(beginIndex <= endIndex, "begin索引大于end索引！");

    for (auto index = beginIndex; index < endIndex; ++index)
    {
        FromUnsignedInt(index, value);
    }
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_DETAIL_H

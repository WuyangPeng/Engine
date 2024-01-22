/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:17)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_DETAIL_H

#include "IntegerData.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysis.h"
#include "IntegerDivisionModuloDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iomanip>
#include <iostream>

template <int N>
Mathematics::IntegerDataAnalysis<N>::IntegerDataAnalysis(const IntegerData& master) noexcept
    : master{ master }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N>
bool Mathematics::IntegerDataAnalysis<N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
Mathematics::IntegerData<N> Mathematics::IntegerDataAnalysis<N>::GetAbsoluteValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = master.GetSign();

    if (symbol == NumericalValueSymbol::Negative)
    {
        return -(*this);
    }
    else
    {
        return master;
    }
}

template <int N>
Mathematics::IntegerData<N> Mathematics::IntegerDataAnalysis<N>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    IntegerData result{ master };
    IntegerDataAmend<N> integerDataAmend{ result };

    integerDataAmend.Negative();

    return result;
}

template <int N>
uint32_t Mathematics::IntegerDataAnalysis<N>::ToUnsignedInt(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return low & boost::numeric_cast<uint32_t>(master[index]);
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::ToInt(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(ToUnsignedInt(index));
}

template <int N>
uint32_t Mathematics::IntegerDataAnalysis<N>::ToUnsignedInt(int lowerIndex, int highIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto lower = ToUnsignedInt(lowerIndex);
    const auto high = ToUnsignedInt(highIndex);

    return (lower | (high << 16));
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetLeadingBlock() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto index = intLast; 0 <= index; --index)
    {
        if (master[index] != 0)
        {
            return index;
        }
    }

    MATHEMATICS_ASSERTION_0(false, "工具函数GetLeadingBlock，值为零！");

    return -1;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetTrailingBlock() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto index = 0; index < intSize; ++index)
    {
        if (master[index] != 0)
        {
            return index;
        }
    }

    MATHEMATICS_ASSERTION_0(false, "工具函数GetTrailingBlock，值为零！");

    return -1;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetLeadingBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < intSize, "输入超出范围！\n");

    // 这是一个二进制搜索m_Buffer[i]的高阶位。
    // 返回值是该索引中的位（0 <= index < 16）。
    auto leadingBit = 0;
    auto valueCopy = master[index];

    MATHEMATICS_ASSERTION_0(valueCopy != 0, "工具函数GetLeadingBit，值为零！");

    for (auto maskIndex = 0; maskIndex < maskSize; ++maskIndex)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        if ((valueCopy & leadingMask[maskIndex]) != 0)
        {
            leadingBit |= (1 << (maskSize - maskIndex - 1));
            valueCopy &= leadingMask[maskIndex];
        }

#include SYSTEM_WARNING_POP
    }

    return leadingBit;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetTrailingBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < intSize, "输入超出范围！\n");

    // 这是一个二进制搜索m_Buffer[i]的低阶位。
    // 返回值是该索引中的位（0 <= index < 16）。
    auto trailingBit = 0x000F;
    auto valueCopy = master[index];

    MATHEMATICS_ASSERTION_0(valueCopy != 0, "工具函数GetTrailingBit，值为零！");

    for (auto maskIndex = 0; maskIndex < maskSize; ++maskIndex)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        if ((valueCopy & trailingMask[maskIndex]) != 0)
        {
            trailingBit &= (~(1 << (maskSize - maskIndex - 1)));
            valueCopy &= trailingMask[maskIndex];
        }

#include SYSTEM_WARNING_POP
    }

    return trailingBit;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetLeadingBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (const auto block = GetLeadingBlock();
        0 <= block)
    {
        if (const auto bit = GetLeadingBit(block);
            0 <= bit)
        {
            return bit + 16 * block;
        }
    }

    return -1;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetTrailingBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (const auto block = GetTrailingBlock();
        0 <= block)
    {
        if (const auto bit = GetTrailingBit(block);
            0 <= bit)
        {
            return bit + 16 * block;
        }
    }

    return -1;
}

template <int N>
Mathematics::IntegerDivisionModulo<N> Mathematics::IntegerDataAnalysis<N>::GetDivisionModulo(const IntegerData& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    IntegerDivisionModulo<N> divisionModulo{ master, rhs };

    return divisionModulo;
}

template <int N>
std::ostream& Mathematics::operator<<(std::ostream& os, const IntegerDataAnalysis<N>& integerDataAnalysis)
{
    const auto leadingBlock = integerDataAnalysis.GetLeadingBlock();

    for (auto index = leadingBlock; 0 <= index; --index)
    {
        if (leadingBlock != index)
        {
            os << std::setw(4);
        }

        os << std::hex << std::setfill('0') << integerDataAnalysis.ToUnsignedInt(index);
    }

    return os;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_DETAIL_H

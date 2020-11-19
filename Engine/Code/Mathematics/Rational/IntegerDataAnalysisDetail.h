///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:10)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_DETAIL_H

#include "IntegerData.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysis.h"
#include "IntegerDivisionModuloDetail.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iomanip>
#include <iostream>

template <int N>
Mathematics::IntegerDataAnalysis<N>::IntegerDataAnalysis(const IntegerData& master) noexcept
    : m_Master{ master }
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
const Mathematics::IntegerData<N> Mathematics::IntegerDataAnalysis<N>::GetAbsoluteValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto symbol = m_Master.GetSign();

    if (symbol == NumericalValueSymbol::Negative)
    {
        return -(*this);
    }
    else
    {
        return m_Master;
    }
}

template <int N>
const Mathematics::IntegerData<N> Mathematics::IntegerDataAnalysis<N>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    IntegerData result{ m_Master };
    IntegerDataAmend<N> integerDataAmend{ result };

    integerDataAmend.Negative();

    return result;
}

template <int N>
uint32_t Mathematics::IntegerDataAnalysis<N>::ToUnsignedInt(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize, "索引错误！");

    return sm_Low & boost::numeric_cast<uint32_t>(m_Master[index]);
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::ToInt(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize, "索引错误！");

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

    for (auto index = sm_IntLast; 0 <= index; --index)
    {
        if (m_Master[index] != 0)
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

    for (auto index = 0; index < sm_IntSize; ++index)
    {
        if (m_Master[index] != 0)
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
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize, "输入超出范围！\n");

    // 这是一个二进制搜索m_Buffer[i]的高阶位。
    // 返回值是该索引中的位（0 <= index < 16）。
    auto leadingBit = 0;
    auto valueCopy = m_Master[index];

    MATHEMATICS_ASSERTION_0(valueCopy != 0, "工具函数GetLeadingBit，值为零！");

    for (auto maskIndex = 0; maskIndex < sm_MaskSize; ++maskIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        if ((valueCopy & sm_LeadingMask[maskIndex]) != 0)
        {
            leadingBit |= (1 << (sm_MaskSize - maskIndex - 1));
            valueCopy &= sm_LeadingMask[maskIndex];
        }
#include STSTEM_WARNING_POP
    }

    return leadingBit;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetTrailingBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize, "输入超出范围！\n");

    // 这是一个二进制搜索m_Buffer[i]的低阶位。
    // 返回值是该索引中的位（0 <= index < 16）。
    auto trailingBit = 0x000F;
    auto valueCopy = m_Master[index];

    MATHEMATICS_ASSERTION_0(valueCopy != 0, "工具函数GetTrailingBit，值为零！");

    for (auto maskIndex = 0; maskIndex < sm_MaskSize; ++maskIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        if ((valueCopy & sm_TrailingMask[maskIndex]) != 0)
        {
            trailingBit &= (~(1 << (sm_MaskSize - maskIndex - 1)));
            valueCopy &= sm_TrailingMask[maskIndex];
        }
#include STSTEM_WARNING_POP
    }

    return trailingBit;
}

template <int N>
int Mathematics::IntegerDataAnalysis<N>::GetLeadingBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto block = GetLeadingBlock();
    if (0 <= block)
    {
        const auto bit = GetLeadingBit(block);
        if (0 <= bit)
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

    const auto block = GetTrailingBlock();
    if (0 <= block)
    {
        const auto bit = GetTrailingBit(block);
        if (0 <= bit)
        {
            return bit + 16 * block;
        }
    }

    return -1;
}

template <int N>
const Mathematics::IntegerDivisionModulo<N> Mathematics::IntegerDataAnalysis<N>::GetDivisionModulo(const IntegerData& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    IntegerDivisionModulo<N> divisionModulo{ m_Master, rhs };

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

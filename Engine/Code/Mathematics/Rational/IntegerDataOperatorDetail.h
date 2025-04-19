/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:18)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H

#include "ConversionIntegerDetail.h"
#include "IntegerData.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataOperator.h"
#include "IntegerMultiplicationDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <int N>
Mathematics::IntegerDataOperator<N>::IntegerDataOperator(IntegerDataType& master) noexcept
    : master{ master }, amend{ master }, analysis{ master }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N>
bool Mathematics::IntegerDataOperator<N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator+=(const IntegerDataType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto sign = master.GetSign();

    auto result = 0u;
    for (auto index = 0; index < intSize; ++index)
    {
        const auto lhsBit = master[index];
        const auto rhsBit = rhs[index];
        const auto sum = lhsBit + rhsBit + result;
        amend.FromUnsignedInt(index, sum);
        result = (sum & carry) ? 1 : 0;
    }

    // 测试溢出
    if (sign == rhs.GetSign() && master.GetSign() != sign)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("IntegerData加减溢出\n"s));
    }

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator-=(const IntegerDataType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDataAnalysisType integerDataAnalysis{ rhs };
    *this += (-integerDataAnalysis);

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator<<=(int shift)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(0 <= shift, "shift必须大于或等于零");

    // 16位块要移位的数目。
    const auto blocks = shift / 16;
    if (intLast < blocks)
    {
        return *this;
    }

    if (0 < blocks)
    {
        auto shiftLaterIndex = boost::numeric_cast<int>(intLast);
        auto shiftBeforeIndex = boost::numeric_cast<int>(intLast - blocks);
        while (0 <= shiftBeforeIndex)
        {
            master[shiftLaterIndex] = master[shiftBeforeIndex];

            --shiftBeforeIndex;
            --shiftLaterIndex;
        }

        amend.SetValue(0, shiftLaterIndex + 1, 0);
    }

    // 遗留的位要移位的数量
    const auto bits = shift % 16;
    if (0 < bits)
    {
        for (auto index = intLast; 1 <= index; --index)
        {
            auto value = analysis.ToUnsignedInt(index - 1, index);
            value <<= bits;
            amend.FromUnsignedInt(index, ((high & value) >> 16));
        }

        auto value = analysis.ToUnsignedInt(0);
        value <<= bits;
        amend.FromUnsignedInt(0, (low & value));
    }

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator>>=(int shift)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(0 <= shift, "shift必须大于或等于零");

    // 16位块要移位的数目。
    const auto blocks = shift / 16;
    if (intLast < blocks)
    {
        return *this;
    }

    if (0 < blocks)
    {
        auto shiftLaterIndex = 0;
        auto shiftBeforeIndex = blocks;
        while (shiftBeforeIndex <= intLast)
        {
            master[shiftLaterIndex] = master[shiftBeforeIndex];

            ++shiftBeforeIndex;
            ++shiftLaterIndex;
        }

        if (master.GetSign() == NumericalValueSymbol::Positive)
        {
            amend.SetValue(shiftLaterIndex, intSize, 0);
        }
        else
        {
            amend.SetValue(shiftLaterIndex, intSize, positive);
        }
    }

    // 遗留的位要移位的数量
    const auto bits = shift % 16;
    if (0 < bits)
    {
        for (auto i = 0; i <= intLast - 1; ++i)
        {
            auto value = analysis.ToUnsignedInt(i, i + 1);
            value >>= bits;
            amend.FromUnsignedInt(i, value);
        }

        auto value = analysis.ToUnsignedInt(intLast);
        if (master.GetSign() == NumericalValueSymbol::Negative)
        {
            value |= high;  // 符号扩展
        }
        value >>= bits;
        amend.FromUnsignedInt(intLast, value);
    }

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator*=(const IntegerDataType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    IntegerMultiplication<N> multiplication{ master, rhs };

    master = multiplication.GetMultiplication();

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator/=(const IntegerDataType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDivisionModulo<N> divisionModulo{ master, rhs };

    master = divisionModulo.GetQuotient();

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator%=(const IntegerDataType& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDivisionModulo<N> divisionModulo{ master, rhs };

    master = divisionModulo.GetRemainder();

    return *this;
}

template <int N>
Mathematics::IntegerData<N> Mathematics::operator+(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
{
    IntegerData<N> sum{ lhs };
    IntegerDataOperator<N> dataOperator{ sum };
    dataOperator += rhs;

    return sum;
}

template <int N>
Mathematics::IntegerData<N> Mathematics::operator-(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
{
    IntegerData<N> sum{ lhs };
    IntegerDataOperator<N> dataOperator{ sum };
    dataOperator -= rhs;

    return sum;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H

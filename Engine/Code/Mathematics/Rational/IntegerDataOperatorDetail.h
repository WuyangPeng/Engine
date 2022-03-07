///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/11 15:19)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_DETAIL_H

#include "ConversionIntegerDetail.h"
#include "IntegerData.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataOperator.h"
#include "IntegerMultiplicationDetail.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::IntegerDataOperator<N>::IntegerDataOperator(IntegerData& master) noexcept
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
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator+=(const IntegerData& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto symbel = master.GetSign();

    auto result = 0u;
    for (auto index = 0; index < intSize; ++index)
    {
        const auto lhsBit = master[index];
        const auto rhsBit = rhs[index];
        const auto sum = lhsBit + rhsBit + result;
        amend.FromUnsignedInt(index, sum);
        result = (sum & carry) ? 1 : 0;
    }

    // �������
    if (symbel == rhs.GetSign() && master.GetSign() != symbel)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("IntegerData�Ӽ����\n"s));
    }

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator-=(const IntegerData& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDataAnalysis integerDataAnalysis{ rhs };
    *this += (-integerDataAnalysis);

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator<<=(int shift)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(0 <= shift, "shift������ڻ������");

    // 16λ��Ҫ��λ����Ŀ��
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

    // ������λҪ��λ������
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
    MATHEMATICS_ASSERTION_1(0 <= shift, "shift������ڻ������");

    // 16λ��Ҫ��λ����Ŀ��
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

    // ������λҪ��λ������
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
            value |= high;  // ������չ
        }
        value >>= bits;
        amend.FromUnsignedInt(intLast, value);
    }

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator*=(const IntegerData& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    IntegerMultiplication<N> multiplication{ master, rhs };

    master = multiplication.GetMultiplication();

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator/=(const IntegerData& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDivisionModulo<N> divisionModulo{ master, rhs };

    master = divisionModulo.GetQuotient();

    return *this;
}

template <int N>
Mathematics::IntegerDataOperator<N>& Mathematics::IntegerDataOperator<N>::operator%=(const IntegerData& rhs)
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

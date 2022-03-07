///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/11 15:36)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H

#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerDivisionModulo.h"
#include "IntegerDivisionMultipleDetail.h"
#include "IntegerMultiplicationDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::IntegerDivisionModulo<N>::IntegerDivisionModulo(const IntegerData& division, const IntegerData& modulo)
    : numerator{ division },
      denominator{ modulo },
      absNumerator{ IntegerDataAnalysis(numerator).GetAbsoluteValue() },
      absDenominator{ IntegerDataAnalysis(denominator).GetAbsoluteValue() },
      quotient{},
      remainder{}
{
    if (!numerator.IsZero() && !denominator.IsZero())
    {
        Calculate();
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::Calculate()
{
    // ������ʹ�þ���ֵ�ķ���ֵ�ͷ�ĸֵ��
    const auto compare = IntegerData::UnsignedDataCompare(absNumerator, absDenominator);
    if (compare == NumericalValueSymbol::Negative)
    {
        // ���� < ��ĸ:  numerator = 0 * denominator + numerator
        quotient.SetZero();
        remainder = numerator;
    }
    else if (compare == NumericalValueSymbol::Zero)
    {
        // ���� == ��ĸ:  numerator = 1 * denominator + 0
        quotient = IntegerData{ 1 };
        remainder.SetZero();
    }
    else
    {
        // ���� > ��ĸ, ʹ�ó��������̺�����
        if (IntegerData{ low } < absDenominator)
        {
            DivisionMultiple();
        }
        else
        {
            DivisionSingle();
        }

        // Ӧ�÷��Ӻͷ�ĸ��ԭʼ���š�
        if (numerator.GetSign() != denominator.GetSign())
        {
            IntegerDataAmend<N> integerDataAmend{ quotient };
            integerDataAmend.Negative();
        }

        if (numerator.GetSign() == NumericalValueSymbol::Negative)
        {
            IntegerDataAmend<N> integerDataAmend{ remainder };
            integerDataAmend.Negative();
        }
    }
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::DivisionSingle()
{
    // ��ĸ�ǵ����ġ�λ����
    const auto lowDenominator = low & boost::numeric_cast<uint32_t>(absDenominator[0]);

    // ��ȡ���ӡ�
    const IntegerDataAnalysis numeratorAnalysis{ absNumerator };
    const auto start = numeratorAnalysis.GetLeadingBlock();

    auto remainderDigit = 0u;

    // �õ��̡�
    auto lastNonZero = -1;
    for (auto index = start; 0 <= index; --index)
    {
        const auto highDigit = remainderDigit;
        remainderDigit = low & boost::numeric_cast<uint32_t>(absNumerator[index]);
        const auto numeratorValue = (highDigit << 16) | remainderDigit;
        const auto quotientValue = numeratorValue / lowDenominator;
        remainderDigit = numeratorValue - quotientValue * lowDenominator;
        quotient[index] = boost::numeric_cast<uint16_t>(quotientValue & low);

        if (lastNonZero == -1 && 0 < quotientValue)
        {
            lastNonZero = index;
        }
    }

    MATHEMATICS_ASSERTION_1(0 <= lastNonZero, "�쳣�Ľ��\n");

    // �õ�����
    if (remainderDigit & high)
    {
        remainder = IntegerData{ remainderDigit };
    }
    else
    {
        remainder = IntegerData{ boost::numeric_cast<uint16_t>(remainderDigit) };
    }
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::DivisionMultiple()
{
    const IntegerDivisionMultiple<N> divisionMultiple{ absNumerator, absDenominator };

    quotient = divisionMultiple.GetQuotient();
    remainder = divisionMultiple.GetRemainder();

    CalculateRemainder();
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::CalculateRemainder()
{
    // �����ȳ�����Ҫ��������
    constexpr auto maxLoop = 20;

    auto loop = 0;
    while (absDenominator <= remainder)
    {
        MATHEMATICS_ASSERTION_1(loop < maxLoop, "����������");

        if (absDenominator == remainder)
        {
            IntegerDataOperator<N> quotientOperator{ quotient };

            quotientOperator += IntegerData{ 1 };
            remainder.SetZero();
        }
        else if (absDenominator < remainder)
        {
            const IntegerDivisionMultiple<N> divisionMultiple{ remainder, absDenominator };

            IntegerDataOperator<N> quotientOperator{ quotient };

            quotientOperator += divisionMultiple.GetQuotient();
            remainder = divisionMultiple.GetRemainder();
        }

        ++loop;
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerDivisionModulo<N>::IsValid() const noexcept
{
    try
    {
        if (!denominator.IsZero() &&
            absNumerator == IntegerDataAnalysis(numerator).GetAbsoluteValue() &&
            absDenominator == IntegerDataAnalysis(denominator).GetAbsoluteValue() &&
            IntegerDataAnalysis{ remainder }.GetAbsoluteValue() < IntegerDataAnalysis{ denominator }.GetAbsoluteValue() &&
            IsCorrect())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

template <int N>
bool Mathematics::IntegerDivisionModulo<N>::IsCorrect() const
{
    IntegerMultiplication<N> multiplication{ denominator, quotient };
    const auto correct = numerator - multiplication.GetMultiplication() - remainder;

    if (correct.IsZero())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
typename Mathematics::IntegerDivisionModulo<N>::IntegerData Mathematics::IntegerDivisionModulo<N>::GetQuotient() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quotient;
}

template <int N>
typename Mathematics::IntegerDivisionModulo<N>::IntegerData Mathematics::IntegerDivisionModulo<N>::GetRemainder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return remainder;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H

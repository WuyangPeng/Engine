///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:20)

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
    : m_Numerator{ division },
      m_Denominator{ modulo },
      m_AbsNumerator{ IntegerDataAnalysis(m_Numerator).GetAbsoluteValue() },
      m_AbsDenominator{ IntegerDataAnalysis(m_Denominator).GetAbsoluteValue() },
      m_Quotient{},
      m_Remainder{}
{
    if (!m_Numerator.IsZero() && !m_Denominator.IsZero())
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
    const auto compare = IntegerData::UnsignedDataCompare(m_AbsNumerator, m_AbsDenominator);
    if (compare == NumericalValueSymbol::Negative)
    {
        // ���� < ��ĸ:  numerator = 0 * denominator + numerator
        m_Quotient.SetZero();
        m_Remainder = m_Numerator;
    }
    else if (compare == NumericalValueSymbol::Zero)
    {
        // ���� == ��ĸ:  numerator = 1 * denominator + 0
        m_Quotient = IntegerData{ 1 };
        m_Remainder.SetZero();
    }
    else
    {
        // ���� > ��ĸ, ʹ�ó��������̺�����
        if (IntegerData{ sm_Low } < m_AbsDenominator)
        {
            DivisionMultiple();
        }
        else
        {
            DivisionSingle();
        }

        // Ӧ�÷��Ӻͷ�ĸ��ԭʼ���š�
        if (m_Numerator.GetSign() != m_Denominator.GetSign())
        {
            IntegerDataAmend<N> integerDataAmend{ m_Quotient };
            integerDataAmend.Negative();
        }

        if (m_Numerator.GetSign() == NumericalValueSymbol::Negative)
        {
            IntegerDataAmend<N> integerDataAmend{ m_Remainder };
            integerDataAmend.Negative();
        }
    }
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::DivisionSingle()
{
    // ��ĸ�ǵ����ġ�λ����
    const auto denominator = sm_Low & boost::numeric_cast<uint32_t>(m_AbsDenominator[0]);

    // ��ȡ���ӡ�
    const IntegerDataAnalysis numeratorAnalysis{ m_AbsNumerator };
    const auto start = numeratorAnalysis.GetLeadingBlock();

    auto remainderDigit = 0u;

    // �õ��̡�
    auto lastNonZero = -1;
    for (auto index = start; 0 <= index; --index)
    {
        const auto highDigit = remainderDigit;
        remainderDigit = sm_Low & boost::numeric_cast<uint32_t>(m_AbsNumerator[index]);
        const auto numerator = (highDigit << 16) | remainderDigit;
        const auto quotient = numerator / denominator;
        remainderDigit = numerator - quotient * denominator;
        m_Quotient[index] = boost::numeric_cast<uint16_t>(quotient & sm_Low);

        if (lastNonZero == -1 && 0 < quotient)
        {
            lastNonZero = index;
        }
    }

    MATHEMATICS_ASSERTION_1(0 <= lastNonZero, "�쳣�Ľ��\n");

    // �õ�����
    if (remainderDigit & sm_High)
    {
        m_Remainder = IntegerData{ remainderDigit };
    }
    else
    {
        m_Remainder = IntegerData{ boost::numeric_cast<uint16_t>(remainderDigit) };
    }
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::DivisionMultiple()
{
    const IntegerDivisionMultiple<N> divisionMultiple{ m_AbsNumerator, m_AbsDenominator };

    m_Quotient = divisionMultiple.GetQuotient();
    m_Remainder = divisionMultiple.GetRemainder();

    CalculateRemainder();
}

// private
template <int N>
void Mathematics::IntegerDivisionModulo<N>::CalculateRemainder()
{
    // �����ȳ�����Ҫ��������
    constexpr auto maxLoop = 20;

    auto loop = 0;
    while (m_AbsDenominator <= m_Remainder)
    {
        MATHEMATICS_ASSERTION_1(loop < maxLoop, "����������");

        if (m_AbsDenominator == m_Remainder)
        {
            IntegerDataOperator<N> quotientOperator{ m_Quotient };

            quotientOperator += IntegerData{ 1 };
            m_Remainder.SetZero();
        }
        else if (m_AbsDenominator < m_Remainder)
        {
            const IntegerDivisionMultiple<N> divisionMultiple{ m_Remainder, m_AbsDenominator };

            IntegerDataOperator<N> quotientOperator{ m_Quotient };

            quotientOperator += divisionMultiple.GetQuotient();
            m_Remainder = divisionMultiple.GetRemainder();
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
        if (!m_Denominator.IsZero() &&
            m_AbsNumerator == IntegerDataAnalysis(m_Numerator).GetAbsoluteValue() &&
            m_AbsDenominator == IntegerDataAnalysis(m_Denominator).GetAbsoluteValue() &&
            IntegerDataAnalysis{ m_Remainder }.GetAbsoluteValue() < IntegerDataAnalysis{ m_Denominator }.GetAbsoluteValue() &&
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
    IntegerMultiplication<N> multiplication{ m_Denominator, m_Quotient };
    const auto correct = m_Numerator - multiplication.GetMultiplication() - m_Remainder;

    if (correct.IsZero())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
typename const Mathematics::IntegerDivisionModulo<N>::IntegerData Mathematics::IntegerDivisionModulo<N>::GetQuotient() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quotient;
}

template <int N>
typename const Mathematics::IntegerDivisionModulo<N>::IntegerData Mathematics::IntegerDivisionModulo<N>::GetRemainder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Remainder;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H

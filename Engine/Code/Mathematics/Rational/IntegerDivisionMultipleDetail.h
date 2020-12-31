///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:22)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_DETAIL_H

#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerDivisionMultiple.h"
#include "IntegerMultiplicationDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <int N>
Mathematics::IntegerDivisionMultiple<N>::IntegerDivisionMultiple(const IntegerData& absNumerator, const IntegerData& absDenominator)
    : m_AbsNumerator{ absNumerator },
      m_AbsDenominator{ absDenominator },
      m_AdjustNumerator{},
      m_AdjustDenominator{},
      m_NumeratorInit{ 0 },
      m_DenominatorInit{ 0 },
      m_Adjust{ 0 },
      m_FirstDigit{ 0 },
      m_SecondDigit{ 0 },
      m_RemainderHat{ 0 },
      m_Quotient{},
      m_Remainder{}
{
    Adjust();
    Calculate();
    Recover();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Adjust()
{
    // ���򻯣�ʹ�������ù��ơ�
    // �����㹻���ǿ��ܵģ����򻯵�������adjust * numerator�˻����������
    // ��������������½�ʧ�ܡ���������£������������
    // �������λ�õ�λ��Ϊ�������ָ��㷨�ķ��ӵĵ�һ�����֡�
    // ��Ȼ�⽫��Ҫ�������<N>������<N+1>��
    const IntegerDataAnalysis denominatorAnalysis{ m_AbsDenominator };
    m_DenominatorInit = denominatorAnalysis.GetLeadingBlock();
    const auto leadingDigit = denominatorAnalysis.ToInt(m_DenominatorInit);
    m_Adjust = sm_Carry / (leadingDigit + 1);

    IntegerMultiplication<N> numeratorAdjust{ IntegerData{ m_Adjust }, m_AbsNumerator };
    m_AdjustNumerator = numeratorAdjust.GetMultiplication();

    IntegerMultiplication<N> denominatorAdjust{ IntegerData{ m_Adjust }, m_AbsDenominator };
    m_AdjustDenominator = denominatorAdjust.GetMultiplication();
}

// private
template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Calculate()
{
    const IntegerDataAnalysis adjustDenominatorAnalysis{ m_AdjustDenominator };

    MATHEMATICS_ASSERTION_1(adjustDenominatorAnalysis.GetLeadingBlock() == m_DenominatorInit, "�쳣�Ľ��\n");

    // ��ȡ��ĸ�������ȵġ����֡���
    m_FirstDigit = adjustDenominatorAnalysis.ToUnsignedInt(m_DenominatorInit);
    m_SecondDigit = adjustDenominatorAnalysis.ToUnsignedInt(m_DenominatorInit - 1);

    // ȷ��������������Ĳ���
    const IntegerDataAnalysis adjustNumeratorAnalysis(m_AdjustNumerator);
    m_NumeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();

    MATHEMATICS_ASSERTION_1(m_DenominatorInit <= m_NumeratorInit, "�쳣�Ľ��\n");

    auto quotientInit = 0;
    if (m_NumeratorInit != m_DenominatorInit)
    {
        quotientInit = m_NumeratorInit - m_DenominatorInit - 1;
        m_RemainderHat = 1;
    }

    for (; 0 <= quotientInit; --quotientInit)
    {
        Calculate(quotientInit);

        if (m_AdjustDenominator <= m_AdjustNumerator)
        {
            // ׼����һ�εĳ������衣
            m_NumeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();
        }
        else
        {
            // �����ȳ���С����ɳ�����
            break;
        }
    }
}

template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Calculate(int quotientInit)
{
    const IntegerDataAnalysis adjustDenominatorAnalysis{ m_AdjustDenominator };
    const IntegerDataAnalysis adjustNumeratorAnalysis{ m_AdjustNumerator };

    // ��ȡ�������ȵ���������
    auto numerator0 = 0u;
    auto numerator1 = 0u;
    auto numerator2 = 0u;
    if (0 < m_RemainderHat)
    {
        numerator0 = adjustNumeratorAnalysis.ToUnsignedInt(m_NumeratorInit--);
        numerator1 = adjustNumeratorAnalysis.ToUnsignedInt(m_NumeratorInit--);
        numerator2 = adjustNumeratorAnalysis.ToUnsignedInt(m_NumeratorInit);
    }
    else
    {
        numerator0 = 0;
        numerator1 = adjustNumeratorAnalysis.ToUnsignedInt(m_NumeratorInit--);
        numerator2 = adjustNumeratorAnalysis.ToUnsignedInt(m_NumeratorInit);
    }

    // �����̵�ֵ
    const auto numeratorFrontTwo = (numerator0 << 16) | numerator1;
    auto quotientHat = (numerator0 != m_FirstDigit ? numeratorFrontTwo / m_FirstDigit : sm_Low);
    const auto denominatorProduct = quotientHat * m_FirstDigit;

    MATHEMATICS_ASSERTION_1(denominatorProduct <= numeratorFrontTwo, "�쳣�Ľ��\n");

    m_RemainderHat = numeratorFrontTwo - denominatorProduct;
    if (sm_Carry * m_RemainderHat + numerator2 < m_SecondDigit * quotientHat)
    {
        --quotientHat;
        m_RemainderHat += m_FirstDigit;
        if (sm_Carry * m_RemainderHat + numerator2 < m_SecondDigit * quotientHat && (quotientHat & sm_Low) != 1)
        {
            // �������ÿ飬���ǶԳ���������ȫ��ͬ���̡�
            // ����������Ժ�Ҳ���ᷢ����
            --quotientHat;
            m_RemainderHat += m_FirstDigit;
        }
    }

    MATHEMATICS_ASSERTION_1((quotientHat & sm_Low) != 0, "�쳣�Ľ��");

    // ���������ÿһ�����̡�
    IntegerData localQuotient;
    IntegerDataAmend<N> localQuotientAmend{ localQuotient };
    localQuotientAmend.FromUnsignedInt(quotientInit, quotientHat);

    // ����������
    IntegerMultiplication<N> multiplication{ localQuotient, m_AdjustDenominator };
    const auto product = multiplication.GetMultiplication();

    IntegerDataOperator<N> adjustNumeratorOperator{ m_AdjustNumerator };
    adjustNumeratorOperator -= product;

    if (m_AdjustNumerator.GetSign() == NumericalValueSymbol::Negative)
    {
        --quotientHat;
        adjustNumeratorOperator += m_AdjustDenominator;

        // ��������
        MATHEMATICS_ASSERTION_1(m_AdjustNumerator.GetSign() == NumericalValueSymbol::Positive, "�쳣�Ľ��\n");
    }

    // �����̵�λ��
    IntegerDataAmend<N> quotientAmend{ m_Quotient };
    quotientAmend.FromUnsignedInt(quotientInit, quotientHat);
}

// private
template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Recover()
{
    // ����������
    if (IntegerData{ 0 } < m_AdjustNumerator)
    {
        auto divisor = boost::numeric_cast<uint16_t>(m_Adjust & sm_Low);

        const IntegerDivisionModulo<N> divisionSingle{ m_AdjustNumerator, IntegerData{ divisor } };
        m_Remainder = divisionSingle.GetQuotient();

        MATHEMATICS_ASSERTION_1(divisionSingle.GetRemainder().IsZero(), "��������Ϊ��");
    }
    else
    {
        m_Remainder.SetZero();
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerDivisionMultiple<N>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int N>
typename const Mathematics::IntegerDivisionMultiple<N>::IntegerData Mathematics::IntegerDivisionMultiple<N>::GetQuotient() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Quotient;
}

template <int N>
typename const Mathematics::IntegerDivisionMultiple<N>::IntegerData Mathematics::IntegerDivisionMultiple<N>::GetRemainder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Remainder;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_DETAIL_H

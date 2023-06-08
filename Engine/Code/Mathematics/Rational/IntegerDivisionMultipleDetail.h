///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:13)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_DETAIL_H

#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerDivisionMultiple.h"
#include "IntegerMultiplicationDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::IntegerDivisionMultiple<N>::IntegerDivisionMultiple(const IntegerData& absNumerator, const IntegerData& absDenominator)
    : absNumerator{ absNumerator },
      absDenominator{ absDenominator },
      adjustNumerator{},
      adjustDenominator{},
      numeratorInit{ 0 },
      denominatorInit{ 0 },
      adjust{ 0 },
      firstDigit{ 0 },
      secondDigit{ 0 },
      remainderHat{ 0 },
      quotient{},
      remainder{}
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
    const IntegerDataAnalysis denominatorAnalysis{ absDenominator };
    denominatorInit = denominatorAnalysis.GetLeadingBlock();
    const auto leadingDigit = denominatorAnalysis.ToInt(denominatorInit);
    adjust = integerCarry / (leadingDigit + 1);

    IntegerMultiplication<N> numeratorAdjust{ IntegerData{ adjust }, absNumerator };
    adjustNumerator = numeratorAdjust.GetMultiplication();

    IntegerMultiplication<N> denominatorAdjust{ IntegerData{ adjust }, absDenominator };
    adjustDenominator = denominatorAdjust.GetMultiplication();
}

// private
template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Calculate()
{
    const IntegerDataAnalysis adjustDenominatorAnalysis{ adjustDenominator };

    MATHEMATICS_ASSERTION_1(adjustDenominatorAnalysis.GetLeadingBlock() == denominatorInit, "�쳣�Ľ��\n");

    // ��ȡ��ĸ�������ȵġ����֡���
    firstDigit = adjustDenominatorAnalysis.ToUnsignedInt(denominatorInit);
    secondDigit = adjustDenominatorAnalysis.ToUnsignedInt(denominatorInit - 1);

    // ȷ��������������Ĳ���
    const IntegerDataAnalysis adjustNumeratorAnalysis(adjustNumerator);
    numeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();

    MATHEMATICS_ASSERTION_1(denominatorInit <= numeratorInit, "�쳣�Ľ��\n");

    auto quotientInit = 0;
    if (numeratorInit != denominatorInit)
    {
        quotientInit = numeratorInit - denominatorInit - 1;
        remainderHat = 1;
    }

    for (; 0 <= quotientInit; --quotientInit)
    {
        Calculate(quotientInit);

        if (adjustDenominator <= adjustNumerator)
        {
            // ׼����һ�εĳ������衣
            numeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();
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
    const IntegerDataAnalysis adjustDenominatorAnalysis{ adjustDenominator };
    const IntegerDataAnalysis adjustNumeratorAnalysis{ adjustNumerator };

    // ��ȡ�������ȵ���������
    auto numerator0 = 0u;
    auto numerator1 = 0u;
    auto numerator2 = 0u;
    if (0 < remainderHat)
    {
        numerator0 = adjustNumeratorAnalysis.ToUnsignedInt(numeratorInit--);
        numerator1 = adjustNumeratorAnalysis.ToUnsignedInt(numeratorInit--);
        numerator2 = adjustNumeratorAnalysis.ToUnsignedInt(numeratorInit);
    }
    else
    {
        numerator0 = 0;
        numerator1 = adjustNumeratorAnalysis.ToUnsignedInt(numeratorInit--);
        numerator2 = adjustNumeratorAnalysis.ToUnsignedInt(numeratorInit);
    }

    // �����̵�ֵ
    const auto numeratorFrontTwo = (numerator0 << 16) | numerator1;
    auto quotientHat = (numerator0 != firstDigit ? numeratorFrontTwo / firstDigit : low);
    const auto denominatorProduct = quotientHat * firstDigit;

    MATHEMATICS_ASSERTION_1(denominatorProduct <= numeratorFrontTwo, "�쳣�Ľ��\n");

    remainderHat = numeratorFrontTwo - denominatorProduct;
    if (integerCarry * remainderHat + numerator2 < secondDigit * quotientHat)
    {
        --quotientHat;
        remainderHat += firstDigit;
        if (integerCarry * remainderHat + numerator2 < secondDigit * quotientHat && (quotientHat & low) != 1)
        {
            // �������ÿ飬���ǶԳ���������ȫ��ͬ���̡�
            // ����������Ժ�Ҳ���ᷢ����
            --quotientHat;
            remainderHat += firstDigit;
        }
    }

    MATHEMATICS_ASSERTION_1((quotientHat & low) != 0, "�쳣�Ľ��");

    // ���������ÿһ�����̡�
    IntegerData localQuotient;
    IntegerDataAmend<N> localQuotientAmend{ localQuotient };
    localQuotientAmend.FromUnsignedInt(quotientInit, quotientHat);

    // ����������
    IntegerMultiplication<N> multiplication{ localQuotient, adjustDenominator };
    const auto product = multiplication.GetMultiplication();

    IntegerDataOperator<N> adjustNumeratorOperator{ adjustNumerator };
    adjustNumeratorOperator -= product;

    if (adjustNumerator.GetSign() == NumericalValueSymbol::Negative)
    {
        --quotientHat;
        adjustNumeratorOperator += adjustDenominator;

        // ��������
        MATHEMATICS_ASSERTION_1(adjustNumerator.GetSign() == NumericalValueSymbol::Positive, "�쳣�Ľ��\n");
    }

    // �����̵�λ��
    IntegerDataAmend<N> quotientAmend{ quotient };
    quotientAmend.FromUnsignedInt(quotientInit, quotientHat);
}

template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Recover()
{
    // ����������
    if (IntegerData{ 0 } < adjustNumerator)
    {
        auto divisor = boost::numeric_cast<uint16_t>(adjust & low);

        const IntegerDivisionModulo<N> divisionSingle{ adjustNumerator, IntegerData{ divisor } };
        remainder = divisionSingle.GetQuotient();

        MATHEMATICS_ASSERTION_1(divisionSingle.GetRemainder().IsZero(), "��������Ϊ��");
    }
    else
    {
        remainder.SetZero();
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
typename Mathematics::IntegerDivisionMultiple<N>::IntegerData Mathematics::IntegerDivisionMultiple<N>::GetQuotient() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quotient;
}

template <int N>
typename Mathematics::IntegerDivisionMultiple<N>::IntegerData Mathematics::IntegerDivisionMultiple<N>::GetRemainder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return remainder;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_DETAIL_H

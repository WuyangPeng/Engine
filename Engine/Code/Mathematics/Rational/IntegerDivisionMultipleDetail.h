///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:22)

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
    // 正则化，使商有良好估计。
    // 分子足够大是可能的，正则化调整导致adjust * numerator乘积计算溢出。
    // 断言在这种情况下将失败。理想情况下，溢出将被允许，
    // 并在溢出位置的位变为在所述分割算法的分子的第一个数字。
    // 虽然这将需要混合整数<N>和整数<N+1>。
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

    MATHEMATICS_ASSERTION_1(adjustDenominatorAnalysis.GetLeadingBlock() == m_DenominatorInit, "异常的结果\n");

    // 获取分母两个最先的“数字”。
    m_FirstDigit = adjustDenominatorAnalysis.ToUnsignedInt(m_DenominatorInit);
    m_SecondDigit = adjustDenominatorAnalysis.ToUnsignedInt(m_DenominatorInit - 1);

    // 确定所需的最大除法的步骤
    const IntegerDataAnalysis adjustNumeratorAnalysis(m_AdjustNumerator);
    m_NumeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();

    MATHEMATICS_ASSERTION_1(m_DenominatorInit <= m_NumeratorInit, "异常的结果\n");

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
            // 准备再一次的除法步骤。
            m_NumeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();
        }
        else
        {
            // 余数比除数小，完成除法。
            break;
        }
    }
}

template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Calculate(int quotientInit)
{
    const IntegerDataAnalysis adjustDenominatorAnalysis{ m_AdjustDenominator };
    const IntegerDataAnalysis adjustNumeratorAnalysis{ m_AdjustNumerator };

    // 获取余数最先的三个索引
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

    // 估计商的值
    const auto numeratorFrontTwo = (numerator0 << 16) | numerator1;
    auto quotientHat = (numerator0 != m_FirstDigit ? numeratorFrontTwo / m_FirstDigit : sm_Low);
    const auto denominatorProduct = quotientHat * m_FirstDigit;

    MATHEMATICS_ASSERTION_1(denominatorProduct <= numeratorFrontTwo, "异常的结果\n");

    m_RemainderHat = numeratorFrontTwo - denominatorProduct;
    if (sm_Carry * m_RemainderHat + numerator2 < m_SecondDigit * quotientHat)
    {
        --quotientHat;
        m_RemainderHat += m_FirstDigit;
        if (sm_Carry * m_RemainderHat + numerator2 < m_SecondDigit * quotientHat && (quotientHat & sm_Low) != 1)
        {
            // 如果进入该块，我们对除法具有完全相同的商。
            // 代码调整块以后也不会发生。
            --quotientHat;
            m_RemainderHat += m_FirstDigit;
        }
    }

    MATHEMATICS_ASSERTION_1((quotientHat & sm_Low) != 0, "异常的结果");

    // 计算除法的每一步的商。
    IntegerData localQuotient;
    IntegerDataAmend<N> localQuotientAmend{ localQuotient };
    localQuotientAmend.FromUnsignedInt(quotientInit, quotientHat);

    // 计算余数。
    IntegerMultiplication<N> multiplication{ localQuotient, m_AdjustDenominator };
    const auto product = multiplication.GetMultiplication();

    IntegerDataOperator<N> adjustNumeratorOperator{ m_AdjustNumerator };
    adjustNumeratorOperator -= product;

    if (m_AdjustNumerator.GetSign() == NumericalValueSymbol::Negative)
    {
        --quotientHat;
        adjustNumeratorOperator += m_AdjustDenominator;

        // 正数或零
        MATHEMATICS_ASSERTION_1(m_AdjustNumerator.GetSign() == NumericalValueSymbol::Positive, "异常的结果\n");
    }

    // 设置商的位。
    IntegerDataAmend<N> quotientAmend{ m_Quotient };
    quotientAmend.FromUnsignedInt(quotientInit, quotientHat);
}

// private
template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Recover()
{
    // 反正则化余数
    if (IntegerData{ 0 } < m_AdjustNumerator)
    {
        auto divisor = boost::numeric_cast<uint16_t>(m_Adjust & sm_Low);

        const IntegerDivisionModulo<N> divisionSingle{ m_AdjustNumerator, IntegerData{ divisor } };
        m_Remainder = divisionSingle.GetQuotient();

        MATHEMATICS_ASSERTION_1(divisionSingle.GetRemainder().IsZero(), "余数必须为零");
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

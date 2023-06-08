///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:13)

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
    // 正则化，使商有良好估计。
    // 分子足够大是可能的，正则化调整导致adjust * numerator乘积计算溢出。
    // 断言在这种情况下将失败。理想情况下，溢出将被允许，
    // 并在溢出位置的位变为在所述分割算法的分子的第一个数字。
    // 虽然这将需要混合整数<N>和整数<N+1>。
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

    MATHEMATICS_ASSERTION_1(adjustDenominatorAnalysis.GetLeadingBlock() == denominatorInit, "异常的结果\n");

    // 获取分母两个最先的“数字”。
    firstDigit = adjustDenominatorAnalysis.ToUnsignedInt(denominatorInit);
    secondDigit = adjustDenominatorAnalysis.ToUnsignedInt(denominatorInit - 1);

    // 确定所需的最大除法的步骤
    const IntegerDataAnalysis adjustNumeratorAnalysis(adjustNumerator);
    numeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();

    MATHEMATICS_ASSERTION_1(denominatorInit <= numeratorInit, "异常的结果\n");

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
            // 准备再一次的除法步骤。
            numeratorInit = adjustNumeratorAnalysis.GetLeadingBlock();
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
    const IntegerDataAnalysis adjustDenominatorAnalysis{ adjustDenominator };
    const IntegerDataAnalysis adjustNumeratorAnalysis{ adjustNumerator };

    // 获取余数最先的三个索引
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

    // 估计商的值
    const auto numeratorFrontTwo = (numerator0 << 16) | numerator1;
    auto quotientHat = (numerator0 != firstDigit ? numeratorFrontTwo / firstDigit : low);
    const auto denominatorProduct = quotientHat * firstDigit;

    MATHEMATICS_ASSERTION_1(denominatorProduct <= numeratorFrontTwo, "异常的结果\n");

    remainderHat = numeratorFrontTwo - denominatorProduct;
    if (integerCarry * remainderHat + numerator2 < secondDigit * quotientHat)
    {
        --quotientHat;
        remainderHat += firstDigit;
        if (integerCarry * remainderHat + numerator2 < secondDigit * quotientHat && (quotientHat & low) != 1)
        {
            // 如果进入该块，我们对除法具有完全相同的商。
            // 代码调整块以后也不会发生。
            --quotientHat;
            remainderHat += firstDigit;
        }
    }

    MATHEMATICS_ASSERTION_1((quotientHat & low) != 0, "异常的结果");

    // 计算除法的每一步的商。
    IntegerData localQuotient;
    IntegerDataAmend<N> localQuotientAmend{ localQuotient };
    localQuotientAmend.FromUnsignedInt(quotientInit, quotientHat);

    // 计算余数。
    IntegerMultiplication<N> multiplication{ localQuotient, adjustDenominator };
    const auto product = multiplication.GetMultiplication();

    IntegerDataOperator<N> adjustNumeratorOperator{ adjustNumerator };
    adjustNumeratorOperator -= product;

    if (adjustNumerator.GetSign() == NumericalValueSymbol::Negative)
    {
        --quotientHat;
        adjustNumeratorOperator += adjustDenominator;

        // 正数或零
        MATHEMATICS_ASSERTION_1(adjustNumerator.GetSign() == NumericalValueSymbol::Positive, "异常的结果\n");
    }

    // 设置商的位。
    IntegerDataAmend<N> quotientAmend{ quotient };
    quotientAmend.FromUnsignedInt(quotientInit, quotientHat);
}

template <int N>
void Mathematics::IntegerDivisionMultiple<N>::Recover()
{
    // 反正则化余数
    if (IntegerData{ 0 } < adjustNumerator)
    {
        auto divisor = boost::numeric_cast<uint16_t>(adjust & low);

        const IntegerDivisionModulo<N> divisionSingle{ adjustNumerator, IntegerData{ divisor } };
        remainder = divisionSingle.GetQuotient();

        MATHEMATICS_ASSERTION_1(divisionSingle.GetRemainder().IsZero(), "余数必须为零");
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

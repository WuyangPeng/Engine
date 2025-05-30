/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:19)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H

#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerDivisionModulo.h"
#include "IntegerDivisionMultipleDetail.h"
#include "IntegerMultiplicationDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N>
Mathematics::IntegerDivisionModulo<N>::IntegerDivisionModulo(const IntegerDataType& division, const IntegerDataType& modulo)
    : numerator{ division },
      denominator{ modulo },
      absNumerator{ IntegerDataAnalysisType(numerator).GetAbsoluteValue() },
      absDenominator{ IntegerDataAnalysisType(denominator).GetAbsoluteValue() },
      quotient{},
      remainder{}
{
    if (!numerator.IsZero() && !denominator.IsZero())
    {
        Calculate();
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N>
void Mathematics::IntegerDivisionModulo<N>::Calculate()
{
    // 计算中使用绝对值的分子值和分母值。
    const auto compare = IntegerDataType::UnsignedDataCompare(absNumerator, absDenominator);
    if (compare == NumericalValueSymbol::Negative)
    {
        // 分子 < 分母:  numerator = 0 * denominator + numerator
        quotient.SetZero();
        remainder = numerator;
    }
    else if (compare == NumericalValueSymbol::Zero)
    {
        // 分子 == 分母:  numerator = 1 * denominator + 0
        quotient = IntegerDataType{ 1 };
        remainder.SetZero();
    }
    else
    {
        // 分子 > 分母, 使用除法计算商和余数
        if (IntegerDataType{ low } < absDenominator)
        {
            DivisionMultiple();
        }
        else
        {
            DivisionSingle();
        }

        // 应用分子和分母的原始符号。
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

template <int N>
void Mathematics::IntegerDivisionModulo<N>::DivisionSingle()
{
    // 分母是单个的“位”。
    const auto lowDenominator = low & boost::numeric_cast<uint32_t>(absDenominator[0]);

    // 获取分子。
    const IntegerDataAnalysisType numeratorAnalysis{ absNumerator };
    const auto start = numeratorAnalysis.GetLeadingBlock();

    auto remainderDigit = 0u;

    // 得到商。
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

    MATHEMATICS_ASSERTION_1(0 <= lastNonZero, "异常的结果\n");

    // 得到余数
    if (remainderDigit & high)
    {
        remainder = IntegerDataType{ remainderDigit };
    }
    else
    {
        remainder = IntegerDataType{ boost::numeric_cast<uint16_t>(remainderDigit) };
    }
}

template <int N>
void Mathematics::IntegerDivisionModulo<N>::DivisionMultiple()
{
    const IntegerDivisionMultiple<N> divisionMultiple{ absNumerator, absDenominator };

    quotient = divisionMultiple.GetQuotient();
    remainder = divisionMultiple.GetRemainder();

    CalculateRemainder();
}

template <int N>
void Mathematics::IntegerDivisionModulo<N>::CalculateRemainder()
{
    auto loop = 0;
    while (absDenominator <= remainder)
    {
        // 余数比除数大，要继续计算
        MAYBE_UNUSED constexpr auto maxLoop = 20;

        MATHEMATICS_ASSERTION_1(loop < maxLoop, "计算量过大！");

        if (absDenominator == remainder)
        {
            IntegerDataOperator<N> quotientOperator{ quotient };

            quotientOperator += IntegerDataType{ 1 };
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
            absNumerator == IntegerDataAnalysisType(numerator).GetAbsoluteValue() &&
            absDenominator == IntegerDataAnalysisType(denominator).GetAbsoluteValue() &&
            IntegerDataAnalysisType{ remainder }.GetAbsoluteValue() < IntegerDataAnalysisType{ denominator }.GetAbsoluteValue() &&
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

    if (const auto correct = numerator - multiplication.GetMultiplication() - remainder;
        correct.IsZero())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
typename Mathematics::IntegerDivisionModulo<N>::IntegerDataType Mathematics::IntegerDivisionModulo<N>::GetQuotient() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quotient;
}

template <int N>
typename Mathematics::IntegerDivisionModulo<N>::IntegerDataType Mathematics::IntegerDivisionModulo<N>::GetRemainder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return remainder;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_DETAIL_H

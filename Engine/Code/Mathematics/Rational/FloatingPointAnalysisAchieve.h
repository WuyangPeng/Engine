/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:16)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_ACHIEVE_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_ACHIEVE_H

#include "FloatingPointAnalysis.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::FloatingPointAnalysis<T>::FloatingPointAnalysis(T value) noexcept
    : value{ value }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::FloatingPointAnalysis<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetSymbolValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto bits = (reinterpret_cast<const IntegerType&>(value));

#include SYSTEM_WARNING_POP

    const auto sign = ((symbol & bits) >> symbolShifting);

    return sign;
}

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetExponent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto bits = (reinterpret_cast<const IntegerType&>(value));

#include SYSTEM_WARNING_POP

    const auto result = ((exponent & bits) >> exponentShifting);

    return result;
}

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto bits = (reinterpret_cast<const IntegerType&>(value));

#include SYSTEM_WARNING_POP

    return (mantissa & bits);
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::FloatingPointAnalysis<T>::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sign = GetSymbolValue();

    if (sign == 0)
        return NumericalValueSymbol::Positive;
    else
        return NumericalValueSymbol::Negative;
}

template <typename T>
Mathematics::FloatingPointAnalysisType Mathematics::FloatingPointAnalysis<T>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto exponentAnalysis = GetExponent();

    if (1 <= exponentAnalysis && exponentAnalysis < maxExponent)
    {
        // 数字是规格化的(double)：  (-1)^s * 2^{e-1023} * 1.m
        return FloatingPointAnalysisType::Valid;
    }
    else if (exponentAnalysis == 0)
    {
        // 数字是次标准的（非规格化double)：  (-1)^s * 2^{-1022} * 0.m
        return FloatingPointAnalysisType::Zero;
    }
    else  // exponent == maxExponent
    {
        const auto mantissaAnalysis = GetMantissa();

        if (0 < mantissaAnalysis)
        {
            if (mantissaAnalysis & quietNaN)
            {
                return FloatingPointAnalysisType::QuietNaN;
            }
            else
            {
                // 有效负载是(double) (mantissa & 0x0007FFFFFFFFFFFFLL)。
                return FloatingPointAnalysisType::SignalingNaN;
            }
        }
        else
        {
            return FloatingPointAnalysisType::Infinity;
        }
    }
}

template <typename T>
int Mathematics::FloatingPointAnalysis<T>::GetRealExponent() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(GetExponent()) - realExponentDifference;
}

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetRealMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto exponentAnalysis = GetExponent();
    const auto mantissaAnalysis = GetMantissa();

    if (1 <= exponentAnalysis && exponentAnalysis <= maxExponent)
    {
        return mantissaAnalysis + (IntegerType{ 1 } << exponentShifting);
    }
    else
    {
        return mantissaAnalysis;
    }
}

#endif  // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_ACHIEVE_H

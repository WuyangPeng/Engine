///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 17:08)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_ACHIEVE_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_ACHIEVE_H

#include "FloatingPointAnalysis.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::FloatingPointAnalysis<T>::FloatingPointAnalysis(T value) noexcept
    : m_Value{ value }
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto bits = (reinterpret_cast<const IntegerType&>(m_Value));
#include STSTEM_WARNING_POP

    const auto sign = ((sm_Symbol & bits) >> sm_SymbolShifting);

    return sign;
}

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetExponent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto bits = (reinterpret_cast<const IntegerType&>(m_Value));
#include STSTEM_WARNING_POP

    const auto exponent = ((sm_Exponent & bits) >> sm_ExponentShifting);

    return exponent;
}

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto bits = (reinterpret_cast<const IntegerType&>(m_Value));
#include STSTEM_WARNING_POP

    const auto mantissa = (sm_Mantissa & bits);

    return mantissa;
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

    const auto exponent = GetExponent();

    if (1 <= exponent && exponent < sm_MaxExponent)
    {
        // 数字是规格化的(double)：  (-1)^s * 2^{e-1023} * 1.m
        return FloatingPointAnalysisType::Valid;
    }
    else if (exponent == 0)
    {
        // 数字是次标准的（非规格化double)：  (-1)^s * 2^{-1022} * 0.m
        return FloatingPointAnalysisType::Zero;
    }
    else  // exponent == sm_MaxExponent
    {
        const auto mantissa = GetMantissa();

        if (0 < mantissa)
        {
            if (mantissa & sm_QuietNaN)
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

    const auto exponent = GetExponent();

    return boost::numeric_cast<int>(exponent) - sm_RealExponentDifference;
}

template <typename T>
typename Mathematics::FloatingPointAnalysis<T>::IntegerType Mathematics::FloatingPointAnalysis<T>::GetRealMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto exponent = GetExponent();
    const auto mantissa = GetMantissa();

    if (1 <= exponent && exponent <= sm_MaxExponent)
    {
        return mantissa + (IntegerType{ 1 } << sm_ExponentShifting);
    }
    else
    {
        return mantissa;
    }
}

#endif  // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_ACHIEVE_H

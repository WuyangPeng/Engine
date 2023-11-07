///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 19:36)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_INTEGER_DETAIL_H
#define MATHEMATICS_RATIONAL_CONVERSION_INTEGER_DETAIL_H

#include "ConversionInteger.h"
#include "FloatingPointAnalysisDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <type_traits>

template <typename T>
Mathematics::ConversionInteger<T>::ConversionInteger(T value)
    : shifting{ 0 },
      mantissa{ 0 },
      symbol{ NumericalValueSymbol::Zero },
      maxMantissaBit{ 0 },
      shiftingMantissa{ 0 }
{
    Init(value, TraitsType{});
    Amendment();
    ShiftingMantissa();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const SignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    if (0 <= value)
    {
        mantissa = value;
        symbol = NumericalValueSymbol::Positive;
    }
    else
    {
        mantissa = -value;
        symbol = NumericalValueSymbol::Negative;
    }

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(mantissa) };
    shifting = floatingPointAnalysis.GetRealExponent();

    maxMantissaBit = shifting;
}

template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const UnsignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    mantissa = value;
    symbol = NumericalValueSymbol::Positive;

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(mantissa) };
    shifting = floatingPointAnalysis.GetRealExponent();

    maxMantissaBit = shifting;
}

template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const FloatType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    const FloatingPointAnalysis<T> floatingPointAnalysis{ value };

    const auto floatingPointAnalysisType = floatingPointAnalysis.GetType();

    if (floatingPointAnalysisType == FloatingPointAnalysisType::Valid || floatingPointAnalysisType == FloatingPointAnalysisType::Zero)
    {
        shifting = floatingPointAnalysis.GetRealExponent();
        mantissa = floatingPointAnalysis.GetRealMantissa();
        symbol = floatingPointAnalysis.GetSymbol();
        maxMantissaBit = TraitsType::exponentShifting;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的浮点数无效！"s));
    }
}

template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const DoubleType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    const FloatingPointAnalysis<T> floatingPointAnalysis{ value };

    const auto floatingPointAnalysisType = floatingPointAnalysis.GetType();

    if (floatingPointAnalysisType == FloatingPointAnalysisType::Valid || floatingPointAnalysisType == FloatingPointAnalysisType::Zero)
    {
        shifting = floatingPointAnalysis.GetRealExponent();
        mantissa = floatingPointAnalysis.GetRealMantissa();
        symbol = floatingPointAnalysis.GetSymbol();
        maxMantissaBit = TraitsType::exponentShifting;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的浮点数无效！"s));
    }
}

template <typename T>
void Mathematics::ConversionInteger<T>::Amendment() noexcept
{
    // 对于（-1，1）之间的数，截断为0
    if (shifting < 0)
    {
        mantissa = 0;
        shifting = 0;
        maxMantissaBit = 0;
        symbol = NumericalValueSymbol::Positive;
    }

    // 截断小数点后的数值
    const auto difference = maxMantissaBit - shifting;

    if (0 < difference)
    {
        mantissa >>= difference;
        maxMantissaBit -= difference;
    }
}

template <typename T>
void Mathematics::ConversionInteger<T>::ShiftingMantissa() noexcept
{
    // 对齐个位的数值
    const auto difference = shifting - maxMantissaBit;
    const auto newShifting = difference % blockSize;

    shiftingMantissa = mantissa << newShifting;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::ConversionInteger<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::ConversionInteger<T>::GetShifting() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return shifting;
}

template <typename T>
uint64_t Mathematics::ConversionInteger<T>::GetMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return mantissa;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetMaxMantissaBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxMantissaBit;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetMantissaSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (shifting + 1) / blockSize + 1;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetCopySize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto copyShiftingMantissa = shiftingMantissa;
    auto size = 0;

    do
    {
        copyShiftingMantissa >>= (blockSize / 2);
        ++size;

    } while (copyShiftingMantissa != 0);

    return size;
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::ConversionInteger<T>::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return symbol;
}

template <typename T>
uint64_t Mathematics::ConversionInteger<T>::GetShiftingMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return shiftingMantissa;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetBeginBlock() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto difference = shifting - maxMantissaBit;

    return difference / blockSize;
}

#endif  // MATHEMATICS_RATIONAL_CONVERSION_INTEGER_DETAIL_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 17:18)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_DETAIL_H
#define MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_DETAIL_H

#include "ConversionRational.h"
#include "FloatingPointAnalysisDetail.h"
#include "IntegerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <type_traits>

template <typename T>
Mathematics::ConversionRational<T>::ConversionRational(T value)
    : numeratorShifting{ 0 },
      denominatorShifting{ 0 },
      numeratorMantissa{ 0 },
      denominatorMantissa{ 0 },
      symbol{ NumericalValueSymbol::Zero },
      maxShifting{ 0 },
      reducibilityShifting{ 0 }
{
    Init(value, TraitsType{});

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const SignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    if (0 <= value)
    {
        numeratorMantissa = value;
        denominatorMantissa = 1;
        symbol = NumericalValueSymbol::Positive;
        numeratorShifting = 0;
        denominatorShifting = 0;
    }
    else
    {
        numeratorMantissa = -value;
        denominatorMantissa = 1;
        symbol = NumericalValueSymbol::Negative;
        numeratorShifting = 0;
        denominatorShifting = 0;
    }

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(numeratorMantissa) };
    maxShifting = floatingPointAnalysis.GetRealExponent();
    if (maxShifting < 0)
    {
        maxShifting = 0;
    }
    reducibilityShifting = 0;
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const UnsignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    numeratorMantissa = value;
    denominatorMantissa = 1;
    symbol = NumericalValueSymbol::Positive;
    numeratorShifting = 0;
    denominatorShifting = 0;

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(numeratorMantissa) };
    maxShifting = floatingPointAnalysis.GetRealExponent();
    if (maxShifting < 0)
    {
        maxShifting = 0;
    }
    reducibilityShifting = 0;
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const FloatType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitFloatingPoint(value);
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const DoubleType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitFloatingPoint(value);
}

template <typename T>
void Mathematics::ConversionRational<T>::InitFloatingPoint(T value)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    const FloatingPointAnalysis<T> floatingPointAnalysis{ value };

    if (floatingPointAnalysis.GetType() == FloatingPointAnalysisType::Valid || floatingPointAnalysis.GetType() == FloatingPointAnalysisType::Zero)
    {
        numeratorMantissa = floatingPointAnalysis.GetRealMantissa();
        denominatorMantissa = uint64_t{ 1 } << TraitsType::exponentShifting;
        symbol = floatingPointAnalysis.GetSymbol();

        auto shifting = floatingPointAnalysis.GetRealExponent();

        if (0 < shifting)
        {
            reducibilityShifting = TraitsType::exponentShifting - shifting;

            if (0 < reducibilityShifting)
            {
                denominatorMantissa >>= shifting;
                shifting = 0;
            }
            else
            {
                reducibilityShifting = 0;
            }

            numeratorShifting = shifting;
            maxShifting = TraitsType::exponentShifting + numeratorShifting;
        }
        else if (shifting < 0)
        {
            denominatorShifting = -shifting;
            maxShifting = TraitsType::exponentShifting - shifting;
            reducibilityShifting = -static_cast<int>(TraitsType::exponentShifting);
        }

        if (floatingPointAnalysis.GetExponent() == 0)
        {
            --denominatorShifting;
            --maxShifting;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的浮点数无效！"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::ConversionRational<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetNumeratorMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numeratorMantissa;
}

template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetDenominatorMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return denominatorMantissa;
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::ConversionRational<T>::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return symbol;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetNumeratorShifting() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numeratorShifting;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetDenominatorShifting() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return denominatorShifting;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetMaxShifting() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxShifting;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetReducibilityShifting() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return reducibilityShifting;
}

template <typename T>
template <int N>
bool Mathematics::ConversionRational<T>::IsCanConversion() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto bit = maxShifting - N * 32 - 1;

    if (0 < bit && 0 <= reducibilityShifting && reducibilityShifting < bit)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
template <int N>
Mathematics::Integer<N> Mathematics::ConversionRational<T>::GetNumerator() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto bit = maxShifting - N * 32 - 1;
    auto numeratorShiftingCopy = numeratorShifting;
    auto numeratorMantissaCopy = numeratorMantissa;

    if (0 < bit)
    {
        numeratorShiftingCopy = GetAssignmentNumeratorShifting(bit);
        numeratorMantissaCopy = GetAssignmentNumeratorMantissa(bit);
    }

    auto numerator = Integer<N>{ numeratorMantissaCopy };
    numerator <<= numeratorShiftingCopy;

    if (symbol == NumericalValueSymbol::Negative)
    {
        numerator = -numerator;
    }

    return numerator;
}

template <typename T>
template <int N>
Mathematics::Integer<N> Mathematics::ConversionRational<T>::GetDenominator() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto bit = maxShifting - N * 32 - 1;
    auto denominatorShiftingCopy = denominatorShifting;
    auto denominatorMantissaCopy = denominatorMantissa;

    if (0 < bit)
    {
        denominatorShiftingCopy = GetAssignmentDenominatorShifting(bit);
        denominatorMantissaCopy = GetAssignmentDenominatorMantissa(bit);
    }

    auto denominator = Integer<N>{ denominatorMantissaCopy };
    denominator <<= denominatorShiftingCopy;

    return denominator;
}

// private
template <typename T>
int Mathematics::ConversionRational<T>::GetAssignmentNumeratorShifting(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= reducibilityShifting)
    {
        const auto shifting = numeratorShifting - reducibilityShifting;

        if (0 <= shifting)
        {
            return numeratorShifting >> reducibilityShifting;
        }
        else
        {
            return numeratorShifting >> (-shifting);
        }
    }
    else if (reducibilityShifting < 0)
    {
        if (-reducibilityShifting <= bit)
        {
            return 0;
        }
        else
        {
            return numeratorShifting;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

// private
template <typename T>
int Mathematics::ConversionRational<T>::GetAssignmentDenominatorShifting(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= reducibilityShifting)
    {
        return denominatorShifting;
    }
    else if (reducibilityShifting < 0)
    {
        if (-reducibilityShifting <= bit)
        {
            return 0;
        }
        else
        {
            const auto shifting = denominatorShifting + reducibilityShifting;

            if (0 <= shifting)
            {
                return denominatorShifting >> reducibilityShifting;
            }
            else
            {
                return denominatorShifting >> (-shifting);
            }
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

// private
template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetAssignmentNumeratorMantissa(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= reducibilityShifting)
    {
        const auto shifting = numeratorShifting - reducibilityShifting;

        if (0 <= shifting)
        {
            return numeratorMantissa;
        }
        else
        {
            return numeratorMantissa >> (reducibilityShifting + shifting);
        }
    }
    else if (reducibilityShifting < 0)
    {
        if (-reducibilityShifting <= bit)
        {
            return 0;
        }
        else
        {
            return numeratorMantissa >> (-reducibilityShifting);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

// private
template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetAssignmentDenominatorMantissa(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= reducibilityShifting)
    {
        return denominatorMantissa >> reducibilityShifting;
    }
    else if (reducibilityShifting < 0)
    {
        if (-reducibilityShifting <= bit)
        {
            return 1;
        }
        else
        {
            const auto shifting = denominatorShifting + reducibilityShifting;

            if (0 <= shifting)
            {
                return denominatorMantissa;
            }
            else
            {
                return denominatorMantissa >> (-reducibilityShifting + shifting);
            }
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

#endif  // MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_DETAIL_H

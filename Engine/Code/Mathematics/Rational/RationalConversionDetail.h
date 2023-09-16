///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:13)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_DETAIL_H

#include "RationalConversion.h"
#include "SignRationalDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <gsl/util>
#include <type_traits>

template <int N, typename T>
Mathematics::RationalConversion<N, T>::RationalConversion(const Rational& rational)
    : absNumerator{ rational.GetNumerator().GetAbsoluteValue() },
      absDenominator{ rational.GetDenominator().GetAbsoluteValue() },
      shifting{ absNumerator.IsZero() ? 0 : (absNumerator.GetLeadingBit() - absDenominator.GetLeadingBit()) },
      symbol{ rational.GetSign() },
      value{},
      mantissa{}
{
    if (!absNumerator.IsZero())
    {
        Init(TraitsType{});
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <int N, typename T>
void Mathematics::RationalConversion<N, T>::Init(const SignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    InitToIntegral();

    if (symbol == NumericalValueSymbol::Negative)
    {
        value = -value;
    }
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::Init(const UnsignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    InitToIntegral();
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::Init(const FloatType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitToFloatingPoint();
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::Init(const DoubleType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitToFloatingPoint();
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::InitToFloatingPoint()
{
    using IntegerType = typename TraitsType::IntegerType;

    CorrectWithShifting();

    if (shifting <= boost::numeric_cast<int>(TraitsType::realExponentDifference))
    {
        CalculateMantissa();
    }
    else
    {
        // 大于max_normal_float。
        THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"s));
    }

    Negative();

    auto result = boost::numeric_cast<IntegerType>(mantissa);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    value = *(reinterpret_cast<T*>(&result));

#include SYSTEM_WARNING_POP
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::CorrectWithShifting()
{
    // 有理数的形式为N/D = 2^{nbit-dbit}*(1+n)/(1+d)所示，
    // 其中n和d是在范围[0,1）。转换到N'/D' = (1+n)/(1+d)。
    if (0 < shifting)
    {
        absDenominator <<= shifting;
    }
    else if (shifting < 0)
    {
        absNumerator <<= -shifting;
    }

    // 表示(1+n)/(1+d) = 1+m，其中m在[0,1)，我们需要n >= d。
    // 如果n < d，转换为N"/D" = (2*(1+n))/(1+d) = 1+m，这是在 [0,1)。
    if (absNumerator < absDenominator)
    {
        absNumerator <<= 1;
        --shifting;
    }
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::CalculateMantissa()
{
    using IntegerType = typename TraitsType::IntegerType;

    constexpr auto realExponentDifference = gsl::narrow_cast<int>(TraitsType::realExponentDifference);
    constexpr auto exponentShifting = gsl::narrow_cast<int>(TraitsType::exponentShifting);

    // -1074 double
    // -149 float
    if (-realExponentDifference - exponentShifting + 1 <= shifting)
    {
        IntegerType exponent{ 0 };
        IntegerType bit{ 0 };
        IntegerType shift{ 0 };
        if (-realExponentDifference < shifting)
        {
            // normal_float, 1.c * 2^{e - 127}
            exponent = gsl::narrow_cast<IntegerType>(shifting) + realExponentDifference;
            bit = 1;
            shift = 0;
        }
        else
        {
            // subnormal_float, 0.c * 2^{-126}
            exponent = 0;
            bit = 0;
            absDenominator <<= 1;
            shift = -(shifting + realExponentDifference);
        }

        const auto beginMask = (IntegerType{ 1 } << (exponentShifting - 1)) >> shift;

        for (auto mask = beginMask; 0 < mask; mask >>= 1)
        {
            if (bit == 1)
            {
                absNumerator -= absDenominator;
            }
            absNumerator <<= 1;

            if (absDenominator <= absNumerator)
            {
                bit = 1;
                mantissa |= mask;
            }
            else
            {
                bit = 0;
            }
        }

        const auto result = exponent << exponentShifting;
        mantissa = boost::numeric_cast<uint64_t>(result | mantissa);
    }
    else
    {
        // 小于 min_subnormal_float, 截断为0。
        mantissa = 0;
    }
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::Negative() noexcept
{
    if (symbol == NumericalValueSymbol::Negative)
    {
        mantissa |= TraitsType::symbol;
    }
}

template <int N, typename T>
void Mathematics::RationalConversion<N, T>::InitToIntegral()
{
    auto division = absNumerator / absDenominator;

    value = division.GetValue<T>();
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename T>
bool Mathematics::RationalConversion<N, T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename T>
T Mathematics::RationalConversion<N, T>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return value;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_DETAIL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 19:39)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_DETAIL_H

#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataConversion.h"
#include "IntegerDataDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <type_traits>

template <int N, typename T>
Mathematics::IntegerDataConversion<N, T>::IntegerDataConversion(const IntegerData& data)
    : absData{ IntegerDataAnalysis<N>(data).GetAbsoluteValue() },
      shifting{ absData.IsZero() ? 0 : IntegerDataAnalysis<N>(absData).GetLeadingBit() },
      mantissa{ 0 },
      symbol{ data.GetSign() },
      value{}
{
    if (!absData.IsZero())
    {
        Init(TraitsType{});
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::Init(const SignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    if (shifting <= sizeof(T) * 8 - 1)
    {
        const auto copySize = shifting / 8 + 1;
        memcpy(&mantissa, &absData[0], copySize);
        value = boost::numeric_cast<T>(mantissa);

        SignedIntegerNegative();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"s));
    }
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::Init(const UnsignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    if (shifting <= sizeof(T) * 8 && symbol == NumericalValueSymbol::Positive)
    {
        const auto copySize = shifting / 8 + 1;
        memcpy(&mantissa, &absData[0], copySize);
        value = boost::numeric_cast<T>(mantissa);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"s));
    }
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::Init(const FloatType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitToFloatingPoint();
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::Init(const DoubleType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitToFloatingPoint();
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::InitToFloatingPoint()
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    if (shifting <= TraitsType::realExponentDifference)
    {
        CalculateMantissa();
        CalculateConversionValue();
        Negative();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"s));
    }
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::CalculateConversionValue()
{
    using IntegerType = typename TraitsType::IntegerType;

    IntegerType mantissaValue{ TraitsType::mantissa & mantissa };

    // 去掉mantissa的最高位
    IntegerType highest{ 1 };
    highest <<= TraitsType::exponentShifting;

    mantissaValue &= ~highest;

    auto exponent = ((boost::numeric_cast<IntegerType>(shifting) + TraitsType::realExponentDifference) << TraitsType::exponentShifting);
    exponent &= TraitsType::exponent;

    auto conversion = exponent | mantissaValue;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    value = *(reinterpret_cast<const T*>(&conversion));

#include SYSTEM_WARNING_POP
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::CalculateMantissa()
{
    using IntegerType = typename TraitsType::IntegerType;

    constexpr auto maxMantissaBit = TraitsType::exponentShifting;

    // 将m_AbsData移位到同maxMantissaBit对齐
    constexpr auto maxMantissaBitRemainder = maxMantissaBit % 16;
    const auto shiftingRemainder = shifting % 16;
    int difference = maxMantissaBitRemainder - shiftingRemainder;

    if (difference < 0)
    {
        difference += 16;
    }

    if (difference != 0)
    {
        IntegerDataOperator<N> integerDataOperator{ absData };
        integerDataOperator <<= difference;
    }

    auto index = IntegerDataAnalysis<N>(absData).GetLeadingBlock();

    index -= (sizeof(IntegerType) / sizeof(uint16_t) - 1);

    memcpy(&mantissa, &absData[index], sizeof(IntegerType));
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::Negative() noexcept
{
    if (symbol == NumericalValueSymbol::Negative)
    {
        value = -value;
    }
}

template <int N, typename T>
void Mathematics::IntegerDataConversion<N, T>::SignedIntegerNegative()
{
    if (symbol == NumericalValueSymbol::Negative)
    {
        if (value <= std::numeric_limits<T>::max())
        {
            value = -value;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("转换溢出！"s));
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename T>
bool Mathematics::IntegerDataConversion<N, T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename T>
T Mathematics::IntegerDataConversion<N, T>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return value;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_DETAIL_H

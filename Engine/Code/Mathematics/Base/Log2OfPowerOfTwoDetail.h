///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 09:13)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

#include "Log2OfPowerOfTwo.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename T>
requires std::is_integral_v<T>
Mathematics::Log2OfPowerOfTwo<T>::Log2OfPowerOfTwo(T powerOfTwo) noexcept
    : powerOfTwo{ powerOfTwo }, powerOfTwoCopy{ powerOfTwo }, log2{ 0 }
{
    Convert();

    SELF_CLASS_IS_VALID_5;
}

template <typename T>
requires std::is_integral_v<T>
void Mathematics::Log2OfPowerOfTwo<T>::Convert() noexcept
{
    auto maskIndex = 0;
    if constexpr (std::is_same_v<CalculateType, uint32_t>)
    {
        for (const auto mask : maskContainer32)
        {
            DetermineWhetherBitExist(maskIndex, mask);

            ++maskIndex;
        }
    }
    else
    {
        for (const auto mask : maskContainer64)
        {
            DetermineWhetherBitExist(maskIndex, mask);

            ++maskIndex;
        }
    }
}

template <typename T>
requires std::is_integral_v<T>
void Mathematics::Log2OfPowerOfTwo<T>::DetermineWhetherBitExist(int maskIndex, CalculateType mask) noexcept
{
    if ((powerOfTwoCopy & mask) != 0)
    {
        PowerOfTwoWithMask(maskIndex, mask);
    }
}

template <typename T>
requires std::is_integral_v<T>
void Mathematics::Log2OfPowerOfTwo<T>::PowerOfTwoWithMask(int maskIndex, CalculateType mask) noexcept
{
    log2 |= (1 << (maskSize - maskIndex - 1));
    powerOfTwoCopy &= mask;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_integral_v<T> bool Mathematics::Log2OfPowerOfTwo<T>::IsValid() const noexcept
{
    if (IsPowerOfTwoValid() && IsLog2Valid() && IsConvertValid())
        return true;
    else
        return false;
}

template <typename T>
requires std::is_integral_v<T> bool Mathematics::Log2OfPowerOfTwo<T>::IsPowerOfTwoValid() const noexcept
{
    if (0 <= powerOfTwo)
        return true;
    else
        return false;
}

template <typename T>
requires std::is_integral_v<T> bool Mathematics::Log2OfPowerOfTwo<T>::IsLog2Valid() const noexcept
{
    if (0 <= gsl::narrow_cast<T>(log2))
        return true;
    else
        return false;
}

template <typename T>
requires std::is_integral_v<T> bool Mathematics::Log2OfPowerOfTwo<T>::IsConvertValid() const noexcept
{
    const auto low = gsl::narrow_cast<T>(GetPowerOfTwoLow());
    const auto high = low * 2;
    const auto original = powerOfTwo;

    if (low <= original && (original < high || high < low))
        return true;
    else
        return false;
}

template <typename T>
requires std::is_integral_v<T>
typename Mathematics::Log2OfPowerOfTwo<T>::CalculateType Mathematics::Log2OfPowerOfTwo<T>::GetPowerOfTwoLow() const noexcept
{
    auto result = 1u;
    for (auto i = 0u; i < log2; ++i)
    {
        result *= 2;
    }

    return result;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_integral_v<T>
int Mathematics::Log2OfPowerOfTwo<T>::GetLog2() const
{
    CLASS_IS_VALID_5;

    return boost::numeric_cast<int>(log2);
}

#endif  // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

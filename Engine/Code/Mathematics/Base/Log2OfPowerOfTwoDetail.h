///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/29 11:17)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

#include "Log2OfPowerOfTwo.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename T>
Mathematics::Log2OfPowerOfTwo<T>::Log2OfPowerOfTwo(T powerOfTwo) noexcept
    : powerOfTwo{ powerOfTwo }, powerOfTwoCopy{ powerOfTwo }, log2{ 0 }
{
    Convert();

    SELF_CLASS_IS_VALID_5;
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>::Convert() noexcept
{
    auto maskIndex = 0;
    for (auto mask : maskContainer)
    {
        DetermineWhetherBitExist(maskIndex, mask);

        ++maskIndex;
    }
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>::DetermineWhetherBitExist(int maskIndex, uint32_t mask) noexcept
{
    if ((powerOfTwoCopy & mask) != 0)
    {
        PowerOfTwoWithMask(maskIndex, mask);
    }
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>::PowerOfTwoWithMask(int maskIndex, uint32_t mask) noexcept
{
    log2 |= (1 << (maskSize - maskIndex - 1));
    powerOfTwoCopy &= mask;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>::IsValid() const noexcept
{
    if (IsPowerOfTwoValid() && IsLog2Valid() && IsConvertValid())
        return true;
    else
        return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>::IsPowerOfTwoValid() const noexcept
{
    if (0 <= powerOfTwo)
        return true;
    else
        return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>::IsLog2Valid() const noexcept
{
    if (0 <= gsl::narrow_cast<T>(log2))
        return true;
    else
        return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>::IsConvertValid() const noexcept
{
    auto low = gsl::narrow_cast<T>(GetPowerOfTwoLow());
    const auto high = low * 2;
    auto original = powerOfTwo;

    if (low <= original && (original < high || high < low))
        return true;
    else
        return false;
}

template <typename T>
uint32_t Mathematics::Log2OfPowerOfTwo<T>::GetPowerOfTwoLow() const noexcept
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
T Mathematics::Log2OfPowerOfTwo<T>::GetLog2() const
{
    CLASS_IS_VALID_5;

    return boost::numeric_cast<T>(log2);
}

#endif  // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

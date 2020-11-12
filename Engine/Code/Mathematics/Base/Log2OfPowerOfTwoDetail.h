///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 14:57)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

#include "Log2OfPowerOfTwo.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/gsl_util>

template <typename T>
Mathematics::Log2OfPowerOfTwo<T>::Log2OfPowerOfTwo(T powerOfTwo) noexcept
    : m_PowerOfTwo{ powerOfTwo }, m_PowerOfTwoCopy{ powerOfTwo }, m_Log2{ 0 }
{
    Convert();

    SELF_CLASS_IS_VALID_5;
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>::Convert() noexcept
{
    auto maskIndex = 0;
    for (auto mask : sm_Mask)
    {
        DetermineWhetherBitExist(maskIndex, mask);

        ++maskIndex;
    }
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>::DetermineWhetherBitExist(int maskIndex, uint32_t mask) noexcept
{
    if ((m_PowerOfTwoCopy & mask) != 0)
    {
        PowerOfTwoWithMask(maskIndex, mask);
    }
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>::PowerOfTwoWithMask(int maskIndex, uint32_t mask) noexcept
{
    m_Log2 |= (1 << (sm_MaskSize - maskIndex - 1));
    m_PowerOfTwoCopy &= mask;
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
    if (0 <= m_PowerOfTwo)
        return true;
    else
        return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>::IsLog2Valid() const noexcept
{
    if (0 <= gsl::narrow_cast<T>(m_Log2))
        return true;
    else
        return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>::IsConvertValid() const noexcept
{
    auto low = gsl::narrow_cast<T>(GetPowerOfTwoLow());
    const auto high = low * 2;
    auto original = m_PowerOfTwo;

    if (low <= original && (original < high || high < low))
        return true;
    else
        return false;
}

template <typename T>
uint32_t Mathematics::Log2OfPowerOfTwo<T>::GetPowerOfTwoLow() const noexcept
{
    auto powerOfTwo = 1u;
    for (auto i = 0u; i < m_Log2; ++i)
    {
        powerOfTwo *= 2;
    }

    return powerOfTwo;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
T Mathematics::Log2OfPowerOfTwo<T>::GetLog2() const
{
    CLASS_IS_VALID_5;

    return boost::numeric_cast<T>(m_Log2);
}

#endif  // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

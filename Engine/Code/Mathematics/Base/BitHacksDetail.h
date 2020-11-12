///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 14:31)

#ifndef MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
#define MATHEMATICS_BASE_BIT_HACKS_DETAIL_H

#include "BitHacks.h"
#include "Log2OfPowerOfTwoDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

// log2的快速整数算法
// 通过掩码计算出powerOfTwo的最高位数，即log2(powerOfTwo)的值。
template <typename T>
T Mathematics::BitHacks::Log2OfPowerOfTwo(T powerOfTwo)
{
    static_assert(std::is_integral_v<T>, "T must be integral.");
    MATHEMATICS_ASSERTION_3(0 < powerOfTwo, "值powerOfTwo必须大于0");

    const Mathematics::Log2OfPowerOfTwo<T> log2OfPowerOfTwo{ powerOfTwo };

    return log2OfPowerOfTwo.GetLog2();
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_DETAIL_H

///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:31)

#ifndef MATHEMATICS_BASE_BIT_HACKS_H
#define MATHEMATICS_BASE_BIT_HACKS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BitHacks final
    {
    public:
        using ClassType = BitHacks;

    public:
        BitHacks() = delete;

    public:
        template <typename T>
        [[nodiscard]] constexpr static bool IsPowerOfTwo(T value) noexcept
        {
            static_assert(std::is_integral_v<T>, "T must be integral.");

            return (0 < value) && ((value & (value - 1)) == 0);
        }

        template <typename T>
        [[nodiscard]] static T Log2OfPowerOfTwo(T powerOfTwo);

        // 从IEEE32位区间在[0,1]的浮点数F，
        // 快速转换为区间在[0,2^P-1]的一个32位整数I，
        // 输入“value”是F，输入“power”是P和函数的返回值是I。
        [[nodiscard]] static int32_t ScaledFloatToInt(float value, int power) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
    };
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_H

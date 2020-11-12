///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 13:31)

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

        // ��IEEE32λ������[0,1]�ĸ�����F��
        // ����ת��Ϊ������[0,2^P-1]��һ��32λ����I��
        // ���롰value����F�����롰power����P�ͺ����ķ���ֵ��I��
        [[nodiscard]] static int32_t ScaledFloatToInt(float value, int power) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
    };
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_H

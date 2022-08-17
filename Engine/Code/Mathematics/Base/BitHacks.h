///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/28 15:49)

#ifndef MATHEMATICS_BASE_BIT_HACKS_H
#define MATHEMATICS_BASE_BIT_HACKS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <array>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BitHacks final
    {
    public:
        using ClassType = BitHacks;

    public:
        BitHacks() noexcept = delete;

    public:
        template <typename T>
        NODISCARD constexpr static bool IsPowerOfTwo(T value) noexcept
        {
            static_assert(std::is_integral_v<T>, "T must be integral.");

            return (0 < value) && ((value & (value - 1)) == 0);
        }

        template <typename T>
        NODISCARD static T Log2OfPowerOfTwo(T powerOfTwo);

        // ��IEEE32λ������[0,1]�ĸ�����F��
        // ����ת��Ϊ������[0,2^P-1]��һ��32λ����I��
        // ���롰scaledFloat����F�����롰power����P�ͺ����ķ���ֵ��I��
        NODISCARD static int32_t ScaledFloatToInt(float scaledFloat, int power) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        NODISCARD static int GetLeadingBit(uint32_t value);
        NODISCARD static int GetLeadingBit(int32_t value);
        NODISCARD static int GetLeadingBit(uint64_t value);
        NODISCARD static int GetLeadingBit(int64_t value);

        NODISCARD static int GetTrailingBit(int32_t value);
        NODISCARD static int GetTrailingBit(uint32_t value);
        NODISCARD static int GetTrailingBit(uint64_t value);
        NODISCARD static int GetTrailingBit(int64_t value);

        NODISCARD static uint64_t RoundUpToPowerOfTwo(uint32_t value);
        NODISCARD static uint32_t RoundDownToPowerOfTwo(uint32_t value);
    };
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_H

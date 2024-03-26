/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 14:19)

#ifndef MATHEMATICS_BASE_BIT_HACKS_H
#define MATHEMATICS_BASE_BIT_HACKS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

/// GetLeadingBit�е�leadingBit���GetTrailingBit��trailingBit����ڵ²�³�����С�
/// �����ƽ⺯����int32����Ҫ���ǷǸ��ģ�����Ϊ��ʱ�����쳣��
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
        requires std::is_integral_v<T>
        NODISCARD static bool IsPowerOfTwo(T value);

        NODISCARD static uint32_t Log2OfPowerOfTwo(uint32_t powerOfTwo) noexcept;
        NODISCARD static int32_t Log2OfPowerOfTwo(int32_t powerOfTwo);
        NODISCARD static int Log2OfPowerOfTwo(uint64_t powerOfTwo) noexcept;
        NODISCARD static int Log2OfPowerOfTwo(int64_t powerOfTwo);

        // ��IEEE32λ������[0,1]�ĸ�����F��
        // ����ת��Ϊ������[0,2^P-1]��һ��32λ����I��
        // ���롰scaledFloat����F�����롰power����P�ͺ����ķ���ֵ��I��
        NODISCARD static int32_t ScaledFloatToInt(float scaledFloat, int power) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// �����ķ���ֵ��32λֵ��������
        /// ���磬 GetLeadingBit(10) = 3��GetTrailingBit(10) = 2��
        /// ������ֵΪ0x0000000000001010��
        /// λλ�ô�ͼ���Ҳ��0��ʼ����ͼ������31������
        /// �������ֵΪ�㣬��û��ǰ��λ��β��λ��
        /// ���ǣ���������0���ⱻ��Ϊ����Ч�ġ�
        /// ���Խ��������������Щ������
        NODISCARD static int GetLeadingBit(uint32_t value);
        NODISCARD static int GetLeadingBit(int32_t value);
        NODISCARD static int GetLeadingBit(uint64_t value);
        NODISCARD static int GetLeadingBit(int64_t value);

        NODISCARD static int GetTrailingBit(int32_t value);
        NODISCARD static int GetTrailingBit(uint32_t value);
        NODISCARD static int GetTrailingBit(uint64_t value);
        NODISCARD static int GetTrailingBit(int64_t value);

        /// �������뵽�����ݡ�
        /// �������Ϊ�㣬�򷵻�Ϊ1��
        /// ����������2^{31}���򷵻�2^{32}��
        NODISCARD static uint32_t RoundUpToPowerOfTwo(uint32_t value);

        /// �������뵽�����ݡ�
        /// �������Ϊ�㣬�򷵻�Ϊ0��
        NODISCARD static uint32_t RoundDownToPowerOfTwo(uint32_t value);

        NODISCARD static uint64_t RoundUpToPowerOfTwo(uint64_t value);
        NODISCARD static uint64_t RoundDownToPowerOfTwo(uint64_t value);
        NODISCARD static uint32_t RoundUpToPowerOfTwo(int32_t value);
        NODISCARD static uint32_t RoundDownToPowerOfTwo(int32_t value);
        NODISCARD static uint64_t RoundUpToPowerOfTwo(int64_t value);
        NODISCARD static uint64_t RoundDownToPowerOfTwo(int64_t value);

        NODISCARD static int PopulationCount(uint32_t value);
        NODISCARD static int PopulationCount(uint64_t value);

        NODISCARD static int GetNumLeadingZeroBits(uint32_t value);
        NODISCARD static int GetNumLeadingZeroBits(uint64_t value);

        NODISCARD static int GetNumTrailingZeroBits(uint32_t value);
        NODISCARD static int GetNumTrailingZeroBits(uint64_t value);
    };
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_H

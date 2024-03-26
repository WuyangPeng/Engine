/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 14:19)

#ifndef MATHEMATICS_BASE_BIT_HACKS_H
#define MATHEMATICS_BASE_BIT_HACKS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

/// GetLeadingBit中的leadingBit表和GetTrailingBit的trailingBit表基于德布鲁因序列。
/// 比特破解函数的int32输入要求是非负的，输入为负时引发异常。
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

        // 从IEEE32位区间在[0,1]的浮点数F，
        // 快速转换为区间在[0,2^P-1]的一个32位整数I，
        // 输入“scaledFloat”是F，输入“power”是P和函数的返回值是I。
        NODISCARD static int32_t ScaledFloatToInt(float scaledFloat, int power) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 函数的返回值是32位值的索引。
        /// 例如， GetLeadingBit(10) = 3，GetTrailingBit(10) = 2。
        /// 二进制值为0x0000000000001010。
        /// 位位置从图案右侧的0开始，到图案左侧的31结束。
        /// 如果输入值为零，则没有前导位和尾随位。
        /// 但是，函数返回0，这被认为是无效的。
        /// 尝试仅对正输入调用这些函数。
        NODISCARD static int GetLeadingBit(uint32_t value);
        NODISCARD static int GetLeadingBit(int32_t value);
        NODISCARD static int GetLeadingBit(uint64_t value);
        NODISCARD static int GetLeadingBit(int64_t value);

        NODISCARD static int GetTrailingBit(int32_t value);
        NODISCARD static int GetTrailingBit(uint32_t value);
        NODISCARD static int GetTrailingBit(uint64_t value);
        NODISCARD static int GetTrailingBit(int64_t value);

        /// 四舍五入到二的幂。
        /// 如果输入为零，则返回为1。
        /// 如果输入大于2^{31}，则返回2^{32}。
        NODISCARD static uint32_t RoundUpToPowerOfTwo(uint32_t value);

        /// 四舍五入到二的幂。
        /// 如果输入为零，则返回为0。
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

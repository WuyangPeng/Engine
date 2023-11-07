///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:51)

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
        BitHacks() noexcept = delete;

    public:
        template <typename T>
        requires std::is_integral_v<T>
        NODISCARD static bool IsPowerOfTwo(T value);

        NODISCARD static int Log2OfPowerOfTwo(uint32_t powerOfTwo);
        NODISCARD static int Log2OfPowerOfTwo(int32_t powerOfTwo);
        NODISCARD static int Log2OfPowerOfTwo(uint64_t powerOfTwo) noexcept;
        NODISCARD static int Log2OfPowerOfTwo(int64_t powerOfTwo);

        // 从IEEE32位区间在[0,1]的浮点数F，
        // 快速转换为区间在[0,2^P-1]的一个32位整数I，
        // 输入“scaledFloat”是F，输入“power”是P和函数的返回值是I。
        NODISCARD static int32_t ScaledFloatToInt(float scaledFloat, int power) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD static int GetLeadingBit(uint32_t value);
        NODISCARD static int GetLeadingBit(int32_t value);
        NODISCARD static int GetLeadingBit(uint64_t value);
        NODISCARD static int GetLeadingBit(int64_t value);

        NODISCARD static int GetTrailingBit(int32_t value);
        NODISCARD static int GetTrailingBit(uint32_t value);
        NODISCARD static int GetTrailingBit(uint64_t value);
        NODISCARD static int GetTrailingBit(int64_t value);

        NODISCARD static uint32_t RoundUpToPowerOfTwo(uint32_t value);
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

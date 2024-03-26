/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 14:21)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "Log2OfPowerOfTwoDetail.h"
#include "ScaledFloatToInt.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

uint32_t Mathematics::BitHacks::Log2OfPowerOfTwo(uint32_t powerOfTwo) noexcept
{
    auto log2 = (powerOfTwo & 0xAAAAAAAAu) != 0 ? 1 : 0;

    log2 |= (((powerOfTwo & 0xFFFF0000u) != 0) ? 1 : 0) << 4;
    log2 |= (((powerOfTwo & 0xFF00FF00u) != 0) ? 1 : 0) << 3;
    log2 |= (((powerOfTwo & 0xF0F0F0F0u) != 0) ? 1 : 0) << 2;
    log2 |= (((powerOfTwo & 0xCCCCCCCCu) != 0) ? 1 : 0) << 1;

    return log2;
}

int32_t Mathematics::BitHacks::Log2OfPowerOfTwo(int32_t powerOfTwo)
{
    if (powerOfTwo < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"s))
    }

    return boost::numeric_cast<int32_t>(Log2OfPowerOfTwo(boost::numeric_cast<uint32_t>(powerOfTwo)));
}

int Mathematics::BitHacks::Log2OfPowerOfTwo(uint64_t powerOfTwo) noexcept
{
    auto log2 = ((powerOfTwo & 0xAAAAAAAAAAAAAAAAull) != 0) ? 1 : 0;

    log2 |= ((powerOfTwo & 0xCCCCCCCCCCCCCCCCull) != 0 ? 1 : 0) << 1;
    log2 |= ((powerOfTwo & 0xF0F0F0F0F0F0F0F0ull) != 0 ? 1 : 0) << 2;
    log2 |= ((powerOfTwo & 0xFF00FF00FF00FF00ull) != 0 ? 1 : 0) << 3;
    log2 |= ((powerOfTwo & 0xFFFF0000FFFF0000ull) != 0 ? 1 : 0) << 4;
    log2 |= ((powerOfTwo & 0xFFFFFFFF00000000ull) != 0 ? 1 : 0) << 5;

    return log2;
}

int Mathematics::BitHacks::Log2OfPowerOfTwo(int64_t powerOfTwo)
{
    return Log2OfPowerOfTwo(boost::numeric_cast<uint64_t>(powerOfTwo));
}

int32_t Mathematics::BitHacks::ScaledFloatToInt(float scaledFloat, int power) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(0 <= scaledFloat && scaledFloat <= 1, "value的区间为[0,1]。");
    MATHEMATICS_ASSERTION_3(0 <= power && power <= 24, "power的区间为[0,24]。");

    const Mathematics::ScaledFloatToInt scaledFloatToInt{ scaledFloat, power };

    return scaledFloatToInt.GetScaledResult();
}

int Mathematics::BitHacks::GetLeadingBit(uint32_t value)
{
#ifndef BIT_HACKS_BETTER

    static const std::array leadingBitTable{ 0, 9, 1, 10, 13, 21, 2, 29,
                                             11, 14, 16, 18, 22, 25, 3, 30,
                                             8, 12, 20, 28, 15, 17, 24, 7,
                                             19, 27, 23, 6, 26, 5, 4, 31 };

    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;

    const auto key = (value * 0x07C4ACDDu) >> 27;

    return leadingBitTable.at(key);

#else  // !BIT_HACKS_BETTER

    return 31 - GetNumLeadingZeroBits(value);

#endif  // BIT_HACKS_BETTER
}

int Mathematics::BitHacks::GetLeadingBit(int32_t value)
{
    return GetLeadingBit(boost::numeric_cast<uint32_t>(value));
}

int Mathematics::BitHacks::GetLeadingBit(uint64_t value)
{
#ifndef BIT_HACKS_BETTER

    if (const auto v1 = boost::numeric_cast<uint32_t>((value >> 32) & 0x00000000FFFFFFFFull);
        v1 != 0)
    {
        return GetLeadingBit(v1) + 32;
    }

    const auto v0 = boost::numeric_cast<uint32_t>(value & 0x00000000FFFFFFFFull);
    return GetLeadingBit(v0);

#else  // !BIT_HACKS_BETTER

    return 63 - GetNumLeadingZeroBits(value);

#endif  // BIT_HACKS_BETTER
}

int Mathematics::BitHacks::GetLeadingBit(int64_t value)
{
    return GetLeadingBit(boost::numeric_cast<uint64_t>(value));
}

int Mathematics::BitHacks::GetTrailingBit(int32_t value)
{
#ifndef BIT_HACKS_BETTER

    static constexpr std::array trailingBitTable{ 0, 1, 28, 2, 29, 14, 24, 3,
                                                  30, 22, 20, 15, 25, 17, 4, 8,
                                                  31, 27, 13, 23, 21, 19, 16, 7,
                                                  26, 12, 18, 6, 11, 5, 10, 9 };

    const auto key = (gsl::narrow_cast<uint32_t>((value & -value) * 0x077CB531u)) >> 27;

    return trailingBitTable.at(key);

#else  // !BIT_HACKS_BETTER

    return GetTrailingBit(boost::numeric_cast<uint32_t>(value));

#endif  // BIT_HACKS_BETTER
}

int Mathematics::BitHacks::GetTrailingBit(uint32_t value)
{
#ifndef BIT_HACKS_BETTER

    /// GetTrailingBit(int32_t)函数包含实际实现。
    /// 如果要实现基于uint32_t的函数，
    /// （value&-value）语句会生成一个编译器警告，
    /// 警告否定一个无符号整数，这需要额外的逻辑来避免。
    return GetTrailingBit(boost::numeric_cast<int32_t>(value));

#else  // !BIT_HACKS_BETTER

    return GetNumTrailingZeroBits(value);

#endif  // BIT_HACKS_BETTER
}

int Mathematics::BitHacks::GetTrailingBit(int64_t value)
{
    return GetTrailingBit(boost::numeric_cast<uint64_t>(value));
}

int Mathematics::BitHacks::GetTrailingBit(uint64_t value)
{
#ifndef BIT_HACKS_BETTER

    if (const auto v0 = gsl::narrow_cast<uint32_t>(value & 0x00000000FFFFFFFFull);
        v0 != 0)
    {
        return GetTrailingBit(v0);
    }

    if (const auto v1 = gsl::narrow_cast<uint32_t>((value >> 32) & 0x00000000FFFFFFFFull);
        v1 != 0)
    {
        return GetTrailingBit(v1) + 32;
    }

    return 0;

#else  // !BIT_HACKS_BETTER

    return GetNumTrailingZeroBits(value);

#endif  // BIT_HACKS_BETTER
}

uint32_t Mathematics::BitHacks::RoundUpToPowerOfTwo(uint32_t value)
{
    if (0 < value)
    {
        const auto leading = GetLeadingBit(value);

        if (const auto mask = (1 << leading);
            (value & ~mask) == 0)
        {
            /// 值是二的幂
            return value;
        }
        else
        {
            /// 四舍五入到二的幂
            if ((mask & 0x80000000u) == 0)
                return (mask << 1);
            else
                return 0;
        }
    }
    else
    {
        return 1ull;
    }
}

uint32_t Mathematics::BitHacks::RoundDownToPowerOfTwo(uint32_t value)
{
    if (0 < value)
    {
        const auto leading = GetLeadingBit(value);
        const auto mask = (1 << leading);
        return mask;
    }
    else
    {
        return 0;
    }
}

uint64_t Mathematics::BitHacks::RoundUpToPowerOfTwo(uint64_t value)
{
    if (0 < value)
    {
        const auto leading = GetLeadingBit(value);

        if (const auto mask = (1LL << leading);
            (value & ~mask) == 0)
        {
            return value;
        }
        else
        {
            if ((mask & 0x8000000000000000ull) == 0)
                return (mask << 1ULL);
            else
                return 0;
        }
    }
    else
    {
        return 1ull;
    }
}

uint64_t Mathematics::BitHacks::RoundDownToPowerOfTwo(uint64_t value)
{
    if (0 < value)
    {
        const auto leading = GetLeadingBit(value);
        const auto mask = (1 << leading);
        return mask;
    }
    else
    {
        return 0;
    }
}

uint32_t Mathematics::BitHacks::RoundDownToPowerOfTwo(int32_t value)
{
    return RoundDownToPowerOfTwo(boost::numeric_cast<uint32_t>(value));
}

uint64_t Mathematics::BitHacks::RoundDownToPowerOfTwo(int64_t value)
{
    return RoundDownToPowerOfTwo(boost::numeric_cast<uint64_t>(value));
}

uint32_t Mathematics::BitHacks::RoundUpToPowerOfTwo(int32_t value)
{
    return RoundUpToPowerOfTwo(boost::numeric_cast<uint32_t>(value));
}

uint64_t Mathematics::BitHacks::RoundUpToPowerOfTwo(int64_t value)
{
    return RoundUpToPowerOfTwo(boost::numeric_cast<uint64_t>(value));
}

int Mathematics::BitHacks::PopulationCount(uint32_t value)
{
    value = (value & 0x55555555u) + ((value >> 1) & 0x55555555u);
    value = (value & 0x33333333u) + ((value >> 2) & 0x33333333u);
    value = (value & 0x0F0F0F0Fu) + ((value >> 4) & 0x0F0F0F0Fu);
    value = (value & 0x00FF00FFu) + ((value >> 8) & 0x00FF00FFu);
    value = (value & 0x0000FFFFu) + ((value >> 16) & 0x0000FFFFu);

    return boost::numeric_cast<int>(value);
}

int Mathematics::BitHacks::PopulationCount(uint64_t value)
{
    value = (value & 0x5555555555555555ull) + ((value >> 1) & 0x5555555555555555ull);
    value = (value & 0x3333333333333333ull) + ((value >> 2) & 0x3333333333333333ull);
    value = (value & 0x0F0F0F0F0F0F0F0Full) + ((value >> 4) & 0x0F0F0F0F0F0F0F0Full);
    value = (value & 0x00FF00FF00FF00FFull) + ((value >> 8) & 0x00FF00FF00FF00FFull);
    value = (value & 0x0000FFFF0000FFFFull) + ((value >> 16) & 0x0000FFFF0000FFFFull);
    value = (value & 0x00000000FFFFFFFFull) + ((value >> 32) & 0x00000000FFFFFFFFull);

    return boost::numeric_cast<int>(value & 0x00000000FFFFFFFFull);
}

int Mathematics::BitHacks::GetNumLeadingZeroBits(uint32_t value)
{
    value = value | (value >> 1);
    value = value | (value >> 2);
    value = value | (value >> 4);
    value = value | (value >> 8);
    value = value | (value >> 16);

    return PopulationCount(~value);
}

int Mathematics::BitHacks::GetNumLeadingZeroBits(uint64_t value)
{
    value = value | (value >> 1);
    value = value | (value >> 2);
    value = value | (value >> 4);
    value = value | (value >> 8);
    value = value | (value >> 16);
    value = value | (value >> 32);

    return PopulationCount(~value);
}

int Mathematics::BitHacks::GetNumTrailingZeroBits(uint32_t value)
{
    return boost::numeric_cast<int>(32 - GetNumLeadingZeroBits(~value & (value - 1)));
}

int Mathematics::BitHacks::GetNumTrailingZeroBits(uint64_t value)
{
    return boost::numeric_cast<int>(64 - GetNumLeadingZeroBits(~value & (value - 1)));
}

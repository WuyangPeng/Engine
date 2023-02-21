///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 22:20)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "ScaledFloatToInt.h"

#include <gsl/util>

int32_t Mathematics::BitHacks::ScaledFloatToInt(float scaledFloat, int power) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(0 <= scaledFloat && scaledFloat <= 1, "value的区间为[0,1]。");
    MATHEMATICS_ASSERTION_3(0 <= power && power <= 24, "power的区间为[0,24]。");

    const Mathematics::ScaledFloatToInt scaledFloatToInt{ scaledFloat, power };

    return scaledFloatToInt.GetScaledResult();
}

int Mathematics::BitHacks::GetLeadingBit(uint32_t value)
{
    static const std::array<int, 32> leadingBitTable{ 0, 9, 1, 10, 13, 21, 2, 29,
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
}

int Mathematics::BitHacks::GetLeadingBit(int32_t value)
{
    return GetLeadingBit(gsl::narrow_cast<uint32_t>(value));
}

int Mathematics::BitHacks::GetLeadingBit(uint64_t value)
{
    auto v1 = gsl::narrow_cast<uint32_t>((value >> 32) & 0x00000000FFFFFFFFull);
    if (v1 != 0)
    {
        return GetLeadingBit(v1) + 32;
    }

    auto v0 = gsl::narrow_cast<uint32_t>(value & 0x00000000FFFFFFFFull);
    return GetLeadingBit(v0);
}

int Mathematics::BitHacks::GetLeadingBit(int64_t value)
{
    return GetLeadingBit(gsl::narrow_cast<uint64_t>(value));
}

int Mathematics::BitHacks::GetTrailingBit(int32_t value)
{
    static const std::array<int, 32> trailingBitTable{ 0, 1, 28, 2, 29, 14, 24, 3,
                                                       30, 22, 20, 15, 25, 17, 4, 8,
                                                       31, 27, 13, 23, 21, 19, 16, 7,
                                                       26, 12, 18, 6, 11, 5, 10, 9 };

    auto key = (gsl::narrow_cast<uint32_t>((value & -value) * 0x077CB531u)) >> 27;

    return trailingBitTable.at(key);
}

int Mathematics::BitHacks::GetTrailingBit(uint32_t value)
{
    return GetTrailingBit(gsl::narrow_cast<int>(value));
}

int Mathematics::BitHacks::GetTrailingBit(int64_t value)
{
    return GetTrailingBit(gsl::narrow_cast<uint64_t>(value));
}

int Mathematics::BitHacks::GetTrailingBit(uint64_t value)
{
    auto v0 = gsl::narrow_cast<uint32_t>(value & 0x00000000FFFFFFFFull);
    if (v0 != 0)
    {
        return GetTrailingBit(v0);
    }

    auto v1 = gsl::narrow_cast<uint32_t>((value >> 32) & 0x00000000FFFFFFFFull);
    if (v1 != 0)
    {
        return GetTrailingBit(v1) + 32;
    }

    return 0;
}

uint64_t Mathematics::BitHacks::RoundUpToPowerOfTwo(uint32_t value)
{
    if (value > 0)
    {
        const auto leading = GetLeadingBit(value);
        const auto mask = (1 << leading);
        if ((value & ~mask) == 0)
        {
            return gsl::narrow_cast<uint64_t>(value);
        }
        else
        {
            return (gsl::narrow_cast<uint64_t>(mask) << 1);
        }
    }
    else
    {
        return 1ull;
    }
}

uint32_t Mathematics::BitHacks::RoundDownToPowerOfTwo(uint32_t value)
{
    if (value > 0)
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

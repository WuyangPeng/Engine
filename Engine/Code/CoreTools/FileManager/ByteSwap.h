/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:42)

#ifndef CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H
#define CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    constexpr auto gByteShiftStep = 16;
    constexpr auto gByteShift2 = 8;
    constexpr auto gByteShift4 = gByteShift2 + gByteShiftStep;
    constexpr auto gByteShift6 = gByteShift4 + gByteShiftStep;
    constexpr auto gByteShift8 = gByteShift6 + gByteShiftStep;

    constexpr auto gByteSwapMask0 = 0x000000FFu;
    constexpr auto gByteSwapMask1 = gByteSwapMask0 << gByteShift2;
    constexpr auto gByteSwapMask2 = gByteSwapMask1 << gByteShift2;
    constexpr auto gByteSwapMask3 = gByteSwapMask2 << gByteShift2;

    constexpr auto gByteSwapMask4 = static_cast<uint64_t>(gByteSwapMask3) << gByteShift2;
    constexpr auto gByteSwapMask5 = gByteSwapMask4 << gByteShift2;
    constexpr auto gByteSwapMask6 = gByteSwapMask5 << gByteShift2;
    constexpr auto gByteSwapMask7 = gByteSwapMask6 << gByteShift2;

    NODISCARD constexpr uint16_t ByteSwap2(uint16_t inData) noexcept
    {
        return (inData >> gByteShift2) | (inData << gByteShift2);
    }

    NODISCARD constexpr uint32_t ByteSwap4(uint32_t inData) noexcept
    {
        return ((inData >> gByteShift4) & gByteSwapMask0) |
               ((inData >> gByteShift2) & gByteSwapMask1) |
               ((inData << gByteShift2) & gByteSwapMask2) |
               ((inData << gByteShift4) & gByteSwapMask3);
    }

    NODISCARD constexpr uint64_t ByteSwap8(uint64_t inData) noexcept
    {
        return ((inData >> gByteShift8) & gByteSwapMask0) |
               ((inData >> gByteShift6) & gByteSwapMask1) |
               ((inData >> gByteShift4) & gByteSwapMask2) |
               ((inData >> gByteShift2) & gByteSwapMask3) |
               ((inData << gByteShift2) & gByteSwapMask4) |
               ((inData << gByteShift4) & gByteSwapMask5) |
               ((inData << gByteShift6) & gByteSwapMask6) |
               ((inData << gByteShift8) & gByteSwapMask7);
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H

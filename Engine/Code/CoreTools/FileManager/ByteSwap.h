///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 8:36)

#ifndef CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H
#define CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    constexpr auto g_ByteShiftStep = 16;
    constexpr auto g_ByteShift2 = 8;
    constexpr auto g_ByteShift4 = g_ByteShift2 + g_ByteShiftStep;
    constexpr auto g_ByteShift6 = g_ByteShift4 + g_ByteShiftStep;
    constexpr auto g_ByteShift8 = g_ByteShift6 + g_ByteShiftStep;

    constexpr auto g_ByteSwapMask0 = 0x000000FFu;
    constexpr auto g_ByteSwapMask1 = g_ByteSwapMask0 << g_ByteShift2;
    constexpr auto g_ByteSwapMask2 = g_ByteSwapMask1 << g_ByteShift2;
    constexpr auto g_ByteSwapMask3 = g_ByteSwapMask2 << g_ByteShift2;

    constexpr auto g_ByteSwapMask4 = static_cast<uint64_t>(g_ByteSwapMask3) << g_ByteShift2;
    constexpr auto g_ByteSwapMask5 = g_ByteSwapMask4 << g_ByteShift2;
    constexpr auto g_ByteSwapMask6 = g_ByteSwapMask5 << g_ByteShift2;
    constexpr auto g_ByteSwapMask7 = g_ByteSwapMask6 << g_ByteShift2;

    NODISCARD constexpr uint16_t ByteSwap2(uint16_t inData) noexcept
    {
        return (inData >> g_ByteShift2) | (inData << g_ByteShift2);
    }

    NODISCARD constexpr uint32_t ByteSwap4(uint32_t inData) noexcept
    {
        return ((inData >> g_ByteShift4) & g_ByteSwapMask0) |
               ((inData >> g_ByteShift2) & g_ByteSwapMask1) |
               ((inData << g_ByteShift2) & g_ByteSwapMask2) |
               ((inData << g_ByteShift4) & g_ByteSwapMask3);
    }

    NODISCARD constexpr uint64_t ByteSwap8(uint64_t inData) noexcept
    {
        return ((inData >> g_ByteShift8) & g_ByteSwapMask0) |
               ((inData >> g_ByteShift6) & g_ByteSwapMask1) |
               ((inData >> g_ByteShift4) & g_ByteSwapMask2) |
               ((inData >> g_ByteShift2) & g_ByteSwapMask3) |
               ((inData << g_ByteShift2) & g_ByteSwapMask4) |
               ((inData << g_ByteShift4) & g_ByteSwapMask5) |
               ((inData << g_ByteShift6) & g_ByteSwapMask6) |
               ((inData << g_ByteShift8) & g_ByteSwapMask7);
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H

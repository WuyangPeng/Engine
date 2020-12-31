///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/01 23:37)

#ifndef CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H
#define CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    constexpr uint16_t ByteSwap2(uint16_t inData) noexcept
    {
        return (inData >> 8) | (inData << 8);
    }

    constexpr uint32_t ByteSwap4(uint32_t inData) noexcept
    {
        return ((inData >> 24) & 0X000000FF) |
               ((inData >> 8) & 0X0000FF00) |
               ((inData << 8) & 0X00FF0000) |
               ((inData << 24) & 0XFF000000);
    }

    constexpr uint64_t ByteSwap8(uint64_t inData) noexcept
    {
        return ((inData >> 56) & 0X00000000000000FF) |
               ((inData >> 40) & 0X000000000000FF00) |
               ((inData >> 24) & 0X0000000000FF0000) |
               ((inData >> 8) & 0X00000000FF000000) |
               ((inData << 8) & 0X000000FF00000000) |
               ((inData << 24) & 0X0000FF0000000000) |
               ((inData << 40) & 0X00FF000000000000) |
               ((inData << 56) & 0XFF00000000000000);
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_BYTE_SWAP_H

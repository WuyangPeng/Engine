///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/01 23:37)

#ifndef CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H
#define CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H

#include "CoreTools/CoreToolsDll.h"

#include "ByteSwap.h"
#include "TypeAliaser.h"

namespace CoreTools
{
    template <typename T, size_t Size>
    class ByteSwapper;

    template <typename T>
    class ByteSwapper<T, 1>
    {
    public:
        using ClassType = ByteSwapper<T, 1>;

    public:
        constexpr T Swap(T inData) const noexcept
        {
            return inData;
        }
    };

    template <typename T>
    class ByteSwapper<T, 2>
    {
    public:
        using ClassType = ByteSwapper<T, 2>;

    public:
        constexpr T Swap(T inData) const noexcept
        {
            const auto result = ByteSwap2(TypeAliaser<T, uint16_t>(inData).Get());
            return TypeAliaser<uint16_t, T>(result).Get();
        }
    };

    template <typename T>
    class ByteSwapper<T, 4>
    {
    public:
        using ClassType = ByteSwapper<T, 4>;

    public:
        constexpr T Swap(T inData) const noexcept
        {
            const auto result = ByteSwap4(TypeAliaser<T, uint32_t>(inData).Get());
            return TypeAliaser<uint32_t, T>(result).Get();
        }
    };

    template <typename T>
    class ByteSwapper<T, 8>
    {
    public:
        using ClassType = ByteSwapper<T, 8>;

    public:
        constexpr T Swap(T inData) const noexcept
        {
            const auto result = ByteSwap8(TypeAliaser<T, uint64_t>(inData).Get());
            return TypeAliaser<uint64_t, T>(result).Get();
        }
    };

    template <typename T>
    static constexpr T ByteSwap(T inData) noexcept
    {
        return ByteSwapper<T, sizeof(T)>().Swap(inData);
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:52)

#ifndef CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H
#define CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H

#include "CoreTools/CoreToolsDll.h"

#include "ByteSwap.h"
#include "TypeAlias.h"

namespace CoreTools
{
    template <typename T, int Size>
    class ByteSwapper;

    template <typename T>
    class ByteSwapper<T, 1>
    {
    public:
        using ClassType = ByteSwapper<T, 1>;

    public:
        NODISCARD static T Swap(T inData) noexcept
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
        NODISCARD static T Swap(T inData) noexcept
        {
            const auto result = ByteSwap2(TypeAlias<T, uint16_t>(inData).Get());
            return TypeAlias<uint16_t, T>(result).Get();
        }
    };

    template <typename T>
    class ByteSwapper<T, 4>
    {
    public:
        using ClassType = ByteSwapper<T, 4>;

    public:
        NODISCARD static T Swap(T inData) noexcept
        {
            const auto result = ByteSwap4(TypeAlias<T, uint32_t>(inData).Get());
            return TypeAlias<uint32_t, T>(result).Get();
        }
    };

    template <typename T>
    class ByteSwapper<T, 8>
    {
    public:
        using ClassType = ByteSwapper<T, 8>;

    public:
        NODISCARD static T Swap(T inData) noexcept
        {
            const auto result = ByteSwap8(TypeAlias<T, uint64_t>(inData).Get());
            return TypeAlias<uint64_t, T>(result).Get();
        }
    };

    template <typename T>
    NODISCARD T ByteSwap(T inData) noexcept
    {
        return ByteSwapper<T, sizeof(T)>().Swap(inData);
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H

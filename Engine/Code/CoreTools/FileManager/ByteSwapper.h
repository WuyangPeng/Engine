///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:38)

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
        NODISCARD static T Swap(T inData) noexcept
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
        NODISCARD static T Swap(T inData) noexcept
        {
            const auto result = ByteSwap8(TypeAliaser<T, uint64_t>(inData).Get());
            return TypeAliaser<uint64_t, T>(result).Get();
        }
    };

    template <typename T>
    NODISCARD T ByteSwap(T inData) noexcept
    {
        return ByteSwapper<T, sizeof(T)>().Swap(inData);
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_BYTE_SWAPPER_H

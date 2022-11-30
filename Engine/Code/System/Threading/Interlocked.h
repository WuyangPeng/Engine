///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:04)

#ifndef SYSTEM_THREADING_INTERLOCKED_H
#define SYSTEM_THREADING_INTERLOCKED_H

#include "System/SystemDll.h"

namespace System
{
    // 原子操作

    template <typename T>
    NODISCARD T SystemInterlockedIncrement(T* addend) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedDecrement(T* addend) noexcept(std::is_same_v<long, T>);

    // 返回的是原来的值。
    template <typename T>
    NODISCARD T SystemInterlockedExchangeAdd(T* addend, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedExchange(T* target, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedExchangeSubtract(T* addend, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedCompareExchange(T* destination, T exchange, T comperand) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedAnd(T* destination, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedOr(T* destination, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedXor(T* destination, T value) noexcept(std::is_same_v<long, T>);
}

#endif  // SYSTEM_THREADING_INTERLOCKED_H
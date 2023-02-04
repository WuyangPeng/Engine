///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/01/30 12:58)

#ifndef SYSTEM_THREADING_INTERLOCKED_DETAIL_H
#define SYSTEM_THREADING_INTERLOCKED_DETAIL_H

#include "Interlocked.h"
#include "System/Helper/Platform.h"

template <typename T>
T System::SystemInterlockedIncrement(T* addend) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedIncrement(addend);

#else  // !SYSTEM_PLATFORM_WIN32

    return ++(*addend);

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedDecrement(T* addend) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedDecrement(addend);

#else  // !SYSTEM_PLATFORM_WIN32

    return --(*addend);

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedExchangeAdd(T* addend, T value) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedExchangeAdd(addend, value);

#else  // !SYSTEM_PLATFORM_WIN32

    return (*addend) += value;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedExchange(T* target, T value) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedExchange(target, value);

#else  // !SYSTEM_PLATFORM_WIN32

    auto old = *target;
    *target = value;
    return old;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedExchangeSubtract(T* addend, T value) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedExchangeSubtract(addend, value);

#else  // !SYSTEM_PLATFORM_WIN32

    return (*addend) -= value;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedCompareExchange(T* destination, T exchange, T comperand) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedCompareExchange(destination, exchange, comperand);

#else  // !SYSTEM_PLATFORM_WIN32

    auto old = *destination;
    if (old == comperand)
    {
        *destination = exchange;
    }

    return old;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedAnd(T* destination, T value) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedAnd(destination, value);

#else  // !SYSTEM_PLATFORM_WIN32

    return (*destination) &= value;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedOr(T* destination, T value) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedOr(destination, value);

#else  // !SYSTEM_PLATFORM_WIN32

    return (*destination) |= value;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
T System::SystemInterlockedXor(T* destination, T value) noexcept(std::is_same_v<long, T>)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InterlockedXor(destination, value);

#else  // !SYSTEM_PLATFORM_WIN32

    return (*destination) ^= value;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_INTERLOCKED_DETAIL_H
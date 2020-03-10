// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:04)

#ifndef SYSTEM_THREADING_INTERLOCKED_DETAIL_H
#define SYSTEM_THREADING_INTERLOCKED_DETAIL_H

#include "Interlocked.h"
#include "System/Helper/Platform.h"

template<typename T>
T System
	::SystemInterlockedIncrement(T* addend) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::InterlockedIncrement(addend);
#else // !SYSTEM_PLATFORM_WIN32
	return ++(*addend);
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedDecrement(T* addend) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedDecrement(addend);
#else // !SYSTEM_PLATFORM_WIN32
	return --(*addend);
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedExchangeAdd(T* addend, T value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::InterlockedExchangeAdd(addend, value);
#else // !SYSTEM_PLATFORM_WIN32
	return (*addend) += value;
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedExchange(T* target, T value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedExchange(target, value);
#else // !SYSTEM_PLATFORM_WIN32
	T old = *target;
	*target = value;
	return old;
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedExchangeSubtract(T* addend, T value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedExchangeSubtract(addend, value);
#else // !SYSTEM_PLATFORM_WIN32
	return (*addend) -= value;
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedCompareExchange(T* destination, T exchange, T comperand) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedCompareExchange(destination, exchange,comperand);
#else // !SYSTEM_PLATFORM_WIN32
	auto old = *destination;
	if (old == comperand)
	{
		*destination = exchange;
	}
	
	return old;
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedAnd(T* destination, T value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedAnd(destination, value);
#else // !SYSTEM_PLATFORM_WIN32
	return (*destination) &= value;
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedOr(T* destination, T value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedOr(destination, value);
#else // !SYSTEM_PLATFORM_WIN32
	return (*destination) |= value;
#endif // SYSTEM_PLATFORM_WIN32
}

template<typename T>
T System
	::SystemInterlockedXor(T* destination, T value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InterlockedXor(destination, value);
#else // !SYSTEM_PLATFORM_WIN32
	return (*destination) ^= value;
#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_INTERLOCKED_DETAIL_H
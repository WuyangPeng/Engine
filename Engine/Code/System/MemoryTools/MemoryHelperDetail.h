// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 0:00)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H

#include "MemoryHelper.h" 

template<typename T>
void System
	::FillMemoryToZero(T& value) noexcept
{
	static_assert(std::is_pod_v<T>);

	::ZeroMemory(&value, sizeof(T));
}

template <typename T>
T System
	::GetWindowsStructDefaultSize() noexcept
{
	static_assert(std::is_nothrow_default_constructible_v<T>);

	T value{ };

	value.cbSize = sizeof(T);

	return value;
}

#endif // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H
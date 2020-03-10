// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:21)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H

#include "MemoryHelper.h" 

template<typename T>
void System
	::FillMemoryToZero(T& value) noexcept
{
	::ZeroMemory(&value, sizeof(T));
}

template <typename T>
T System
	::GetWindowsStructDefaultSize() noexcept
{
	T value{};

	value.cbSize = sizeof(T);

	return value;
}

#endif // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H
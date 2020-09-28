//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:56)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H

#include "HeapTools.h"
#include "Flags/HeapToolsFlags.h"

#include <new>

template <typename T>
T* System::AllocateProcessHeap(uint32_t length) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return static_cast<T*>(AllocateProcessHeap(GetCurrentProcessHeap(), HeapCreate::ZeroMemory, length * sizeof(T)));
#else  // !SYSTEM_PLATFORM_WIN32
    return new (std::nothrow) T[length];
#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
bool System::FreeProcessHeap(T* ptr) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return FreeProcessHeap(GetCurrentProcessHeap(), HeapCreate::Default, ptr);
#else  // !SYSTEM_PLATFORM_WIN32
    delete[] ptr;

    return true;
#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H

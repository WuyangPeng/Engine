///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:39)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H

#include "HeapTools.h"
#include "Flags/HeapToolsFlags.h"

#include <new>

template <typename T>
T* System::AllocateProcessHeap(size_t length) noexcept
{
    static_assert(std::is_pod_v<T>);

#ifdef SYSTEM_PLATFORM_WIN32

    return static_cast<T*>(AllocateProcessHeap(GetCurrentProcessHeap(), HeapCreate::ZeroMemory, length * sizeof(T)));

#else  // !SYSTEM_PLATFORM_WIN32

    return new (std::nothrow) T[length];

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
bool System::FreeProcessHeap(T* memory) noexcept
{
    static_assert(std::is_pod_v<T>);

#ifdef SYSTEM_PLATFORM_WIN32

    return FreeProcessHeap(GetCurrentProcessHeap(), HeapCreate::Default, memory);

#else  // !SYSTEM_PLATFORM_WIN32

    delete[] memory;

    return true;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H

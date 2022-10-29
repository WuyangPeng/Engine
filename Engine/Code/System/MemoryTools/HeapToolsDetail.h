///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/16 19:22)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H

#include "HeapTools.h"
#include "Flags/HeapToolsFlags.h"

#include <new>
#include <type_traits>

template <typename T>
T* System::AllocateProcessHeap(size_t length) noexcept
{
    static_assert(std::is_trivial_v<T> && std::is_standard_layout_v<T>);

#ifdef SYSTEM_PLATFORM_WIN32

    return static_cast<T*>(AllocateProcessHeap(GetCurrentProcessHeap(), HeapCreate::ZeroMemory, length * sizeof(T)));

#else  // !SYSTEM_PLATFORM_WIN32

    return new (std::nothrow) T[length];

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename T>
bool System::FreeProcessHeap(T* memory) noexcept
{
    static_assert(std::is_trivial_v<T> && std::is_standard_layout_v<T>);

#ifdef SYSTEM_PLATFORM_WIN32

    return FreeProcessHeap(GetCurrentProcessHeap(), HeapCreate::Default, memory);

#else  // !SYSTEM_PLATFORM_WIN32

    delete[] memory;

    return true;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_DETAIL_H

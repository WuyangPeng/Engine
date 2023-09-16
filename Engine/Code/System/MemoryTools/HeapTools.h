///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:00)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <type_traits>

// 分配堆与内存工具。
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateProcessHeap(HeapCreate options, WindowsSize initialSize, WindowsSize maximumSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DestroyProcessHeap(WindowsHandle heap) noexcept;

    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE AllocateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsSize bytes) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetProcessHeapSize(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE ValidateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetProcessHeapCompact(WindowsHandle heap, HeapCreate flags) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeap() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeaps(WindowsDWord numberOfHeaps, WindowsHandlePtr processHeaps) noexcept;

    template <typename T>
    requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
    MAYBE_NULLPTR T* AllocateProcessHeap(size_t length) noexcept;

    template <typename T>
    requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
    NODISCARD bool FreeProcessHeap(T* memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
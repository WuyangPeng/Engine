//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:00)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/HeapToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 分配堆与内存工具。

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateProcessHeap(HeapCreate options, WindowSize initialSize, WindowSize maximumSize) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DestroyProcessHeap(WindowHandle heap) noexcept;

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE AllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowSize bytes) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE ReAllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem, WindowSize bytes) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FreeProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;
    [[nodiscard]] WindowSize SYSTEM_DEFAULT_DECLARE GetProcessHeapSize(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ValidateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;
    [[nodiscard]] WindowSize SYSTEM_DEFAULT_DECLARE GetProcessHeapCompact(WindowHandle heap, HeapCreate flags) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeap() noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeaps(WindowDWord numberOfHeaps, WindowHandlePtr processHeaps) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LockProcessHeap(WindowHandle heap) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UnlockProcessHeap(WindowHandle heap) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WalkProcessHeap(WindowHandle heap, MemoryProcessHeapEntryPtr entry) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnableProcessHeapTerminationOnCorruption(WindowHandle heapHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE QueryProcessHeapInformation(WindowHandle heapHandle, WindowULong* heapInformation) noexcept;

    template <typename T>
    [[nodiscard]] T* AllocateProcessHeap(uint32_t length) noexcept;

    template <typename T>
    [[nodiscard]] bool FreeProcessHeap(T* ptr) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
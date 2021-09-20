///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/19 15:00)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/HeapToolsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // ��������ڴ湤�ߡ�

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateProcessHeap(HeapCreate options, WindowsSize initialSize, WindowsSize maximumSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DestroyProcessHeap(WindowsHandle heap) noexcept;

    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE AllocateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsSize bytes) noexcept;
    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE ReAllocateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory, WindowsSize bytes) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetProcessHeapSize(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE ValidateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetProcessHeapCompact(WindowsHandle heap, HeapCreate flags) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeap() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeaps(WindowsDWord numberOfHeaps, WindowsHandlePtr processHeaps) noexcept;

    template <typename T>
    MAYBE_NULLPTR T* AllocateProcessHeap(size_t length) noexcept;

    template <typename T>
    NODISCARD bool FreeProcessHeap(T* memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
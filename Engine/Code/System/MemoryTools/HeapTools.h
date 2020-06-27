// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 0:07)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H

#include "System/SystemDll.h"

#include "Using/HeapToolsUsing.h"
#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 分配堆与内存工具。

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateProcessHeap(HeapCreate options, WindowSize initialSize, WindowSize maximumSize) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DestroyProcessHeap(WindowHandle heap) noexcept;

	WindowVoidPtr SYSTEM_DEFAULT_DECLARE AllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowSize bytes) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE ReAllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem, WindowSize bytes) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FreeProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;
	WindowSize SYSTEM_DEFAULT_DECLARE GetProcessHeapSize(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;

	bool SYSTEM_DEFAULT_DECLARE ValidateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;
	WindowSize SYSTEM_DEFAULT_DECLARE GetProcessHeapCompact(WindowHandle heap, HeapCreate flags) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeap() noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHeaps(WindowDWord numberOfHeaps, WindowHandlePtr processHeaps) noexcept;

	bool SYSTEM_DEFAULT_DECLARE LockProcessHeap(WindowHandle heap) noexcept;
	bool SYSTEM_DEFAULT_DECLARE UnlockProcessHeap(WindowHandle heap) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WalkProcessHeap(WindowHandle heap, MemoryProcessHeapEntryPtr entry) noexcept;

	bool SYSTEM_DEFAULT_DECLARE EnableProcessHeapTerminationOnCorruption(WindowHandle heapHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE QueryProcessHeapInformation(WindowHandle heapHandle, WindowULong* heapInformation) noexcept;

	template <typename T>
	T* AllocateProcessHeap(uint32_t length) noexcept;

	template <typename T>
	bool FreeProcessHeap(T* ptr) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_H
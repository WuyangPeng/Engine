// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_FWD_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_FWD_H 

#include "MemoryToolsFlagsFwd.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"
 
namespace System
{	
	WindowHandle CreateProcessHeap(HeapCreate options, WindowSize initialSize, WindowSize maximumSize) noexcept;
	bool DestroyProcessHeap(WindowHandle heap) noexcept;

	WindowVoidPtr AllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowSize bytes) noexcept;
	WindowVoidPtr ReAllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem, WindowSize bytes) noexcept;
	bool FreeProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;
	WindowSize GetProcessHeapSize(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;

	bool ValidateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept;
	WindowSize GetProcessHeapCompact(WindowHandle heap, HeapCreate flags) noexcept;
	WindowHandle GetCurrentProcessHeap() noexcept;
	WindowDWord GetCurrentProcessHeaps(WindowDWord numberOfHeaps, WindowHandlePtr processHeaps) noexcept;
	
	bool LockProcessHeap(WindowHandle heap) noexcept;
	bool UnlockProcessHeap(WindowHandle heap) noexcept;
	bool WalkProcessHeap(WindowHandle heap, MemoryProcessHeapEntryPtr entry) noexcept;
	
	bool EnableProcessHeapTerminationOnCorruption(WindowHandle heapHandle) noexcept;
	bool QueryProcessHeapInformation(WindowHandle heapHandle, WindowULong* heapInformation) noexcept;
	  
	template <typename T>
	T* AllocateProcessHeap(uint32_t length) noexcept;

	template <typename T>
	bool FreeProcessHeap(T* ptr) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_FWD_H
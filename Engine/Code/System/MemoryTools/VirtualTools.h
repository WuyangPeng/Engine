// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:23)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H

#include "System/SystemDll.h" 

#include "Using/HeapToolsUsing.h"
#include "Using/VirtualToolsUsing.h" 
#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// –Èƒ‚ƒ⁄¥Êπ§æﬂ°£

	WindowVoidPtr SYSTEM_DEFAULT_DECLARE AllocateVirtual(WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FreeVirtual(WindowVoidPtr address) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetVirtualProtect(WindowVoidPtr address, WindowSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetVirtualQuery(WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;

	WindowVoidPtr SYSTEM_DEFAULT_DECLARE AllocateVirtual(WindowHandle process, WindowVoidPtr address, WindowSize size,
														 MemoryAllocation allocationType, MemoryProtect protect) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FreeVirtual(WindowHandle process, WindowVoidPtr address) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetVirtualProtect(WindowHandle process, WindowVoidPtr address, WindowSize size,
												  MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetVirtualQuery(WindowHandle process, WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;

	bool SYSTEM_DEFAULT_DECLARE LockVirtual(WindowVoidPtr address, WindowSize size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE UnlockVirtual(WindowVoidPtr address, WindowSize size) noexcept;

	WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetVirtualAllocNuma(WindowHandle process, WindowVoidPtr address, WindowSize size,
															 MemoryAllocation allocationType, MemoryProtect protect, WindowDWord preferred) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H
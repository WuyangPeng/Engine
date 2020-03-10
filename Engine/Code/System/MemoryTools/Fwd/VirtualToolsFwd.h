// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_FWD_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_FWD_H 

#include "MemoryToolsFlagsFwd.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"
#include "System/MemoryTools/Using/VirtualToolsUsing.h"

namespace System
{
	WindowVoidPtr AllocateVirtual(WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept;
	bool FreeVirtual(WindowVoidPtr address) noexcept;

	bool SetVirtualProtect(WindowVoidPtr address, WindowSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept;

	bool GetVirtualQuery(WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;

	WindowVoidPtr AllocateVirtual(WindowHandle process, WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept;
	bool FreeVirtual(WindowHandle process, WindowVoidPtr address) noexcept;
	bool SetVirtualProtect(WindowHandle process, WindowVoidPtr address, WindowSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept;
	bool GetVirtualQuery(WindowHandle process, WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;

	bool LockVirtual(WindowVoidPtr address, WindowSize size) noexcept;
	bool UnlockVirtual(WindowVoidPtr address, WindowSize size) noexcept;

	WindowVoidPtr GetVirtualAllocNuma(WindowHandle process, WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect, WindowDWord preferred) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_FWD_H
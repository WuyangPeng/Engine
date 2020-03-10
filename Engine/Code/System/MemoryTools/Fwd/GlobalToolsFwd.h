// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_FWD_H
#define SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_FWD_H 

#include "MemoryToolsFlagsFwd.h"
#include "System/MemoryTools/Using/GlobalToolsUsing.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
	DynamicLinkGlobal GlobalAllocBytes(GlobalMemory flags, WindowSize bytes) noexcept;
	DynamicLinkGlobal GlobalReAllocBytes(DynamicLinkGlobal mem, WindowSize bytes, GlobalMemory flags) noexcept;
	WindowSize GetGlobalSize(DynamicLinkGlobal mem) noexcept;
	GlobalMemory GetGlobalFlags(DynamicLinkGlobal mem) noexcept;

	WindowVoidPtr GetGlobalLock(DynamicLinkGlobal mem) noexcept;
	DynamicLinkGlobal GetGlobalHandle(WindowVoidPtr mem) noexcept;
	bool GetGlobalUnlock(DynamicLinkGlobal mem) noexcept;
	DynamicLinkGlobal GetGlobalFree(DynamicLinkGlobal mem) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_FWD_H
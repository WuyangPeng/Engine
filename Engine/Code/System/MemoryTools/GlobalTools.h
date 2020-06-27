// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 0:07)

#ifndef SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
	// 全局堆分配函数

	DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GlobalAllocBytes(GlobalMemory flags, WindowSize bytes) noexcept;
	DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GlobalReAllocBytes(DynamicLinkGlobal mem, WindowSize bytes, GlobalMemory flags) noexcept;
	WindowSize SYSTEM_DEFAULT_DECLARE GetGlobalSize(DynamicLinkGlobal mem) noexcept;
	GlobalMemory SYSTEM_DEFAULT_DECLARE GetGlobalFlags(DynamicLinkGlobal mem) noexcept;

	WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetGlobalLock(DynamicLinkGlobal mem) noexcept;
	DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GetGlobalHandle(WindowVoidPtr mem) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetGlobalUnlock(DynamicLinkGlobal mem) noexcept;
	DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GetGlobalFree(DynamicLinkGlobal mem) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_H
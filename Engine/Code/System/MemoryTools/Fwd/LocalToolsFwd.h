// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_FWD_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_FWD_H

#include "MemoryToolsFlagsFwd.h"
#include "System/CharacterString/Using/CodePageUsing.h"

namespace System
{
	bool LocalMemoryFree(WindowHLocal& memory) noexcept;
	WindowHLocal LocalMemoryAlloc(LocalMemory flags, WindowSize bytes) noexcept; 
	WindowVoidPtr LocalMemoryLock(WindowHLocal& memory) noexcept;
	bool LocalMemoryUnlock(WindowHLocal& memory) noexcept;
	WindowHLocal GetLocalMemoryHandle(WindowConstVoidPtr memory) noexcept;
	WindowSize GetLocalMemorySize(WindowHLocal& memory) noexcept;
	WindowUInt GetLocalMemoryFlags(WindowHLocal& memory) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_FWD_H
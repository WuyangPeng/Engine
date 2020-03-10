// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_FLAGS_H

#include "System/Helper/Platform.h" 

namespace System
{	 
#ifdef SYSTEM_PLATFORM_WIN32 

	enum class GlobalMemory
	{
		Fixed = GMEM_FIXED,
		Moveable = GMEM_MOVEABLE,
		NoCompact = GMEM_NOCOMPACT,
		NoDiscard = GMEM_NODISCARD,
		ZeroInit = GMEM_ZEROINIT,
		Modify = GMEM_MODIFY,
		Discardable = GMEM_DISCARDABLE,
		NotBanked = GMEM_NOT_BANKED,
		Share = GMEM_SHARE,
		Ddeshare = GMEM_DDESHARE,
		Notify = GMEM_NOTIFY,
		Lower  = GMEM_LOWER,
		ValidFlags = GMEM_VALID_FLAGS,
		InvalidHandle = GMEM_INVALID_HANDLE,
		Ghnd = GHND,
		GPtr = GPTR,
		Discarded = GMEM_DISCARDED,
		LockCount = GMEM_LOCKCOUNT,
	};

#else // !SYSTEM_PLATFORM_WIN32  

	enum class GlobalMemory
	{
		Fixed = 0x0000,
		Moveable = 0x0002,
		NoCompact = 0x0010,
		NoDiscard = 0x0020,
		ZeroInit = 0x0040,
		Modify = 0x0080,
		Discardable = 0x0100,
		NotBanked = 0x1000,
		Share = 0x2000,
		Ddeshare = 0x2000,
		Notify = 0x4000,
		Lower = NotBanked,
		ValidFlags = 0x7F72,
		InvalidHandle = 0x8000,
		Ghnd = Moveable | ZeroInit,
		GPtr = Fixed | ZeroInit,
		Discarded = 0x4000,
		LockCount = 0x00FF,
	};
		
#endif // SYSTEM_PLATFORM_WIN32	 
}

#endif // SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_FLAGS_H

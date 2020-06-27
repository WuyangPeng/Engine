// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 23:57)

#ifndef SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_USING_H
#define SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_USING_H

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using WindowMemoryStatus = MEMORYSTATUS;
	using WindowMemoryStatusPtr = LPMEMORYSTATUS;

#else // !SYSTEM_PLATFORM_WIN32	 

	struct WindowMemoryStatus
	{
		WindowDWord dwLength;
		WindowDWord dwMemoryLoad;
		WindowSize dwTotalPhys;
		WindowSize dwAvailPhys;
		WindowSize dwTotalPageFile;
		WindowSize dwAvailPageFile;
		WindowSize dwTotalVirtual;
		WindowSize dwAvailVirtual;
	};

	using WindowMemoryStatusPtr = WindowMemoryStatus*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_USING_H
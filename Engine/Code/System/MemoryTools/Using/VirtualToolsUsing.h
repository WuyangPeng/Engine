// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:23)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using MemoryBasicInformation = MEMORY_BASIC_INFORMATION;
	using MemoryBasicInformationPtr = PMEMORY_BASIC_INFORMATION;

#else // !SYSTEM_PLATFORM_WIN32		

	struct MemoryBasicInformation
	{
		void* BaseAddress;
		void* AllocationBase;
		WindowDWord AllocationProtect;
		WindowSize RegionSize;
		WindowDWord State;
		WindowDWord Protect;
		WindowDWord Type;
	};

	using MemoryBasicInformationPtr = MemoryBasicInformation*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H
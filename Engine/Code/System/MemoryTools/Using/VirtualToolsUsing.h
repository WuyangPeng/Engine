// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 23:58)

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
		uint32_t AllocationProtect;
		size_t RegionSize;
		uint32_t State;
		uint32_t Protect;
		uint32_t Type;
	};

	using MemoryBasicInformationPtr = MemoryBasicInformation*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H
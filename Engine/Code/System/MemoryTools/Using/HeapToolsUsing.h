// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:23)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_USING_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_USING_H

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	 

	using MemoryProcessHeapEntry = PROCESS_HEAP_ENTRY;
	using MemoryProcessHeapEntryPtr = LPPROCESS_HEAP_ENTRY;
	using MemoryHeapInformationClass = HEAP_INFORMATION_CLASS;

#else // !SYSTEM_PLATFORM_WIN32	   

	struct MemoryProcessHeapEntry
	{
		WindowVoidPtr lpData;
		WindowDWord cbData;
		uint8_t cbOverhead;
		uint8_t iRegionIndex;
		uint16_t wFlags;
		union
		{
			struct
			{
				WindowHandle hMem;
				WindowDWord dwReserved[3];
			} Block;
			struct
			{
				WindowDWord dwCommittedSize;
				WindowDWord dwUnCommittedSize;
				WindowVoidPtr lpFirstBlock;
				WindowVoidPtr lpLastBlock;
			} Region;
		} DUMMYUNIONNAME;
	};

	using MemoryProcessHeapEntryPtr = MemoryProcessHeapEntry*;

	enum MemoryHeapInformationClass
	{
		HeapCompatibilityInformation = 0,
		HeapEnableTerminationOnCorruption = 1,
		HeapOptimizeResources = 3,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_USING_H
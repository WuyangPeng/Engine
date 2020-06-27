// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 23:55)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H 
 
#include "System/Helper/ConfigMacro.h"

namespace System
{	
	// GlobalTools
	enum class GlobalMemory;

	// HeapTools
	enum class HeapCreate;
	enum class ProcessHeap;

	// LocalMemory
	enum class LocalMemory;

	// MemoryHelper
	enum class WorkingSetSizesQuotaLimits;
	enum class FileCache;
	enum class WriteWatch;

	// ViewOfFile
	enum class FileMapDesiredAccess;
	enum class FileMapProtection : uint32_t;

	// VirtualTools
	enum class MemoryAllocation : uint32_t;
	enum class MemoryProtect;
}

#endif // SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H
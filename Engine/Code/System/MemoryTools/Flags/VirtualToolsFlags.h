// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H

#include "System/Helper/Platform.h" 
#include "System/Helper/EnumMacro.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32 

	enum class MemoryAllocation : uint32_t
	{  
		Zero = 0,
		Commit = MEM_COMMIT,
		Reserve = MEM_RESERVE,
		ReserveAndCommit = Reserve | Commit,
		Reset = MEM_RESET,
		Physical = MEM_PHYSICAL | Reserve,

		LargePages = MEM_LARGE_PAGES,		
		TopDown = MEM_TOP_DOWN,
		WriteWatch = MEM_WRITE_WATCH | Reserve,

		DeCommit = MEM_DECOMMIT,
		Release = MEM_RELEASE,

		Free = MEM_FREE,
		Private = MEM_PRIVATE,
		Mapped = MEM_MAPPED,			
		Rotate = MEM_ROTATE,		
		Mem4mbPages = MEM_4MB_PAGES, 
	};	

	enum class MemoryProtect 
	{  
		NoAccess = PAGE_NOACCESS,
		Guard = PAGE_GUARD,			

		ReadOnly = PAGE_READONLY,
		ReadWrite = PAGE_READWRITE,		
		Execute = PAGE_EXECUTE,
		ExecuteRead = PAGE_EXECUTE_READ,
		ExecuteReadWrite = PAGE_EXECUTE_READWRITE,

		WriteCopy = PAGE_WRITECOPY,
		ExecuteWriteCopy = PAGE_EXECUTE_WRITECOPY,

		Nocache = PAGE_NOCACHE,
		WriteCombine = PAGE_WRITECOMBINE,
	};
	
#else // !SYSTEM_PLATFORM_WIN32 

	enum class MemoryAllocation : uint32_t
	{  
		Zero = 0,
		Commit = 0x1000,    
		Reserve = 0x2000,    
		ReserveAndCommit = Reserve | Commit,
		DeCommit = 0x4000,      
		Release = 0x8000,      
		Free = 0x10000,     
		Private = 0x20000,     
		Mapped = 0x40000,     
		Reset = 0x80000,     
		TopDown = 0x100000,    
		WriteWatch = 0x200000 | Reserve,   
		Physical = 0x400000 | Reserve,    
		Rotate = 0x800000,    
		LargePages = 0x20000000,  
		Mem4mbPages = 0x80000000,  
	};	

	enum class MemoryProtect 
	{  
		NoAccess = 0x01,     
		ReadOnly = 0x02,     
		ReadWrite = 0x04,     
		WriteCopy = 0x08,    
		Execute = 0x10,     
		ExecuteRead = 0x20,     
		ExecuteReadWrite = 0x40,     
		ExecuteWriteCopy = 0x80,                     
		Guard = 0x100,
		Nocache = 0x200,
		WriteCombine = 0x400,
	};
	
#endif // SYSTEM_PLATFORM_WIN32

	ENUM_ORABLE_OPERATOR_DEFINE(MemoryAllocation);
	ENUM_ORABLE_OPERATOR_DEFINE(MemoryProtect);
}

#endif // SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H

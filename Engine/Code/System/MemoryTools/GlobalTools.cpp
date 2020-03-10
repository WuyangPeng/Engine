// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:23)

#include "System/SystemExport.h"

#include "GlobalTools.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

#include <new>

System::DynamicLinkGlobal System
	::GlobalAllocBytes(GlobalMemory flags, WindowSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GlobalAlloc(EnumCastUnderlying(flags), bytes);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flags);

	return new(std::nothrow) char[WindowSize];
#endif // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System
	::GlobalReAllocBytes(DynamicLinkGlobal mem, WindowSize bytes, GlobalMemory flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GlobalReAlloc(mem, bytes, EnumCastUnderlying(flags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flags);

	delete[] mem;

	return new(std::nothrow) char[WindowSize];
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System
	::GetGlobalSize(DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GlobalSize(mem);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mem);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::GlobalMemory System
	::GetGlobalFlags(DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return UnderlyingCastEnum<GlobalMemory>(::GlobalFlags(mem));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mem);

	return GlobalMemory::Fixed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::GetGlobalLock(DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GlobalLock(mem);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mem);

	return mem;
#endif // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System
	::GetGlobalHandle(WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GlobalHandle(mem);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mem);

	return mem;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetGlobalUnlock(DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::GlobalUnlock(mem) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mem);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System
	::GetGlobalFree(DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GlobalFree(mem);
#else // !SYSTEM_PLATFORM_WIN32
	delete[] mem;

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}


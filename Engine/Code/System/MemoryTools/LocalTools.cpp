// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:24)

#include "System/SystemExport.h"

#include "LocalTools.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::LocalMemoryFree(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::LocalFree(memory) != nullptr)
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	delete[] memory;

	return true;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHLocal System
	::LocalMemoryAlloc(LocalMemory flags, WindowSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LocalAlloc(EnumCastUnderlying(flags), bytes);
#else // !SYSTEM_PLATFORM_WIN32
	return new(std::nothrow) char[bytes];
#endif // SYSTEM_PLATFORM_WIN32
}
 
System::WindowVoidPtr System
	::LocalMemoryLock(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LocalLock(memory);
#else // !SYSTEM_PLATFORM_WIN32
	return memory;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::LocalMemoryUnlock(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::LocalUnlock(memory) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(memory);

	return true;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHLocal System
	::GetLocalMemoryHandle(WindowConstVoidPtr memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LocalHandle(memory);
#else // !SYSTEM_PLATFORM_WIN32
	return memory;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System
	::GetLocalMemorySize(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LocalSize(memory);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowUInt System
	::GetLocalMemoryFlags(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LocalFlags(memory);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

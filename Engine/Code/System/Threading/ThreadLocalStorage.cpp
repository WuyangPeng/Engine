// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 13:09)

#include "System/SystemExport.h"

#include "ThreadLocalStorage.h"
#include "Flags/ThreadLocalStorageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

System::WindowDWord System
	::ThreadLocalStorageAlloc() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::TlsAlloc();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::GetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::TlsGetValue(threadLocalStorageIndex);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadLocalStorageIndex);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex, WindowVoidPtr threadLocalStorageValue) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TlsSetValue(threadLocalStorageIndex, threadLocalStorageValue) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadLocalStorageIndex);
	SYSTEM_UNUSED_ARG(threadLocalStorageValue);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ThreadLocalStorageFree(WindowDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TlsFree(threadLocalStorageIndex) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadLocalStorageIndex);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsThreadLocalStorageValid(WindowDWord threadLocalStorageIndex) noexcept
{
	if (threadLocalStorageIndex != EnumCastUnderlying(ThreadLocalStorageIndexes::OutOfIndexes))
		return true;
	else
		return false;
}

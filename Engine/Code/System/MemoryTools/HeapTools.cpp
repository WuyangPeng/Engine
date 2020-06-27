// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 0:09)

#include "System/SystemExport.h"

#include "HeapTools.h"
#include "Using/HeapToolsUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/ExceptionFlags.h"

System::WindowHandle System
	::CreateProcessHeap(HeapCreate options, WindowSize initialSize, WindowSize maximumSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::HeapCreate(EnumCastUnderlying(options), initialSize, maximumSize);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(options);
	SYSTEM_UNUSED_ARG(initialSize);
	SYSTEM_UNUSED_ARG(maximumSize);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DestroyProcessHeap(WindowHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapDestroy(heap) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::AllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	__try
	{
		return ::HeapAlloc(heap, EnumCastUnderlying(flags), bytes);
	}
	__except (EnumCastUnderlying(Exception::ExecuteHandler))
	{
		return nullptr;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(bytes);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::ReAllocateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem, WindowSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	__try
	{
		return ::HeapReAlloc(heap, EnumCastUnderlying(flags), mem, bytes);
	}
	__except (EnumCastUnderlying(Exception::ExecuteHandler))
	{
		return nullptr;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(mem);
	SYSTEM_UNUSED_ARG(bytes);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FreeProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapFree(heap, EnumCastUnderlying(flags), mem) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(mem);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System
	::GetProcessHeapSize(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::HeapSize(heap, EnumCastUnderlying(flags), mem);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(mem);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ValidateProcessHeap(WindowHandle heap, HeapCreate flags, WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapValidate(heap, EnumCastUnderlying(flags), mem) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(mem);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System
	::GetProcessHeapCompact(WindowHandle heap, HeapCreate flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::HeapCompact(heap, EnumCastUnderlying(flags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(flags);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::GetCurrentProcessHeap() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetProcessHeap();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetCurrentProcessHeaps(WindowDWord numberOfHeaps, WindowHandlePtr processHeaps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetProcessHeaps(numberOfHeaps, processHeaps);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(numberOfHeaps);
	SYSTEM_UNUSED_ARG(processHeaps);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::LockProcessHeap(WindowHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapLock(heap) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UnlockProcessHeap(WindowHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapUnlock(heap) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WalkProcessHeap(WindowHandle heap, MemoryProcessHeapEntryPtr entry) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapWalk(heap, entry) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heap);
	SYSTEM_UNUSED_ARG(entry);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EnableProcessHeapTerminationOnCorruption(WindowHandle heapHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapSetInformation(heapHandle, HeapEnableTerminationOnCorruption, nullptr, 0) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heapHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::QueryProcessHeapInformation(WindowHandle heapHandle, WindowULong* heapInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::HeapQueryInformation(heapHandle, HeapCompatibilityInformation, heapInformation, sizeof(WindowULong), nullptr) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(heapHandle);
	SYSTEM_UNUSED_ARG(heapInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

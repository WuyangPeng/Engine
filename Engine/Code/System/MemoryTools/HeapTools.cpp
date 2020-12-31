//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:02)

#include "System/SystemExport.h"

#include "HeapTools.h"
#include "Using/HeapToolsUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/ExceptionFlags.h"

System::WindowHandle System::CreateProcessHeap([[maybe_unused]] HeapCreate options, [[maybe_unused]] WindowSize initialSize, [[maybe_unused]] WindowSize maximumSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::HeapCreate(EnumCastUnderlying(options), initialSize, maximumSize);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DestroyProcessHeap([[maybe_unused]] WindowHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapDestroy(heap) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::AllocateProcessHeap([[maybe_unused]] WindowHandle heap, [[maybe_unused]] HeapCreate flags, [[maybe_unused]] WindowSize bytes) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::ReAllocateProcessHeap([[maybe_unused]] WindowHandle heap, [[maybe_unused]] HeapCreate flags, [[maybe_unused]] WindowVoidPtr mem, [[maybe_unused]] WindowSize bytes) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeProcessHeap([[maybe_unused]] WindowHandle heap, [[maybe_unused]] HeapCreate flags, [[maybe_unused]] WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapFree(heap, EnumCastUnderlying(flags), mem) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System::GetProcessHeapSize([[maybe_unused]] WindowHandle heap, [[maybe_unused]] HeapCreate flags, [[maybe_unused]] WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::HeapSize(heap, EnumCastUnderlying(flags), mem);
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ValidateProcessHeap([[maybe_unused]] WindowHandle heap, [[maybe_unused]] HeapCreate flags, [[maybe_unused]] WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapValidate(heap, EnumCastUnderlying(flags), mem) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System::GetProcessHeapCompact([[maybe_unused]] WindowHandle heap, [[maybe_unused]] HeapCreate flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::HeapCompact(heap, EnumCastUnderlying(flags));
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::GetCurrentProcessHeap() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetProcessHeap();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetCurrentProcessHeaps([[maybe_unused]] WindowDWord numberOfHeaps, [[maybe_unused]] WindowHandlePtr processHeaps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetProcessHeaps(numberOfHeaps, processHeaps);
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LockProcessHeap([[maybe_unused]] WindowHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapLock(heap) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UnlockProcessHeap([[maybe_unused]] WindowHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapUnlock(heap) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WalkProcessHeap([[maybe_unused]] WindowHandle heap, [[maybe_unused]] MemoryProcessHeapEntryPtr entry) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapWalk(heap, entry) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnableProcessHeapTerminationOnCorruption([[maybe_unused]] WindowHandle heapHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapSetInformation(heapHandle, HeapEnableTerminationOnCorruption, nullptr, 0) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::QueryProcessHeapInformation([[maybe_unused]] WindowHandle heapHandle, [[maybe_unused]] WindowULong* heapInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HeapQueryInformation(heapHandle, HeapCompatibilityInformation, heapInformation, sizeof(WindowULong), nullptr) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

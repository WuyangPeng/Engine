//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:01)

#include "System/SystemExport.h"

#include "GlobalTools.h"
#include "System/Helper/EnumCast.h"

#include <new>

System::DynamicLinkGlobal System::GlobalAllocBytes([[maybe_unused]] GlobalMemory flags, WindowSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GlobalAlloc(EnumCastUnderlying(flags), bytes);
#else  // !SYSTEM_PLATFORM_WIN32
    return new (std::nothrow) char[WindowSize];
#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System::GlobalReAllocBytes(DynamicLinkGlobal mem, WindowSize bytes, [[maybe_unused]] GlobalMemory flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GlobalReAlloc(mem, bytes, EnumCastUnderlying(flags));
#else  // !SYSTEM_PLATFORM_WIN32 
    delete[] mem;

    return new (std::nothrow) char[WindowSize];
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System::GetGlobalSize([[maybe_unused]] DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GlobalSize(mem);
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::GlobalMemory System::GetGlobalFlags([[maybe_unused]] DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<GlobalMemory>(::GlobalFlags(mem));
#else  // !SYSTEM_PLATFORM_WIN32 
    return GlobalMemory::Fixed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::GetGlobalLock([[maybe_unused]] DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GlobalLock(mem);
#else  // !SYSTEM_PLATFORM_WIN32 
    return mem;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System::GetGlobalHandle([[maybe_unused]] WindowVoidPtr mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GlobalHandle(mem);
#else  // !SYSTEM_PLATFORM_WIN32 
    return mem;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetGlobalUnlock([[maybe_unused]] DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GlobalUnlock(mem) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System::GetGlobalFree(DynamicLinkGlobal mem) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GlobalFree(mem);
#else  // !SYSTEM_PLATFORM_WIN32
    delete[] mem;

    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:04)

#include "System/SystemExport.h"

#include "LocalTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::LocalMemoryFree(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::LocalFree(memory) != nullptr)
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    delete[] memory;

    return true;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHLocal System::LocalMemoryAlloc(LocalMemory flags, WindowSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LocalAlloc(EnumCastUnderlying(flags), bytes);
#else  // !SYSTEM_PLATFORM_WIN32
    return new (std::nothrow) char[bytes];
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::LocalMemoryLock(WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LocalLock(memory);
#else  // !SYSTEM_PLATFORM_WIN32
    return memory;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LocalMemoryUnlock([[maybe_unused]] WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::LocalUnlock(memory) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return true;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHLocal System::GetLocalMemoryHandle(WindowConstVoidPtr memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LocalHandle(memory);
#else  // !SYSTEM_PLATFORM_WIN32
    return memory;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System::GetLocalMemorySize([[maybe_unused]] WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LocalSize(memory);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowUInt System::GetLocalMemoryFlags([[maybe_unused]] WindowHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LocalFlags(memory);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:43)

#include "System/SystemExport.h"

#include "ThreadLocalStorage.h"
#include "Flags/ThreadLocalStorageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowDWord System::ThreadLocalStorageAlloc() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::TlsAlloc();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::GetThreadLocalStorageValue([[maybe_unused]] WindowDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::TlsGetValue(threadLocalStorageIndex);
#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetThreadLocalStorageValue([[maybe_unused]] WindowDWord threadLocalStorageIndex, [[maybe_unused]] WindowVoidPtr threadLocalStorageValue) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TlsSetValue(threadLocalStorageIndex, threadLocalStorageValue) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ThreadLocalStorageFree([[maybe_unused]] WindowDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TlsFree(threadLocalStorageIndex) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsThreadLocalStorageValid(WindowDWord threadLocalStorageIndex) noexcept
{
    if (threadLocalStorageIndex != EnumCastUnderlying(ThreadLocalStorageIndexes::OutOfIndexes))
        return true;
    else
        return false;
}

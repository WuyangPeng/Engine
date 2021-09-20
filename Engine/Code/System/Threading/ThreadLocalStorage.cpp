///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/26 18:57)

#include "System/SystemExport.h"

#include "ThreadLocalStorage.h"
#include "Flags/ThreadLocalStorageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowsDWord System::ThreadLocalStorageAlloc() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::TlsAlloc();

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::GetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::TlsGetValue(threadLocalStorageIndex);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord>(threadLocalStorageIndex);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex, WindowsVoidPtr threadLocalStorageValue) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TlsSetValue(threadLocalStorageIndex, threadLocalStorageValue) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, WindowsVoidPtr>(threadLocalStorageIndex, threadLocalStorageValue);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ThreadLocalStorageFree(WindowsDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TlsFree(threadLocalStorageIndex) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord>(threadLocalStorageIndex);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsThreadLocalStorageValid(WindowsDWord threadLocalStorageIndex) noexcept
{
    if (threadLocalStorageIndex != EnumCastUnderlying(ThreadLocalStorageIndexes::OutOfIndexes))
        return true;
    else
        return false;
}

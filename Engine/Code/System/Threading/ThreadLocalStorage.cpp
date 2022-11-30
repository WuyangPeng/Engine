///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:06)

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

    UnusedFunction(threadLocalStorageIndex);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex, WindowsVoidPtr threadLocalStorageValue) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TlsSetValue(threadLocalStorageIndex, threadLocalStorageValue) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadLocalStorageIndex, threadLocalStorageValue);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ThreadLocalStorageFree(WindowsDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TlsFree(threadLocalStorageIndex) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadLocalStorageIndex);

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

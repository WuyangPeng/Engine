/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 18:19)

#include "System/SystemExport.h"

#include "ThreadLocalStorage.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
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

    return ::TlsSetValue(threadLocalStorageIndex, threadLocalStorageValue) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadLocalStorageIndex, threadLocalStorageValue);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ThreadLocalStorageFree(WindowsDWord threadLocalStorageIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::TlsFree(threadLocalStorageIndex) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(threadLocalStorageIndex);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

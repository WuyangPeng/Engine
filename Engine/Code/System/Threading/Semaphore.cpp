///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:15)

#include "System/SystemExport.h"

#include "Semaphore.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::WindowsHandle System::CreateSystemSemaphore(WindowSecurityAttributesPtr semaphoreAttributes, WindowsLong initialCount, WindowsLong maximumCount, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateSemaphore(semaphoreAttributes, initialCount, maximumCount, name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(semaphoreAttributes, initialCount, maximumCount, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemSemaphore(WindowsLong initialCount, WindowsLong maximumCount) noexcept
{
    return CreateSystemSemaphore(nullptr, initialCount, maximumCount, nullptr);
}

bool System::WaitForSystemSemaphore(WindowsHandle handle) noexcept
{
    return WaitForSystemSemaphore(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsHandle handle, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemSemaphore(WindowsHandle handle, WindowsLong releaseCount, WindowsLongPtr previousCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReleaseSemaphore(handle, releaseCount, previousCount) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, releaseCount, previousCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemSemaphore(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemSemaphore(MutexStandardAccess desiredAccess, SemaphoreSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenSemaphore(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(desiredAccess, specificAccess, inheritHandle, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemSemaphoreValid(WindowsHandle handle) noexcept
{
    if (handle != nullptr && handle != gInvalidHandleValue)
        return true;
    else
        return false;
}
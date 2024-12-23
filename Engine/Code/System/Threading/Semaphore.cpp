/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:19)

#include "System/SystemExport.h"

#include "Semaphore.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

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

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObject(handle, milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemSemaphore(WindowsHandle handle, WindowsLong releaseCount, WindowsLongPtr previousCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ReleaseSemaphore(handle, releaseCount, previousCount) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, releaseCount, previousCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemSemaphore(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CloseHandle(handle) != gFalse;

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
    return handle != nullptr && handle != invalidHandleValue;
}
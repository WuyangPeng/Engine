//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:11)

#include "System/SystemExport.h"

#include "Semaphore.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System::CreateSystemSemaphore([[maybe_unused]] WindowSecurityAttributesPtr semaphoreAttributes, [[maybe_unused]] WindowLong initialCount, [[maybe_unused]] WindowLong maximumCount, [[maybe_unused]] const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateSemaphore(semaphoreAttributes, initialCount, maximumCount, name);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemSemaphore(WindowLong initialCount, WindowLong maximumCount) noexcept
{
    return CreateSystemSemaphore(nullptr, initialCount, maximumCount, nullptr);
}

bool System::WaitForSystemSemaphore(WindowHandle handle) noexcept
{
    return WaitForSystemSemaphore(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemSemaphore([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemSemaphore([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemSemaphore([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowLong releaseCount, [[maybe_unused]] WindowLongPtr previousCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReleaseSemaphore(handle, releaseCount, previousCount) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemSemaphore([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::OpenSystemSemaphore([[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] SemaphoreSpecificAccess specificAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenSemaphore(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemSemaphoreValid(WindowHandle handle) noexcept
{
    if (handle != nullptr && handle != g_InvalidHandleValue)
        return true;
    else
        return false;
}
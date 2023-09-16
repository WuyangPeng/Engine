///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 18:22)

#include "System/SystemExport.h"

#include "Event.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

System::WindowsHandle System::CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, bool manualReset, bool initialState, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateEvent(securityAttributes, BoolConversion(manualReset), BoolConversion(initialState), name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityAttributes, manualReset, initialState, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemEvent(bool manualReset, bool initialState) noexcept
{
    return CreateSystemEvent(nullptr, manualReset, initialState, nullptr);
}

System::WindowsHandle System::CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, const TChar* name, CreateEventType flag, MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateEventEx(securityAttributes, name, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityAttributes, name, flag, desiredAccess, specificAccess);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemEvent(WindowsHandle handle) noexcept
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

bool System::SetSystemEvent(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetEvent(handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ResetSystemEvent(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ResetEvent(handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemEvent(WindowsHandle handle) noexcept
{
    return WaitForSystemEvent(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsHandle handle, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObject(handle, milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemEvent(MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenEvent(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(desiredAccess, specificAccess, inheritHandle, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemEventValid(WindowsHandle eventHandle) noexcept
{
    if (eventHandle != nullptr && eventHandle != invalidHandleValue)
        return true;
    else
        return false;
}

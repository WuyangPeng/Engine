///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/25 20:15)

#include "System/SystemExport.h"

#include "Event.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::WindowsHandle System::CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, bool manualReset, bool initialState, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateEvent(securityAttributes, BoolConversion(manualReset), BoolConversion(initialState), name);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowSecurityAttributesPtr, bool, bool, const TChar*>(securityAttributes, manualReset, initialState, name);

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

    NullFunction<WindowSecurityAttributesPtr, const TChar*, CreateEventType, MutexStandardAccess, EventSpecificAccess>(securityAttributes, name, flag, desiredAccess, specificAccess);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemEvent(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(handle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemEvent(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetEvent(handle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ResetSystemEvent(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ResetEvent(handle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(handle);

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

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsDWord>(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsDWord, bool>(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, const WindowsHandle*, bool, WindowsDWord, bool>(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, const WindowsHandle*, bool, WindowsDWord>(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemEvent(MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenEvent(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<MutexStandardAccess, EventSpecificAccess, bool, const TChar*>(desiredAccess, specificAccess, inheritHandle, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemEventValid(WindowsHandle eventHandle) noexcept
{
    if (eventHandle != nullptr && eventHandle != g_InvalidHandleValue)
        return true;
    else
        return false;
}

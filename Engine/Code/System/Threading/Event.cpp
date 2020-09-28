//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:06)

#include "System/SystemExport.h"

#include "Event.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System::CreateSystemEvent([[maybe_unused]] WindowSecurityAttributesPtr securityAttributes, [[maybe_unused]] bool manualReset, [[maybe_unused]] bool initialState, [[maybe_unused]] const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateEvent(securityAttributes, BoolConversion(manualReset), BoolConversion(initialState), name);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemEvent(bool manualReset, bool initialState) noexcept
{
    return CreateSystemEvent(nullptr, manualReset, initialState, nullptr);
}

System::WindowHandle System::CreateSystemEvent([[maybe_unused]] WindowSecurityAttributesPtr securityAttributes, [[maybe_unused]] const TChar* name, [[maybe_unused]] CreateEventType flag, [[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] EventSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateEventEx(securityAttributes, name, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemEvent([[maybe_unused]] WindowHandle handle) noexcept
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

bool System::SetSystemEvent([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetEvent(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ResetSystemEvent([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ResetEvent(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemEvent(WindowHandle handle) noexcept
{
    return WaitForSystemEvent(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemEvent([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32 
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32 
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32 
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemEvent([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32 
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::OpenSystemEvent([[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] EventSpecificAccess specificAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenEvent(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemEventValid(WindowHandle eventHandle) noexcept
{
    if (eventHandle != nullptr && eventHandle != g_InvalidHandleValue)
        return true;
    else
        return false;
}

//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:58)

#include "System/SystemExport.h"

#include "WaitableTimer.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System::CreateSystemWaitableTimer([[maybe_unused]] WindowSecurityAttributesPtr timerAttributes, [[maybe_unused]] bool manualReset, [[maybe_unused]] const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateWaitableTimer(timerAttributes, BoolConversion(manualReset), timerName);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemWaitableTimer([[maybe_unused]] WindowSecurityAttributesPtr timerAttributes, [[maybe_unused]] const TChar* timerName, [[maybe_unused]] CreateWaitableTimerReset flag,
                                                       [[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] WaitableTimerSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateWaitableTimerEx(timerAttributes, timerName, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CancelSystemWaitableTimer([[maybe_unused]] WindowHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CancelWaitableTimer(timer) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemWaitableTimer([[maybe_unused]] WindowHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(timer) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemWaitableTimer(WindowHandle timer) noexcept
{
    return WaitForSystemWaitableTimer(timer, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer([[maybe_unused]] WindowHandle timer, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(timer, milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer([[maybe_unused]] WindowHandle timer, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(timer, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* timer, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, timer, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* timer, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, timer, BoolConversion(waitAll), milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemWaitableTimer([[maybe_unused]] WindowHandle timer, [[maybe_unused]] const WindowLargeInteger* dueTime, [[maybe_unused]] WindowLong period, [[maybe_unused]] TimerApcRoutine completionRoutine,
                                    [[maybe_unused]] WindowVoidPtr argToCompletionRoutine, [[maybe_unused]] WaitableTimerReasonContextPtr wakeContext, [[maybe_unused]] WindowULong tolerableDelay) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetWaitableTimerEx(timer, dueTime, period, completionRoutine, argToCompletionRoutine, wakeContext, tolerableDelay) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemWaitableTimer([[maybe_unused]] WindowHandle timer, [[maybe_unused]] const WindowLargeInteger* dueTime, [[maybe_unused]] WindowLong period,
                                    [[maybe_unused]] TimerApcRoutine completionRoutine, [[maybe_unused]] WindowVoidPtr argToCompletionRoutine, [[maybe_unused]] bool resume) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetWaitableTimer(timer, dueTime, period, completionRoutine, argToCompletionRoutine, BoolConversion(resume)) != g_False)
        return true;
    else
        return false;
#else  // SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::OpenSystemWaitableTimer([[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] WaitableTimerSpecificAccess specificAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenWaitableTimer(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), timerName);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsWaitableTimerValid(WindowHandle handle) noexcept
{
    if (handle != nullptr && handle != g_InvalidHandleValue)
        return true;
    else
        return false;
}

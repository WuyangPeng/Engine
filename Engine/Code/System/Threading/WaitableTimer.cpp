///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/26 19:49)

#include "System/SystemExport.h"

#include "WaitableTimer.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::WindowsHandle System::CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, bool manualReset, const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateWaitableTimer(timerAttributes, BoolConversion(manualReset), timerName);
#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowSecurityAttributesPtr, bool, const TChar*>(timerAttributes, manualReset, timerName);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes,
                                                       const TChar* timerName,
                                                       CreateWaitableTimerReset flag,
                                                       MutexStandardAccess desiredAccess,
                                                       WaitableTimerSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateWaitableTimerEx(timerAttributes, timerName, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowSecurityAttributesPtr, const TChar*, CreateWaitableTimerReset, MutexStandardAccess, WaitableTimerSpecificAccess>(timerAttributes, timerName, flag, desiredAcces, specificAccess);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CancelSystemWaitableTimer(WindowsHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CancelWaitableTimer(timer) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(timer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemWaitableTimer(WindowsHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(timer) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(timer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemWaitableTimer(WindowsHandle timer) noexcept
{
    return WaitForSystemWaitableTimer(timer, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsHandle timer, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(timer, milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsDWord>(timer, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsHandle timer, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(timer, milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsDWord, bool>(timer, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsDWord count, const WindowsHandle* timer, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, timer, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, const WindowsHandle*, bool, WindowsDWord, bool>(count, timer, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsDWord count, const WindowsHandle* timer, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, timer, BoolConversion(waitAll), milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, const WindowsHandle*, bool, WindowsDWord>(count, timer, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemWaitableTimer(WindowsHandle timer,
                                    const WindowsLargeInteger* dueTime,
                                    WindowsLong period,
                                    TimerApcRoutine completionRoutine,
                                    WindowsVoidPtr argToCompletionRoutine,
                                    WaitableTimerReasonContextPtr wakeContext,
                                    WindowsULong tolerableDelay) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetWaitableTimerEx(timer, dueTime, period, completionRoutine, argToCompletionRoutine, wakeContext, tolerableDelay) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, const WindowsLargeInteger*, WindowsLong, TimerApcRoutine, WindowsVoidPtr, WaitableTimerReasonContextPtr, WindowsULong>(timer, dueTime, period, completionRoutine, argToCompletionRoutine, wakeContext, tolerableDelay);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemWaitableTimer(WindowsHandle timer,
                                    const WindowsLargeInteger* dueTime,
                                    WindowsLong period,
                                    TimerApcRoutine completionRoutine,
                                    WindowsVoidPtr argToCompletionRoutine,
                                    bool resume) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetWaitableTimer(timer, dueTime, period, completionRoutine, argToCompletionRoutine, BoolConversion(resume)) != g_False)
        return true;
    else
        return false;

#else  // SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, const WindowsLargeInteger*, WindowsLong, TimerApcRoutine, WindowsVoidPtr, bool>(timer, dueTime, period, completionRoutine, argToCompletionRoutine, resume);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemWaitableTimer(MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess, bool inheritHandle, const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenWaitableTimer(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), timerName);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<MutexStandardAccess, WaitableTimerSpecificAccess, bool, const TChar*>(desiredAccess, specificAccess, inheritHandle, timerName);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsWaitableTimerValid(WindowsHandle handle) noexcept
{
    if (handle != nullptr && handle != g_InvalidHandleValue)
        return true;
    else
        return false;
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:20)

#include "System/SystemExport.h"

#include "WaitableTimer.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

System::WindowsHandle System::CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, bool manualReset, const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateWaitableTimer(timerAttributes, BoolConversion(manualReset), timerName);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(timerAttributes, manualReset, timerName);

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

    UnusedFunction(timerAttributes, timerName, flag, desiredAccess, specificAccess);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CancelSystemWaitableTimer(WindowsHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CancelWaitableTimer(timer) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(timer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemWaitableTimer(WindowsHandle timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CloseHandle(timer) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(timer);

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

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObject(timer, milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(timer, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsHandle timer, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObjectEx(timer, milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(timer, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsDWord count, const WindowsHandle* timer, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjectsEx(count, timer, BoolConversion(waitAll), milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, timer, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemWaitableTimer(WindowsDWord count, const WindowsHandle* timer, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjects(count, timer, BoolConversion(waitAll), milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, timer, waitAll, milliseconds);

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

    return ::SetWaitableTimerEx(timer, dueTime, period, completionRoutine, argToCompletionRoutine, wakeContext, tolerableDelay) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(timer, dueTime, period, completionRoutine, argToCompletionRoutine, wakeContext, tolerableDelay);

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

    return ::SetWaitableTimer(timer, dueTime, period, completionRoutine, argToCompletionRoutine, BoolConversion(resume)) != gFalse;

#else  // SYSTEM_PLATFORM_WIN32

    UnusedFunction(timer, dueTime, period, completionRoutine, argToCompletionRoutine, resume);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemWaitableTimer(MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess, bool inheritHandle, const TChar* timerName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenWaitableTimer(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), timerName);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(desiredAccess, specificAccess, inheritHandle, timerName);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsWaitableTimerValid(WindowsHandle handle) noexcept
{
    return handle != nullptr && handle != invalidHandleValue;
}
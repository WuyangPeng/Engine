///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:06)

#include "System/SystemExport.h"

#include "SyncTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

void System::SystemSleep(WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::Sleep(milliseconds);

#else  // !SYSTEM_PLATFORM_WIN32

    usleep(milliseconds);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::SleepReturn System::SystemSleep(WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<SleepReturn>(SleepEx(milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    usleep(milliseconds);

    UnusedFunction(alertable);

    return SleepReturn::Succeed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(SignalObjectAndWait(objectToSignal, objectToWaitOn, milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(objectToSignal, objectToWaitOn, milliseconds, alertable);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 18:07)

#include "System/SystemExport.h"

#include "SyncTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

#ifdef SYSTEM_PLATFORM_LINUX

    #include <unistd.h>

#endif  // SYSTEM_PLATFORM_LINUX

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

    const auto result = SleepEx(milliseconds, BoolConversion(alertable));

    return UnderlyingCastEnum<SleepReturn>(gsl::narrow_cast<int>(result));

#else  // !SYSTEM_PLATFORM_WIN32

    usleep(milliseconds);

    UnusedFunction(alertable);

    return SleepReturn::Succeed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto result = SignalObjectAndWait(objectToSignal, objectToWaitOn, milliseconds, BoolConversion(alertable));

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(result));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(objectToSignal, objectToWaitOn, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

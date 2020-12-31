//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:37)

#include "System/SystemExport.h"

#include "SyncTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

void System::SystemSleep(WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::Sleep(milliseconds);
#else  // !SYSTEM_PLATFORM_WIN32
    usleep(milliseconds);
#endif  // SYSTEM_PLATFORM_WIN32
}

System::SleepReturn System::SystemSleep(WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<SleepReturn>(SleepEx(milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    usleep(milliseconds);

    return SleepReturn::Succeed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::SystemSignalObjectAndWait([[maybe_unused]] ThreadHandle objectToSignal, [[maybe_unused]] ThreadHandle objectToWaitOn, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(SignalObjectAndWait(objectToSignal, objectToWaitOn, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

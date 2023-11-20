///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:30)

#include "System/SystemExport.h"

#include "SyncTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Windows/WindowsSystem.h"

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

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

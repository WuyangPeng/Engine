///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/25 14:41)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_H
#define SYSTEM_THREADING_SYNC_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 线程暂停

    void SYSTEM_DEFAULT_DECLARE SystemSleep(WindowsDWord milliseconds) noexcept;
    NODISCARD SleepReturn SYSTEM_DEFAULT_DECLARE SystemSleep(WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowsDWord milliseconds, bool alertable) noexcept;
}

#endif  // SYSTEM_THREADING_SYNC_TOOLS_H
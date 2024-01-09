/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 16:04)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_H
#define SYSTEM_THREADING_SYNC_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// 线程暂停
namespace System
{
    void SYSTEM_DEFAULT_DECLARE SystemSleep(WindowsDWord milliseconds) noexcept;
    NODISCARD SleepReturn SYSTEM_DEFAULT_DECLARE SystemSleep(WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE SystemSignalObjectAndWait(ThreadHandle objectToSignal,
                                                                               ThreadHandle objectToWaitOn,
                                                                               WindowsDWord milliseconds,
                                                                               bool alertable) noexcept;
}

#endif  // SYSTEM_THREADING_SYNC_TOOLS_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:04)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_H
#define SYSTEM_THREADING_SYNC_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // �߳���ͣ

    void SYSTEM_DEFAULT_DECLARE SystemSleep(WindowsDWord milliseconds) noexcept;
    NODISCARD SleepReturn SYSTEM_DEFAULT_DECLARE SystemSleep(WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE SystemSignalObjectAndWait(ThreadHandle objectToSignal,
                                                                               ThreadHandle objectToWaitOn,
                                                                               WindowsDWord milliseconds,
                                                                               bool alertable) noexcept;
}

#endif  // SYSTEM_THREADING_SYNC_TOOLS_H
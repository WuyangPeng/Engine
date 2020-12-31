//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:27)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_H
#define SYSTEM_THREADING_SYNC_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // �߳���ͣ

    void SYSTEM_DEFAULT_DECLARE SystemSleep(WindowDWord milliseconds) noexcept;
    [[nodiscard]] SleepReturn SYSTEM_DEFAULT_DECLARE SystemSleep(WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowDWord milliseconds, bool alertable) noexcept;
}

#endif  // SYSTEM_THREADING_SYNC_TOOLS_H
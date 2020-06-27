// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/10 11:33)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_H
#define SYSTEM_THREADING_SYNC_TOOLS_H

#include "System/SystemDll.h"

#include "Using/ThreadUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// �߳���ͣ

	void SYSTEM_DEFAULT_DECLARE SystemSleep(WindowDWord milliseconds) noexcept;
	SleepReturn SYSTEM_DEFAULT_DECLARE SystemSleep(WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowDWord milliseconds, bool alertable) noexcept;
}

#endif // SYSTEM_THREADING_SYNC_TOOLS_H
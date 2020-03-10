// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_FWD_H 
#define SYSTEM_THREADING_SYNC_TOOLS_FWD_H 

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadUsing.h"

namespace System
{
	void SystemSleep(WindowDWord milliseconds) noexcept;
	SleepReturn SystemSleep(WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SystemSignalObjectAndWait(ThreadHandle objectToSignal, ThreadHandle objectToWaitOn, WindowDWord milliseconds, bool alertable) noexcept;
}

#endif // SYSTEM_THREADING_SYNC_TOOLS_FWD_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_FWD_H 
#define SYSTEM_THREADING_WAITABLE_TIMER_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/WaitableTimerUsing.h" 

namespace System
{
	WindowHandle CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, bool manualReset, const TChar* timerName) noexcept;
	WindowHandle CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, const TChar* timerName, CreateWaitableTimerReset flag,
										   MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess) noexcept;
	WindowHandle OpenSystemWaitableTimer(MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess, bool inheritHandle, const TChar* timerName) noexcept;

	bool CancelSystemWaitableTimer(WindowHandle timer) noexcept;
	bool CloseSystemWaitableTimer(WindowHandle timer) noexcept;

	bool WaitForSystemWaitableTimer(WindowHandle timer) noexcept;
	MutexWaitReturn WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds) noexcept;
	MutexWaitReturn WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds) noexcept;

	bool SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period, TimerApcRoutine completionRoutine,
								WindowVoidPtr argToCompletionRoutine, WaitableTimerReasonContextPtr wakeContext, WindowULong tolerableDelay) noexcept;
	bool SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period,
								TimerApcRoutine completionRoutine, WindowVoidPtr argToCompletionRoutine, bool resume) noexcept;

	bool IsWaitableTimerValid(WindowHandle handle) noexcept;
}

#endif // SYSTEM_THREADING_WAITABLE_TIMER_FWD_H
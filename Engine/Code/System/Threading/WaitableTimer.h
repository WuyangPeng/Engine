// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:14)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_H
#define SYSTEM_THREADING_WAITABLE_TIMER_H

#include "System/SystemDll.h"

#include "Using/InitOnceUsing.h"
#include "Using/WaitableTimerUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 等待计时器的创建、销毁、等待和设置。

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, bool manualReset, const TChar* timerName) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, const TChar* timerName, CreateWaitableTimerReset flag,
																  MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemWaitableTimer(MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess, bool inheritHandle, const TChar* timerName) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CancelSystemWaitableTimer(WindowHandle timer) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemWaitableTimer(WindowHandle timer) noexcept;

	bool SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowHandle timer) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period, TimerApcRoutine completionRoutine,
													   WindowVoidPtr argToCompletionRoutine, WaitableTimerReasonContextPtr wakeContext, WindowULong tolerableDelay) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period,
													   TimerApcRoutine completionRoutine, WindowVoidPtr argToCompletionRoutine, bool resume) noexcept;

	bool SYSTEM_DEFAULT_DECLARE IsWaitableTimerValid(WindowHandle handle) noexcept;
}

#endif // SYSTEM_THREADING_WAITABLE_TIMER_H
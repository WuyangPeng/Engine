// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_THREAD_H
#define SYSTEM_THREADING_THREAD_H

#include "System/SystemDll.h"

#include "Using/ThreadUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 创建和销毁线程

	ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemThread(WindowSecurityAttributesPtr threadAttributes,WindowSize stackSize,ThreadStartRoutine startAddress,
														   WindowVoidPtr parameter,ThreadCreation creationFlags,WindowDWordPtr threadID) noexcept;
	ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemThread(WindowSize stackSize, ThreadStartRoutine startAddress,WindowVoidPtr parameter,WindowDWordPtr threadID) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemThread(ThreadHandle thread) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE ResumeSystemThread(ThreadHandle thread) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE SuspendSystemThread(ThreadHandle thread) noexcept;
	ThreadHandle SYSTEM_DEFAULT_DECLARE GetCurrentSystemThread() noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentSystemThreadID() noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept;
	int SYSTEM_DEFAULT_DECLARE GetSystemThreadPriority(ThreadHandle thread) noexcept;

	bool SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds,bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;

	ThreadHandle SYSTEM_DEFAULT_DECLARE BeginSystemThread(void* security, unsigned stacksize, StartAddress startAddress,
														  void* argument, unsigned createFlag, unsigned* threadAddress) noexcept;
	void SYSTEM_DEFAULT_DECLARE EndSystemThread(unsigned retCode) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsThreadHandleValid(ThreadHandle threadHandle) noexcept;

	WindowDWord SYSTEM_DEFAULT_DECLARE ExitSystemThread(WindowDWord exitCode) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_H
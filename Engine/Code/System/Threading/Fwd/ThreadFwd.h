// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_THREAD_FWD_H
#define SYSTEM_THREADING_THREAD_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadUsing.h" 

namespace System
{
	ThreadHandle CreateSystemThread(WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
									WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept;

	ThreadHandle CreateSystemThread(WindowSize stackSize, ThreadStartRoutine startAddress, WindowVoidPtr parameter, WindowDWordPtr threadID) noexcept;

	bool CloseSystemThread(ThreadHandle thread) noexcept;
	WindowDWord ResumeSystemThread(ThreadHandle thread) noexcept;
	WindowDWord SuspendSystemThread(ThreadHandle thread) noexcept;
	ThreadHandle GetCurrentSystemThread() noexcept;
	WindowDWord GetCurrentSystemThreadID() noexcept;
	bool SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept;
	int GetSystemThreadPriority(ThreadHandle thread) noexcept;

	bool WaitForSystemThread(ThreadHandle handle) noexcept;
	MutexWaitReturn WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;

	ThreadHandle BeginSystemThread(void* security, unsigned stacksize, StartAddress startAddress, void* argument, unsigned createFlag, unsigned* threadAddress) noexcept;
	void EndSystemThread(unsigned retCode) noexcept;
	bool IsThreadHandleValid(ThreadHandle threadHandle) noexcept;
	WindowDWord ExitSystemThread(WindowDWord exitCode) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_FWD_H
//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:29)

#ifndef SYSTEM_THREADING_THREAD_H
#define SYSTEM_THREADING_THREAD_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 创建和销毁线程

    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemThread(WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
                                                                         WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept;
    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemThread(WindowSize stackSize, ThreadStartRoutine startAddress, WindowVoidPtr parameter, WindowDWordPtr threadID) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemThread(ThreadHandle thread) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE ResumeSystemThread(ThreadHandle thread) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE SuspendSystemThread(ThreadHandle thread) noexcept;
    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE GetCurrentSystemThread() noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentSystemThreadID() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GetSystemThreadPriority(ThreadHandle thread) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowDWord count, const ThreadHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;

    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE BeginSystemThread(void* security, unsigned stacksize, StartAddress startAddress,
                                                                        void* argument, unsigned createFlag, unsigned* threadAddress) noexcept;
    void SYSTEM_DEFAULT_DECLARE EndSystemThread(unsigned retCode) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsThreadHandleValid(ThreadHandle threadHandle) noexcept;

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE ExitSystemThread(WindowDWord exitCode) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_H
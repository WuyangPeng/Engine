///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 18:09)

#ifndef SYSTEM_THREADING_THREAD_H
#define SYSTEM_THREADING_THREAD_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 创建和销毁线程

    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemThread(WindowSecurityAttributesPtr threadAttributes,
                                                                         WindowsSize stackSize,
                                                                         ThreadStartRoutine startAddress,
                                                                         WindowsVoidPtr parameter,
                                                                         ThreadCreation creationFlags,
                                                                         WindowsDWordPtr threadID) noexcept;
    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemThread(WindowsSize stackSize,
                                                                         ThreadStartRoutine startAddress,
                                                                         WindowsVoidPtr parameter,
                                                                         WindowsDWordPtr threadID) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemThread(ThreadHandle thread) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE ResumeSystemThread(ThreadHandle thread) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE SuspendSystemThread(ThreadHandle thread) noexcept;

    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE GetCurrentSystemThread() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetCurrentSystemThreadID() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetSystemThreadPriority(ThreadHandle thread) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept;

    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE BeginSystemThread(void* security,
                                                                        unsigned stacksize,
                                                                        StartAddress startAddress,
                                                                        void* argument,
                                                                        unsigned createFlag,
                                                                        unsigned* threadAddress) noexcept;
    void SYSTEM_DEFAULT_DECLARE EndSystemThread(unsigned retCode) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsThreadHandleValid(ThreadHandle threadHandle) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE ExitSystemThread(WindowsDWord exitCode) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_H
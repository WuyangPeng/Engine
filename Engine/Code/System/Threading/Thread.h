///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/01/30 13:19)

#ifndef SYSTEM_THREADING_THREAD_H
#define SYSTEM_THREADING_THREAD_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// �����������߳�
namespace System
{
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
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetCurrentSystemThreadId() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriority(ThreadHandle thread, int priority) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetSystemThreadPriority(ThreadHandle thread) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(ThreadHandle handle, WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemThread(WindowsDWord count, const ThreadHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsThreadHandleValid(ThreadHandle threadHandle) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE ExitSystemThread(WindowsDWord exitCode) noexcept;

    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE BeginSystemThread(void* security,
                                                                        unsigned int stacksize,
                                                                        StartAddress startAddress,
                                                                        void* argument,
                                                                        unsigned int createFlag,
                                                                        unsigned int* threadAddress) noexcept;
    void SYSTEM_DEFAULT_DECLARE EndSystemThread(unsigned int retCode) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_H
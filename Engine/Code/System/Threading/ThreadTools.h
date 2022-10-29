///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:05)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_H
#define SYSTEM_THREADING_THREAD_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadToolsUsing.h"
#include "Using/ThreadUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 线程辅助工具。

    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE OpenSystemThread(ThreadStandardAccess standardDesiredAccess,
                                                                       ThreadSpecificAccess specificDesiredAccess,
                                                                       bool inheritHandle,
                                                                       WindowsDWord threadID) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetThreadExitCode(ThreadHandle thread, WindowsDWordPtr exitCode) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetSystemThreadID(ThreadHandle thread) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemThreadPriorityBoost(ThreadHandle thread, bool* disablePriorityBoost) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenSystemThreadToken(ThreadHandle thread,
                                                                TokenStandardAccess standardAccess,
                                                                TokenSpecificAccess specificAccess,
                                                                bool openAsSelf,
                                                                WindowsHandlePtr tokenHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemThreadToken(ThreadHandlePtr thread, WindowsHandle tokenHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseTokenHandle(WindowsHandle tokenHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemThreadTimes(ThreadHandle thread,
                                                               FileTimePtr creationTime,
                                                               FileTimePtr exitTime,
                                                               FileTimePtr kernelTime,
                                                               FileTimePtr userTime) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_TOOLS_H
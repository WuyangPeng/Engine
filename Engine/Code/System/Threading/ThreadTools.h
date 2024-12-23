/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:15)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_H
#define SYSTEM_THREADING_THREAD_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// 线程辅助工具。
namespace System
{
    MAYBE_NULLPTR ThreadHandle SYSTEM_DEFAULT_DECLARE OpenSystemThread(ThreadStandardAccess standardDesiredAccess,
                                                                       ThreadSpecificAccess specificDesiredAccess,
                                                                       bool inheritHandle,
                                                                       WindowsDWord threadId) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetThreadExitCode(ThreadHandle thread, WindowsDWordPtr exitCode) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetSystemThreadId(ThreadHandle thread) noexcept;

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
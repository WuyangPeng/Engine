//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:32)

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

    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
                                                                               WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept;
    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize,
                                                                               ThreadStartRoutine startAddress, WindowVoidPtr parameter, ThreadCreation creationFlags,
                                                                               ProcThreadAttributeListPtr attributeList, WindowDWordPtr threadID) noexcept;
    [[nodiscard]] ThreadHandle SYSTEM_DEFAULT_DECLARE OpenSystemThread(ThreadStandardAccess standardDesiredAccess, ThreadSpecificAccess specificDesiredAccess, bool inheritHandle, WindowDWord threadID) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetThreadExitCode(ThreadHandle thread, WindowDWordPtr exitCode) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemThreadID(ThreadHandle thread) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemThreadPriorityBoost(ThreadHandle thread, WindowBoolPtr disablePriorityBoost) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SwitchToSystemThread() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE OpenSystemThreadToken(ThreadHandle thread, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, bool openAsSelf, WindowHandlePtr tokenHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemThreadToken(ThreadHandlePtr thread, WindowHandle tokenHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseTokenHandle(WindowHandle tokenHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept;
    void SYSTEM_DEFAULT_DECLARE InitThreadContextFlags(WindowContext& context, ThreadContextState flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemThreadContext(ThreadHandle thread, WindowContextPtr context) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemThreadContext(ThreadHandle thread, const WindowContext* context) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_TOOLS_H
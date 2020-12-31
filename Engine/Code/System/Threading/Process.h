//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_PROCESS_H
#define SYSTEM_THREADING_PROCESS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ProcessUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 进程的创建和销毁
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const String& applicationName);

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes,
                                                                  bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
                                                                  const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemProcess(WindowHandle process) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandle() noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandleID() noexcept;
    void SYSTEM_DEFAULT_DECLARE ExitSystemProcess(WindowUInt exitCode) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetProcessHandleID(WindowHandle process) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetProcessPriorityClass(WindowHandle process, ProcessCreation priorityClass) noexcept;
    [[nodiscard]] ProcessCreation SYSTEM_DEFAULT_DECLARE GetProcessPriorityClass(WindowHandle process) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemProcess(ProcessStandardAccess standardAccess, ProcessSpecificAccess desiredAccess, bool inheritHandle, WindowDWord processID) noexcept;
}

#endif  // SYSTEM_THREADING_PROCESS_H
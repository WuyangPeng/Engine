/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:14)

#ifndef SYSTEM_THREADING_PROCESS_H
#define SYSTEM_THREADING_PROCESS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ProcessUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// 进程的创建和销毁
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const String& applicationName);
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const TChar* applicationName,
                                                              TChar* commandLine,
                                                              WindowSecurityAttributesPtr processAttributes,
                                                              WindowSecurityAttributesPtr threadAttributes,
                                                              bool inheritHandles,
                                                              ProcessCreation creationFlags,
                                                              WindowsVoidPtr environment,
                                                              const TChar* currentDirectory,
                                                              ProcessStartupInfoPtr startupInfo,
                                                              ProcessInformationPtr processInformation) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemProcess(WindowsHandle process) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandle() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandleId() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetProcessHandleId(WindowsHandle process) noexcept;

    void SYSTEM_DEFAULT_DECLARE ExitSystemProcess(WindowsUInt exitCode) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetProcessPriorityClass(WindowsHandle process, ProcessCreation priorityClass) noexcept;
    NODISCARD ProcessCreation SYSTEM_DEFAULT_DECLARE GetProcessPriorityClass(WindowsHandle process) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemProcess(ProcessStandardAccess standardAccess,
                                                                         ProcessSpecificAccess desiredAccess,
                                                                         bool inheritHandle,
                                                                         WindowsDWord processId) noexcept;
}

#endif  // SYSTEM_THREADING_PROCESS_H
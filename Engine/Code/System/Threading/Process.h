///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/01/30 13:18)

#ifndef SYSTEM_THREADING_PROCESS_H
#define SYSTEM_THREADING_PROCESS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ProcessUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// ���̵Ĵ���������
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
                                                              ProcessStartupinfoPtr startupInfo,
                                                              ProcessInformationPtr processInformation) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemProcess(WindowsHandle process) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandle() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandleID() noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetProcessHandleID(WindowsHandle process) noexcept;

    void SYSTEM_DEFAULT_DECLARE ExitSystemProcess(WindowsUInt exitCode) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetProcessPriorityClass(WindowsHandle process, ProcessCreation priorityClass) noexcept;
    NODISCARD ProcessCreation SYSTEM_DEFAULT_DECLARE GetProcessPriorityClass(WindowsHandle process) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemProcess(ProcessStandardAccess standardAccess,
                                                                         ProcessSpecificAccess desiredAccess,
                                                                         bool inheritHandle,
                                                                         WindowsDWord processID) noexcept;
}

#endif  // SYSTEM_THREADING_PROCESS_H
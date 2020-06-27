// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 11:33)

#ifndef SYSTEM_THREADING_PROCESS_H
#define SYSTEM_THREADING_PROCESS_H

#include "System/SystemDll.h"

#include "Using/ProcessUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h" 
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 进程的创建和销毁
	bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const String& applicationName);

	bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes,
													bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
													const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemProcess(WindowHandle process) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandle() noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessHandleID() noexcept;
	void SYSTEM_DEFAULT_DECLARE ExitSystemProcess(WindowUInt exitCode) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetProcessHandleID(WindowHandle process) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetProcessPriorityClass(WindowHandle process, ProcessCreation priorityClass) noexcept;
	ProcessCreation SYSTEM_DEFAULT_DECLARE GetProcessPriorityClass(WindowHandle process) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemProcess(ProcessStandardAccess standardAccess, ProcessSpecificAccess desiredAccess, bool inheritHandle, WindowDWord processID) noexcept;
}

#endif // SYSTEM_THREADING_PROCESS_H
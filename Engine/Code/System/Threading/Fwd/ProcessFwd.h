// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_PROCESS_FWD_H
#define SYSTEM_THREADING_PROCESS_FWD_H   

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/ProcessUsing.h"

namespace System
{
	bool CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes, bool inheritHandles,
							 ProcessCreation creationFlags, WindowVoidPtr environment, const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
	bool CloseSystemProcess(WindowHandle process) noexcept;
	WindowHandle GetCurrentProcessHandle() noexcept;
	WindowDWord GetCurrentProcessHandleID() noexcept;
	void ExitSystemProcess(WindowUInt exitCode) noexcept;
	WindowDWord GetProcessHandleID(WindowHandle process) noexcept;
	bool SetProcessPriorityClass(WindowHandle process, ProcessCreation priorityClass) noexcept;
	ProcessCreation GetProcessPriorityClass(WindowHandle process) noexcept;
	WindowHandle OpenSystemProcess(ProcessStandardAccess standardAccess, ProcessSpecificAccess desiredAccess, bool inheritHandle, WindowDWord processID) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_FWD_H
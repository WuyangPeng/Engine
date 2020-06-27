// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 13:00)

#include "System/SystemExport.h"

#include "Process.h"
#include "Thread.h"
#include "Flags/ProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h" 
#include "System/Window/Engineering.h"
#include "System/Window/WindowSystem.h"

bool System
	::CreateSystemProcess(const String& applicationName)
{
	ProcessStartupinfo startupInfo{ };
	ProcessInformation processInformation{ };

	auto fullName = GetEngineeringDirectory() + applicationName + GetEngineeringSuffix() + GetEngineeringExeSuffix();

	const auto result = CreateSystemProcess(fullName.c_str(), nullptr, nullptr, nullptr, true,
											ProcessCreation::CreateNewConsole, nullptr, nullptr, &startupInfo, &processInformation);

	if (result)
	{
		CloseSystemThread(processInformation.hThread);
		CloseSystemProcess(processInformation.hProcess);
	}

	return result;
}

bool System
	::CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes,
						  bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
						  const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreateProcess(applicationName, commandLine, processAttributes, threadAttributes, BoolConversion(inheritHandles),
						EnumCastUnderlying(creationFlags), environment, currentDirectory, startupInfo, processInformation) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(applicationName);
	SYSTEM_UNUSED_ARG(commandLine);
	SYSTEM_UNUSED_ARG(processAttributes);
	SYSTEM_UNUSED_ARG(threadAttributes);
	SYSTEM_UNUSED_ARG(inheritHandles);
	SYSTEM_UNUSED_ARG(creationFlags);
	SYSTEM_UNUSED_ARG(environment);
	SYSTEM_UNUSED_ARG(currentDirectory);
	SYSTEM_UNUSED_ARG(startupInfo);
	SYSTEM_UNUSED_ARG(processInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::GetCurrentProcessHandle() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentProcess();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WindowDWord System
	::GetCurrentProcessHandleID() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentProcessId();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

void System
	::ExitSystemProcess(WindowUInt exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::ExitProcess(exitCode);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(exitCode);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WindowDWord System
	::GetProcessHandleID(WindowHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetProcessId(process);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::SetProcessPriorityClass(WindowHandle process, ProcessCreation priorityClass) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetPriorityClass(process, EnumCastUnderlying(priorityClass)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(priorityClass);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ProcessCreation System
	::GetProcessPriorityClass(WindowHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<ProcessCreation>(::GetPriorityClass(process));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);

	return ProcessCreation::ProcessModeBackgroundBegin;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WindowHandle System
	::OpenSystemProcess(ProcessStandardAccess standardAccess, ProcessSpecificAccess desiredAccess, bool inheritHandle, WindowDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::OpenProcess(EnumCastUnderlying(standardAccess) | EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), processID);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(standardAccess);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(processID);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::CloseSystemProcess(WindowHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(process) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

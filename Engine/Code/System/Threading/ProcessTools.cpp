// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 13:04)	

#include "System/SystemExport.h"

#include "ProcessTools.h"
#include "Process.h"
#include "Flags/ProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h" 
#include "System/Window/WindowSystem.h"
#include "System/MemoryTools/MemoryHelperDetail.h"

bool System
	::GenerateSystemConsoleCtrlEvent(CtrlEvent ctrlEvent, WindowDWord processGroupID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GenerateConsoleCtrlEvent(EnumCastUnderlying(ctrlEvent), processGroupID) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(ctrlEvent);
	SYSTEM_UNUSED_ARG(processGroupId);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AttachSystemConsole(WindowDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AttachConsole(processID) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(processID);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleProcessList(WindowDWordPtr processList, WindowDWord processCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleProcessList(processList, processCount);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(processList);
	SYSTEM_UNUSED_ARG(processCount);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::QueueUserAsynchronousProcedureCall(AsynchronousProcedureCallFunction functionAPC, ThreadHandle thread, WindowPtrULong data) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::QueueUserAPC(functionAPC, thread, data);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(functionAPC);
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(data);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSysemProcessTimes(WindowHandle process, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetProcessTimes(process, creationTime, exitTime, kernelTime, userTime) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(creationTime);
	SYSTEM_UNUSED_ARG(exitTime);
	SYSTEM_UNUSED_ARG(kernelTime);
	SYSTEM_UNUSED_ARG(userTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSysemProcessExitCode(WindowHandle process, WindowDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetExitCodeProcess(process, exitCode) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(exitCode);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSysemProcessVersion(WindowDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetProcessVersion(processID);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(processID);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::GetProcessStartupInfo(ProcessStartupinfoPtr startupInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetStartupInfo(startupInfo);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(startupInfo);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::OpenSysemProcessToken(WindowHandle process, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::OpenProcessToken(process, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(standardAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(tokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ProcessIDToSessionID(WindowDWord processID, WindowDWord* sessionID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (g_False != ::ProcessIdToSessionId(processID, sessionID))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(processID);
	SYSTEM_UNUSED_ARG(sessionID);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::FlushSystemProcessWriteBuffers() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FlushProcessWriteBuffers();
#else // !SYSTEM_PLATFORM_WIN32

#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemProcessIDOfThread(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetProcessIdOfThread(thread);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::InitializeProcessThreadAttributeList(ProcThreadAttributeListPtr attributeList, WindowDWord attributeCount, WindowSizePtr size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitializeProcThreadAttributeList(attributeList, attributeCount, 0, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attributeList);
	SYSTEM_UNUSED_ARG(attributeCount);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::DeleteProcessThreadAttributeList(ProcThreadAttributeListPtr attributeList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::DeleteProcThreadAttributeList(attributeList);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attributeList);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemProcessAffinityUpdateMode(WindowHandle process, ProcessAffinity flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetProcessAffinityUpdateMode(process, EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::QuerySystemProcessAffinityUpdateMode(WindowHandle process, ProcessAffinity* flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowDWord mode{ 0 };

	if (g_False != ::QueryProcessAffinityUpdateMode(process, &mode))
	{
		UnderlyingCastEnumPtr(mode, flags);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FlushProcessInstructionCache(WindowHandle process, WindowConstVoidPtr baseAddress, WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FlushInstructionCache(process, baseAddress, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(baseAddress);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsProcessProcessorFeaturePresent(ProcessorFeature processorFeature) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsProcessorFeaturePresent(EnumCastUnderlying(processorFeature)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(processorFeature);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetCurrentProcessProcessorNumber() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentProcessorNumber();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemProcessHandleCount(WindowHandle process, WindowDWordPtr handleCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetProcessHandleCount(process, handleCount) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(handleCount);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::SetSystemThreadIdealProcessor(ThreadHandle thread, WindowDWord idealProcessor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadIdealProcessor(thread, idealProcessor);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(idealProcessor);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemThreadIdealProcessor(ThreadHandle thread, ProcessorNumberPtr idealProcessor, ProcessorNumberPtr previousIdealProcessor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadIdealProcessorEx(thread, idealProcessor, previousIdealProcessor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(idealProcessor);
	SYSTEM_UNUSED_ARG(previousIdealProcessor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32 
}

bool System
	::GetSystemThreadIdealProcessor(ThreadHandle thread, ProcessorNumberPtr idealProcessor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetThreadIdealProcessorEx(thread, idealProcessor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(idealProcessor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::GetCurrentProcessProcessorNumber(ProcessorNumberPtr procNumber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentProcessorNumberEx(procNumber);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(procNumber);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemProcessPriorityBoost(WindowHandle process, WindowBoolPtr disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetProcessPriorityBoost(process, disablePriorityBoost) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(disablePriorityBoost);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemProcessPriorityBoost(WindowHandle process, bool disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetProcessPriorityBoost(process, BoolConversion(disablePriorityBoost)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(disablePriorityBoost);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemThreadIOPendingFlag(ThreadHandle thread, WindowBoolPtr iOIsPending) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetThreadIOPendingFlag(thread, iOIsPending) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(iOIsPending);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetCurrentSystemTimes(FileTimePtr idleTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetSystemTimes(idleTime, kernelTime, userTime) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(idleTime);
	SYSTEM_UNUSED_ARG(kernelTime);
	SYSTEM_UNUSED_ARG(userTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes,
						  bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
						  const TChar* currentDirectory, ProcessStartupinfoExPtr startupInfo, ProcessInformationPtr processInformation) noexcept
{
	creationFlags |= ProcessCreation::ExtendedStartupinfoPresent;

	return CreateSystemProcess(applicationName, commandLine, processAttributes, threadAttributes, inheritHandles,
							   creationFlags, environment, currentDirectory, reinterpret_cast<ProcessStartupinfoPtr>(startupInfo), processInformation);
}

bool System
	::CreateSystemProcessAsUser(WindowHandle token, const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes,
								WindowSecurityAttributesPtr threadAttributes, bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
								const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreateProcessAsUser(token, applicationName, commandLine, processAttributes, threadAttributes, BoolConversion(inheritHandles),
							  EnumCastUnderlying(creationFlags), environment, currentDirectory, startupInfo, processInformation) != g_False)
	{
		return true;
	}

	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(token);
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

bool System
	::SetSystemProcessShutdownParameters(WindowDWord level, ProcessShutdownParameters flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetProcessShutdownParameters(level, EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(level);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UpdateProcessThreadAttribute(ProcThreadAttributeListPtr attributeList, ProcessThreadAttribute flags, WindowVoidPtr value, WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::UpdateProcThreadAttribute(attributeList, 0, EnumCastUnderlying(flags), value, size, nullptr, nullptr) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attributeList);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(value);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::InitProcessStartupinfo(ProcessStartupinfoEx& processStartupinfoEx, ProcThreadAttributeListPtr attributeList) noexcept
{
	processStartupinfoEx.lpAttributeList = attributeList;
	FillMemoryToZero(processStartupinfoEx.StartupInfo);
	processStartupinfoEx.StartupInfo.cb = sizeof(processStartupinfoEx);
}

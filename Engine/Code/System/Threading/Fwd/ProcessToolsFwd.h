// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_FWD_H
#define SYSTEM_THREADING_PROCESS_TOOLS_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/ProcessToolsUsing.h" 

namespace System
{
	WindowDWord GetSystemConsoleProcessList(WindowDWordPtr processList, WindowDWord processCount) noexcept;
	bool GenerateSystemConsoleCtrlEvent(CtrlEvent ctrlEvent, WindowDWord processGroupID) noexcept;
	bool AttachSystemConsole(WindowDWord processID) noexcept;
	WindowDWord QueueUserAsynchronousProcedureCall(AsynchronousProcedureCallFunction functionAPC, ThreadHandle thread, WindowPtrULong data) noexcept;
	bool GetSysemProcessTimes(WindowHandle process, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;
	bool GetSysemProcessExitCode(WindowHandle process, WindowDWordPtr exitCode) noexcept;
	WindowDWord GetSysemProcessVersion(WindowDWord processID) noexcept;
	void GetProcessStartupInfo(ProcessStartupinfoPtr startupInfo) noexcept;
	bool OpenSysemProcessToken(WindowHandle process, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowHandlePtr tokenHandle) noexcept;
	bool ProcessIDToSessionID(WindowDWord processID, WindowDWord* sessionID) noexcept;
	void FlushSystemProcessWriteBuffers() noexcept;
	WindowDWord GetSystemProcessIDOfThread(ThreadHandle thread) noexcept;
	bool InitializeProcessThreadAttributeList(ProcThreadAttributeListPtr attributeList, WindowDWord attributeCount, WindowSizePtr size) noexcept;
	void DeleteProcessThreadAttributeList(ProcThreadAttributeListPtr attributeList) noexcept;
	bool SetSystemProcessAffinityUpdateMode(WindowHandle process, ProcessAffinity flags) noexcept;
	bool QuerySystemProcessAffinityUpdateMode(WindowHandle process, ProcessAffinity* flags) noexcept;
	bool FlushProcessInstructionCache(WindowHandle process, WindowConstVoidPtr baseAddress, WindowSize size) noexcept;
	bool IsProcessProcessorFeaturePresent(ProcessorFeature processorFeature) noexcept;
	WindowDWord GetCurrentProcessProcessorNumber() noexcept;
	bool GetSystemProcessHandleCount(WindowHandle process, WindowDWordPtr handleCount) noexcept;
	WindowDWord SetSystemThreadIdealProcessor(ThreadHandle thread, WindowDWord idealProcessor) noexcept;
	bool SetSystemThreadIdealProcessor(ThreadHandle thread, ProcessorNumberPtr idealProcessor, ProcessorNumberPtr previousIdealProcessor) noexcept;
	bool GetSystemThreadIdealProcessor(ThreadHandle thread, ProcessorNumberPtr idealProcessor) noexcept;
	void GetCurrentProcessProcessorNumber(ProcessorNumberPtr procNumber) noexcept;
	bool GetSystemProcessPriorityBoost(WindowHandle process, WindowBoolPtr disablePriorityBoost) noexcept;
	bool SetSystemProcessPriorityBoost(WindowHandle process, bool disablePriorityBoost) noexcept;
	bool GetSystemThreadIOPendingFlag(ThreadHandle thread, WindowBoolPtr iOIsPending) noexcept;
	bool GetCurrentSystemTimes(FileTimePtr idleTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;
	bool CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes, bool inheritHandles,
							 ProcessCreation creationFlags, WindowVoidPtr environment, const TChar* currentDirectory, ProcessStartupinfoExPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
	bool CreateSystemProcessAsUser(WindowHandle token, const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes,
								   WindowSecurityAttributesPtr threadAttributes, bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
								   const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
	bool SetSystemProcessShutdownParameters(WindowDWord level, ProcessShutdownParameters flags) noexcept;
	bool UpdateProcessThreadAttribute(ProcThreadAttributeListPtr attributeList, ProcessThreadAttribute flags, WindowVoidPtr value, WindowSize size) noexcept;
	void InitProcessStartupinfo(ProcessStartupinfoEx& processStartupinfoEx, ProcThreadAttributeListPtr attributeList) noexcept;
}

#endif // SYSTEM_THREADING_PROCESS_TOOLS_FWD_H
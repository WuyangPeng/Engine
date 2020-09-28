//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_H
#define SYSTEM_THREADING_PROCESS_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ProcessToolsUsing.h"
#include "Using/ProcessUsing.h"
#include "Using/ThreadToolsUsing.h"
#include "Using/ThreadUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 进程工具

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleProcessList(WindowDWordPtr processList, WindowDWord processCount) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GenerateSystemConsoleCtrlEvent(CtrlEvent ctrlEvent, WindowDWord processGroupID) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AttachSystemConsole(WindowDWord processID) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeProcessThreadAttributeList(ProcThreadAttributeListPtr attributeList, WindowDWord attributeCount, WindowSizePtr size) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteProcessThreadAttributeList(ProcThreadAttributeListPtr attributeList) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UpdateProcessThreadAttribute(ProcThreadAttributeListPtr attributeList, ProcessThreadAttribute flags, WindowVoidPtr value, WindowSize size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes,
                                                                  bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
                                                                  const TChar* currentDirectory, ProcessStartupinfoExPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
    void SYSTEM_DEFAULT_DECLARE InitProcessStartupinfo(ProcessStartupinfoEx& processStartupinfoEx, ProcThreadAttributeListPtr attributeList) noexcept;

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetCurrentProcessProcessorNumber() noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE SetSystemThreadIdealProcessor(ThreadHandle thread, WindowDWord idealProcessor) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemThreadIdealProcessor(ThreadHandle thread, ProcessorNumberPtr idealProcessor, ProcessorNumberPtr previousIdealProcessor) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemThreadIdealProcessor(ThreadHandle thread, ProcessorNumberPtr idealProcessor) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetCurrentProcessProcessorNumber(ProcessorNumberPtr procNumber) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsProcessProcessorFeaturePresent(ProcessorFeature processorFeature) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSysemProcessTimes(WindowHandle process, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemTimes(FileTimePtr idleTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSysemProcessExitCode(WindowHandle process, WindowDWordPtr exitCode) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSysemProcessVersion(WindowDWord processID) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetProcessStartupInfo(ProcessStartupinfoPtr startupInfo) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemProcessIDOfThread(ThreadHandle thread) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemProcessHandleCount(WindowHandle process, WindowDWordPtr handleCount) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemProcessPriorityBoost(WindowHandle process, WindowBoolPtr disablePriorityBoost) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemProcessPriorityBoost(WindowHandle process, bool disablePriorityBoost) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemProcessAffinityUpdateMode(WindowHandle process, ProcessAffinity flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE QuerySystemProcessAffinityUpdateMode(WindowHandle process, ProcessAffinity* flags) noexcept;

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE QueueUserAsynchronousProcedureCall(AsynchronousProcedureCallFunction functionAPC, ThreadHandle thread, WindowPtrULong data) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE OpenSysemProcessToken(WindowHandle process, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowHandlePtr tokenHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemProcessAsUser(WindowHandle token, const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes,
                                                                        WindowSecurityAttributesPtr threadAttributes, bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
                                                                        const TChar* currentDirectory, ProcessStartupinfoPtr startupInfo, ProcessInformationPtr processInformation) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ProcessIDToSessionID(WindowDWord processID, WindowDWord* sessionID) noexcept;

    void SYSTEM_DEFAULT_DECLARE FlushSystemProcessWriteBuffers() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FlushProcessInstructionCache(WindowHandle process, WindowConstVoidPtr baseAddress, WindowSize size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemThreadIOPendingFlag(ThreadHandle thread, WindowBoolPtr iOIsPending) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemProcessShutdownParameters(WindowDWord level, ProcessShutdownParameters flags) noexcept;
}

#endif  // SYSTEM_THREADING_PROCESS_TOOLS_H
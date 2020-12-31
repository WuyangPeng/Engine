//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:47)

#include "System/SystemExport.h"

#include "Process.h"
#include "ProcessTools.h"
#include "Flags/ProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Window/WindowSystem.h"

bool System::GenerateSystemConsoleCtrlEvent([[maybe_unused]] CtrlEvent ctrlEvent, [[maybe_unused]] WindowDWord processGroupID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GenerateConsoleCtrlEvent(EnumCastUnderlying(ctrlEvent), processGroupID) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AttachSystemConsole([[maybe_unused]] WindowDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AttachConsole(processID) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleProcessList([[maybe_unused]] WindowDWordPtr processList, [[maybe_unused]] WindowDWord processCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleProcessList(processList, processCount);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::QueueUserAsynchronousProcedureCall([[maybe_unused]] AsynchronousProcedureCallFunction functionAPC, [[maybe_unused]] ThreadHandle thread, [[maybe_unused]] WindowPtrULong data) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::QueueUserAPC(functionAPC, thread, data);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSysemProcessTimes([[maybe_unused]] WindowHandle process, [[maybe_unused]] FileTimePtr creationTime, [[maybe_unused]] FileTimePtr exitTime, [[maybe_unused]] FileTimePtr kernelTime, [[maybe_unused]] FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetProcessTimes(process, creationTime, exitTime, kernelTime, userTime) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSysemProcessExitCode([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetExitCodeProcess(process, exitCode) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSysemProcessVersion([[maybe_unused]] WindowDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetProcessVersion(processID);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::GetProcessStartupInfo([[maybe_unused]] ProcessStartupinfoPtr startupInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetStartupInfo(startupInfo);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::OpenSysemProcessToken([[maybe_unused]] WindowHandle process, [[maybe_unused]] TokenStandardAccess standardAccess, [[maybe_unused]] TokenSpecificAccess specificAccess, [[maybe_unused]] WindowHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::OpenProcessToken(process, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ProcessIDToSessionID([[maybe_unused]] WindowDWord processID, [[maybe_unused]] WindowDWord* sessionID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (g_False != ::ProcessIdToSessionId(processID, sessionID))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::FlushSystemProcessWriteBuffers() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FlushProcessWriteBuffers();
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemProcessIDOfThread([[maybe_unused]] ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetProcessIdOfThread(thread);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeProcessThreadAttributeList([[maybe_unused]] ProcThreadAttributeListPtr attributeList, [[maybe_unused]] WindowDWord attributeCount, [[maybe_unused]] WindowSizePtr size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitializeProcThreadAttributeList(attributeList, attributeCount, 0, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::DeleteProcessThreadAttributeList([[maybe_unused]] ProcThreadAttributeListPtr attributeList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::DeleteProcThreadAttributeList(attributeList);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemProcessAffinityUpdateMode([[maybe_unused]] WindowHandle process, [[maybe_unused]] ProcessAffinity flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetProcessAffinityUpdateMode(process, EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::QuerySystemProcessAffinityUpdateMode([[maybe_unused]] WindowHandle process, [[maybe_unused]] ProcessAffinity* flags) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushProcessInstructionCache([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowConstVoidPtr baseAddress, [[maybe_unused]] WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FlushInstructionCache(process, baseAddress, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsProcessProcessorFeaturePresent([[maybe_unused]] ProcessorFeature processorFeature) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsProcessorFeaturePresent(EnumCastUnderlying(processorFeature)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetCurrentProcessProcessorNumber() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentProcessorNumber();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemProcessHandleCount([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowDWordPtr handleCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetProcessHandleCount(process, handleCount) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::SetSystemThreadIdealProcessor([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] WindowDWord idealProcessor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadIdealProcessor(thread, idealProcessor);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemThreadIdealProcessor([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] ProcessorNumberPtr idealProcessor, [[maybe_unused]] ProcessorNumberPtr previousIdealProcessor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadIdealProcessorEx(thread, idealProcessor, previousIdealProcessor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadIdealProcessor([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] ProcessorNumberPtr idealProcessor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetThreadIdealProcessorEx(thread, idealProcessor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::GetCurrentProcessProcessorNumber([[maybe_unused]] ProcessorNumberPtr procNumber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentProcessorNumberEx(procNumber);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemProcessPriorityBoost([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowBoolPtr disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetProcessPriorityBoost(process, disablePriorityBoost) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemProcessPriorityBoost([[maybe_unused]] WindowHandle process, [[maybe_unused]] bool disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetProcessPriorityBoost(process, BoolConversion(disablePriorityBoost)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemThreadIOPendingFlag([[maybe_unused]] ThreadHandle thread, [[maybe_unused]] WindowBoolPtr iOIsPending) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetThreadIOPendingFlag(thread, iOIsPending) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCurrentSystemTimes([[maybe_unused]] FileTimePtr idleTime, [[maybe_unused]] FileTimePtr kernelTime, [[maybe_unused]] FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetSystemTimes(idleTime, kernelTime, userTime) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemProcess(const TChar* applicationName, TChar* commandLine, WindowSecurityAttributesPtr processAttributes, WindowSecurityAttributesPtr threadAttributes,
                                 bool inheritHandles, ProcessCreation creationFlags, WindowVoidPtr environment,
                                 const TChar* currentDirectory, ProcessStartupinfoExPtr startupInfo, ProcessInformationPtr processInformation) noexcept
{
    creationFlags |= ProcessCreation::ExtendedStartupinfoPresent;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    return CreateSystemProcess(applicationName, commandLine, processAttributes, threadAttributes, inheritHandles,
                               creationFlags, environment, currentDirectory, reinterpret_cast<ProcessStartupinfoPtr>(startupInfo), processInformation);
#include STSTEM_WARNING_POP
}

bool System::CreateSystemProcessAsUser([[maybe_unused]] WindowHandle token, [[maybe_unused]] const TChar* applicationName, [[maybe_unused]] TChar* commandLine, [[maybe_unused]] WindowSecurityAttributesPtr processAttributes,
                                       [[maybe_unused]] WindowSecurityAttributesPtr threadAttributes, [[maybe_unused]] bool inheritHandles, [[maybe_unused]] ProcessCreation creationFlags, [[maybe_unused]] WindowVoidPtr environment,
                                       [[maybe_unused]] const TChar* currentDirectory, [[maybe_unused]] ProcessStartupinfoPtr startupInfo, [[maybe_unused]] ProcessInformationPtr processInformation) noexcept
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

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemProcessShutdownParameters([[maybe_unused]] WindowDWord level, [[maybe_unused]] ProcessShutdownParameters flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetProcessShutdownParameters(level, EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UpdateProcessThreadAttribute([[maybe_unused]] ProcThreadAttributeListPtr attributeList, [[maybe_unused]] ProcessThreadAttribute flags, [[maybe_unused]] WindowVoidPtr value, [[maybe_unused]] WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::UpdateProcThreadAttribute(attributeList, 0, EnumCastUnderlying(flags), value, size, nullptr, nullptr) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::InitProcessStartupinfo(ProcessStartupinfoEx& processStartupinfoEx, ProcThreadAttributeListPtr attributeList) noexcept
{
    processStartupinfoEx.lpAttributeList = attributeList;
    FillMemoryToZero(processStartupinfoEx.StartupInfo);
    processStartupinfoEx.StartupInfo.cb = sizeof(processStartupinfoEx);
}

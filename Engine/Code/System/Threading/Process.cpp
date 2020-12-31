//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:00)

#include "System/SystemExport.h"

#include "Process.h"
#include "Thread.h"
#include "Flags/ProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Engineering.h"
#include "System/Window/WindowSystem.h"

bool System::CreateSystemProcess(const String& applicationName)
{
    ProcessStartupinfo startupInfo{};
    ProcessInformation processInformation{};

    auto fullName = GetEngineeringDirectory() + applicationName + GetEngineeringSuffix() + GetEngineeringExeSuffix();

    const auto result = CreateSystemProcess(fullName.c_str(), nullptr, nullptr, nullptr, true,
                                            ProcessCreation::CreateNewConsole, nullptr, nullptr, &startupInfo, &processInformation);

    if (result)
    {
        [[maybe_unused]] const auto closeThread = CloseSystemThread(processInformation.hThread);
        [[maybe_unused]] const auto closeProcess = CloseSystemProcess(processInformation.hProcess);
    }

    return result;
}

bool System::CreateSystemProcess([[maybe_unused]] const TChar* applicationName, [[maybe_unused]] TChar* commandLine, [[maybe_unused]] WindowSecurityAttributesPtr processAttributes, [[maybe_unused]] WindowSecurityAttributesPtr threadAttributes,
                                 [[maybe_unused]] bool inheritHandles, [[maybe_unused]] ProcessCreation creationFlags, [[maybe_unused]] WindowVoidPtr environment,
                                 [[maybe_unused]] const TChar* currentDirectory, [[maybe_unused]] ProcessStartupinfoPtr startupInfo, [[maybe_unused]] ProcessInformationPtr processInformation) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::GetCurrentProcessHandle() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentProcess();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetCurrentProcessHandleID() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetCurrentProcessId();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ExitSystemProcess([[maybe_unused]] WindowUInt exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ExitProcess(exitCode);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetProcessHandleID([[maybe_unused]] WindowHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetProcessId(process);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetProcessPriorityClass([[maybe_unused]] WindowHandle process, [[maybe_unused]] ProcessCreation priorityClass) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetPriorityClass(process, EnumCastUnderlying(priorityClass)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ProcessCreation System::GetProcessPriorityClass([[maybe_unused]] WindowHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<ProcessCreation>(::GetPriorityClass(process));
#else  // !SYSTEM_PLATFORM_WIN32
    return ProcessCreation::ProcessModeBackgroundBegin;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::OpenSystemProcess([[maybe_unused]] ProcessStandardAccess standardAccess, [[maybe_unused]] ProcessSpecificAccess desiredAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] WindowDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenProcess(EnumCastUnderlying(standardAccess) | EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), processID);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemProcess([[maybe_unused]] WindowHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(process) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

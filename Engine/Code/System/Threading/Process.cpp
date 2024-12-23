/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:18)

#include "System/SystemExport.h"

#include "Process.h"
#include "Thread.h"
#include "Flags/ProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "System/Windows/Engineering.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

bool System::CreateSystemProcess(const String& applicationName)
{
    const auto fullName = GetEngineeringDirectory() + applicationName + GetEngineeringSuffix() + GetEngineeringExeSuffix();

    ProcessStartupInfo startupInfo{};
    ProcessInformation processInformation{};

    const auto result = CreateSystemProcess(fullName.c_str(),
                                            nullptr,
                                            nullptr,
                                            nullptr,
                                            true,
                                            ProcessCreation::CreateNewConsole,
                                            nullptr,
                                            nullptr,
                                            &startupInfo,
                                            &processInformation);

    if (result)
    {
        if (!CloseSystemThread(processInformation.hThread) || !CloseSystemProcess(processInformation.hProcess))
        {
            OutputDebugStringWithTChar(SYSTEM_TEXT("CreateSystemProcess����ͷ�ʧ�ܡ�\n"));
        }
    }

    return result;
}

bool System::CreateSystemProcess(const TChar* applicationName,
                                 TChar* commandLine,
                                 WindowSecurityAttributesPtr processAttributes,
                                 WindowSecurityAttributesPtr threadAttributes,
                                 bool inheritHandles,
                                 ProcessCreation creationFlags,
                                 WindowsVoidPtr environment,
                                 const TChar* currentDirectory,
                                 ProcessStartupInfoPtr startupInfo,
                                 ProcessInformationPtr processInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateProcess(applicationName,
                           commandLine,
                           processAttributes,
                           threadAttributes,
                           BoolConversion(inheritHandles),
                           EnumCastUnderlying(creationFlags),
                           environment,
                           currentDirectory,
                           startupInfo,
                           processInformation) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(applicationName,
                   commandLine,
                   processAttributes,
                   threadAttributes,
                   inheritHandles,
                   creationFlags,
                   environment,
                   currentDirectory,
                   startupInfo,
                   processInformation);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::GetCurrentProcessHandle() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentProcess();

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetCurrentProcessHandleId() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetCurrentProcessId();

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ExitSystemProcess(WindowsUInt exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ExitProcess(exitCode);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(exitCode);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetProcessHandleId(WindowsHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetProcessId(process);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetProcessPriorityClass(WindowsHandle process, ProcessCreation priorityClass) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetPriorityClass(process, EnumCastUnderlying(priorityClass)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, priorityClass);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ProcessCreation System::GetProcessPriorityClass(WindowsHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ProcessCreation>(gsl::narrow_cast<int>(::GetPriorityClass(process)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process);

    return ProcessCreation::ProcessModeBackgroundBegin;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemProcess(ProcessStandardAccess standardAccess, ProcessSpecificAccess desiredAccess, bool inheritHandle, WindowsDWord processId) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenProcess(EnumCastUnderlying(standardAccess) | EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), processId);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardAccess, desiredAccess, inheritHandle, processId);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemProcess(WindowsHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CloseHandle(process) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
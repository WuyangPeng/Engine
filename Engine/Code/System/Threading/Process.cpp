///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 19:11)

#include "System/SystemExport.h"

#include "Process.h"
#include "Thread.h"
#include "Flags/ProcessFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "System/Windows/Engineering.h"
#include "System/Windows/WindowsSystem.h"

bool System::CreateSystemProcess(const String& applicationName)
{
    ProcessStartupinfo startupInfo{};
    ProcessInformation processInformation{};

    auto fullName = GetEngineeringDirectory() + applicationName + GetEngineeringSuffix() + GetEngineeringExeSuffix();

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
                                 ProcessStartupinfoPtr startupInfo,
                                 ProcessInformationPtr processInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreateProcess(applicationName,
                        commandLine,
                        processAttributes,
                        threadAttributes,
                        BoolConversion(inheritHandles),
                        EnumCastUnderlying(creationFlags),
                        environment,
                        currentDirectory,
                        startupInfo,
                        processInformation) != g_False)
    {
        return true;
    }
    else
    {
        return false;
    }

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

System::WindowsDWord System::GetCurrentProcessHandleID() noexcept
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

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetProcessHandleID(WindowsHandle process) noexcept
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

    if (::SetPriorityClass(process, EnumCastUnderlying(priorityClass)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, priorityClass);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ProcessCreation System::GetProcessPriorityClass(WindowsHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ProcessCreation>(::GetPriorityClass(process));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process);

    return ProcessCreation::ProcessModeBackgroundBegin;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemProcess(ProcessStandardAccess standardAccess, ProcessSpecificAccess desiredAccess, bool inheritHandle, WindowsDWord processID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenProcess(EnumCastUnderlying(standardAccess) | EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), processID);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardAccess, desiredAccess, inheritHandle, processID);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemProcess(WindowsHandle process) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(process) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

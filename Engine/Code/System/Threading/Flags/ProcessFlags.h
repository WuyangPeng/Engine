///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 18:11)

#ifndef SYSTEM_THREADING_PROCESS_FLAGS_H
#define SYSTEM_THREADING_PROCESS_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ProcessCreation : uint32_t
    {
        DebugProcess = DEBUG_PROCESS,
        DebugOnlyThisProcess = DEBUG_ONLY_THIS_PROCESS,
        CreateSuspended = CREATE_SUSPENDED,
        DetachedProcess = DETACHED_PROCESS,

        CreateNewConsole = CREATE_NEW_CONSOLE,
        NormalPriorityClass = NORMAL_PRIORITY_CLASS,
        IdlePriorityClass = IDLE_PRIORITY_CLASS,
        HighPriorityClass = HIGH_PRIORITY_CLASS,

        RealTimePriorityClass = REALTIME_PRIORITY_CLASS,
        CreateNewProcessGroup = CREATE_NEW_PROCESS_GROUP,
        CreateUnicodeEnvironment = CREATE_UNICODE_ENVIRONMENT,
        CreateSeparateWowVdm = CREATE_SEPARATE_WOW_VDM,

        CreateSharedWowVdm = CREATE_SHARED_WOW_VDM,
        CreateForceDos = CREATE_FORCEDOS,
        BelowNormalPriorityClass = BELOW_NORMAL_PRIORITY_CLASS,
        AboveNormalPriorityClass = ABOVE_NORMAL_PRIORITY_CLASS,

        InheritParentAffinity = INHERIT_PARENT_AFFINITY,
        InheritCallerPriority = INHERIT_CALLER_PRIORITY,
        CreateProtectedProcess = CREATE_PROTECTED_PROCESS,
        ExtendedStartupInfoPresent = EXTENDED_STARTUPINFO_PRESENT,

        ProcessModeBackgroundBegin = PROCESS_MODE_BACKGROUND_BEGIN,
        ProcessModeBackgroundEnd = PROCESS_MODE_BACKGROUND_END,

        CreateBreakawayFromJob = CREATE_BREAKAWAY_FROM_JOB,
        CreatePreserveCodeAuthzLevel = CREATE_PRESERVE_CODE_AUTHZ_LEVEL,
        CreateDefaultErrorMode = CREATE_DEFAULT_ERROR_MODE,
        CreateNoWindow = CREATE_NO_WINDOW,

        ProfileUser = PROFILE_USER,
        ProfileKernel = PROFILE_KERNEL,
        ProfileServer = PROFILE_SERVER,
        CreateIgnoreSystemDefault = CREATE_IGNORE_SYSTEM_DEFAULT,
    };

    enum class ProcessStandardAccess
    {
        Delete = DELETE,
        ReadControl = READ_CONTROL,
        WriteDac = WRITE_DAC,
        WriteOwner = WRITE_OWNER,
        Synchronize = SYNCHRONIZE,
    };

    enum class ProcessSpecificAccess
    {
        Terminate = PROCESS_TERMINATE,
        CreateThread = PROCESS_CREATE_THREAD,
        SetSessionId = PROCESS_SET_SESSIONID,
        VmOperation = PROCESS_VM_OPERATION,
        VmRead = PROCESS_VM_READ,
        VmWrite = PROCESS_VM_WRITE,
        DupHandle = PROCESS_DUP_HANDLE,
        CreateProcess = PROCESS_CREATE_PROCESS,
        SetQuota = PROCESS_SET_QUOTA,
        SetInformation = PROCESS_SET_INFORMATION,
        QueryInformation = PROCESS_QUERY_INFORMATION,
        SuspendResume = PROCESS_SUSPEND_RESUME,
        QueryLimitedInformation = PROCESS_QUERY_LIMITED_INFORMATION,

        AllAccess = PROCESS_ALL_ACCESS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ProcessCreation : uint32_t
    {
        DebugProcess = 0x00000001,
        DebugOnlyThisProcess = 0x00000002,
        CreateSuspended = 0x00000004,
        DetachedProcess = 0x00000008,

        CreateNewConsole = 0x00000010,
        NormalPriorityClass = 0x00000020,
        IdlePriorityClass = 0x00000040,
        HighPriorityClass = 0x00000080,

        RealTimePriorityClass = 0x00000100,
        CreateNewProcessGroup = 0x00000200,
        CreateUnicodeEnvironment = 0x00000400,
        CreateSeparateWowVdm = 0x00000800,

        CreateSharedWowVdm = 0x00001000,
        CreateForceDos = 0x00002000,
        BelowNormalPriorityClass = 0x00004000,
        AboveNormalPriorityClass = 0x00008000,

        InheritParentAffinity = 0x00010000,
        InheritCallerPriority = 0x00020000,
        CreateProtectedProcess = 0x00040000,
        ExtendedStartupInfoPresent = 0x00080000,

        ProcessModeBackgroundBegin = 0x00100000,
        ProcessModeBackgroundEnd = 0x00200000,

        CreateBreakawayFromJob = 0x01000000,
        CreatePreserveCodeAuthzLevel = 0x02000000,
        CreateDefaultErrorMode = 0x04000000,
        CreateNoWindow = 0x08000000,

        ProfileUser = 0x10000000,
        ProfileKernel = 0x20000000,
        ProfileServer = 0x40000000,
        CreateIgnoreSystemDefault = 0x80000000,
    };

    enum class ProcessStandardAccess
    {
        Delete = (0x00010000L),
        ReadControl = (0x00020000L),
        WriteDac = (0x00040000L),
        WriteOwner = (0x00080000L),
        Synchronize = (0x00100000L),
    };

    enum class ProcessSpecificAccess
    {
        Terminate = (0x0001),
        CreateThread = (0x0002),
        SetSessionId = (0x0004),
        VmOperation = (0x0008),
        VmRead = (0x0010),
        VmWrite = (0x0020),
        DupHandle = (0x0040),
        CreateProcess = (0x0080),
        SetQuota = (0x0100),
        SetInformation = (0x0200),
        QueryInformation = (0x0400),
        SuspendResume = (0x0800),
        QueryLimitedInformation = (0x1000),

        AllAccess = (0x000F0000L | 0x00100000L | 0xFFFF),
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_THREADING_PROCESS_FLAGS_H
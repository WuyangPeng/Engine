///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 18:17)

#ifndef SYSTEM_THREADING_PROCESS_USING_H
#define SYSTEM_THREADING_PROCESS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ProcessStartupInfo = STARTUPINFO;
    using ProcessStartupInfoPtr = LPSTARTUPINFO;
    using ProcessInformation = PROCESS_INFORMATION;
    using ProcessInformationPtr = LPPROCESS_INFORMATION;
    using ProcessStartupInfoEx = STARTUPINFOEX;
    using ProcessStartupInfoExPtr = LPSTARTUPINFOEX;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ProcessStartupInfo
    {
        uint32_t cb;
        TChar* lpReserved;
        TChar* lpDesktop;
        TChar* lpTitle;
        uint32_t dwX;
        uint32_t dwY;
        uint32_t dwXSize;
        uint32_t dwYSize;
        uint32_t dwXCountChars;
        uint32_t dwYCountChars;
        uint32_t dwFillAttribute;
        uint32_t dwFlags;
        int wShowWindow;
        int cbReserved2;
        uint8_t* lpReserved2;
        void* hStdInput;
        void* hStdOutput;
        void* hStdError;
    };
    using ProcessStartupInfoPtr = ProcessStartupInfo*;

    struct ProcessInformation
    {
        void* hProcess;
        void* hThread;
        uint32_t dwProcessId;
        uint32_t dwThreadId;
    };
    using ProcessInformationPtr = ProcessInformation*;

    struct ProcessStartupInfoEx
    {
        ProcessStartupInfo StartupInfo;
        ProcThreadAttributeListPtr lpAttributeList;
    };
    using ProcessStartupInfoExPtr = ProcessStartupInfoEx*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_PROCESS_USING_H
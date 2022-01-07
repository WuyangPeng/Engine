///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 12:43)

#ifndef SYSTEM_WINDOWS_WINDOWS_NAMED_PIPE_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_NAMED_PIPE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsOpenMode
    {
        AccessInbound = PIPE_ACCESS_INBOUND,
        AccessOutbound = PIPE_ACCESS_OUTBOUND,
        AccessDuplex = PIPE_ACCESS_DUPLEX,
        FirstPipeInstance = FILE_FLAG_FIRST_PIPE_INSTANCE,
        WriteThrough = FILE_FLAG_WRITE_THROUGH,
        Overlapped = FILE_FLAG_OVERLAPPED,
        WriteDac = WRITE_DAC,
        WriteOwner = WRITE_OWNER,
        AccessSystemSecurity = ACCESS_SYSTEM_SECURITY,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsOpenMode
    {
        AccessInbound = 0x00000001,
        AccessOutbound = 0x00000002,
        AccessDuplex = 0x00000003,
        FirstPipeInstance = 0x00080000,
        WriteThrough = 0x80000000,
        Overlapped = 0x40000000,
        WriteDac = 0x00040000L,
        WriteOwner = 0x00080000L,
        AccessSystemSecurity = 0x01000000L,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_NAMED_PIPE_FLAGS_H

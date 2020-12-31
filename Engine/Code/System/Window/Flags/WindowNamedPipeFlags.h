//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 10:50)

#ifndef SYSTEM_WINDOW_WINDOW_NAMED_PIPE_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_NAMED_PIPE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowOpenMode
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

    enum class WindowOpenMode
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

#endif  // SYSTEM_WINDOW_WINDOW_NAMED_PIPE_FLAGS_H

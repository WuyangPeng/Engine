/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:27)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WinSockData = WSADATA;
    using WinSockDataPtr = LPWSADATA;
    using WinSockHandle = HANDLE;

    constexpr WindowsWord winSockDescriptionLen{ WSADESCRIPTION_LEN };
    constexpr WindowsWord winSockSystemStatusLen{ WSASYS_STATUS_LEN };

#else  // !SYSTEM_PLATFORM_WIN32

    constexpr WindowsWord winSockDescriptionLen{ 256 };
    constexpr WindowsWord winSockSystemStatusLen{ 128 };

    struct WinSockData
    {
        uint16_t wVersion;
        uint16_t wHighVersion;
        char szDescription[winSockDescriptionLen + 1];
        char szSystemStatus[winSockSystemStatusLen + 1];
        uint16_t iMaxSockets;
        uint16_t iMaxUdpDg;
        char* lpVendorInfo;
    };

    using WinSockDataPtr = WinSockData*;
    using WinSockHandle = void*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H
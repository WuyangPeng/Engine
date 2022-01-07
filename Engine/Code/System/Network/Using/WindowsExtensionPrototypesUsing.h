///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:33)

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

    constexpr WindowsWord g_WinSockDescriptionLen{ WSADESCRIPTION_LEN };
    constexpr WindowsWord g_WinSockSystemStatusLen{ WSASYS_STATUS_LEN };

#else  // !SYSTEM_PLATFORM_WIN32

    constexpr WindowsWord g_WinSockDescriptionLen{ 256 };
    constexpr WindowsWord g_WinSockSystemStatusLen{ 128 };

    struct WinSockData
    {
        uint16_t wVersion;
        uint16_t wHighVersion;
        char szDescription[g_WinSockDescriptionLen + 1];
        char szSystemStatus[g_WinSockSystemStatusLen + 1];
        uint16_t iMaxSockets;
        uint16_t iMaxUdpDg;
        char* lpVendorInfo;
    };

    using WinSockDataPtr = WinSockData*;
    using WinSockHandle = void*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H
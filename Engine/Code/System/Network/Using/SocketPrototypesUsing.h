/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 21:04)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_USING_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>
    #include <Ws2ipdef.h>

#else  // !SYSTEM_PLATFORM_WIN32

    #include "System/Windows/Using/WindowsUsing.h"

#endif  // SYSTEM_PLATFORM_WIN32

#include <string>

namespace System
{
    const std::string defaultRouteAddress{ "0.0.0.0" };

#ifdef SYSTEM_PLATFORM_WIN32

    using InternetAddress = in_addr;
    using WinSockInternetAddress = sockaddr_in;
    using Internet6Address = in6_addr;
    using WinSockInternetAddress6 = sockaddr_in6;
    using WinSockScopeId = SCOPE_ID;
    using WinSocket = SOCKET;
    using WinSockAddress = sockaddr;
    using WinSockFdSet = fd_set;
    using WinSockTimeVal = timeval;
    using SocketLinger = LINGER;

    constexpr WinSocket invalidSocket{ INVALID_SOCKET };
    constexpr auto socketError = SOCKET_ERROR;
    constexpr auto internetAddressAny = INADDR_ANY;
    constexpr auto fdSetSize = FD_SETSIZE;
    constexpr auto internetAddressLoopback = INADDR_LOOPBACK;
    constexpr auto soMaxConn = SOMAXCONN;

#else  // !SYSTEM_PLATFORM_WIN32

    struct InternetAddress
    {
        union
        {
            struct
            {
                uint8_t s_b1, s_b2, s_b3, s_b4;
            } S_un_b;
            struct
            {
                uint16_t s_w1, s_w2;
            } S_un_w;
            WindowsULong S_addr;
        } S_un;
    };

    struct WinSockInternetAddress
    {
        int16_t sin_family;
        uint16_t sin_port;
        InternetAddress sin_addr;
        char sin_zero[8];
    };

    struct Internet6Address
    {
        union
        {
            uint8_t Byte[16];
            uint16_t Word[8];
        } u;
    };

    struct WinSockScopeId
    {
        union
        {
            struct
            {
                WindowsULong Zone : 28;
                WindowsULong Level : 4;
            };
            WindowsULong Value;
        };
    };

    struct WinSockInternetAddress6
    {
        uint16_t sin6_family;
        uint16_t sin6_port;
        WindowsULong sin6_flowinfo;
        Internet6Address sin6_addr;
        union
        {
            WindowsULong sin6_scope_id;
            WinSockScopeId sin6_scope_struct;
        };
    };

    using WinSocket = int64_t;

    struct WinSockAddress
    {
        uint16_t sa_family;
        char sa_data[14];
    };

    constexpr auto fdSetSize = 64;

    using WinSockFdSet = fd_set;

    struct WinSockTimeVal
    {
        long tv_sec;
        long tv_usec;
    };

    struct SocketLinger
    {
        uint16_t l_onoff;
        uint16_t l_linger;
    };

    constexpr auto invalidSocket = static_cast<WinSocket>(~0);
    constexpr auto socketError = -1;
    constexpr auto internetAddressAny = 0x00000000;
    constexpr auto internetAddressLoopback = 0x7f000001;
    constexpr auto soMaxConn = 0x7fffffff;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_SOCKET_PROTOTYPES_USING_H
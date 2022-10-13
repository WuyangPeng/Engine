///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:33)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_USING_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <WinSock2.h>
    #include <Ws2ipdef.h>
#else  // !SYSTEM_PLATFORM_WIN32
    #include "System/Windows/Using/WindowsUsing.h"
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WinSockInAddr = in_addr;
    using WinSockAddrIn = sockaddr_in;
    using WinSockIn6Addr = in6_addr;
    using WinSockAddrIn6 = sockaddr_in6;
    using WinSockScopeID = SCOPE_ID;
    using WinSocket = SOCKET;
    using WinSockAddr = sockaddr;
    using WinSockFdSet = fd_set;
    using WinSockTimeval = timeval;
    using SocketLinger = LINGER;

    constexpr WinSocket g_InvalidSocket{ INVALID_SOCKET };
    constexpr auto g_SocketError = SOCKET_ERROR;
    constexpr auto gInAddrAny = INADDR_ANY;
    constexpr auto g_FdSetSize = FD_SETSIZE;
    constexpr auto g_InAddrLoopback = INADDR_LOOPBACK;
    constexpr auto g_SoMaxConn = SOMAXCONN;

#else  // !SYSTEM_PLATFORM_WIN32

    struct WinSockInAddr
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

    struct WinSockAddrIn
    {
        int16_t sin_family;
        uint16_t sin_port;
        WinSockInAddr sin_addr;
        char sin_zero[8];
    };

    struct WinSockIn6Addr
    {
        union
        {
            uint8_t Byte[16];
            uint16_t Word[8];
        } u;
    };

    struct WinSockScopeID
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

    struct WinSockAddrIn6
    {
        uint16_t sin6_family;
        uint16_t sin6_port;
        WindowsULong sin6_flowinfo;
        WinSockIn6Addr sin6_addr;
        union
        {
            WindowsULong sin6_scope_id;
            WinSockScopeID sin6_scope_struct;
        };
    };

    using WinSocket = int64_t;

    struct WinSockAddr
    {
        uint16_t sa_family;
        char sa_data[14];
    };

    constexpr auto g_FdSetSize = 64;

    struct WinSockFdSet
    {
        uint32_t fd_count;
        WinSocket fd_array[g_FdSetSize];
    };

    struct WinSockTimeval
    {
        long tv_sec;
        long tv_usec;
    };

    struct SocketLinger
    {
        uint16_t l_onoff;
        uint16_t l_linger;
    };

    constexpr auto g_InvalidSocket = static_cast<WinSocket>(~0);
    constexpr auto g_SocketError = -1;
    constexpr auto gInAddrAny = 0x00000000;
    constexpr auto g_InAddrLoopback = 0x7f000001;
    constexpr auto g_SoMaxConn = 0x7fffffff;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_SOCKET_PROTOTYPES_USING_H
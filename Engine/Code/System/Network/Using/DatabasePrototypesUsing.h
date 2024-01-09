/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:26)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_USING_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WinSockHostEnt = hostent;
    using WinSockServEnt = servent;
    using WinSockProtoEnt = protoent;

#else  // !SYSTEM_PLATFORM_WIN32

    struct WinSockHostEnt
    {
        char* h_name;
        char** h_aliases;
        short h_addrtype;
        short h_length;
        char** h_addr_list;
    };

    struct WinSockServEnt
    {
        char* s_name;
        char** s_aliases;
        short s_port;
        char* s_proto;
    };

    struct WinSockProtoEnt
    {
        char* p_name;
        char** p_aliases;
        short p_proto;
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_USING_H
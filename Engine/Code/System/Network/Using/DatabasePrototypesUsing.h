///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 15:10)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_USING_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WinSockHostent = hostent;
    using WinSockServent = servent;
    using WinSockProtoent = protoent;

#else  // !SYSTEM_PLATFORM_WIN32

    struct WinSockHostent
    {
        char* h_name;
        char** h_aliases;
        short h_addrtype;
        short h_length;
        char** h_addr_list;
    };

    struct WinSockServent
    {
        char* s_name;
        char** s_aliases;
        short s_port;
        char* s_proto;
    };

    struct WinSockProtoent
    {
        char* p_name;
        char** p_aliases;
        short p_proto;
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_USING_H
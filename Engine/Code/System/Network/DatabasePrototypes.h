///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.4 (2021/06/04 14:46)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/DatabasePrototypesUsing.h"
#include "Using/SocketPrototypesUsing.h"

namespace System
{
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostent* GetHostByAddr(const WinSockInAddr* addr, ProtocolFamilies type) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostent* GetHostByName(const char* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetHostName(char* name, int namelen) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServent* GetServentByPort(int port, const char* proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServent* GetServentByName(const char* name, const char* proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoent* GetProtoentByNumber(int proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoent* GetProtoentByName(const char* name) noexcept;
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

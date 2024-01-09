/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:27)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/DatabasePrototypesUsing.h"
#include "Using/SocketPrototypesUsing.h"

namespace System
{
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostEnt* GetHostByAddress(const InternetAddress* address, ProtocolFamilies type) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostEnt* GetHostByName(const char* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetHostName(char* name, int nameLength) noexcept;

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServEnt* GetServerByPort(int port, const char* proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServEnt* GetServerByName(const char* name, const char* proto) noexcept;

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoEnt* GetProtoByNumber(int proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoEnt* GetProtoByName(const char* name) noexcept;
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

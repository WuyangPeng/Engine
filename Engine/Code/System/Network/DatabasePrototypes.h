/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 21:05)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/DatabasePrototypesUsing.h"
#include "Using/SocketPrototypesUsing.h"

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetHostName(char* name, int nameLength) noexcept;

    ///  这些函数都不是线程安全的，因为它们使用了静态数据结构。

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostEnt* GetHostByAddress(const InternetAddress* address, ProtocolFamilies type) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostEnt* GetHostByName(const char* name) noexcept;

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServerEnt* GetServerByPort(int port, const char* proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServerEnt* GetServerByName(const char* name, const char* proto) noexcept;

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoEnt* GetProtoByNumber(int proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoEnt* GetProtoByName(const char* name) noexcept;
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

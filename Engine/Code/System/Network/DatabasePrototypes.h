///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/07 13:46)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/DatabasePrototypesUsing.h"
#include "Using/SocketPrototypesUsing.h"

namespace System
{
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostent* GetHostByAddress(const InternetAddress* address, ProtocolFamilies type) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockHostent* GetHostByName(const char* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetHostName(char* name, int nameLength) noexcept;

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServent* GetServentByPort(int port, const char* proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockServent* GetServentByName(const char* name, const char* proto) noexcept;

    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoent* GetProtoentByNumber(int proto) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE WinSockProtoent* GetProtoentByName(const char* name) noexcept;
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

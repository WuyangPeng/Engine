//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:02)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_H
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/DatabasePrototypesUsing.h"
#include "Using/SocketPrototypesUsing.h"

namespace System
{
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE WinSockHostent* GetHostByAddr(const WinSockInAddr* addr, ProtocolFamilies type) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE WinSockHostent* GetHostByName(const char* name) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetHostName(char* name, int namelen) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE WinSockServent* GetServentByPort(int port, const char* proto) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE WinSockServent* GetServentByName(const char* name, const char* proto) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE WinSockProtoent* GetProtoentByNumber(int proto) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE WinSockProtoent* GetProtoentByName(const char* name) noexcept;
}

#endif  // SYSTEM_NETWORK_DATABASE_PROTOTYPES_H

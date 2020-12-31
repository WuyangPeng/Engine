//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 15:30)

#ifndef NETWORK_NETWORK_INTERFACE_SOCKET_DATA_H
#define NETWORK_NETWORK_INTERFACE_SOCKET_DATA_H

#include "Network/NetworkDll.h"

#include "InterfaceFwd.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SocketData final
    {
    public:
        using ClassType = SocketData;

    public:
        SocketData(SocketType socketType, int serverID) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] SocketType GetSocketType() const noexcept;
        [[nodiscard]] int GetServerID() const noexcept;

    private:
        SocketType m_SocketType;
        int m_ServerID;
    };

     [[nodiscard]] bool NETWORK_DEFAULT_DECLARE operator<(const SocketData& lhs, const SocketData& rhs) noexcept;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCKET_DATA_H

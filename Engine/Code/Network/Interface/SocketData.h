///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 09:09)

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
        SocketData(SocketType socketType, int serverId) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD SocketType GetSocketType() const noexcept;
        NODISCARD int GetServerId() const noexcept;

    private:
        SocketType socketType;
        int serverId;
    };

    NODISCARD bool NETWORK_DEFAULT_DECLARE operator<(const SocketData& lhs, const SocketData& rhs) noexcept;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCKET_DATA_H

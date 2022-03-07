///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 15:34)

#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SendSocket.h"
#include "Network/Interface/SocketData.h"
#include "Network/NetworkMessage/MessageInterface.h"

#include <map>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SendSocketManagerImpl final
    {
    public:
        using ClassType = SendSocketManagerImpl;

    public:
        explicit SendSocketManagerImpl(const std::string& fileName);
        ~SendSocketManagerImpl() noexcept = default;
        SendSocketManagerImpl(const SendSocketManagerImpl& rhs) noexcept = delete;
        SendSocketManagerImpl& operator=(const SendSocketManagerImpl& rhs) noexcept = delete;
        SendSocketManagerImpl(SendSocketManagerImpl&& rhs) noexcept = delete;
        SendSocketManagerImpl& operator=(SendSocketManagerImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // 发送网络消息
        void Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message);

        NODISCARD SendSocketSharedPtr GetSendSocket(const SocketData& socketData);
        NODISCARD SocketManagerSharedPtr GetSocketManager() noexcept;

    private:
        using SendSocketType = std::map<SocketData, SendSocketSharedPtr>;

    private:
        SendSocketType sendSocket;
        SocketManagerSharedPtr socketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H

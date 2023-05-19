///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:01)

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
        void Send(const SocketData& socketData, int64_t socketId, const MessageInterfaceSharedPtr& message);

        NODISCARD SendSocketSharedPtr GetSendSocket(const SocketData& socketData);
        NODISCARD MessageEventManagerSharedPtr GetMessageEventManager() noexcept;

    private:
        using SendSocketType = std::map<SocketData, SendSocketSharedPtr>;

    private:
        SendSocketType sendSocket;
        MessageEventManagerSharedPtr messageEventManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_IMPL_H

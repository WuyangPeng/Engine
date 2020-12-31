//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:21)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "SendSocket.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <string>

NETWORK_EXPORT_SHARED_PTR(ClientImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Client : public SendSocket
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Client);
        using ParentType = SendSocket;

    public:
        Client(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);

        ~Client() noexcept = default;
        Client(const Client&) = delete;
        Client& operator=(const Client&) = delete;
        Client(Client&&) noexcept = delete;
        Client& operator=(Client&&) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] uint64_t Connect();
        void AsyncConnect();

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

        void Receive();
        void AsyncReceive();
        void ImmediatelySend(uint64_t socketID);
        void ImmediatelyAsyncSend(uint64_t socketID);

        [[nodiscard]] uint64_t GetSocketID() const;

    private:
        IMPL_TYPE_DECLARE(Client);
    };

    using ClientSharedPtr = std::shared_ptr<Client>;
    using ConstClientSharedPtr = std::shared_ptr<const Client>;
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_H

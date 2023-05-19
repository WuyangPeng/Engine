///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:36)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "SendSocket.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <string>

NETWORK_NON_COPY_EXPORT_IMPL(ClientImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Client : public SendSocket
    {
    public:
        NON_COPY_TYPE_DECLARE(Client);
        using ParentType = SendSocket;

    public:
        Client(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int64_t Connect();
        void AsyncConnect();

        void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) override;

        void Receive();
        void AsyncReceive();
        void ImmediatelySend(int64_t socketId);
        void ImmediatelyAsyncSend(int64_t socketId);

        NODISCARD int64_t GetSocketId() const noexcept;

    private:
        PackageType impl;
    };

    using ClientSharedPtr = std::shared_ptr<Client>;
    using ConstClientSharedPtr = std::shared_ptr<const Client>;
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_H

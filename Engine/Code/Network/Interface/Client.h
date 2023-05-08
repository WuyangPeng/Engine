///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 16:42)

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
        Client(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD uint64_t Connect();
        void AsyncConnect();

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

        void Receive();
        void AsyncReceive();
        void ImmediatelySend(uint64_t socketID);
        void ImmediatelyAsyncSend(uint64_t socketID);

        NODISCARD uint64_t GetSocketID() const noexcept;

    private:
        PackageType impl;
    };

    using ClientSharedPtr = std::shared_ptr<Client>;
    using ConstClientSharedPtr = std::shared_ptr<const Client>;
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_H

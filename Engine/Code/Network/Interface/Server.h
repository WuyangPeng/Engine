//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:25)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_SERVER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "SendSocket.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/SocketManager.h"

NETWORK_EXPORT_SHARED_PTR(ServerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Server : public SendSocket
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Server);
        using ParentType = SendSocket;

    public:
        Server(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] bool RunServer();

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

    private:
        IMPL_TYPE_DECLARE(Server);
    };

    using ServerSharedPtr = std::shared_ptr<Server>;
    using ConstServerSharedPtr = std::shared_ptr<const Server>;

    using ServerWeakPtr = std::weak_ptr<Server>;
    using ConstServerWeakPtr = std::weak_ptr<const Server>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_H

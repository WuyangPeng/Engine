///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 16:45)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_SERVER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "SendSocket.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/MessageEventManager.h"

NETWORK_NON_COPY_EXPORT_IMPL(ServerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Server : public SendSocket
    {
    public:
        NON_COPY_TYPE_DECLARE(Server);
        using ParentType = SendSocket;

    public:
        Server(const MessageEventManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool RunServer();

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

    private:
        PackageType impl;
    };

    using ServerSharedPtr = std::shared_ptr<Server>;
    using ConstServerSharedPtr = std::shared_ptr<const Server>;

    using ServerWeakPtr = std::weak_ptr<Server>;
    using ConstServerWeakPtr = std::weak_ptr<const Server>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_H

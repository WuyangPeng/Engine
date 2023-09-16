///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:34)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

NETWORK_NON_COPY_EXPORT_IMPL(RouteServiceImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE RouteService
    {
    public:
        NON_COPY_TYPE_DECLARE(RouteService);

        using String = System::String;

    public:
        explicit RouteService(const ConfigurationStrategy& configurationStrategy);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetAddress() const;
        NODISCARD String GetFirstConsumer(SocketType serverType) const;

        void AddConsumer(SocketType serverType, int serverId, const String& address);
        void RemoveConsumer(SocketType serverType, int serverId);

        void BroadcastMessage(SocketType serverType, const MessageInterfaceSharedPtr& message);
        void BroadcastMessage(const MessageInterfaceSharedPtr& message);
        void SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message);

        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_H

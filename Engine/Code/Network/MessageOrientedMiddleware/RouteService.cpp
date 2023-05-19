///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 17:01)

#include "Network/NetworkExport.h"

#include "RouteService.h"
#include "Detail/RouteServiceImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::RouteService::RouteService(const ConfigurationStrategy& configurationStrategy)
    : impl{ configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, RouteService)

System::String Network::RouteService::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetAddress();
}

System::String Network::RouteService::GetFirstConsumer(SocketType serverType) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFirstConsumer(serverType);
}

void Network::RouteService::AddConsumer(SocketType serverType, int serverId, const String& address)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->AddConsumer(serverType, serverId, address);
}

void Network::RouteService::RemoveConsumer(SocketType serverType, int serverId)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->RemoveConsumer(serverType, serverId);
}

void Network::RouteService::BroadcastMessage(SocketType serverType, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->BroadcastMessage(serverType, message);
}

void Network::RouteService::BroadcastMessage(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->BroadcastMessage(message);
}

void Network::RouteService::SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->SendServerMessage(address, message);
}

void Network::RouteService::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Insert(messageId, messageEvent);
}

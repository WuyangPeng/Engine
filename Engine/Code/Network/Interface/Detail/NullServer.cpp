///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 14:51)

#include "Network/NetworkExport.h"

#include "NullServer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

Network::NullServer::NullServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ socketManager, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullServer)

void Network::NullServer::Send(MAYBE_UNUSED uint64_t socketID, MAYBE_UNUSED const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullServer::WaitForMultipleEvents() noexcept
{
    return true;
}

bool Network::NullServer::HandleConnections(MAYBE_UNUSED SocketManager& socketManager) noexcept
{
    return true;
}

bool Network::NullServer::HandleData(MAYBE_UNUSED const SocketManagerSharedPtr& socketManager) noexcept
{
    return true;
}

bool Network::NullServer::ImmediatelySend() noexcept
{
    return true;
}

bool Network::NullServer::ImmediatelySend(MAYBE_UNUSED uint64_t socketID) noexcept
{
    return true;
}

void Network::NullServer::AsyncSend(MAYBE_UNUSED uint64_t socketID, MAYBE_UNUSED const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullServer::ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullServer::EventFunction(MAYBE_UNUSED const CoreTools::CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}

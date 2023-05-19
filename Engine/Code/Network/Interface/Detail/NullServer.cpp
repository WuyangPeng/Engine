///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:16)

#include "Network/NetworkExport.h"

#include "NullServer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

Network::NullServer::NullServer(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept
    : ParentType{ configurationStrategy, messageEventManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullServer)

void Network::NullServer::Send(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId, message);
}

bool Network::NullServer::WaitForMultipleEvents() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}

bool Network::NullServer::HandleConnections() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}

bool Network::NullServer::HandleData(const MessageEventManagerSharedPtr& aMessageEventManager) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(aMessageEventManager);

    return true;
}

bool Network::NullServer::ImmediatelySend() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}

bool Network::NullServer::ImmediatelySend(int64_t socketId) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId);

    return true;
}

void Network::NullServer::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId, message);
}

void Network::NullServer::ImmediatelyAsyncSend(int64_t socketId) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId);
}

bool Network::NullServer::EventFunction(const CoreTools::CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(callbackParameters);

    return true;
}

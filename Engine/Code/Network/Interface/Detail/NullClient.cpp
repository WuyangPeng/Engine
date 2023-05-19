///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:14)

#include "Network/NetworkExport.h"

#include "NullClient.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"

Network::NullClient::NullClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept
    : ParentType{ configurationStrategy, messageEventManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullClient)

int64_t Network::NullClient::Connect() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return 0;
}

void Network::NullClient::AsyncConnect() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::AsyncReceive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::Send(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId, message);
}

void Network::NullClient::ImmediatelySend(int64_t socketId) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId);
}

void Network::NullClient::Receive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId, message);
}

void Network::NullClient::ImmediatelyAsyncSend(int64_t socketId) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId);
}

int64_t Network::NullClient::GetSocketId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool Network::NullClient::EventFunction(const CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(callbackParameters);

    return true;
}

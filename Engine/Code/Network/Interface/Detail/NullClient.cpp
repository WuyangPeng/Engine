///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 17:20)

#include "Network/NetworkExport.h"

#include "NullClient.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"

Network::NullClient::NullClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager) noexcept
    : ParentType{ configurationStrategy, socketManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullClient)

uint64_t Network::NullClient::Connect() noexcept
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

void Network::NullClient::Send(MAYBE_UNUSED uint64_t socketID, MAYBE_UNUSED const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::ImmediatelySend(MAYBE_UNUSED uint64_t socketID) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::Receive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::AsyncSend(MAYBE_UNUSED uint64_t socketID, MAYBE_UNUSED const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullClient::ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

uint64_t Network::NullClient::GetSocketID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool Network::NullClient::EventFunction(MAYBE_UNUSED const CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return true;
}

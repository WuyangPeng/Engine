// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.4 (2020/03/11 11:02)

#include "Network/NetworkExport.h"

#include "ClientImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"

#include "CoreTools/ClassInvariant/Noexcept.h"
#include <vector>

using std::string;
using std::vector;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

Network::ClientImpl ::ClientImpl(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager) noexcept
    : ParentType{}, m_ConfigurationStrategy{ configurationStrategy }, m_SocketManager{ socketManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ClientImpl)

uint64_t Network::ClientImpl ::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DoNothing();

    return 0;
}

void Network::ClientImpl ::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DoNothing();
}

void Network::ClientImpl ::AsyncReceive()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DoNothing();
}

void Network::ClientImpl ::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(socketID);
    SYSTEM_UNUSED_ARG(message);

    CoreTools::DoNothing();
}

void Network::ClientImpl ::ImmediatelySend(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(socketID);

    CoreTools::DoNothing();
}

void Network::ClientImpl ::Receive()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DoNothing();
}

Network::ConfigurationStrategy Network::ClientImpl ::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}

void Network::ClientImpl ::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(socketID);
    SYSTEM_UNUSED_ARG(message);

    CoreTools::DoNothing();
}

void Network::ClientImpl ::ImmediatelyAsyncSend(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(socketID);

    CoreTools::DoNothing();
}

uint64_t Network::ClientImpl ::GetSocketID() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DoNothing();

    return 0;
}

bool Network::ClientImpl ::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(callbackParameters);

    CoreTools::DoNothing();

    return false;
}

Network::SocketManagerSharedPtr Network::ClientImpl ::GetSocketManagerSharedPtr()
{
    NETWORK_CLASS_IS_VALID_9;

    auto result = m_SocketManager.lock();

    if (result)
    {
        return result;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Socket 管理器已失效。"s));
    }
}
#include STSTEM_WARNING_POP
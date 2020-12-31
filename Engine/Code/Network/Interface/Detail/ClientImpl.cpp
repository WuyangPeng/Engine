//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:17)

#include "Network/NetworkExport.h"

#include "ClientImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"

#include <vector>

using std::string;
using std::vector;

Network::ClientImpl::ClientImpl(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager) noexcept
    : ParentType{}, m_ConfigurationStrategy{ configurationStrategy }, m_SocketManager{ socketManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ClientImpl)

uint64_t Network::ClientImpl::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return 0;
}

void Network::ClientImpl::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Network::ClientImpl::AsyncReceive()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Network::ClientImpl::Send([[maybe_unused]] uint64_t socketID, [[maybe_unused]] const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    auto process = message;

    CoreTools::DisableNoexcept();
}

void Network::ClientImpl::ImmediatelySend([[maybe_unused]] uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Network::ClientImpl::Receive()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

Network::ConfigurationStrategy Network::ClientImpl::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}

void Network::ClientImpl::AsyncSend([[maybe_unused]] uint64_t socketID, [[maybe_unused]] const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    auto process = message;

    CoreTools::DisableNoexcept();
}

void Network::ClientImpl::ImmediatelyAsyncSend([[maybe_unused]] uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

uint64_t Network::ClientImpl::GetSocketID() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return 0;
}

bool Network::ClientImpl::EventFunction([[maybe_unused]] const CoreTools::CallbackParameters& callbackParameters)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return false;
}

Network::SocketManagerSharedPtr Network::ClientImpl::GetSocketManagerSharedPtr()
{
    NETWORK_CLASS_IS_VALID_9;

    auto result = m_SocketManager.lock();

    if (result != nullptr)
    {
        return result;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Socket 管理器已失效。"s));
    }
}

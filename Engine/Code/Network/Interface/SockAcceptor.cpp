/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "SockAcceptor.h"
#include "Detail/SockAcceptorFactory.h"
#include "Detail/SockAcceptorImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SockAcceptor::SockAcceptor(int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, port, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAcceptor::SockAcceptor(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hostName, port, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAcceptor::SockAcceptor(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAcceptor)

bool Network::SockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Accept(sockStream, sockAddress);
}

bool Network::SockAcceptor::Accept(SockStream& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Accept(sockStream);
}

bool Network::SockAcceptor::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->EnableNonBlock();
}

Network::ACEHandleType Network::SockAcceptor::GetACEHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetACEHandle();
}

Network::BoostHandleType Network::SockAcceptor::GetBoostHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetBoostHandle();
}

Network::WinSocketType Network::SockAcceptor::GetWinSocket()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetWinSocket();
}

std::string Network::SockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetAddress();
}

int Network::SockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetPort();
}

void Network::SockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->AsyncAccept(eventInterface, sockStream);
}

void Network::SockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->AsyncAccept(eventInterface, sockStream, sockAddress);
}

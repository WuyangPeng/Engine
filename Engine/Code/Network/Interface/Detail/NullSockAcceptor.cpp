///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 15:24)

#include "Network/NetworkExport.h"

#include "NullSockAcceptor.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::NullSockAcceptor::NullSockAcceptor() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAcceptor)

bool Network::NullSockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(sockStream, sockAddress);

    return false;
}

void Network::NullSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream);
}

bool Network::NullSockAcceptor::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

void Network::NullSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream, sockAddress);
}

bool Network::NullSockAcceptor::Accept(SockStream& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(sockStream);

    return false;
}

std::string Network::NullSockAcceptor::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::string{};
}

int Network::NullSockAcceptor::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

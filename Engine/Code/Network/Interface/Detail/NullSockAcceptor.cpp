//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:38)

#include "Network/NetworkExport.h"

#include "NullSockAcceptor.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;
using std::to_string;

Network::NullSockAcceptor::NullSockAcceptor() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAcceptor)

bool Network::NullSockAcceptor::Accept([[maybe_unused]] const SockStreamSharedPtr& sockStream, [[maybe_unused]] const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

void Network::NullSockAcceptor::AsyncAccept([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, [[maybe_unused]] const SockStreamSharedPtr& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullSockAcceptor::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

void Network::NullSockAcceptor::AsyncAccept([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, [[maybe_unused]] const SockStreamSharedPtr& sockStream, [[maybe_unused]] const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullSockAcceptor::Accept([[maybe_unused]] const SockStreamSharedPtr& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

const std::string Network::NullSockAcceptor::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return string{};
}

int Network::NullSockAcceptor::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

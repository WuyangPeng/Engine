//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:12)

#include "Network/NetworkExport.h"

#include "SockAcceptor.h"
#include "Detail/SockAcceptorFactory.h"
#include "Detail/SockAcceptorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Network::SockAcceptor::SockAcceptor(int port, const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockAcceptorFactory::Create(port, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAcceptor::SockAcceptor(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockAcceptorFactory::Create(hostName, port, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAcceptor::SockAcceptor(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockAcceptorFactory::Create(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, SockAcceptor)

bool Network::SockAcceptor::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Accept(sockStream, sockAddress);
}

void Network::SockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AsyncAccept(eventInterface, sockStream);
}

void Network::SockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AsyncAccept(eventInterface, sockStream, sockAddress);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, SockAcceptor, Accept, SockStreamSharedPtr, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetACEHandle, Network::SockAcceptor::ACEHandleType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetBoostHandle, Network::SockAcceptor::BoostHandleType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetWinSocket, Network::SockAcceptor::WinSocketType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, EnableNonBlock, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetAddress, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetPort, int)

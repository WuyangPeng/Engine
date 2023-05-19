///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:11)

#include "Network/NetworkExport.h"

#include "SockAcceptor.h"
#include "Detail/SockAcceptorFactory.h"
#include "Detail/SockAcceptorImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAcceptor)

bool Network::SockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Accept(sockStream, sockAddress);
}

void Network::SockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncAccept(eventInterface, sockStream);
}

void Network::SockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncAccept(eventInterface, sockStream, sockAddress);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SockAcceptor, Accept, SockStream&, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetACEHandle, Network::ACEHandleType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetBoostHandle, Network::BoostHandleType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetWinSocket, Network::WinSocketType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, EnableNonBlock, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetAddress, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAcceptor, GetPort, int)

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.1.0 (2019/10/17 09:48)


#include "Network/NetworkExport.h" 

#include "SockAcceptor.h"
#include "Detail/SockAcceptorImpl.h"
#include "Detail/SockAcceptorFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;
 
Network::SockAcceptor
	::SockAcceptor(int port, const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockAcceptorFactory::Create(port,configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAcceptor
	::SockAcceptor(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockAcceptorFactory::Create(hostName,port, configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAcceptor
	::SockAcceptor(const ConfigurationStrategy& configurationStrategy)
	: m_Impl{ SockAcceptorFactory::Create(configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, SockAcceptor) 

bool Network::SockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	return m_Impl->Accept(sockStream, sockAddress);
}

void Network::SockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AsyncAccept(eventInterface, sockStream);
}

void Network::SockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream,  const SockAddressSharedPtr& sockAddress)
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
 
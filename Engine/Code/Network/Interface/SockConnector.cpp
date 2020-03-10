// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.1.0 (2019/10/21 17:04)


#include "Network/NetworkExport.h" 

#include "SockConnector.h"
#include "Detail/SockConnectorFactory.h"
#include "Detail/SockConnectorImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(Network, SockConnector)
DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Network,SockConnector)
 
Network::SockConnector
	::SockConnector(const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockConnectorFactory::Create(configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, SockConnector)

bool Network::SockConnector
	::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT; 
	
	return m_Impl->Connect(sockStream, sockAddress);
}

void Network::SockConnector
	::AsyncConnect(const EventInterfaceSharedPtr& eventInterface,const SockStreamSharedPtr& sockStream,const SockAddressSharedPtr& sockAddress)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AsyncConnect(eventInterface,sockStream, sockAddress);
}




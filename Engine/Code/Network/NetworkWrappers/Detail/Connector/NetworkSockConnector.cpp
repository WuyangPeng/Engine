// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/02 10:24)

#include "Network/NetworkExport.h" 

#include "NetworkSockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h" 
#include "CoreTools/MessageEvent/EventInterface.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Helper/UnusedMacro.h"

using std::make_shared;

Network::NetworkSockConnector
	::NetworkSockConnector() 
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockConnector
	::~NetworkSockConnector()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockConnector)

bool Network::NetworkSockConnector
	::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	if (System::Connect(sockStream->GetNetworkSockStream(), &sockAddress->GetWinSockInetAddress()))
		return true;
	else
		return false;
}

void Network::NetworkSockConnector
	::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream,const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	System::Connect(sockStream->GetNetworkSockStream(), &sockAddress->GetWinSockInetAddress());

	SYSTEM_UNUSED_ARG(eventInterface);
}

const Network::NetworkSockConnector::SockConnectorPtr Network::NetworkSockConnector
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}
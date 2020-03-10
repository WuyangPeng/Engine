// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.1.0 (2019/11/29 10:30)


#include "Network/NetworkExport.h" 

#include "Client.h"
#include "Detail/ClientImpl.h"
#include "Detail/ClientFactory.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::string;

Network::Client
	::Client(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
	:ParentType{}, m_Impl{ ClientFactory::Create(configurationStrategy,socketManager) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::Client
	::~Client()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, Client)

void Network::Client
	::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Send(socketID, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, Receive, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, Client, ImmediatelySend, uint64_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, AsyncReceive, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, Connect, uint64_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, AsyncConnect, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Client, GetSocketID, uint64_t)

void Network::Client
	::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AsyncSend(socketID, message);
}

void Network::Client
	::ImmediatelyAsyncSend(uint64_t socketID)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ImmediatelyAsyncSend(socketID);
}


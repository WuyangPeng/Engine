// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 10:55)

#include "Network/NetworkExport.h" 

#include "Client.h"
#include "Detail/ClientImpl.h"
#include "Detail/ClientFactory.h"

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

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Network, Client)

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


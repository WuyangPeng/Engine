// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 10:55)

#include "Network/NetworkExport.h" 

#include "Server.h"
#include "Detail/ServerImpl.h"
#include "Detail/ServerFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::Server
	::Server(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
	:ParentType{}, m_Impl{ ServerFactory::Create(socketManager, configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::Server
	::~Server()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, Server)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, Server, RunServer, bool)

void Network::Server
	::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Send(socketID, message);
}

void Network::Server
	::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AsyncSend(socketID, message);
}


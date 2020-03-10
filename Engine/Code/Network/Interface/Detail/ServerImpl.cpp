// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/01 17:25)

#include "Network/NetworkExport.h" 

#include "ServerImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ServerImpl
	::ServerImpl(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
	:ParentType{},m_ConfigurationStrategy{ configurationStrategy }, m_SocketManagerWeakPtr{ socketManager }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServerImpl
	::~ServerImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network,ServerImpl)

Network::ConfigurationStrategy Network::ServerImpl
	::GetConfigurationStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

bool Network::ServerImpl
	::RunServer()
{
	NETWORK_CLASS_IS_VALID_9;

	return WaitForMultipleEvents() && HandleConnections(m_SocketManagerWeakPtr.lock()) &&
		   HandleData(m_SocketManagerWeakPtr.lock()) && ImmediatelySend();
}
 
void Network::ServerImpl
	::Send( uint64_t socketID,const MessageInterfaceSharedPtr& message )
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(socketID);
	SYSTEM_UNUSED_ARG(message); 
}

bool Network::ServerImpl
	::WaitForMultipleEvents()
{
	return true;
}

bool Network::ServerImpl
	::HandleConnections(const SocketManagerSharedPtr& socketManager)
{
	SYSTEM_UNUSED_ARG(socketManager);

	return true;
}

bool Network::ServerImpl
	::HandleData(const SocketManagerSharedPtr& socketManager)
{
	SYSTEM_UNUSED_ARG(socketManager);

	return true;
}

bool Network::ServerImpl
	::ImmediatelySend()
{
	return true;
}

bool Network::ServerImpl
	::ImmediatelySend(uint64_t socketID)
{
	SYSTEM_UNUSED_ARG(socketID);

	return true;
}

void Network::ServerImpl
	::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(socketID);
	SYSTEM_UNUSED_ARG(message);
}

void Network::ServerImpl
	::ImmediatelyAsyncSend(uint64_t socketID)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(socketID);
}

Network::SocketManagerSharedPtr Network::ServerImpl
	::GetSocketManagerSharedPtr()
{
	NETWORK_CLASS_IS_VALID_9;

	auto result = m_SocketManagerWeakPtr.lock();

	if (result)
	{
		return result;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Socket 管理器已失效。"));
	}
}

bool Network::ServerImpl
	::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(callbackParameters);

	return true;
}

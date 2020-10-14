// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 11:26)

#include "Network/NetworkExport.h" 

#include "ServerImpl.h"

#include "Network/Interface/BaseMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26418)

Network::ServerImpl
	::ServerImpl(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy) noexcept
	:ParentType{}, m_ConfigurationStrategy{ configurationStrategy }, m_SocketManagerWeakPtr{ socketManager }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServerImpl
	::~ServerImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServerImpl)

Network::ConfigurationStrategy Network::ServerImpl ::GetConfigurationStrategy() const noexcept
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

void Network::ServerImpl ::Send([[maybe_unused]] uint64_t socketID, [[maybe_unused]] const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();
}

bool Network::ServerImpl
	::WaitForMultipleEvents()
{
    CoreTools::DisableNoexcept();

	return true;
}

bool Network::ServerImpl ::HandleConnections([[maybe_unused]] const SocketManagerSharedPtr& socketManager)
{
 

	CoreTools::DisableNoexcept();

	return true;
}

bool Network::ServerImpl ::HandleData([[maybe_unused]] const SocketManagerSharedPtr& socketManager)
{
	 

	CoreTools::DisableNoexcept();

	return true;
}

bool Network::ServerImpl
	::ImmediatelySend()
{
    CoreTools::DisableNoexcept();

	return true;
}

bool Network::ServerImpl ::ImmediatelySend([[maybe_unused]] uint64_t socketID)
{
    CoreTools::DisableNoexcept();

 
	return true;
}

void Network::ServerImpl ::AsyncSend([[maybe_unused]] uint64_t socketID, [[maybe_unused]] const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	 
}

void Network::ServerImpl ::ImmediatelyAsyncSend([[maybe_unused]] uint64_t socketID)
{
	NETWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

 
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
		THROW_EXCEPTION(SYSTEM_TEXT("Socket 管理器已失效。"s));
	}
}

bool Network::ServerImpl ::EventFunction([[maybe_unused]] const CoreTools::CallbackParameters& callbackParameters)
{
	NETWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

 

	return true;
}
#include STSTEM_WARNING_POP
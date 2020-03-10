// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/01 17:12)

#include "Network/NetworkExport.h" 

#include "CacheClient.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/SocketManager.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"

#include <boost/numeric/conversion/cast.hpp>
#include <vector>


using std::string;
using std::vector;
using std::make_shared;

Network::CacheClient
	::CacheClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
	:ParentType{ configurationStrategy,socketManager },
	 m_SockConnector{ configurationStrategy },
	 m_SockStream{ make_shared<SockStream>(configurationStrategy) },
	 m_SockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(),boost::numeric_cast<int>(configurationStrategy.GetPort()), configurationStrategy) },
	 m_BufferSendStream{ configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy() },
	 m_SocketID{ 0 },
	m_Buffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy())),
	m_Buffer2(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
	NETWORK_CLASS_IS_VALID_9;
}

Network::CacheClient
	::~CacheClient()
{
	NETWORK_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClient)

uint64_t Network::CacheClient
	::Connect()
{
	NETWORK_CLASS_IS_VALID_9;

	auto configurationStrategy = GetConfigurationStrategy();
	auto socketManager = GetSocketManagerSharedPtr();

	SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(),boost::numeric_cast<int>(configurationStrategy.GetPort()),GetConfigurationStrategy()) };
	if (socketManager && m_SockConnector.Connect(m_SockStream, sockAddress))
	{
		m_SocketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
		socketManager->Insert(m_SocketID);

		return m_SocketID;
	}

	return 0;
}

void Network::CacheClient
	::AsyncConnect()
{
	NETWORK_CLASS_IS_VALID_9;
 
	m_SockConnector.AsyncConnect(shared_from_this(), m_SockStream, m_SockAddress);
}

void Network::CacheClient
	::Send(uint64_t socketID,const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_SocketID == socketID)
	{
		if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
		{
			ImmediatelySend(socketID);
		}
		else
		{
			if (!m_BufferSendStream.Insert(message))			 
			{
				ImmediatelySend(socketID);

				if (!m_BufferSendStream.Insert(message))
				{
					LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
						<< SYSTEM_TEXT("消息包长度过长，包被丢弃。")
						<< LOG_SINGLETON_TRIGGER_ASSERT;
				}
			}
		}		
	}		
}

void Network::CacheClient
	::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
	{
		ImmediatelyAsyncSend(socketID);
	}
	else
	{
		if (!m_BufferSendStream.Insert(message))
		{
			ImmediatelyAsyncSend(socketID);

			if (!m_BufferSendStream.Insert(message))
			{
				LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
					<< SYSTEM_TEXT("消息包长度过长，包被丢弃。")
					<< LOG_SINGLETON_TRIGGER_ASSERT;
			}
		}
	}
}

void Network::CacheClient
	::ImmediatelySend(uint64_t socketID)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_SocketID == socketID && !m_BufferSendStream.IsEmpty())
	{
		m_Buffer->ClearCurrentIndex();
		m_BufferSendStream.Save(m_Buffer);

		m_SockStream->Send(m_Buffer);

		m_BufferSendStream.Clear();
	}
}

void Network::CacheClient
	::ImmediatelyAsyncSend(uint64_t socketID)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_SocketID == socketID && !m_BufferSendStream.IsEmpty())
	{
		m_Buffer->ClearCurrentIndex();
		m_BufferSendStream.Save(m_Buffer);

		m_SockStream->AsyncSend(GetSocketManagerSharedPtr(), m_Buffer);

		m_BufferSendStream.Clear();
	}
}

void Network::CacheClient
	::Receive()
{
	NETWORK_CLASS_IS_VALID_9; 

	try
	{
		if (m_SockStream->Receive(m_Buffer2))
		{
			BufferReceiveStream bufferReceiveStream{ m_Buffer2,GetConfigurationStrategy().GetParserStrategy() };
			bufferReceiveStream.OnEvent(m_SocketID, GetSocketManagerSharedPtr());
			m_Buffer2->ClearCurrentIndex();
		}		
	}
	catch (CoreTools::Error& )
	{
		 
	}		
}

void Network::CacheClient
	::AsyncReceive()
{
	NETWORK_CLASS_IS_VALID_9;

	m_Buffer2->ClearCurrentIndex();
	m_SockStream->AsyncReceive(shared_from_this(), m_Buffer2);
}

uint64_t Network::CacheClient
	::GetSocketID() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_SocketID;
}

bool Network::CacheClient
	::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
	auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Event)));

	switch (eventType)
	{
	case SocketManagerEvent::AsyncConnect:
	{
		auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Error));
		if (result == 0)
		{
			m_SocketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
			GetSocketManagerSharedPtr()->Insert(m_SocketID);		 
			GetSocketManagerSharedPtr()->EventFunction(callbackParameters);

			return true;
		}
	}
	break;

	case SocketManagerEvent::AsyncReceive:
	{
		BufferReceiveStream bufferReceiveStream{ m_Buffer2,GetConfigurationStrategy().GetParserStrategy() };
		bufferReceiveStream.OnEvent(m_SocketID, GetSocketManagerSharedPtr());	

		GetSocketManagerSharedPtr()->EventFunction(callbackParameters);

		return true;
	}
		break;

	default:
		break;
	}

	return false;
}


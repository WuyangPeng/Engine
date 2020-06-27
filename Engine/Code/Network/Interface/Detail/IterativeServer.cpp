// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:12)

#include "Network/NetworkExport.h" 

#include "IterativeServer.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/SocketManager.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::string;
using std::vector;
using std::make_pair;
using std::make_shared;

Network::IterativeServer
	::IterativeServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
	:ParentType{ socketManager,configurationStrategy },
	 m_SockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
	 m_StreamContainer{},
	 m_ReceiveBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy())),
	 m_SendBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
	m_SockAcceptor.EnableNonBlock();

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::IterativeServer
	::~IterativeServer()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, IterativeServer)

bool Network::IterativeServer
	::HandleConnections(const SocketManagerSharedPtr& socketManager)
{
	SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(GetConfigurationStrategy()) };
	SockStreamSharedPtr sockStreamSharedPtr{ make_shared<SockStream>(GetConfigurationStrategy()) };

	if (m_SockAcceptor.Accept(sockStreamSharedPtr->shared_from_this(), sockAddress))
	{
		auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
		socketManager->Insert(socketID);

		sockStreamSharedPtr->EnableNonBlock();
		StreamContainer streamContainer{ GetConfigurationStrategy(),sockStreamSharedPtr };

		m_StreamContainer.insert({ socketID,streamContainer });

		CoreTools::CallbackParameters callbackParameters{};
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), 0);

		socketManager->EventFunction(callbackParameters);
	}

	return true;
}

bool Network::IterativeServer
	::HandleData(const SocketManagerSharedPtr& socketManager)
{
	for (auto iter = m_StreamContainer.begin(); iter != m_StreamContainer.end();)
	{
		auto sockStreamSharedPtr = iter->second.GetSockStreamSharedPtr();

		try
		{
			m_ReceiveBuffer->ClearCurrentIndex();
			auto result = sockStreamSharedPtr->Receive(m_ReceiveBuffer);
			if (0 < result)
			{
				BufferReceiveStream bufferReceiveStream(m_ReceiveBuffer, GetConfigurationStrategy().GetParserStrategy());
				bufferReceiveStream.OnEvent(iter->first, socketManager);
				m_ReceiveBuffer->ClearCurrentIndex();
				++iter;
			}
			else if (result < 0)
			{
				sockStreamSharedPtr->CloseHandle();
				socketManager->Remove(iter->first);
				m_StreamContainer.erase(iter++);
			}
			else
			{
				++iter;
			}
		}
		catch (CoreTools::Error&)
		{
			sockStreamSharedPtr->CloseHandle();
			socketManager->Remove(iter->first);
			m_StreamContainer.erase(iter++);
		}
	}

	return true;
}

bool Network::IterativeServer
	::ImmediatelySend()
{
	return true;
}

void Network::IterativeServer
	::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_StreamContainer.find(socketID);

	if (iter != m_StreamContainer.cend())
	{
		auto sockStreamSharedPtr = iter->second.GetSockStreamSharedPtr();
		auto& bufferSendStream = iter->second.GetBufferSendStream();

		if (bufferSendStream.Insert(message))
		{
			m_SendBuffer->ClearCurrentIndex();
			bufferSendStream.Save(m_SendBuffer);

			sockStreamSharedPtr->Send(m_SendBuffer);

			bufferSendStream.Clear();
		}
	}
}

void Network::IterativeServer
	::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	auto iter = m_StreamContainer.find(socketID);

	if (iter != m_StreamContainer.cend())
	{
		auto sockStreamSharedPtr = iter->second.GetSockStreamSharedPtr();
		auto& bufferSendStream = iter->second.GetBufferSendStream();

		if (bufferSendStream.Insert(message))
		{
			m_SendBuffer->ClearCurrentIndex();
			bufferSendStream.Save(m_SendBuffer);

			sockStreamSharedPtr->AsyncSend(GetSocketManagerSharedPtr(), m_SendBuffer);

			bufferSendStream.Clear();
		}
	}
}


// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:54)

#ifndef NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H

#include "Network/NetworkDll.h"

#include "ServerImpl.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "StreamContainer.h"

namespace Network
{	
	class MessageEventManager;

	class NETWORK_HIDDEN_DECLARE IterativeServer : public ServerImpl
	{
	public:
		using ClassType = IterativeServer;
		using ParentType = ServerImpl;

	public:
		IterativeServer(const SocketManagerSharedPtr& socketManager,  const ConfigurationStrategy& configurationStrategy);
		virtual ~IterativeServer();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
		virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override; 

	private:
		virtual bool HandleConnections(const SocketManagerSharedPtr& socketManager) override;
		virtual bool HandleData(const SocketManagerSharedPtr& socketManager) override;
		virtual bool ImmediatelySend() override;

	private:
		using BufferType = std::vector<char>;
		using Container = std::map<uint64_t, StreamContainer>; 

	private:
		SockAcceptor m_SockAcceptor;
		Container m_StreamContainer;
		MessageBufferSharedPtr m_Buffer;
		MessageBufferSharedPtr m_Buffer2;
	};
} 

#endif // NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H

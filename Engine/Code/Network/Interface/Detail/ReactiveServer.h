// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:08)

#ifndef NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H

#include "Network/NetworkDll.h"

#include "IterativeServer.h" 
#include "HandleSetContainer.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/Data/BufferSendStreamMultiIndexContainer.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

namespace Network
{ 
	class NETWORK_HIDDEN_DECLARE ReactiveServer : public ServerImpl
	{
	public:
		using ClassType = ReactiveServer;
		using ParentType = ServerImpl;

	public:
		explicit ReactiveServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
		virtual ~ReactiveServer();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

	private:
		using BufferType = std::vector<char>;

	private:
		void Init();

		virtual bool WaitForMultipleEvents() override;
		virtual bool HandleConnections(const SocketManagerSharedPtr& socketManager) override;
		virtual bool HandleData(const SocketManagerSharedPtr& socketManager) override;
		virtual bool ImmediatelySend(uint64_t socketID) override;
		virtual bool ImmediatelySend() override;

	private:
		SockAcceptor m_SockAcceptor;
		SockStreamSharedPtr m_SockStream;
		BufferSendStreamMultiIndexContainer m_BufferSendStream;
		HandleSetContainer m_MasterHandleSet;
		HandleSet m_ActiveHandles;
		MessageBufferSharedPtr m_Buffer;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H

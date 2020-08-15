// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 10:01)

#ifndef NETWORK_NETWORK_INTERFACE_CACHE_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_CACHE_CLIENT_H

#include "Network/NetworkDll.h"

#include "ClientImpl.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/BufferSendStream.h"  

namespace Network
{
	class NETWORK_HIDDEN_DECLARE CacheClient : public ClientImpl
	{
	public:
		using ClassType = CacheClient;
		using ParentType = ClientImpl;
		using SockAddressSharedPtr = std::shared_ptr<SockAddress>;

	public:
		CacheClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);
	 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		uint64_t Connect() override;
		void AsyncConnect() override;

		void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
		void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

		void Receive() override;
		void AsyncReceive() override;
		void ImmediatelySend(uint64_t socketID) override;
		void ImmediatelyAsyncSend(uint64_t socketID) override;

		uint64_t GetSocketID() const noexcept override;

	private:
		using BufferType = std::vector<char>;

	private:
		bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

	private:
		SockConnector m_SockConnector;
		SockStreamSharedPtr m_SockStream;
		BufferSendStream m_BufferSendStream;
		SockAddressSharedPtr m_SockAddress;
		uint64_t m_SocketID;
		MessageBufferSharedPtr m_SendBuffer;
		MessageBufferSharedPtr m_ReceiveBuffer;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_CACHE_CLIENT_H

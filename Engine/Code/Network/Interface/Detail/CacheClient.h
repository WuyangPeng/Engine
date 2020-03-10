// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:53)

#ifndef NETWORK_NETWORK_INTERFACE_CACHE_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_CACHE_CLIENT_H

#include "Network/NetworkDll.h"

#include "ClientImpl.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockConnector.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/BufferSendStream.h" 
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

namespace Network
{	
	class SockAddress;

	class NETWORK_HIDDEN_DECLARE CacheClient : public ClientImpl
	{
	public:
		using ClassType = CacheClient;
		using ParentType = ClientImpl;
		using SockAddressSharedPtr = std::shared_ptr<SockAddress>;

	public:
		CacheClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);
		virtual ~CacheClient();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
 
		virtual uint64_t Connect() override;
		virtual void AsyncConnect() override;

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
		virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

		virtual void Receive() override;
		virtual void AsyncReceive() override;
		virtual void ImmediatelySend(uint64_t socketID) override;
		virtual void ImmediatelyAsyncSend(uint64_t socketID) override;

		virtual uint64_t GetSocketID() const;

	private:
		using BufferType = std::vector<char>;

	private:
		virtual bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;
		 	 
	private:	
		SockConnector m_SockConnector;
		SockStreamSharedPtr m_SockStream;
		BufferSendStream m_BufferSendStream;
		SockAddressSharedPtr m_SockAddress;
		uint64_t m_SocketID;
		MessageBufferSharedPtr m_Buffer;
		MessageBufferSharedPtr m_Buffer2;
	};
} 

#endif // NETWORK_NETWORK_INTERFACE_CACHE_CLIENT_H

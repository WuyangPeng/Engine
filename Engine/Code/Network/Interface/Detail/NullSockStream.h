// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:55)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H

#include "Network/NetworkDll.h"
 
#include "SockStreamImpl.h"

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE NullSockStream :public SockStreamImpl
	{
	public:
		using ClassType = NullSockStream;
		using ParentType = SockStreamImpl;

	public:
		NullSockStream();
		virtual ~NullSockStream();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual int Send(const MessageBufferSharedPtr& messageBuffer) override;
		virtual int Receive(const MessageBufferSharedPtr& messageBuffer) override;

		virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
 
		virtual bool CloseHandle() override;

		virtual bool EnableNonBlock() override;

		virtual const std::string GetRemoteAddress() const override;
		virtual int GetRemotePort() const override;
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H

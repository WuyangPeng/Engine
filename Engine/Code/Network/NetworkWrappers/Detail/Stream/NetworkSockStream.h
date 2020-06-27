// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 16:30)

#ifndef NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NetworkSockStream : public SockStreamImpl
	{
	public:
		using ClassType = NetworkSockStream;
		using ParentType = SockStreamImpl;

	public:
		NetworkSockStream();
		virtual ~NetworkSockStream();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual WinSocketStreamType& GetNetworkSockStream() override;

		virtual int Receive(const MessageBufferSharedPtr& messageBuffer) override;
		virtual int Send(const MessageBufferSharedPtr& messageBuffer) override;

		virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

		virtual bool CloseHandle() override;
		virtual void SetNetworkHandle(WinSocketStreamType winSocket) override;

		virtual bool EnableNonBlock() override;

		virtual const std::string GetRemoteAddress() const override;
		virtual int GetRemotePort() const override;

	private:
		WinSocketStreamType m_WinSocket;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H

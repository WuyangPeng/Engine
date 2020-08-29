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
		NetworkSockStream() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 WinSocketStreamType& GetNetworkSockStream() noexcept override;

		 int Receive(const MessageBufferSharedPtr& messageBuffer) override;
		 int Send(const MessageBufferSharedPtr& messageBuffer) override;

		 void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
		 void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

		 bool CloseHandle() noexcept override;
		 void SetNetworkHandle(WinSocketStreamType winSocket) noexcept override;

		 bool EnableNonBlock() noexcept override;

		 const std::string GetRemoteAddress() const override;
		 int GetRemotePort() const noexcept override;

	private:
		WinSocketStreamType m_WinSocket;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H

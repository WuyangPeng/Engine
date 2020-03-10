// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/15 13:18)


#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE SockStreamImpl
	{
	public:
		using ClassType = SockStreamImpl;

	public:
		SockStreamImpl();
		virtual ~SockStreamImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual int Send(const MessageBufferSharedPtr& messageBuffer) = 0;
		virtual int Receive(const MessageBufferSharedPtr& messageBuffer) = 0;

		virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) = 0;
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) = 0;

		virtual ACESockStreamNativeType& GetACESockStream();
		virtual BoostSockStreamType& GetBoostSockStream();
		virtual WinSocketStreamType& GetNetworkSockStream();

		virtual ACEHandleType GetACEHandle() const;

		virtual void SetACEHandle(ACEHandleType handle);
		virtual void SetNetworkHandle(WinSocketStreamType winSocket);

		virtual bool CloseHandle() = 0;

		virtual bool EnableNonBlock() = 0;

		virtual const std::string GetRemoteAddress() const = 0;
		virtual int GetRemotePort() const = 0;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H

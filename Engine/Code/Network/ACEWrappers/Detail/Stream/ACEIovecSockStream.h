// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:43)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "ACESockStream.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ACEIovecSockStream : public ACESockStream
	{
	public:
		using ClassType = ACEIovecSockStream;
		using ParentType = ACESockStream;

	public:
		ACEIovecSockStream(); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int Send(const MessageBufferSharedPtr& messageBuffer) override;
		void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/26 22:40)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "BoostSockStream.h"  

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostFixedSockStream : public BoostSockStream
	{
	public:
		using ClassType = BoostFixedSockStream;
		using ParentType = BoostSockStream;

	public:
		BoostFixedSockStream();
		virtual ~BoostFixedSockStream();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual int Receive(const MessageBufferSharedPtr& messageBuffer) override;
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

	private:
		virtual void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) override;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/26 22:29)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "BoostSockStream.h"  
#include "Network/Interface/Flags/StreamFlags.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSegmentationSockStream : public BoostSockStream
	{
	public:
		using ClassType = BoostSegmentationSockStream;
		using ParentType = BoostSockStream;

	public:
		BoostSegmentationSockStream();
		virtual ~BoostSegmentationSockStream();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual int Receive(const MessageBufferSharedPtr& messageBuffer) override;
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

	private:
		int ReceiveHead(const MessageBufferSharedPtr& messageBuffer);
		int ReceiveContent(const MessageBufferSharedPtr& messageBuffer);

		void AsyncReceiveHead(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);
		void AsyncReceiveContent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

		void SubclassAsyncReceiveHeadEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);
		void SubclassAsyncReceiveContentEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

		virtual void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) override;

	private:
		StreamReceive m_StreamReceive;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H

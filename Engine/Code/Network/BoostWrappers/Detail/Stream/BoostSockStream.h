// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:48)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"  

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSockStream : public SockStreamImpl
	{
	public:
		using ClassType = BoostSockStream;
		using ParentType = SockStreamImpl;

	public:
		BoostSockStream();
		virtual ~BoostSockStream() = 0;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual BoostSockStreamType& GetBoostSockStream() override;

		virtual int Send(const MessageBufferSharedPtr& messageBuffer) override;
		virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

		virtual bool CloseHandle() override;

		virtual bool EnableNonBlock() override;

		virtual const std::string GetRemoteAddress() const override;
		virtual int GetRemotePort() const override;

	protected:
		int HandleReceive(const MessageBufferSharedPtr& messageBuffer);
		void HandleAsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

	private:
		void AsyncSendEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalReadIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);
		void AsyncReceiveEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);

		virtual void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) = 0;

	private:
		BoostSockStreamType m_Socket;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H

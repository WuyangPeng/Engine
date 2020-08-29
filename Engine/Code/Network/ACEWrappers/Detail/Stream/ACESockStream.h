// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:43)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/SockStreamImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ACESockStream : public SockStreamImpl
	{
	public:
		using ClassType = ACESockStream;
		using ParentType = SockStreamImpl;

	public:
		ACESockStream();
		~ACESockStream();
		ACESockStream(const ACESockStream&) = delete;
		ACESockStream& operator=(const ACESockStream&) = delete;
		ACESockStream(ACESockStream&&) noexcept = delete;
		ACESockStream& operator=(ACESockStream&&) noexcept = delete;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		ACESockStreamNativeType& GetACESockStream() noexcept override;

		int Send(const MessageBufferSharedPtr& messageBuffer) override;
		int Receive(const MessageBufferSharedPtr& messageBuffer) override;

		void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
		void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

		ACEHandle GetACEHandle() const override;

		void SetACEHandle(ACEHandle handle) override;
		bool CloseHandle() override;

		const std::string GetRemoteAddress() const override;
		int GetRemotePort() const override;

		bool EnableNonBlock() override;

	private:
		ACE_SOCK_Stream m_ACESockStream;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H

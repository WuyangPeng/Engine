// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 13:43)

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
		virtual ~ACESockStream();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual ACESockStreamNativeType& GetACESockStream() override;

		virtual int Send(const MessageBufferSharedPtr& messageBuffer) override;
		virtual int Receive(const MessageBufferSharedPtr& messageBuffer) override;

		virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

		virtual ACEHandle GetACEHandle() const override;

		virtual void SetACEHandle(ACEHandle handle) override;
		virtual bool CloseHandle() override;

		virtual const std::string GetRemoteAddress() const override;
		virtual int GetRemotePort() const override;

		virtual bool EnableNonBlock() override;

	private:
		ACE_SOCK_Stream m_ACESockStream;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H

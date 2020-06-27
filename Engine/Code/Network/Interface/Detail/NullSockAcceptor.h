// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:06)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "SockAcceptorImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NullSockAcceptor :public SockAcceptorImpl
	{
	public:
		using ClassType = NullSockAcceptor;
		using ParentType = SockAcceptorImpl;

	public:
		NullSockAcceptor();
		virtual ~NullSockAcceptor();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
		virtual bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		virtual bool Accept(const SockStreamSharedPtr& sockStream) override;
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		virtual bool EnableNonBlock() override;

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 16:28)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAcceptorImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NetworkSockAcceptor : public SockAcceptorImpl
	{
	public:
		using ClassType = NetworkSockAcceptor;
		using ParentType = SockAcceptorImpl;

	public:
		explicit NetworkSockAcceptor(int port);
		NetworkSockAcceptor(const std::string& hostName, int port);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		 bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		 bool Accept(const SockStreamSharedPtr& sockStream) override;

		 void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
		 void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		 bool EnableNonBlock() noexcept override;

		 WinSocketType GetWinSocket() noexcept override;

		 const std::string GetAddress() const override;
		 int GetPort() const noexcept override;

	private:
		WinSocketType m_SocketHandle;
	};
}

#endif // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H

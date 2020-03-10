// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/02 10:16)

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
		virtual ~NetworkSockAcceptor();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		virtual bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		virtual bool Accept(const SockStreamSharedPtr& sockStream) override;

		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		
		virtual bool EnableNonBlock() override;

		virtual WinSocketType GetWinSocket() override;

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;

	private:
		WinSocketType m_SocketHandle;
	};	
} 

#endif // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H

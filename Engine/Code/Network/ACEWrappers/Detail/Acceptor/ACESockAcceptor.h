// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 20:13)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/SockAcceptorImpl.h"

#include <ace/SOCK_Acceptor.h>

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE ACESockAcceptor : public SockAcceptorImpl
	{
	public:
		using ClassType = ACESockAcceptor;
		using ParentType = SockAcceptorImpl;

	public:
		explicit ACESockAcceptor(int port);
		ACESockAcceptor(const std::string& hostName, int port);
		virtual ~ACESockAcceptor();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		virtual bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		virtual bool Accept(const SockStreamSharedPtr& sockStream) override;

		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		virtual bool EnableNonBlock() override;

		virtual ACEHandle GetACEHandle() override;

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;

	private:
		ACE_SOCK_Acceptor m_ACESockAcceptor;
	};	
} 

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

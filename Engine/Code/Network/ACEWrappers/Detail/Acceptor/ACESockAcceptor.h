// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:41)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/SockAcceptorImpl.h"

#include "System/Helper/PragmaWarning/ACE.h"

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
		~ACESockAcceptor();
		ACESockAcceptor(const ACESockAcceptor&) = delete;
		ACESockAcceptor& operator=(const ACESockAcceptor&) = delete;
		ACESockAcceptor(ACESockAcceptor&&) noexcept = delete;
		ACESockAcceptor& operator=(ACESockAcceptor&&) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		bool Accept(const SockStreamSharedPtr& sockStream) override;

		void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
		void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		bool EnableNonBlock() override;

		ACEHandle GetACEHandle() override;

		const std::string GetAddress() const override;
		int GetPort() const override;

	private:
		ACE_SOCK_Acceptor m_ACESockAcceptor;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

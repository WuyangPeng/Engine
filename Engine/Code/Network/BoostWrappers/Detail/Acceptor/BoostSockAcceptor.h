// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/31 13:49)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAcceptorImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSockAcceptor : public SockAcceptorImpl
	{
	public:
		using ClassType = BoostSockAcceptor;
		using ParentType = SockAcceptorImpl;

	public:
		// hostName默认为"0.0.0.0"。
		explicit BoostSockAcceptor(int port);
		BoostSockAcceptor(const std::string& hostName, int port);
		virtual ~BoostSockAcceptor();

		BoostSockAcceptor(BoostSockAcceptor&& rhs) noexcept;
		BoostSockAcceptor& operator=(BoostSockAcceptor&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool Accept(const SockStreamSharedPtr& sockStream) override;
		virtual bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		// 异步回调来自另一个线程，需要对事件管理进行加锁处理。
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		virtual BoostHandleType GetBoostHandle() override;

		virtual bool EnableNonBlock() override;	

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;

	private:
		using AcceptorType = boost::asio::ip::tcp::acceptor;

	private:
		AcceptorType m_Acceptor;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H

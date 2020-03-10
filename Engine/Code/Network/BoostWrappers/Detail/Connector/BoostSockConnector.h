// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/21 17:15)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockConnectorImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSockConnector : public SockConnectorImpl
	{
	public:
		using ClassType = BoostSockConnector;
		using ParentType = SockConnectorImpl;

	public:
		BoostSockConnector();
		virtual ~BoostSockConnector();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		virtual const SockConnectorPtr Clone() const override;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_H

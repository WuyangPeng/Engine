// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:47)

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

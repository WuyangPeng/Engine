// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 16:30)

#ifndef NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H
#define NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockConnectorImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NetworkSockConnector : public SockConnectorImpl
	{
	public:
		using ClassType = NetworkSockConnector;
		using ParentType = SockConnectorImpl;

	public:
		NetworkSockConnector() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		 void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		 const SockConnectorPtr Clone() const override;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H

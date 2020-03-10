// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/02 10:16)

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
		NetworkSockConnector();
		virtual ~NetworkSockConnector();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override; 
		virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream,const SockAddressSharedPtr& sockAddress) override;

		virtual const SockConnectorPtr Clone() const override;
	};	
} 

#endif // NETWORK_BOOST_WRAPPERS_NETWORK_SOCK_CONNECTOR_H

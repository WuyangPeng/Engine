// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:55)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"
 
#include "SockConnectorImpl.h"

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE NullSockConnector :public SockConnectorImpl
	{
	public:
		using ClassType = NullSockConnector;
		using ParentType = SockConnectorImpl;

	public:
		NullSockConnector();
		virtual ~NullSockConnector();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override; 
		virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		virtual const SockConnectorPtr Clone() const override;
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_NULL_SOCK_CONNECTOR_H

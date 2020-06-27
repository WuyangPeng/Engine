// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:43)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/SockConnectorImpl.h"

#include <ace/SOCK_Connector.h>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ACESockConnector : public SockConnectorImpl
	{
	public:
		using ClassType = ACESockConnector;
		using ParentType = SockConnectorImpl;

	public:
		ACESockConnector();
		virtual ~ACESockConnector();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
		virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

		virtual const SockConnectorPtr Clone() const override;

	private:
		ACE_SOCK_Connector m_ACESockConnector;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_ACE_SOCK_CONNECTOR_H

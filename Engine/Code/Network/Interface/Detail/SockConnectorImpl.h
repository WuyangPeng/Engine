// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 17:03)


#ifndef NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE SockConnectorImpl
	{
	public:
		using ClassType = SockConnectorImpl;
		using SockConnectorPtr = std::shared_ptr<ClassType>;

	public:
		SockConnectorImpl ();	
		virtual ~SockConnectorImpl ();

		CLASS_INVARIANT_VIRTUAL_DECLARE;		
		
		virtual bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0; 
		virtual void AsyncConnect(const EventInterfaceSharedPtr& eventInterface,const SockStreamSharedPtr& sockStream,const SockAddressSharedPtr& sockAddress) = 0;

		virtual const SockConnectorPtr Clone() const = 0;
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_IMPL_H

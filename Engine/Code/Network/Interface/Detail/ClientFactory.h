// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:53)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H

#include "Network/NetworkDll.h" 

#include "Network/NetworkMessage/SocketManager.h"

#include <memory>

namespace Network
{	
	class ClientImpl;
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE ClientFactory
	{
	public:
		using ClassType = ClientFactory;
		using ImplType = ClientImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		ClientFactory ();	 

		CLASS_INVARIANT_DECLARE;
		 	 
		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H

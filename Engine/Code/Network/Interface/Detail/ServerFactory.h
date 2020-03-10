// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:55)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/SocketManager.h"

#include <memory>

namespace Network
{	
	class ServerImpl;
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE ServerFactory
	{
	public:
		using ClassType = ServerFactory;
		using ImplType = ServerImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		ServerFactory ();	 

		CLASS_INVARIANT_DECLARE;
		 
		static const ImplTypePtr Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H

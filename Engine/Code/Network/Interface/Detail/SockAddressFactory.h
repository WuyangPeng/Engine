// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/20 17:39)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H

#include "Network/NetworkDll.h"

#include <memory>
#include <string>

namespace Network
{	
	class SockAddressImpl;
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE SockAddressFactory
	{
	public:
		using ClassType = SockAddressFactory;
		using ImplType = SockAddressImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		SockAddressFactory ();	 

		CLASS_INVARIANT_DECLARE;
		 	 
		static const ImplTypePtr Create(const std::string& hostName, int port,const ConfigurationStrategy& configurationStrategy);
		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
		static const ImplTypePtr Create(int port, const ConfigurationStrategy& configurationStrategy);
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H

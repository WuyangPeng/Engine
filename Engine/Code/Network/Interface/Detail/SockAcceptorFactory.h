// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/20 17:37)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_FACTORY_H

#include "Network/NetworkDll.h"

#include <memory>
#include <string>

namespace Network
{	
	class SockAcceptorImpl;
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE SockAcceptorFactory
	{
	public:
		using ClassType = SockAcceptorFactory;
		using ImplType = SockAcceptorImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		SockAcceptorFactory (); 

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create(int port, const ConfigurationStrategy& configurationStrategy);
		static const ImplTypePtr Create(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_FACTORY_H

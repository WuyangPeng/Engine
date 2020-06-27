// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:11)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/SocketManager.h"
#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ServerFactory
	{
	public:
		using ClassType = ServerFactory;
		using ImplType = ServerImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		ServerFactory();

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_SERVER_FACTORY_H

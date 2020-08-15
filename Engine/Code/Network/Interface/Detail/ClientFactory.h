// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:02)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H

#include "Network/NetworkDll.h" 

#include "Network/NetworkMessage/SocketManager.h"
#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ClientFactory
	{
	public:
		using ClassType = ClientFactory;
		using ImplType = ClientImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		ClientFactory() noexcept;

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_CLIENT_FACTORY_H

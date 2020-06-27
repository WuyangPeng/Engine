// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:16)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE SockStreamFactory
	{
	public:
		using ClassType = SockStreamFactory;
		using ImplType = SockStreamImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		SockStreamFactory();

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_FACTORY_H

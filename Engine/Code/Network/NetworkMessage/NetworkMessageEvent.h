// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:37)

#ifndef NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_H
#define NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::NetworkMessageEvent>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::NetworkMessageEvent>;

namespace Network
{
	class NETWORK_DEFAULT_DECLARE NetworkMessageEvent : public std::enable_shared_from_this<NetworkMessageEvent>
	{
	public:
		using ClassType = NetworkMessageEvent;

	public:
		NetworkMessageEvent();
		virtual ~NetworkMessageEvent();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) = 0;
	};

	using NetworkMessageEventSharedPtr = std::shared_ptr<NetworkMessageEvent>;
	using ConstNetworkMessageEventSharedPtr = std::shared_ptr<const NetworkMessageEvent>;

	using NetworkMessageEventWeakPtr = std::weak_ptr<NetworkMessageEvent>;
	using ConstNetworkMessageEventWeakPtr = std::weak_ptr<const NetworkMessageEvent>;
}

#endif // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_H

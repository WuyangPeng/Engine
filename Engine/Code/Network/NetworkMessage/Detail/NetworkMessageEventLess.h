// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:26)

#ifndef NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H
#define NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageEvent.h" 

namespace Network
{
	class NETWORK_DEFAULT_DECLARE NetworkMessageEventLess
	{
	public:
		using ClassType = NetworkMessageEventLess;

	public:
		NetworkMessageEventLess();

		CLASS_INVARIANT_DECLARE;

		bool operator()(const NetworkMessageEventWeakPtr& lhs, const NetworkMessageEventWeakPtr& rhs) const;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H

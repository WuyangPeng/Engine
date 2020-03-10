// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:19)

#ifndef NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_INTERNAL_FWD_H
#define NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_INTERNAL_FWD_H

#include "Network/NetworkDll.h"  

#include "NetworkMessageFwd.h"

#include <memory>

namespace Network
{	 
	enum class ParserStrategy;

	class MessageBufferImpl;
	class MessageEventContainerImpl;
	class MultiMessageEventContainerImpl; 

	using MessageSourceSharedPtr = std::shared_ptr<MessageSource>;
	using MessageTargetSharedPtr = std::shared_ptr<MessageTarget>;	
	using MessageBufferSharedPtr = std::shared_ptr<MessageBuffer>;
	using SocketManagerSharedPtr = std::shared_ptr<SocketManager>;
	using MessageInterfaceSharedPtr = std::shared_ptr<MessageInterface>;
	using ConstMessageInterfaceSharedPtr = std::shared_ptr<const MessageInterface>;
	using NetworkMessageEventSharedPtr = std::shared_ptr<NetworkMessageEvent>;
	using ConstNetworkMessageEventSharedPtr = std::shared_ptr<const NetworkMessageEvent>;
	using NetworkMessageEventWeakPtr = std::weak_ptr<NetworkMessageEvent>;
	using ConstNetworkMessageEventWeakPtr = std::weak_ptr<const NetworkMessageEvent>;	 
} 

#endif // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_INTERNAL_FWD_H

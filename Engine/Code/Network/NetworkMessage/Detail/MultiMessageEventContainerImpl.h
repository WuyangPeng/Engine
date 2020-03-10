// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:26)

#ifndef NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_IMPL_H

#include "Network/NetworkDll.h" 

#include "NetworkMessageEventLess.h"
#include "Network/NetworkMessage/NetworkMessageEvent.h" 
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <set>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MultiMessageEventContainerImpl
	{
	public:
		using ClassType = MultiMessageEventContainerImpl;
		using ImplPtr = std::shared_ptr<MessageEventContainerImpl>;

	public:
		MultiMessageEventContainerImpl();
		explicit MultiMessageEventContainerImpl(const NetworkMessageEventSharedPtr& messageEvent);

		CLASS_INVARIANT_DECLARE;

		void Insert(const NetworkMessageEventSharedPtr& messageEvent);
		void Remove(const NetworkMessageEventSharedPtr& messageEvent);

		void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

		ImplPtr CloneToPriorityMessage(MessageEventPriority priority) const;

	private:
		using PointerContainer = std::set<NetworkMessageEventWeakPtr, NetworkMessageEventLess>;

	private:
		PointerContainer m_MessageEventContainer;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H

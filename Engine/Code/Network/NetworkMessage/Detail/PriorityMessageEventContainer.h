// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:26)

#ifndef NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MessageEventContainerImpl.h"
#include "MultiMessageEventContainerImpl.h"

#include <vector>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE PriorityMessageEventContainer : public MessageEventContainerImpl
	{
	public:
		using ClassType = PriorityMessageEventContainer;
		using ParentType = MessageEventContainerImpl;

	public:
		PriorityMessageEventContainer();
		 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		  void Insert(const NetworkMessageEventSharedPtr& messageEvent) override;
		  void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) override;
		  void Remove(const NetworkMessageEventSharedPtr& messageEvent) override;

		  void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) override;

		  ImplPtr Clone() const override;
		  ImplPtr CloneToMultiMessage() const override;
		  ImplPtr CloneToPriorityMessage() const override;

		  bool IsCanInsert() const noexcept override;
		  bool IsPrioritySame(MessageEventPriority priority) const noexcept override;

	private:
		using PriorityPointerContainer = std::vector<MultiMessageEventContainerImpl>;

	private:
		PriorityPointerContainer m_MultiMessageEventContainer;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H

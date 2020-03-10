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
		virtual ~PriorityMessageEventContainer();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent) override;
		virtual void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) override;
		virtual void Remove(const NetworkMessageEventSharedPtr& messageEvent) override;

		virtual void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) override;

		virtual ImplPtr Clone() const override;
		virtual ImplPtr CloneToMultiMessage() const override;
		virtual ImplPtr CloneToPriorityMessage() const override;

		virtual bool IsCanInsert() const override;
		virtual bool IsPrioritySame(MessageEventPriority priority) const override;

	private:
		using PriorityPointerContainer = std::vector<MultiMessageEventContainerImpl>;

	private:
		PriorityPointerContainer m_MultiMessageEventContainer;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H

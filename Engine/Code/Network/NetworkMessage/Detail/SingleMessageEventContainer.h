// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:27)

#ifndef NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MessageEventContainerImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE SingleMessageEventContainer : public MessageEventContainerImpl
	{
	public:
		using ClassType = SingleMessageEventContainer;
		using ParentType = MessageEventContainerImpl;

	public:
		SingleMessageEventContainer();
		virtual ~SingleMessageEventContainer();

		SingleMessageEventContainer(const SingleMessageEventContainer& rhs);
		SingleMessageEventContainer& operator=(const SingleMessageEventContainer& rhs);
		SingleMessageEventContainer(SingleMessageEventContainer&& rhs) noexcept;
		SingleMessageEventContainer& operator=(SingleMessageEventContainer&& rhs) noexcept;

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
		NetworkMessageEventWeakPtr m_MessageEvent;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_SINGLE_MESSAGE_EVENT_CONTAINER_H

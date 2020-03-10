// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:25)

#ifndef NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "MessageEventContainerImpl.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MultiMessageEventContainer : public MessageEventContainerImpl
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(MultiMessageEventContainer);
		using ParentType = MessageEventContainerImpl;

	public:
		MultiMessageEventContainer();
		virtual ~MultiMessageEventContainer();

		MultiMessageEventContainer(MultiMessageEventContainer&& rhs) noexcept;
		MultiMessageEventContainer& operator=(MultiMessageEventContainer&& rhs) noexcept;

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
		IMPL_TYPE_DECLARE(MultiMessageEventContainer);
		MessageEventPriority m_Priority;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H

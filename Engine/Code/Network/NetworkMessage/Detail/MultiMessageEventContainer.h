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
		~MultiMessageEventContainer();

		MultiMessageEventContainer(MultiMessageEventContainer&& rhs) noexcept;
		MultiMessageEventContainer& operator=(MultiMessageEventContainer&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		  void Insert(const NetworkMessageEventSharedPtr& messageEvent) override;
		  void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) override;
		  void Remove(const NetworkMessageEventSharedPtr& messageEvent) noexcept override;

		  void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) override;

		  ImplPtr Clone() const override;
		  ImplPtr CloneToMultiMessage() const override;
		  ImplPtr CloneToPriorityMessage() const override;

		  bool IsCanInsert() const noexcept override;
		  bool IsPrioritySame(MessageEventPriority priority) const noexcept override;

	private:
		IMPL_TYPE_DECLARE(MultiMessageEventContainer);
		MessageEventPriority m_Priority;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H

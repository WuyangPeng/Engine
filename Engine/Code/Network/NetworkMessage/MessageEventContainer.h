// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:29)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h" 

NETWORK_EXPORT_SHARED_PTR(MessageEventContainerImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE MessageEventContainer
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MessageEventContainer);

	public:
		MessageEventContainer();

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(MessageEventContainer);

		void Insert(const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(const NetworkMessageEventSharedPtr& messageEvent);

		void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

	private:
		IMPL_TYPE_DECLARE(MessageEventContainer);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:29)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkMessageEvent.h" 
#include "CoreTools/Helper/ExportMacro.h" 

NETWORK_EXPORT_SHARED_PTR(MessageEventManagerImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE MessageEventManager
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MessageEventManager);

	public:
		MessageEventManager();

		CLASS_INVARIANT_DECLARE;

	public:
		void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(int64_t messageID);
		void Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

		void OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

	private:
		IMPL_TYPE_DECLARE(MessageEventManager);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H

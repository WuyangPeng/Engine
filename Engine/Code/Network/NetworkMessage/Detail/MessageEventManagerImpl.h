// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:23)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Threading/Mutex.h" 
#include "Network/NetworkMessage/MessageEventContainer.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <map>
#include <memory>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageEventManagerImpl
	{
	public:
		using ClassType = MessageEventManagerImpl;

	public:
		MessageEventManagerImpl();

		MessageEventManagerImpl(const MessageEventManagerImpl& rhs);
		MessageEventManagerImpl& operator=(const MessageEventManagerImpl& rhs);
		MessageEventManagerImpl(MessageEventManagerImpl&& rhs) noexcept;
		MessageEventManagerImpl& operator=(MessageEventManagerImpl&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

	public:
		void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(int64_t messageID);
		void Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

		void OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

	private:
		using EventContainer = std::map<int64_t, MessageEventContainer>;
		using MutexUniquePtr = std::unique_ptr<CoreTools::Mutex>;

	private:
		EventContainer m_EventContainer;
		MutexUniquePtr m_Mutex;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H

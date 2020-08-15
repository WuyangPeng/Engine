// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:27)

#ifndef NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/SendSocket.h"
#include "Network/NetworkMessage/MessageEventManager.h" 

#include <map>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE SocketManagerImpl
	{
	public:
		using ClassType = SocketManagerImpl;

	public:
		SocketManagerImpl();
		~SocketManagerImpl() = default;

		SocketManagerImpl(const SocketManagerImpl& rhs);
		SocketManagerImpl& operator=(const SocketManagerImpl& rhs);
		SocketManagerImpl(SocketManagerImpl&& rhs) noexcept;
		SocketManagerImpl& operator=(SocketManagerImpl&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

	public:
		void Insert(uint64_t socketID);
		void Remove(uint64_t socketID);

		void Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(uint64_t socketID, int64_t messageID);
		void Remove(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

		void OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message);

		int GetSocketSize() const;

	private:
		using MessageEventManagerContainer = std::map<uint64_t, MessageEventManager>;
		using MutexUniquePtr = std::unique_ptr<CoreTools::Mutex>;

	private:
		MessageEventManagerContainer m_MessageEventManagerContainer;
		MutexUniquePtr m_Mutex;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H

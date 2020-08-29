// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:38)

#ifndef NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

#include "MessageInterface.h"
#include "NetworkMessageEvent.h"
#include "Flags/MessageEventFlags.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SendSocket.h"

NETWORK_EXPORT_SHARED_PTR(SocketManagerImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE SocketManager : public CoreTools::EventInterface, private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(SocketManager);

	public:
		SocketManager(); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	public:
		void Insert(uint64_t socketID);
		void Remove(uint64_t socketID);

		void OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message);

		int GetSocketSize() const;

		// 接口名字要换个，和上面的重复了。。。
		void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(int64_t messageID);
		void Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

	protected:
		void Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(uint64_t socketID, int64_t messageID);
		void Remove(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

	private:
		virtual void InitEvent(uint64_t socketID) = 0;

	private:
		IMPL_TYPE_DECLARE(SocketManager);
	};

	using SocketManagerSharedPtr = std::shared_ptr<SocketManager>;
	using ConstSocketManagerSharedPtr = std::shared_ptr<const SocketManager>;

	using SocketManagerWeakPtr = std::weak_ptr<SocketManager>;
	using ConstSocketManagerWeakPtr = std::weak_ptr<const SocketManager>;
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H

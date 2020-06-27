// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.1.0.2 (2020/04/26 18:33)

#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/NetworkMessage/MessageInterface.h" 

#include <boost/noncopyable.hpp>
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <map>
#include "SendSocket.h"

EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE SendSocketManager : private boost::noncopyable
	{
	public:
		using ClassType = SendSocketManager;

	public:
		explicit SendSocketManager(const std::string& fileName);

		CLASS_INVARIANT_DECLARE;

		// 发送网络消息
		void Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message);

		// 链接成功消息，消息号负数。
		// 注册事件回调，监听所有服务器ID则ID设为0。
		// 消息号为0则监听所有事件。
		void Insert(SocketType socketType, int serverID,int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(SocketType socketType, int serverID, int64_t messageID);
		void Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

		void HandlingMessages();
		void Destroy();

		SocketManagerSharedPtr GetSocketManager(SocketType socketType, int serverID);
		std::vector<std::pair<SocketType, int>>::const_iterator begin();
		std::vector<std::pair<SocketType, int>>::const_iterator end();

	private:
		//std::map<std::pair<SocketType, int>, SendSocketSharedPtr> m_SendSocket;
		//SocketManagerSharedPtr socketManager;
	};	 
}

#endif // NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H

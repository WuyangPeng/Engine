// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.1.0.2 (2020/04/26 18:33)

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

		// ����������Ϣ
		void Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message);

		// ���ӳɹ���Ϣ����Ϣ�Ÿ�����
		// ע���¼��ص����������з�����ID��ID��Ϊ0��
		// ��Ϣ��Ϊ0����������¼���
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

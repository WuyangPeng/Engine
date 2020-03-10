// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/11/29 10:28)


#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE SendSocket : private boost::noncopyable
	{
	public:
		using ClassType = SendSocket;
		using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;

	public:
		SendSocket();
		virtual ~SendSocket();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) = 0;
		virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) = 0;
	};

	using SendSocketSharedPtr = std::shared_ptr<SendSocket>;
	using ConstSendSocketSharedPtr = std::shared_ptr<const SendSocket>;
}

#endif // NETWORK_NETWORK_INTERFACE_CLIENT_H

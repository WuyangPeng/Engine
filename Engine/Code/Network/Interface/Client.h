// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 09:57)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_H

#include "Network/NetworkDll.h"

#include "SendSocket.h"
#include "NetworkInternalFwd.h"
#include "Network/NetworkMessage/SocketManager.h"
#include "Network/NetworkMessage/MessageInterface.h" 

#include <string>

NETWORK_EXPORT_SHARED_PTR(ClientImpl);

namespace Network
{ 
	class NETWORK_DEFAULT_DECLARE Client : public SendSocket
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Client);
		using ParentType = SendSocket;

	public:
		Client(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);
		virtual ~Client();

		IMPL_MOVE_OPERATOR_COMPLETE_DECLARE(Client);

		uint64_t Connect();
		void AsyncConnect();

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
		virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

		void Receive();
		void AsyncReceive();
		void ImmediatelySend(uint64_t socketID);
		void ImmediatelyAsyncSend(uint64_t socketID);

		uint64_t GetSocketID() const;

	private:
		IMPL_TYPE_DECLARE(Client);
	};

	using ClientSharedPtr = std::shared_ptr<Client>;
	using ConstClientSharedPtr = std::shared_ptr<const Client>;
}

#endif // NETWORK_NETWORK_INTERFACE_CLIENT_H

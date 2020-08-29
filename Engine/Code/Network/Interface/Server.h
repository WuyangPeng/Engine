// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 09:58)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_SERVER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "SendSocket.h" 
#include "NetworkInternalFwd.h"
#include "Network/NetworkMessage/SocketManager.h"

NETWORK_EXPORT_SHARED_PTR(ServerImpl);

namespace Network
{ 
	class NETWORK_DEFAULT_DECLARE Server : public SendSocket
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Server);
		using ParentType = SendSocket;

	public:
		Server(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
 
		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool RunServer();

		 void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
		 void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

	private:
		IMPL_TYPE_DECLARE(Server);
	};

	using ServerSharedPtr = std::shared_ptr<Server>;
	using ConstServerSharedPtr = std::shared_ptr<const Server>;

	using ServerWeakPtr = std::weak_ptr<Server>;
	using ConstServerWeakPtr = std::weak_ptr<const Server>;
}

#endif // NETWORK_NETWORK_INTERFACE_SERVER_H

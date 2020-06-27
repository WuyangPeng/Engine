// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:45)

#ifndef FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE NetworkManagerImpl
	{
	public:
		using ClassType = NetworkManagerImpl;
		using SocketType = Network::SocketType;
		using MessageEventPriority = Network::MessageEventPriority;
		using MessageInterfaceSharedPtr = Network::MessageInterfaceSharedPtr;
		using NetworkMessageEventSharedPtr = Network::NetworkMessageEventSharedPtr;
		using SendSocketManager = Network::SendSocketManager;
		using SendSocketManagerSharedPtr = Network::SendSocketManagerSharedPtr;
		using ConstSendSocketManagerSharedPtr = Network::ConstSendSocketManagerSharedPtr;

	public:
		NetworkManagerImpl() noexcept;
		~NetworkManagerImpl() noexcept = default;
		NetworkManagerImpl(const NetworkManagerImpl& rhs) noexcept = delete;
		NetworkManagerImpl& operator=(const NetworkManagerImpl& rhs) noexcept = delete;
		NetworkManagerImpl(NetworkManagerImpl&& rhs) noexcept;
		NetworkManagerImpl& operator=(NetworkManagerImpl&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		void ResetSendSocketManager(const std::string& fileName);

		SendSocketManagerSharedPtr GetSendSocketManager() noexcept;
		ConstSendSocketManagerSharedPtr GetSendSocketManager() const noexcept;

		void Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message);

		void Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(SocketType socketType, int serverID, int64_t messageID);
		void Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

		void HandlingMessages();
		void Destroy();

	private:
		SendSocketManagerSharedPtr m_SendSocketManager;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_IMPL_H




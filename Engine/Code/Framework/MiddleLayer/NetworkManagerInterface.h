// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"  
#include "CoreTools/Helper/ExportMacro.h" 
#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(NetworkManagerImpl);
FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 网络接口，与外部实体间的通信，其中包括游戏或硬件设备、匹配服务等。
	class FRAMEWORK_DEFAULT_DECLARE NetworkManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using NetworkManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(NetworkManagerInterface);
		using SocketType = Network::SocketType;
		using ParentType = EngineMiddleLayerInterface;
		using MessageEventPriority = Network::MessageEventPriority;
		using MessageInterfaceSharedPtr = Network::MessageInterfaceSharedPtr;
		using NetworkMessageEventSharedPtr = Network::NetworkMessageEventSharedPtr;
		using SendSocketManager = Network::SendSocketManager;
		using SendSocketManagerSharedPtr = Network::SendSocketManagerSharedPtr;
		using ConstSendSocketManagerSharedPtr = Network::ConstSendSocketManagerSharedPtr;

	public:
		explicit NetworkManagerInterface(MiddleLayerPlatform middleLayerPlatform);
		~NetworkManagerInterface() noexcept = default;
		NetworkManagerInterface(const NetworkManagerInterface& rhs) noexcept = delete;
		NetworkManagerInterface& operator=(const NetworkManagerInterface& rhs) noexcept = delete;
		NetworkManagerInterface(NetworkManagerInterface&& rhs) noexcept;
		NetworkManagerInterface& operator=(NetworkManagerInterface&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) override;
		bool Initialize() override;
		bool Destroy() override;
		bool Idle(int64_t timeDelta) override;

		void Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message);

		void Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
		void Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
		void Remove(SocketType socketType, int serverID, int64_t messageID);
		void Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);		

		// 渲染中间层处理
		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

		// 按键消息中间层处理
		bool KeyUp(int key, const WindowPoint& point) final;
		bool KeyDown(int key, const WindowPoint& point) final;
		bool SpecialKeyUp(int key, const WindowPoint& point) final;
		bool SpecialKeyDown(int key, const WindowPoint& point) final;

		// 鼠标消息中间层处理
		bool PassiveMotion(const WindowPoint& point) final;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);

	protected:
		SendSocketManagerSharedPtr GetSendSocketManager();
		ConstSendSocketManagerSharedPtr GetSendSocketManager() const;

	private:
		using NetworkManagerImplPtr = std::shared_ptr<NetworkManagerImpl>;

	private:
		virtual void RegisteredMessages();

	private:
		IMPL_TYPE_DECLARE(NetworkManagerInterface);
		NetworkManagerImplPtr m_NetworkManager;
	};

	using NetworkManagerInterfaceSharedPtr = std::shared_ptr<NetworkManagerInterface>;
	using ConstNetworkManagerInterfaceSharedPtr = std::shared_ptr<const NetworkManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H


///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 10:55)

#ifndef FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"
#include "Framework/Helper/MiddleLayerMacro.h"

EXPORT_SHARED_PTR(Framework, NetworkManagerImpl, FRAMEWORK_DEFAULT_DECLARE);
FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    // ����ӿڣ����ⲿʵ����ͨ�ţ����а�����Ϸ��Ӳ���豸��ƥ�����ȡ�
    class FRAMEWORK_DEFAULT_DECLARE NetworkManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using NetworkManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(NetworkManagerInterface);
        using SocketType = Network::SocketType;
        using ParentType = EngineMiddleLayerInterface;
        using MessageEventPriority = Network::MessageEventPriority;
        using MessageInterfaceSharedPtr = Network::MessageInterfaceSharedPtr;
        using NetworkMessageEventSharedPtr = Network::NetworkMessageEventSharedPtr;
        using SendSocketManager = Network::SendSocketManager;
        using SendSocketManagerSharedPtr = Network::SendSocketManagerSharedPtr;
        using ConstSendSocketManagerSharedPtr = Network::ConstSendSocketManagerSharedPtr;

    public:
        NetworkManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);
        ~NetworkManagerInterface() noexcept = default;
        NetworkManagerInterface(const NetworkManagerInterface& rhs) noexcept = delete;
        NetworkManagerInterface& operator=(const NetworkManagerInterface& rhs) noexcept = delete;
        NetworkManagerInterface(NetworkManagerInterface&& rhs) noexcept;
        NetworkManagerInterface& operator=(NetworkManagerInterface&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;
        NODISCARD bool Destroy() override;
        NODISCARD bool Idle(int64_t timeDelta) override;

        void Send(const Network::SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message);

        // ��Ⱦ�м�㴦��
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        // ������Ϣ�м�㴦��
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // �����Ϣ�м�㴦��
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);

    protected:
        NODISCARD SendSocketManagerSharedPtr GetSendSocketManager();
        NODISCARD ConstSendSocketManagerSharedPtr GetSendSocketManager() const;

    private:
        using NetworkManagerImplPtr = std::shared_ptr<NetworkManagerImpl>;

    private:
        virtual void RegisteredMessages();

    private:
        PackageType impl;
        NetworkManagerImplPtr networkManager;
    };

    using NetworkManagerInterfaceSharedPtr = std::shared_ptr<NetworkManagerInterface>;
    using ConstNetworkManagerInterfaceSharedPtr = std::shared_ptr<const NetworkManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

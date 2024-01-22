/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:00)

#ifndef FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(NetworkManagerImpl);
FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

// 网络接口，与外部实体间的通信，其中包括游戏或硬件设备、匹配服务等。
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE NetworkManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using NetworkManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(NetworkManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

        using SocketData = Network::SocketData;
        using SocketType = Network::SocketType;
        using MessageEventPriority = Network::MessageEventPriority;
        using MessageInterfaceSharedPtr = Network::MessageInterfaceSharedPtr;
        using NetworkMessageEventSharedPtr = Network::NetworkMessageEventSharedPtr;

    public:
        NetworkManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;
        NODISCARD bool Destroy() override;
        NODISCARD bool Idle(int64_t timeDelta) override;

        // 渲染中间层处理
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        // 按键消息中间层处理
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // 鼠标消息中间层处理
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic)

    private:
        using NetworkManagerPackageType = CoreTools::NonCopyImpl<NetworkManagerImpl>;

    private:
        virtual void RegisteredMessages();

    private:
        PackageType impl;
        NetworkManagerPackageType networkManager;
    };

    using NetworkManagerInterfaceSharedPtr = std::shared_ptr<NetworkManagerInterface>;
    using ConstNetworkManagerInterfaceSharedPtr = std::shared_ptr<const NetworkManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_NETWORK_MANAGER_INTERFACE_H

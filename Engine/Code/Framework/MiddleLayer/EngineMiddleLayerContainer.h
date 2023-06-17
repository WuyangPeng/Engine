///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H

#include "AudioManagerInterface.h"
#include "CameraSystemsManagerInterface.h"
#include "EngineMiddleLayerInterface.h"
#include "EventManagerInterface.h"
#include "GUIManagerInterface.h"
#include "InputManager.h"
#include "MessageManagerInterface.h"
#include "NetworkManagerInterface.h"
#include "ObjectLogicManagerInterface.h"
#include "PhysicalModellingManagerInterface.h"
#include "RenderingManagerInterface.h"
#include "ResourceManagerInterface.h"
#include "SystemManagerInterface.h"

#include <type_traits>

namespace Framework
{
    // 这个游戏系统管理器分为输入管理器、网络管理器、对象逻辑、物理模拟、
    // 消息管理器、事件管理器、系统管理器、资源管理器、
    // 音频管理器、相机系统、渲染管理器、GUI管理器构成。
    template <typename ApplicationTrait,
              template <typename> class InputManager = InputManager,
              typename NetworkManager = NetworkManagerInterface,
              typename ObjectLogicManager = ObjectLogicManagerInterface,
              typename PhysicalModellingManager = PhysicalModellingManagerInterface,
              typename MessageManager = MessageManagerInterface,
              typename EventManager = EventManagerInterface,
              typename SystemManager = SystemManagerInterface,
              typename ResourceManager = ResourceManagerInterface,
              typename AudioManager = AudioManagerInterface,
              typename CameraSystemsManager = CameraSystemsManagerInterface,
              typename RenderingManager = RenderingManagerInterface,
              typename GUIManager = GUIManagerInterface>
    class EngineMiddleLayerContainer : public EngineMiddleLayerInterface
    {
    public:
        using ClassType = EngineMiddleLayerContainer<ApplicationTrait,
                                                     InputManager,
                                                     NetworkManager,
                                                     ObjectLogicManager,
                                                     PhysicalModellingManager,
                                                     MessageManager,
                                                     EventManager,
                                                     SystemManager,
                                                     ResourceManager,
                                                     AudioManager,
                                                     CameraSystemsManager,
                                                     RenderingManager,
                                                     GUIManager>;
        using ParentType = EngineMiddleLayerInterface;
        using InputManagerType = InputManager<ApplicationTrait>;
        using NetworkManagerType = NetworkManager;
        using ObjectLogicManagerType = ObjectLogicManager;
        using PhysicalModellingManagerType = PhysicalModellingManager;
        using MessageManagerType = MessageManager;
        using EventManagerType = EventManager;
        using SystemManagerType = SystemManager;
        using ResourceManagerType = ResourceManager;
        using AudioManagerType = AudioManager;
        using CameraSystemsManagerType = CameraSystemsManager;
        using RenderingManagerType = RenderingManager;
        using GUIManagerType = GUIManager;
        using MiddleLayerSharedPtr = std::unique_ptr<ClassType>;

    public:
        static_assert(std::is_base_of_v<InputManagerInterface, InputManagerType>);
        static_assert(std::is_base_of_v<NetworkManagerInterface, NetworkManagerType>);
        static_assert(std::is_base_of_v<ObjectLogicManagerInterface, ObjectLogicManagerType>);
        static_assert(std::is_base_of_v<PhysicalModellingManagerInterface, PhysicalModellingManagerType>);
        static_assert(std::is_base_of_v<MessageManagerInterface, MessageManagerType>);
        static_assert(std::is_base_of_v<EventManagerInterface, EventManagerType>);
        static_assert(std::is_base_of_v<SystemManagerInterface, SystemManagerType>);
        static_assert(std::is_base_of_v<ResourceManagerInterface, ResourceManagerType>);
        static_assert(std::is_base_of_v<AudioManagerInterface, AudioManagerType>);
        static_assert(std::is_base_of_v<CameraSystemsManagerInterface, CameraSystemsManagerType>);
        static_assert(std::is_base_of_v<RenderingManagerInterface, RenderingManagerType>);
        static_assert(std::is_base_of_v<GUIManagerInterface, GUIManagerType>);

    public:
        EngineMiddleLayerContainer(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory);
        ~EngineMiddleLayerContainer() noexcept;
        EngineMiddleLayerContainer(const EngineMiddleLayerContainer& rhs) noexcept = delete;
        EngineMiddleLayerContainer& operator=(const EngineMiddleLayerContainer& rhs) noexcept = delete;
        EngineMiddleLayerContainer(EngineMiddleLayerContainer&& rhs) noexcept;
        EngineMiddleLayerContainer& operator=(EngineMiddleLayerContainer&& rhs) noexcept;

        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager) override;
        void SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager) override;
        void SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager) override;
        void SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager) override;
        void SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager) override;
        void SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager) override;
        void SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager) override;
        void SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager) override;
        void SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager) override;
        void SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager) override;
        void SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager) override;
        void SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager) override;

        NODISCARD bool PreCreate() override;
        NODISCARD bool Initialize() override;
        void PreIdle() override;
        void Terminate() override;
        NODISCARD bool Paint() override;
        NODISCARD bool Move(const WindowPoint& point) override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool KeyUp(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) override;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        NODISCARD bool PassiveMotion(const WindowPoint& point) override;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Destroy() override;
        NODISCARD bool Idle(int64_t timeDelta) override;

    private:
        void Init();
        void InitNetworkManager();
        void InitInputManager();
        void InitObjectLogicManager();
        void InitPhysicalModellingManager();
        void InitMessageManager();
        void InitEventManager();
        void InitSystemManager();
        void InitResourceManager();
        void InitAudioManager();
        void InitCameraSystemsManager();
        void InitRenderingManager();
        void InitGUIManager();

        void ResetNetworkManager();
        void ResetInputManager();
        void ResetObjectLogicManager();
        void ResetPhysicalModellingManager();
        void ResetMessageManager();
        void ResetEventManager();
        void ResetSystemManager();
        void ResetResourceManager();
        void ResetAudioManager();
        void ResetCameraSystemsManager();
        void ResetRenderingManager();
        void ResetGUIManager();

        bool InitSystemEngineInterface();

        void SetEngineManagerNullptr();

    private:
        NetworkManagerInterfaceSharedPtr network;
        InputManagerInterfaceSharedPtr input;
        ObjectLogicManagerInterfaceSharedPtr objectLogic;
        PhysicalModellingManagerInterfaceSharedPtr physicalModelling;
        MessageManagerInterfaceSharedPtr message;
        EventManagerInterfaceSharedPtr event;
        SystemManagerInterfaceSharedPtr system;
        ResourceManagerInterfaceSharedPtr resource;
        AudioManagerInterfaceSharedPtr audio;
        CameraSystemsManagerInterfaceSharedPtr cameraSystems;
        RenderingManagerInterfaceSharedPtr rendering;
        GUIManagerInterfaceSharedPtr gui;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H

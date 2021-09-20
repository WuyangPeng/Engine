// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerInterface.h"
#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE EngineMiddleLayerInterface : public MiddleLayerInterface
    {
    public:
        using ClassType = EngineMiddleLayerInterface;
        using ParentType = MiddleLayerInterface;

    public:
        explicit EngineMiddleLayerInterface(MiddleLayerPlatform modelViewController) noexcept;
        ~EngineMiddleLayerInterface() noexcept = default;
        EngineMiddleLayerInterface(const EngineMiddleLayerInterface& rhs) noexcept = delete;
        virtual EngineMiddleLayerInterface& operator=(const EngineMiddleLayerInterface& rhs) noexcept = delete;
        EngineMiddleLayerInterface(EngineMiddleLayerInterface&& rhs) noexcept;
        virtual EngineMiddleLayerInterface& operator=(EngineMiddleLayerInterface&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual void SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager);
        virtual void SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager);
        virtual void SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager);
        virtual void SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager);
        virtual void SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager);
        virtual void SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager);
        virtual void SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager);
        virtual void SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager);
        virtual void SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager);
        virtual void SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager);
        virtual void SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager);
        virtual void SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager);
        virtual void SetEngineManager(const MiddleLayerInterfaceSharedPtr& engineManager);

    protected:
        virtual const MiddleLayerInterfaceSharedPtr GetNetworkManager();
        virtual const MiddleLayerInterfaceSharedPtr GetInputManager();
        virtual const MiddleLayerInterfaceSharedPtr GetObjectLogicManager();
        virtual const MiddleLayerInterfaceSharedPtr GetPhysicalModellingManager();
        virtual const MiddleLayerInterfaceSharedPtr GetMessageManager();
        virtual const MiddleLayerInterfaceSharedPtr GetEventManager();
        virtual const MiddleLayerInterfaceSharedPtr GetSystemManager();
        virtual const MiddleLayerInterfaceSharedPtr GetResourceManager();
        virtual const MiddleLayerInterfaceSharedPtr GetAudioManager();
        virtual const MiddleLayerInterfaceSharedPtr GetCameraSystemsManager();
        virtual const MiddleLayerInterfaceSharedPtr GetRenderingManager();
        virtual const MiddleLayerInterfaceSharedPtr GetGUIManager();
        virtual const MiddleLayerInterfaceSharedPtr GetEngineManager();

        virtual const ConstMiddleLayerInterfaceSharedPtr GetNetworkManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetInputManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetObjectLogicManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetPhysicalModellingManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetMessageManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetEventManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetSystemManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetResourceManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetAudioManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetCameraSystemsManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetRenderingManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetGUIManager() const;
        virtual const ConstMiddleLayerInterfaceSharedPtr GetEngineManager() const;
    };

    using EngineMiddleLayerInterfaceSharedPtr = std::shared_ptr<EngineMiddleLayerInterface>;
    using ConstEngineMiddleLayerInterfaceSharedPtr = std::shared_ptr<const EngineMiddleLayerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H

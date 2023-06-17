///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerInterface.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"

#include <memory>

namespace Framework
{
    // 引擎中间层接口类，基类提供虚函数抛出异常的实现。
    class FRAMEWORK_DEFAULT_DECLARE EngineMiddleLayerInterface : public MiddleLayerInterface
    {
    public:
        using ClassType = EngineMiddleLayerInterface;
        using ParentType = MiddleLayerInterface;
        using MiddleLayerSharedPtr = std::shared_ptr<ClassType>;

    protected:
        EngineMiddleLayerInterface(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory) noexcept;

    public:
        EngineMiddleLayerInterface(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept;

        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

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
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetNetworkManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetInputManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetObjectLogicManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetPhysicalModellingManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetMessageManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetEventManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetSystemManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetResourceManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetAudioManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetCameraSystemsManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetRenderingManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetGUIManager();
        NODISCARD virtual MiddleLayerInterfaceSharedPtr GetEngineManager();

        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetNetworkManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetInputManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetObjectLogicManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetPhysicalModellingManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetMessageManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetEventManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetSystemManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetResourceManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetAudioManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetCameraSystemsManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetRenderingManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetGUIManager() const;
        NODISCARD virtual ConstMiddleLayerInterfaceSharedPtr GetEngineManager() const;

    protected:
        SYSTEM_NORETURN static void ThrowException();
    };

    using EngineMiddleLayerInterfaceSharedPtr = std::shared_ptr<EngineMiddleLayerInterface>;
    using ConstEngineMiddleLayerInterfaceSharedPtr = std::shared_ptr<const EngineMiddleLayerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H

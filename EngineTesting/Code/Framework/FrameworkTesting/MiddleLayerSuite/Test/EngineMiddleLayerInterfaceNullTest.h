///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/10 14:14)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_NULL_TEST_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_NULL_TEST_H

#include "Framework/MiddleLayer/EngineMiddleLayerInterface.h"

namespace Framework
{
    class EngineMiddleLayerInterfaceNullTest : public EngineMiddleLayerInterface
    {
    public:
        using ClassType = EngineMiddleLayerInterfaceNullTest;
        using ParentType = EngineMiddleLayerInterface;
        using MiddleLayerSharedPtr = std::shared_ptr<ClassType>;

    public:
        EngineMiddleLayerInterfaceNullTest(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept;

        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetNetworkManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetInputManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetObjectLogicManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetPhysicalModellingManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetMessageManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetEventManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetSystemManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetResourceManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetAudioManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetCameraSystemsManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetRenderingManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetGUIManager() override;
        MAYBE_NULLPTR MiddleLayerInterfaceSharedPtr GetEngineManager() override;

        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetNetworkManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetInputManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetObjectLogicManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetPhysicalModellingManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetMessageManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetEventManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetSystemManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetResourceManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetAudioManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetCameraSystemsManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetRenderingManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetGUIManager() const noexcept override;
        MAYBE_NULLPTR ConstMiddleLayerInterfaceSharedPtr GetEngineManager() const noexcept override;
    };

    using EngineMiddleLayerInterfaceNullTestSharedPtr = std::shared_ptr<EngineMiddleLayerInterfaceNullTest>;
    using ConstEngineMiddleLayerInterfaceNullTestSharedPtr = std::shared_ptr<const EngineMiddleLayerInterfaceNullTest>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_NULL_TEST_H
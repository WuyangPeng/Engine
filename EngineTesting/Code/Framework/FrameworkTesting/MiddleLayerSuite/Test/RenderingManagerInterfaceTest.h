///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MIDDLE_LAYER_INTERFACE_TEST_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MIDDLE_LAYER_INTERFACE_TEST_H

#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace Framework
{
    class RenderingManagerInterfaceTest final : public RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManagerInterfaceTest;
        using ParentType = RenderingManagerInterface;

        using MiddleLayerSharedPtr = std::shared_ptr<ClassType>;

    public:
        RenderingManagerInterfaceTest(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD MiddleLayerInterfaceSharedPtr GetNetworkManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetInputManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetObjectLogicManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetPhysicalModellingManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetMessageManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetEventManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetSystemManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetResourceManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetAudioManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetCameraSystemsManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetRenderingManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetGUIManager() override;
        NODISCARD MiddleLayerInterfaceSharedPtr GetEngineManager() override;

        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetNetworkManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetInputManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetObjectLogicManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetPhysicalModellingManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetMessageManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetEventManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetSystemManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetResourceManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetAudioManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetCameraSystemsManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetRenderingManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetGUIManager() const override;
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetEngineManager() const override;

        NODISCARD RendererSharedPtr GetRendererSharedPtr();
        NODISCARD ConstRendererSharedPtr GetRendererSharedPtr() const;
    };

    using RenderingManagerInterfaceTestSharedPtr = std::shared_ptr<RenderingManagerInterfaceTest>;
    using ConstRenderingManagerInterfaceTestSharedPtr = std::shared_ptr<const RenderingManagerInterfaceTest>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MIDDLE_LAYER_INTERFACE_TEST_H
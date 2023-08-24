///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/07 10:57)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

#include "ModelViewControllerMiddleLayer.h"

#include <type_traits>

namespace Framework
{
    template <typename ApplicationTrait,
              typename ModelMiddleLayer,
              typename ViewMiddleLayer,
              template <typename> class ControllerMiddleLayer>
    class ModelViewControllerMiddleLayerContainer final : public MiddleLayerInterface
    {
    public:
        using ControllerMiddleLayerType = ControllerMiddleLayer<ApplicationTrait>;

        static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ModelMiddleLayer>);
        static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ViewMiddleLayer>);
        static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ControllerMiddleLayer<ApplicationTrait>>);

        using ClassType = ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>;
        using ParentType = MiddleLayerInterface;

    public:
        ModelViewControllerMiddleLayerContainer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);
        ~ModelViewControllerMiddleLayerContainer() noexcept = default;
        ModelViewControllerMiddleLayerContainer(const ModelViewControllerMiddleLayerContainer& rhs) noexcept = delete;
        ModelViewControllerMiddleLayerContainer& operator=(const ModelViewControllerMiddleLayerContainer& rhs) noexcept = delete;
        ModelViewControllerMiddleLayerContainer(ModelViewControllerMiddleLayerContainer&& rhs) noexcept;
        ModelViewControllerMiddleLayerContainer& operator=(ModelViewControllerMiddleLayerContainer&& rhs) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool PreCreate() override;
        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;

        NODISCARD bool Destroy() override;
        void Terminate() override;

        void PreIdle() override;
        NODISCARD bool Idle(int64_t timeDelta) override;

        NODISCARD bool Paint() override;
        NODISCARD bool Move(const WindowPoint& point) override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        NODISCARD bool KeyUp(int key, const WindowPoint& point) override;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) override;

        NODISCARD bool PassiveMotion(const WindowPoint& point) override;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;

    private:
        ModelViewControllerMiddleLayerSharedPtr modelMiddleLayer;
        ModelViewControllerMiddleLayerSharedPtr viewMiddleLayer;
        ModelViewControllerMiddleLayerSharedPtr controllerMiddleLayer;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

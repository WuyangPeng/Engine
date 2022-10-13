///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 10:51)

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
        static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ModelMiddleLayer>);
        static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ViewMiddleLayer>);
        static_assert(std::is_base_of_v<ModelViewControllerMiddleLayer, ControllerMiddleLayer<ApplicationTrait>>);

    public:
        using ClassType = ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>;
        using ParentType = MiddleLayerInterface;
        using ClassShareType = CoreTools::NonCopyClasses;
        using ModelMiddleLayerType = ModelMiddleLayer;
        using ViewMiddleLayerType = ViewMiddleLayer;
        using ControllerMiddleLayerType = ControllerMiddleLayer<ApplicationTrait>;
        using MiddleLayerSharedPtr = ModelViewControllerMiddleLayerSharedPtr;
        using MiddleLayerInterfaceSharedPtr = std::unique_ptr<ClassType>;

    public:
        ModelViewControllerMiddleLayerContainer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);
        ~ModelViewControllerMiddleLayerContainer() noexcept = default;
        ModelViewControllerMiddleLayerContainer(const ModelViewControllerMiddleLayerContainer& rhs) noexcept = delete;
        ModelViewControllerMiddleLayerContainer& operator=(const ModelViewControllerMiddleLayerContainer& rhs) noexcept = delete;
        ModelViewControllerMiddleLayerContainer(ModelViewControllerMiddleLayerContainer&& rhs) noexcept;
        ModelViewControllerMiddleLayerContainer& operator=(ModelViewControllerMiddleLayerContainer&& rhs) noexcept;

        NODISCARD static MiddleLayerInterfaceSharedPtr Create(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool PreCreate() final;
        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) final;
        NODISCARD bool Initialize() final;

        NODISCARD bool Destroy() final;
        void Terminate() final;

        void PreIdle() final;
        NODISCARD bool Idle(int64_t timeDelta) final;

        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

    private:
        MiddleLayerSharedPtr modelMiddleLayer;
        MiddleLayerSharedPtr viewMiddleLayer;
        MiddleLayerSharedPtr controllerMiddleLayer;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_H

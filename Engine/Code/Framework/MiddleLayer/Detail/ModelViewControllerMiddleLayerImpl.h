///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ModelViewControllerMiddleLayerImpl
    {
    public:
        using ClassType = ModelViewControllerMiddleLayerImpl;
        using MiddleLayerWeakPtr = std::weak_ptr<MiddleLayerInterface>;
        using MiddleLayerSharedPtr = MiddleLayerInterfaceSharedPtr;
        using ConstMiddleLayerSharedPtr = ConstMiddleLayerInterfaceSharedPtr;

    public:
        ModelViewControllerMiddleLayerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetModelMiddleLayer(const MiddleLayerSharedPtr& modelMiddleLayer) noexcept;
        void SetViewMiddleLayer(const MiddleLayerSharedPtr& viewMiddleLayer) noexcept;
        void SetControllerMiddleLayer(const MiddleLayerSharedPtr& controllerMiddleLayer) noexcept;

        NODISCARD MiddleLayerSharedPtr GetModelMiddleLayer() noexcept;
        NODISCARD MiddleLayerSharedPtr GetViewMiddleLayer() noexcept;
        NODISCARD MiddleLayerSharedPtr GetControllerMiddleLayer() noexcept;

        NODISCARD ConstMiddleLayerSharedPtr GetConstModelMiddleLayer() const noexcept;
        NODISCARD ConstMiddleLayerSharedPtr GetConstViewMiddleLayer() const noexcept;
        NODISCARD ConstMiddleLayerSharedPtr GetConstControllerMiddleLayer() const noexcept;

    private:
        MiddleLayerWeakPtr model;
        MiddleLayerWeakPtr view;
        MiddleLayerWeakPtr controller;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H

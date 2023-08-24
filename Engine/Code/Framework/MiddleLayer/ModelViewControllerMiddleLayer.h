///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 17:45)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(ModelViewControllerMiddleLayerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ModelViewControllerMiddleLayer : public MiddleLayerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(ModelViewControllerMiddleLayer);
        using ParentType = MiddleLayerInterface;

    public:
        ModelViewControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetModelMiddleLayer(const MiddleLayerSharedPtr& modelMiddleLayer) noexcept;
        void SetViewMiddleLayer(const MiddleLayerSharedPtr& viewMiddleLayer) noexcept;
        void SetControllerMiddleLayer(const MiddleLayerSharedPtr& controllerMiddleLayer) noexcept;

    protected:
        NODISCARD MiddleLayerSharedPtr GetModelMiddleLayer() noexcept;
        NODISCARD MiddleLayerSharedPtr GetViewMiddleLayer() noexcept;
        NODISCARD MiddleLayerSharedPtr GetControllerMiddleLayer() noexcept;

        NODISCARD ConstMiddleLayerSharedPtr GetConstModelMiddleLayer() const noexcept;
        NODISCARD ConstMiddleLayerSharedPtr GetConstViewMiddleLayer() const noexcept;
        NODISCARD ConstMiddleLayerSharedPtr GetConstControllerMiddleLayer() const noexcept;

    private:
        PackageType impl;
    };

    using ModelViewControllerMiddleLayerSharedPtr = std::shared_ptr<ModelViewControllerMiddleLayer>;
    using ConstModelViewControllerMiddleLayerSharedPtr = std::shared_ptr<const ModelViewControllerMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 10:39)

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
        using MiddleLayerSharedPtr = MiddleLayerInterfaceSharedPtr;
        using ConstMiddleLayerSharedPtr = ConstMiddleLayerInterfaceSharedPtr;

    public:
        explicit ModelViewControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform);
        ~ModelViewControllerMiddleLayer() noexcept = default;
        ModelViewControllerMiddleLayer(const ModelViewControllerMiddleLayer& rhs) noexcept = delete;
        virtual ModelViewControllerMiddleLayer& operator=(const ModelViewControllerMiddleLayer& rhs) noexcept = delete;
        ModelViewControllerMiddleLayer(ModelViewControllerMiddleLayer&& rhs) noexcept;
        virtual ModelViewControllerMiddleLayer& operator=(ModelViewControllerMiddleLayer&& rhs) noexcept;

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

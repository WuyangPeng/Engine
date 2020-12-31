// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerInterface.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(ModelViewControllerMiddleLayerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ModelViewControllerMiddleLayer : public MiddleLayerInterface
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ModelViewControllerMiddleLayer);
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
        const MiddleLayerSharedPtr GetModelMiddleLayer() noexcept;
        const MiddleLayerSharedPtr GetViewMiddleLayer() noexcept;
        const MiddleLayerSharedPtr GetControllerMiddleLayer() noexcept;

        const ConstMiddleLayerSharedPtr GetConstModelMiddleLayer() const noexcept;
        const ConstMiddleLayerSharedPtr GetConstViewMiddleLayer() const noexcept;
        const ConstMiddleLayerSharedPtr GetConstControllerMiddleLayer() const noexcept;

    private:
        IMPL_TYPE_DECLARE(ModelViewControllerMiddleLayer);
    };

    using ModelViewControllerMiddleLayerSharedPtr = std::shared_ptr<ModelViewControllerMiddleLayer>;
    using ConstModelViewControllerMiddleLayerSharedPtr = std::shared_ptr<const ModelViewControllerMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H

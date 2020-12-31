// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.3.0.1 (2020/05/21 14:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(ModelMiddleLayerImpl);

namespace Framework
{
    // 模型层类
    class FRAMEWORK_DEFAULT_DECLARE ModelMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ModelMiddleLayer);
        using ParentType = ModelViewControllerMiddleLayer;

    public:
        explicit ModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform);
        ~ModelMiddleLayer() noexcept = default;
        ModelMiddleLayer(const ModelMiddleLayer& rhs) noexcept = delete;
        virtual ModelMiddleLayer& operator=(const ModelMiddleLayer& rhs) noexcept = delete;
        ModelMiddleLayer(ModelMiddleLayer&& rhs) noexcept;
        virtual ModelMiddleLayer& operator=(ModelMiddleLayer&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Idle(int64_t timeDelta) override;

        double GetFrameRate() const;
        std::string GetFrameRateMessage() const;

        void ResetTime();
        void MeasureTime();
        void UpdateFrameCount();

        // 渲染中间层处理
        bool Paint() final;
        bool Move(const WindowPoint& point) final;
        bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        // 按键消息中间层处理
        bool KeyUp(int key, const WindowPoint& point) final;
        bool KeyDown(int key, const WindowPoint& point) final;
        bool SpecialKeyUp(int key, const WindowPoint& point) final;
        bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // 鼠标消息中间层处理
        bool PassiveMotion(const WindowPoint& point) final;
        bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

    private:
        IMPL_TYPE_DECLARE(ModelMiddleLayer);
    };

    using ModelMiddleLayerSharedPtr = std::shared_ptr<ModelMiddleLayer>;
    using ConstModelMiddleLayerSharedPtr = std::shared_ptr<const ModelMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H

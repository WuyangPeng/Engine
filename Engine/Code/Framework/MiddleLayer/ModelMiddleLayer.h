///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 17:05)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

FRAMEWORK_NON_COPY_EXPORT_IMPL(ModelMiddleLayerImpl);

namespace Framework
{
    // ģ�Ͳ���
    class FRAMEWORK_DEFAULT_DECLARE ModelMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        NON_COPY_TYPE_DECLARE(ModelMiddleLayer);
        using ParentType = ModelViewControllerMiddleLayer;

    public:
        ModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);
        ~ModelMiddleLayer() noexcept = default;
        ModelMiddleLayer(const ModelMiddleLayer& rhs) noexcept = delete;
        virtual ModelMiddleLayer& operator=(const ModelMiddleLayer& rhs) noexcept = delete;
        ModelMiddleLayer(ModelMiddleLayer&& rhs) noexcept;
        virtual ModelMiddleLayer& operator=(ModelMiddleLayer&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Idle(int64_t timeDelta) override;

        NODISCARD double GetFrameRate() const;
        NODISCARD std::string GetFrameRateMessage() const;

        void ResetTime();
        void MeasureTime();
        void UpdateFrameCount();

        // ��Ⱦ�м�㴦��
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        // ������Ϣ�м�㴦��
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // �����Ϣ�м�㴦��
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

    private:
        PackageType impl;
    };

    using ModelMiddleLayerSharedPtr = std::shared_ptr<ModelMiddleLayer>;
    using ConstModelMiddleLayerSharedPtr = std::shared_ptr<const ModelMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H

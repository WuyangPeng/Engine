///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

#include "ModelViewControllerMiddleLayer.h"

namespace Framework
{
    // ���Ʋ��������
    template <typename ApplicationTrait>
    class ControllerMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        using ClassType = ControllerMiddleLayer<ApplicationTrait>;
        using ParentType = ModelViewControllerMiddleLayer;

    public:
        explicit ControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;

        // ��Ⱦ�м�㴦��
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

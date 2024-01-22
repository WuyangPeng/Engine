/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:59)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"

// 控制层类的声明
namespace Framework
{
    template <typename ApplicationTrait>
    class ControllerMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        using ClassType = ControllerMiddleLayer<ApplicationTrait>;
        using ParentType = ModelViewControllerMiddleLayer;

    public:
        ControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;

        // 渲染中间层处理
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

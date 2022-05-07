///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

#include "ModelViewControllerMiddleLayer.h"

namespace Framework
{
    // 控制层类的声明
    template <typename ApplicationTrait>
    class ControllerMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        using ClassType = ControllerMiddleLayer<ApplicationTrait>;
        using ParentType = ModelViewControllerMiddleLayer;

    public:
        explicit ControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;

        // 渲染中间层处理
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

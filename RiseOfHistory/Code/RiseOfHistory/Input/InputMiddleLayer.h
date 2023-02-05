///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.2 (2022/09/11 22:02)

#ifndef RISE_OF_HISTORY_INPUT_MIDDLE_LAYER_H
#define RISE_OF_HISTORY_INPUT_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/InputManager.h"

namespace RiseOfHistory
{
    template <typename ApplicationTrait>
    class InputMiddleLayer final : public Framework::InputManager<ApplicationTrait>
    {
    public:
        using ClassType = InputMiddleLayer<ApplicationTrait>;
        using ParentType = Framework::InputManager<ApplicationTrait>;

        using WindowPoint = Framework::WindowPoint;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        InputMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;

    private:
        int lastKey;
        int keyCount;
    };
}

#endif  // RISE_OF_HISTORY_INPUT_MIDDLE_LAYER_H

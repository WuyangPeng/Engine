///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 14:01)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/InputManager.h"

namespace ThreadingCoreRenderEngineAssist
{
    template <typename ApplicationTrait>
    class InputMiddleLayer final : public Framework::InputManager<ApplicationTrait>
    {
    public:
        using ClassType = InputMiddleLayer<ApplicationTrait>;
        using ParentType = Framework::InputManager<ApplicationTrait>;
        using WindowPoint = Framework::WindowPoint;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;

    public:
        explicit InputMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;

    private:
        int lastKey;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_H

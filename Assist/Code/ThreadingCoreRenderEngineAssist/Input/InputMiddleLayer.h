///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 10:58)

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

        [[nodiscard]] bool KeyDown(int key, const WindowPoint& point) final;

    private:
        int lastKey;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_H

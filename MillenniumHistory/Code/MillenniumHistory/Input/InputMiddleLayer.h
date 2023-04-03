///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:32)

#ifndef MILLENNIUM_HISTORY_INPUT_MIDDLE_LAYER_H
#define MILLENNIUM_HISTORY_INPUT_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/InputManager.h"

namespace MillenniumHistory
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

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;

    private:
        int lastKey;
        int keyCount;
    };
}

#endif  // MILLENNIUM_HISTORY_INPUT_MIDDLE_LAYER_H

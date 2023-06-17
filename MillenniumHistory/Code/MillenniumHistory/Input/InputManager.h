///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/15 23:02)

#ifndef MILLENNIUM_HISTORY_INPUT_MANAGER_H
#define MILLENNIUM_HISTORY_INPUT_MANAGER_H

#include "Framework/MiddleLayer/InputManager.h"

namespace MillenniumHistory
{
    template <typename ApplicationTrait>
    class InputManager final : public Framework::InputManager<ApplicationTrait>
    {
    public:
        using ClassType = InputManager<ApplicationTrait>;
        using ParentType = Framework::InputManager<ApplicationTrait>;

        using WindowPoint = Framework::WindowPoint;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;

    private:
        static constexpr auto keyCode0 = ApplicationTrait::KeyIdentifiers::keyCode0;
        static constexpr auto keyCode9 = ApplicationTrait::KeyIdentifiers::keyCode9;

    private:
        void KeyDown(int key);

    private:
        int lastKey;
        int keyCount;
    };
}

#endif  // MILLENNIUM_HISTORY_INPUT_MANAGER_H

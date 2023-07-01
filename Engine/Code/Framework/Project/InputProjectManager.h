///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 15:09)
///
///	��Ԫ���ԣ�Pass

#ifndef FRAMEWORK_PROJECT_INPUT_PROJECT_MANAGER_H
#define FRAMEWORK_PROJECT_INPUT_PROJECT_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/InputManager.h"

namespace Framework
{
    template <typename ApplicationTrait>
    class InputProjectManager : public InputManager<ApplicationTrait>
    {
    public:
        using ClassType = InputProjectManager<ApplicationTrait>;
        using ParentType = InputManager<ApplicationTrait>;

    public:
        InputProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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

#endif  // FRAMEWORK_PROJECT_INPUT_PROJECT_MANAGER_H

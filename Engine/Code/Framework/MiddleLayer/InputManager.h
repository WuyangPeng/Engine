/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:59)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_H

#include "InputManagerInterface.h"

namespace Framework
{
    template <typename ApplicationTrait>
    class InputManager : public InputManagerInterface
    {
    public:
        using ClassType = InputManager<ApplicationTrait>;
        using ParentType = InputManagerInterface;

    public:
        InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

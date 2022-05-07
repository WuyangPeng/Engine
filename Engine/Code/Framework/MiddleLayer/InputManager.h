///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 17:02)

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
        explicit InputManager(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

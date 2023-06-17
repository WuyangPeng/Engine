///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:21)

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
        explicit InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

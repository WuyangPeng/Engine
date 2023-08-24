///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:20)

#ifndef FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class HelperMiddleLayer
    {
        Input,
        ObjectLogic,
        Message,
        Event,
        Resource,
        Audio,
        CameraSystems,
        Rendering,
        Engine,

        Count,
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_FLAGS_H
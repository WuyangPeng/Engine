///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:10)

#ifndef FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class SystemMiddleLayer
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

#endif  // FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H
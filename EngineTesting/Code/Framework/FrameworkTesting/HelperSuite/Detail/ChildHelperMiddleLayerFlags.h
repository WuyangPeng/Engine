///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:06)

#ifndef FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_FLAGS_H
#define FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class ChildHelperMiddleLayer
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

#endif  // FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_FLAGS_H
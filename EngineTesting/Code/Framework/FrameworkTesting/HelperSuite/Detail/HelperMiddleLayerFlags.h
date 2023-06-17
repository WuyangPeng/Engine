///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:17)

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
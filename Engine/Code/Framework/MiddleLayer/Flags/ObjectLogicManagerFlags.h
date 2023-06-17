///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:20)

#ifndef FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class ObjectLogicMiddleLayer
    {
        Input,
        Network,
        PhysicalModelling,
        Message,
        System,

        Count,
    };
}

#endif  // FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:58)

#ifndef FRAMEWORK_RESOURCE_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_RESOURCE_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class ResourceMiddleLayer
    {
        System,
        Audio,
        Rendering,
        GUI,

        Count,
    };
}

#endif  // FRAMEWORK_RESOURCE_MANAGER_INTERFACE_FLAGS_H
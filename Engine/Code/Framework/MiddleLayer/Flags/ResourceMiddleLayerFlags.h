///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:20)

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
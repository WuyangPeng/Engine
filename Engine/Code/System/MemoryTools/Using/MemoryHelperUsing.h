///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:00)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_USING_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using MemoryResourceNotificationType = MEMORY_RESOURCE_NOTIFICATION_TYPE;

#else  // !SYSTEM_PLATFORM_WIN32

    enum MemoryResourceNotificationType
    {
        LowMemoryResourceNotification,
        HighMemoryResourceNotification,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_USING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/19 11:44)

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
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:43)

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
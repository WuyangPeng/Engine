///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/03 12:42)

#ifndef SYSTEM_WINDOWS_WINDOWS_PROCESS_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_PROCESS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class PeekMessageOptions
    {
        NoRemove = PM_NOREMOVE,
        Remove = PM_REMOVE,
        Noyield = PM_NOYIELD,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class PeekMessageOptions
    {
        NoRemove = 0x0000,
        Remove = 0x0001,
        Noyield = 0x0002,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_PROCESS_FLAGS_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 16:14)

#ifndef SYSTEM_WINDOWS_WINDOWS_PROCESS_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_PROCESS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class PeekMessageOptions : int8_t
    {
        NoRemove = PM_NOREMOVE,
        Remove = PM_REMOVE,
        NoYield = PM_NOYIELD,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class PeekMessageOptions : int8_t
    {
        NoRemove = 0x0000,
        Remove = 0x0001,
        NoYield = 0x0002,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_PROCESS_FLAGS_H

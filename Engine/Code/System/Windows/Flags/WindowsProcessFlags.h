///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 11:37)

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

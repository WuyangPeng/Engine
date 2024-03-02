/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 10:24)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_FLAGS_H
#define SYSTEM_THREADING_CRITICAL_SECTION_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class CriticalSectionInfo
    {
        Default = 0x00000000,
        NoDebugInfo = CRITICAL_SECTION_NO_DEBUG_INFO,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class CriticalSectionInfo
    {
        Default = 0x00000000,
        NoDebugInfo = 0x01000000,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_CRITICAL_SECTION_FLAGS_H
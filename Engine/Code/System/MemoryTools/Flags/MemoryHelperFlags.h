//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:58)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WorkingSetSizesQuotaLimits
    {
        HardwsMinEnable = QUOTA_LIMITS_HARDWS_MIN_ENABLE,
        HardwsMinDisable = QUOTA_LIMITS_HARDWS_MIN_DISABLE,
        HardwsMaxEnable = QUOTA_LIMITS_HARDWS_MAX_ENABLE,
        HardwsMaxDisable = QUOTA_LIMITS_HARDWS_MAX_DISABLE,
        UseDefaultLimits = QUOTA_LIMITS_USE_DEFAULT_LIMITS,
    };

    enum class FileCache
    {
        MaxHardEnable = FILE_CACHE_MAX_HARD_ENABLE,
        MaxHardDisable = FILE_CACHE_MAX_HARD_DISABLE,
        MinHardEnable = FILE_CACHE_MIN_HARD_ENABLE,
        MinHardDisable = FILE_CACHE_MIN_HARD_DISABLE,
    };

    enum class WriteWatch
    {
        Default = 0x00,
        Reset = WRITE_WATCH_FLAG_RESET,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WorkingSetSizesQuotaLimits
    {
        HardwsMinEnable = 0x00000001,
        HardwsMinDisable = 0x00000002,
        HardwsMaxEnable = 0x00000004,
        HardwsMaxDisable = 0x00000008,
        UseDefaultLimits = 0x00000010,
    };

    enum class FileCache
    {
        MaxHardEnable = 0x00000001,
        MaxHardDisable = 0x00000002,
        MinHardEnable = 0x00000004,
        MinHardDisable = 0x00000008,
    };

    enum class WriteWatch
    {
        Default = 0x00,
        Reset = 0x01,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_FLAGS_H

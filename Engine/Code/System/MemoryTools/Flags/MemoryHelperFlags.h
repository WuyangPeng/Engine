///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/18 18:44)

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

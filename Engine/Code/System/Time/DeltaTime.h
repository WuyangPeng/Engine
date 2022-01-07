///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 16:39)

#ifndef SYSTEM_TIME_DELTA_TIME_H
#define SYSTEM_TIME_DELTA_TIME_H

#include "System/SystemDll.h"

#include "Using/DeltaTimeUsing.h"
#include "Data/DeltaTimeValueData.h"

namespace System
{
    // 获取当前时间
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInSeconds(const DeltaTimeValueData& deltaTime) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInMicroseconds() noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInSeconds() noexcept;

    // 暂停控制台
    SYSTEM_DEFAULT_DECLARE void SystemPause() noexcept;
}

#endif  // SYSTEM_TIME_DELTA_TIME_H

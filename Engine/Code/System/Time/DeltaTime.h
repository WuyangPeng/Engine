//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:49)

#ifndef SYSTEM_TIME_DELTA_TIME_H
#define SYSTEM_TIME_DELTA_TIME_H

#include "System/SystemDll.h"

#include "Using/DeltaTimeUsing.h"
#include "Data/DeltaTimeValueData.h"

namespace System
{
    // 获取当前时间
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE int64_t GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE int64_t GetTimeInSeconds(const DeltaTimeValueData& deltaTime) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE int64_t GetTimeInMicroseconds() noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE int64_t GetTimeInSeconds() noexcept;

    // 暂停控制台
    SYSTEM_DEFAULT_DECLARE void SystemPause() noexcept;
}

#endif  // SYSTEM_TIME_DELTA_TIME_H

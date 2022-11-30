///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:07)

#ifndef SYSTEM_TIME_CURRENT_DELTA_TIME_H
#define SYSTEM_TIME_CURRENT_DELTA_TIME_H

#include "System/SystemDll.h"

#include "DeltaTimeValueData.h"
#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
    // 获取当前时间
    class SYSTEM_DEFAULT_DECLARE CurrentDeltaTime final
    {
    public:
        using ClassType = CurrentDeltaTime;

    public:
        CurrentDeltaTime() noexcept;

        NODISCARD const DeltaTimeValueData GetDeltaTimeValueData() const noexcept;

    public:
        DeltaTimeB currentTime;
    };
}

#endif  // SYSTEM_TIME_CURRENT_DELTA_TIME_H
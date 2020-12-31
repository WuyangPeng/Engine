//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:47)

#ifndef SYSTEM_TIME_DELTA_TIME_VALUE_H
#define SYSTEM_TIME_DELTA_TIME_VALUE_H

#include "System/SystemDll.h"

#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
    // 时间差值数据
    class SYSTEM_DEFAULT_DECLARE DeltaTimeValueData
    {
    public:
        using ClassType = DeltaTimeValueData;

    public:
        DeltaTimeValueData() noexcept;
        DeltaTimeValueData(int64_t second, int32_t microsecond) noexcept;
        explicit DeltaTimeValueData(const DeltaTimeValue& deltaTimeValue) noexcept;

        [[nodiscard]] const DeltaTimeValue GetDeltaTimeValue() const noexcept;
        void SetValue(int64_t second, int32_t microsecond) noexcept;
        [[nodiscard]] int64_t GetSecond() const noexcept;
        [[nodiscard]] int32_t GetMicrosecond() const noexcept;

        void Correction() noexcept;

    public:
        DeltaTimeValue m_DeltaTimeValue;
    };

    [[nodiscard]] DeltaTimeValueData SYSTEM_DEFAULT_DECLARE operator-(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept;
}

#endif  // SYSTEM_TIME_DELTA_TIME_VALUE_H
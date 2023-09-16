///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 09:09)

#ifndef SYSTEM_TIME_DELTA_TIME_VALUE_H
#define SYSTEM_TIME_DELTA_TIME_VALUE_H

#include "System/SystemDll.h"

#include "System/Time/Using/DeltaTimeUsing.h"

// ʱ���ֵ����
namespace System
{
    class SYSTEM_DEFAULT_DECLARE DeltaTimeValueData final
    {
    public:
        using ClassType = DeltaTimeValueData;

    public:
        DeltaTimeValueData() noexcept = default;
        DeltaTimeValueData(int64_t second, int32_t microsecond) noexcept;
        explicit DeltaTimeValueData(const DeltaTimeValue& deltaTimeValue) noexcept;

        NODISCARD DeltaTimeValue GetDeltaTimeValue() const noexcept;
        void SetValue(int64_t second, int32_t microsecond) noexcept;
        NODISCARD int64_t GetSecond() const noexcept;
        NODISCARD int32_t GetMicrosecond() const noexcept;

        void Correction() noexcept;

    public:
        DeltaTimeValue deltaTimeValue;
    };

    NODISCARD DeltaTimeValueData SYSTEM_DEFAULT_DECLARE operator-(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept;
}

#endif  // SYSTEM_TIME_DELTA_TIME_VALUE_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 14:59)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Time/CustomTime.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE PerformanceMeasurementsImpl
    {
    public:
        using ClassType = PerformanceMeasurementsImpl;

        using CustomTime = CoreTools::CustomTime;

    public:
        explicit PerformanceMeasurementsImpl(int maxTimer) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD double GetFrameRate() const;
        NODISCARD std::string GetFrameRateMessage() const;

        void ResetTime() noexcept;
        void MeasureTime() noexcept;
        void UpdateFrameCount() noexcept;

    private:
        CustomTime customTime;
        int64_t accumulatedTime;
        int frameCount;
        int accumulatedFrameCount;
        int timer;
        int maxTimer;
    };
}

#endif  // FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H

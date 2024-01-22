/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:22)

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

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 10:52)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(PerformanceMeasurements, PerformanceMeasurementsImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE PerformanceMeasurements
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PerformanceMeasurements);

    public:
        explicit PerformanceMeasurements(int maxTimer);

        CLASS_INVARIANT_DECLARE;

        NODISCARD double GetFrameRate() const;
        NODISCARD std::string GetFrameRateMessage() const;

        void ResetTime();
        void MeasureTime();
        void UpdateFrameCount();

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H

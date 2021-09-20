// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include <string>

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(PerformanceMeasurements,PerformanceMeasurementsImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE PerformanceMeasurements
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PerformanceMeasurements);

    public:
        explicit PerformanceMeasurements(int maxTimer);

        CLASS_INVARIANT_DECLARE;

        double GetFrameRate() const;
        std::string GetFrameRateMessage() const;

        void ResetTime();
        void MeasureTime();
        void UpdateFrameCount();

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H

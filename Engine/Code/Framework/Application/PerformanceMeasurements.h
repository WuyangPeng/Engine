/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:24)

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

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:15)

#ifndef FRAMEWORK_APPLICATION_SUITE_PERFORMANCE_MEASUREMENTS_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_PERFORMANCE_MEASUREMENTS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class PerformanceMeasurementsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PerformanceMeasurementsTesting;
        using ParentType = UnitTest;

    public:
        explicit PerformanceMeasurementsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void PerformanceMeasurementsTest();
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_PERFORMANCE_MEASUREMENTS_TESTING_H
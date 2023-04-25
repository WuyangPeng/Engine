///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:40)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestSuiteReportOutputTesting final : public UnitTest
    {
    public:
        using ClassType = UnitTestSuiteReportOutputTesting;
        using ParentType = UnitTest;

    public:
        explicit UnitTestSuiteReportOutputTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void UnitTestSuiteReportOutputEquilongTest();
        void UnitTestSuiteReportOutputTimeTest();
        void UnitTestSuiteReportOutputTestResultTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H
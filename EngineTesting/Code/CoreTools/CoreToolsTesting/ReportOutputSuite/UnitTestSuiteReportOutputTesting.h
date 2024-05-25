/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 10:20)

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
        void DoRunUnitTest() override;
        void MainTest();

        void UnitTestSuiteReportOutputEquidistantTest();
        void UnitTestSuiteReportOutputTimeTest();
        void UnitTestSuiteReportOutputTestResultTest();
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:19)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestSuiteReportOutputTesting : public UnitTest
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
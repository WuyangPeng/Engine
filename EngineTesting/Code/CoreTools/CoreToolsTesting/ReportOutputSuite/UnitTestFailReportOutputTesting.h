///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:18)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_FAIL_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_FAIL_REPORT_OUTPUT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestFailReportOutputTesting : public UnitTest
    {
    public:
        using ClassType = UnitTestFailReportOutputTesting;
        using ParentType = UnitTest;

    public:
        explicit UnitTestFailReportOutputTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void ReportOutputTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_FAIL_REPORT_OUTPUT_TESTING_H
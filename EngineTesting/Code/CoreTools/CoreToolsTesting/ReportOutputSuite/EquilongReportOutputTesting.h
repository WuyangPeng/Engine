///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:39)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_EQUILONG_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_EQUILONG_REPORT_OUTPUT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EquilongReportOutputTesting final : public UnitTest
    {
    public:
        using ClassType = EquilongReportOutputTesting;
        using ParentType = UnitTest;

    public:
        explicit EquilongReportOutputTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void ReportOutputTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_SUITE_EQUILONG_REPORT_OUTPUT_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 10:20)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_EQUIDISTANT_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_EQUIDISTANT_REPORT_OUTPUT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EquidistantReportOutputTesting final : public UnitTest
    {
    public:
        using ClassType = EquidistantReportOutputTesting;
        using ParentType = UnitTest;

    public:
        explicit EquidistantReportOutputTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReportOutputTest();
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_SUITE_EQUIDISTANT_REPORT_OUTPUT_TESTING_H
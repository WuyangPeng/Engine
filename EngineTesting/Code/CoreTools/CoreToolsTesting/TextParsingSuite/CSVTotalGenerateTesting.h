///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.5 (2021/10/25 13:00)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVTotalGenerateTesting final : public UnitTest
    {
    public:
        using ClassType = CSVTotalGenerateTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVTotalGenerateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateCSV();
        void CSVTotalGenerateHeadTest();
        void CSVTotalGenerateFwdHeadTest();
        void CSVTotalGenerateContainerHeadTest();
        void CSVTotalGenerateContainerSourceTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H

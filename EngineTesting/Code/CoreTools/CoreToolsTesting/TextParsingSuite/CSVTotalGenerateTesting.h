///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:11)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CreateCSV();
        void CSVTotalGenerateHeadTest();
        void CSVTotalGenerateFwdHeadTest();
        void CSVTotalGenerateContainerHeadTest();
        void CSVTotalGenerateContainerSourceTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H

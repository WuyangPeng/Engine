///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.5 (2021/10/21 15:26)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVGenerateTesting final : public UnitTest
    {
    public:
        using ClassType = CSVGenerateTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVGenerateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateCSV();
        void CSVGenerateBaseHeadTest();
        void CSVGenerateChildHeadTest();
        void CSVGenerateContainerHeadTest();
        void CSVGenerateContainerDetailHeadTest();
        void CSVGenerateBaseSourceTest();
        void CSVGenerateChildSourceTest();
        void CSVGenerateContainerSourceTest();
        void CSVGenerateTotalVectorTest();
        void CSVGenerateTotalTreeMapTest();
        void CSVGenerateTotalHashMapTest();
        void CSVGenerateTotalKeyTest();
        void CSVGenerateTotalEnumHeadTest();
        void CSVGenerateTotalEnumSourceTest();
        void CSVGenerateTotalEnumTotalTest();
        void CSVGenerateTotalUniqueTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H

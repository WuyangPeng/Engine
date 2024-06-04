/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:27)

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
        using String = System::String;

    private:
        void DoRunUnitTest() override;
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

    private:
        String directory;
        String csvEngineeringDirectory;
        String csvGenerateDirectory;
        String csvEngineeringJson;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H
